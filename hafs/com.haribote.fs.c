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
int disknr;
int HAFS_init(int disknr1)
{
	disknr = disknr1;
	char *buf = (char *)mem_alloc(SEG_LONG);
	disk_read(disknr,2,SEG_LONG,buf);
	bsmarg = (struct bsmar *)mem_alloc(sizeof(struct bsmar));
	rootdirg = (struct rootdir *)mem_alloc(sizeof(struct rootdir));
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
	
	
	return 1;
	error:
		mem_free(buf);
		mem_free(bsmarg);
		mem_free(rootdirg);
		mem_free(seg1g);
		return 0;
} 






