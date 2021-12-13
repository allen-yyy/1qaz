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
	if(rootdirg->numfile>ROOTFILEMAX) goto error;
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
	bsmarg->etcflag = etcflag;
	bsmarg->filesys[0]='H';
	bsmarg->filesys[1]='A';
	bsmarg->filesys[2]='F';
	bsmarg->filesys[3]='S';
	bsmarg->version = FS_VERSION;
	bsmarg->device = DEVTYPE_HD;
	bsmarg->seg_a_bit = 128; 
	
	struct diskinfo info;
	disk_info(disknr,&info);
	bsmarg->device=(int)(info.devicetype);
	bsmarg->allsize1=info.disksize;
	
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
	memcpy(buf1+sizeof(seg1),bsmarg,sizeof(struct bsmar));
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
	rootdirg->numfile=2;
	rootdirg->files[0].flag=fileflag;
	rootdirg->files[0].filenamelen=1;
	rootdirg->files[0].flongL=88+3;
	rootdirg->files[0].dirs=2;
	rootdirg->files[0].filenamelen=1;
	
	return;
}






