/*
	Name: com.haribote.fs.c 
	Copyright: 
	Author: Allen
	Date: 29/10/21 20:00
	Description: hafs c file
*/

#include "com.haribote.fs.inc.h"
/*Add your OS's header file there.*/

//version
int HAFS_version()
{
	return FS_VERSION;
}

//init
struct seg1 *seg1g;
struct bsmar *bsmarg;
struct rootdir *rootdirg;
struct log *logg; 
int disknr;
int HAFS_init(int disknr1)
{
	disknr = disknr1;
	char *buf = (char *)mem_alloc(SEG_LONG);
	disk_read(disknr,2,SEG_LONG,buf);
	bsmarg = (struct bsmar *)mem_alloc(sizeof(struct bsmar));
	rootdirg = (struct rootdir *)mem_alloc(SEG_LONG);
	seg1g = (struct seg1 *)mem_alloc(sizeof(struct seg1));
	memcpy(seg1g,buf,sizeof(struct seg1));
	
	/*bsmar and seg1*/
	if(seg1g->flag!=segflag||seg1g->filesys[0]!="H"||seg1g->filesys[1]!="A"||\
	seg1g->filesys[2]!="F"||seg1g->filesys[3]!="S") goto error;
	memcpy(bsmarg,buf+sizeof(struct seg1),sizeof(struct bsmar));
	if(bsmarg->flag!=bsmarflag||bsmarg->filesys[0]!="H"||bsmarg->filesys[1]!="A"||\
	bsmarg->filesys[2]!="F"||bsmarg->filesys[3]!="S") goto error;
	
	/*dir parse*/
	disk_read(disknr,3,SEG_LONG,buf);
	memcpy(rootdirg,buf+sizeof(struct segn),SEG_LONG-sizeof(struct segn));
	if(rootdirg->flag!=dataflag) goto error;
	if(rootdirg->numfiles>ROOTFILEMAX) goto error;
	if(rootdirg->files[0].filenamelen!=1) goto error;//first FILED always is .
	
	/*log*/
	logg = (struct log *)mem_alloc(sizeof(struct log));
	disk_read(disknr,4,SEG_LONG,buf);
	memcpy(logg,buf+sizeof(struct segn),SEG_LONG-sizeof(struct segn));
	
	/*set flag*/
	bsmarg->status|=STATUS_BOOTS;
	buf=(char *)seg1g;
	char *buf1=buf+sizeof(struct seg1);
	buf1=(char *)bsmarg;
	disk_write(disknr,2,SEG_LONG,buf);
	 
	/* OK */
	return 1;
	error:
		mem_free(buf);
		mem_free(bsmarg);
		mem_free(rootdirg);
		mem_free(seg1g);
		return 0;
}

void HAFS_freeAll()
{
	if(bsmarg) mem_free(bsmarg);
	if(rootdirg) mem_free(rootdirg);
	if(seg1g) mem_free(seg1g);
	if(logg) mem_free(logg);
	return;
}

//format
void HAFS_format(int disknr1)
{
	disknr=disknr1;
	HAFS_freeAll();
	bsmarg = (struct bsmar *)mem_alloc(sizeof(struct bsmar));
	rootdirg = (struct rootdir *)mem_alloc(SEG_LONG);
	seg1g = (struct seg1 *)mem_alloc(sizeof(struct seg1));
	logg = (struct log *)mem_alloc(sizeof(struct log));
	struct segn *segs =  (struct segn *)mem_alloc(sizeof(struct segn));
	/*bsmar*/
	bsmarg->flag = bsmarflag;
	bsmarg->etcflag = etc1flag;
	bsmarg->filesys[0]='H';
	bsmarg->filesys[1]='A';
	bsmarg->filesys[2]='F';
	bsmarg->filesys[3]='S';
	bsmarg->version = FS_VERSION;
	bsmarg->device = DEVTYPE_HD;
	
	
	struct diskinfo info;
	disk_info(disknr,&info);
	bsmarg->device=(int)(info.devicetype);
	bsmarg->allsize1=info.disksize;
	
	
	int tmp=bsmarg->allsize1 / SEG_LONG / 1600;
	if(tmp<6) tmp=5;
	bsmarg->seg_a_bit = tmp; 
	
	bsmarg->maps.frees = bsmarg->allsize1 / SEG_LONG / tmp;
	memset(bsmarg->maps.free,0,1600);
	bsmarg->maps.free[0].bitmap_a[0]=1;//seg-group1 used 
	
	bsmarg->status=0;
	memset(bsmarg->pad,0,431*4+0*2);
	/*seg1*/
	seg1g->flag=segflag;
	seg1g->s_flag=0;
	seg1g->filesys[0]='H';
	seg1g->filesys[1]='A';
	seg1g->filesys[2]='F';
	seg1g->filesys[3]='S';
	
	char *buf1=(char *)mem_alloc(SEG_LONG);
	memcpy(buf1,seg1g,sizeof(struct seg1));
	memcpy(buf1+sizeof(struct seg1),bsmarg,sizeof(struct bsmar));
	disk_write(disknr,2,SEG_LONG,buf1);
	memset(buf1,0,SEG_LONG);
	
	/*segn*/
	segs->filesys[0]='H';
	segs->filesys[1]='A';
	segs->filesys[2]='F';
	segs->filesys[3]='S';
	segs->flag=segflag;
	segs->segn=2;
	
	/*rootdir*/
	rootdirg->flag=dataflag;
	rootdirg->numfiles=2;
	//rootdirg->files[0].flag=fileflag;
	rootdirg->files[0].node=0;
	rootdirg->files[0].resize=20;
	rootdirg->files[0].nextoff=20;
	rootdirg->files[0].filenamelen=1;
	rootdirg->files[0].filename[0]='.';
	rootdirg->files[0].filename[1]=' ';
	rootdirg->files[0].filename[2]=' ';
	rootdirg->files[0].filename[3]=' ';
	rootdirg->files[0].type=T_dir;
	
	struct FILED *tmp2=(&rootdirg->files[0])+rootdirg->files[0].nextoff;
	tmp2->node=0;
	tmp2->resize=20;
	tmp2->nextoff=rootdirg->files[0].nextoff+rootdirg->files[1].resize;
	tmp2->filenamelen=2;
	tmp2->filename[0]='.';
	tmp2->filename[1]='.';
	tmp2->filename[2]=' ';
	tmp2->filename[3]=' ';
	tmp2->type=T_dir; 
	
	memcpy(buf1,segs,sizeof(struct segn));
	memcpy(buf1+sizeof(struct segn),rootdirg,sizeof(struct rootdir));
	disk_write(disknr,3,SEG_LONG,buf1);
	memset(buf1,0,SEG_LONG);
	
	/*log*/
	segs->segn++;
	
	logg->many=4;
	logg->logs[0].segA=1;
	logg->logs[0].segB=0;
	logg->logs[0].segC=0;
	logg->logs[0].type=LOG_WRITE;
	
	logg->logs[1].segA=2;
	logg->logs[1].segB=0;
	logg->logs[1].segC=0;
	logg->logs[1].type=LOG_WRITE;
	
	logg->logs[2].segA=3;
	logg->logs[2].segB=0;
	logg->logs[2].segC=0;
	logg->logs[2].type=LOG_WRITE;
	
	logg->logs[3].segA=4;
	logg->logs[3].segB=0;
	logg->logs[3].segC=0;
	logg->logs[3].type=LOG_WRITE;
	
	memcpy(buf1,segs,sizeof(struct segn));
	memcpy(buf1+sizeof(segn),logg,sizeof(struct log));
	disk_write(disknr,4,SEG_LONG,buf1);
	memset(buf1,0,SEG_LONG);
	
	/*node*/
	struct FILEND *onen=(struct FILED *)buf1;
	onen->num=0;
	onen->flag=fileflag;
	onen->flongL=40;
	onen->flongH=0;
	onen->dirs=1;
	onen->blocks[0]=2*2+0;
	onen->root[0]=onen->root[1]=onen->root[2]=0;
	disk_write(disknr,5,SEG_LONG,buf1);
	
	/*seg-group*/
	//none
	
	//OK 
	return;
}

char *get_name(char *names)
{
	char *name;
	int i=0;
	while(names[i]!='\\'&&names[i]!=0)
	{
		i++;
	}
	name=(char *)mem_alloc(i);
	memcpy(name,names,i);
	return name;
}

/*find-file*/
int HAFS_findFile(char *name) //hafs dir-name:drive+path+filename like C:\a\a\a\a.int.file
{
	int node=0,i=0,len=0;
	for(i=0;i<65536;i++)
	{
		if(name[i]!=0)
		{
			len++;
		}else{
			break;
		}
	}
	name+=3;
	char *tmpn=get_name(name);
	
	while(1)
	{
		
		
	}
	return node;
}

struct handle_s handle_data[512];
int handle_map[64];

/*open*/
int HAFS_open(char *name,int flag) 
{
	
	return 0; 
} 




