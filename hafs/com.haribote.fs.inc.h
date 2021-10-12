/*
	Name: com.haribote.fs.inc.h
	Copyright: 
	Author: Allen
	Date: 14/06/21 17:56
	Description: 
*/

#define FS_NAME "HAFS"
#define _VERSION(a,b) a<<16+0x2e<<8+b
#define FS_VERSION _VERSION(1,0) 
#define SEG_LONG 8192
#define BLOCK_LONG 4096

struct seg1{
	int flag;
	int s_flag; //0-can't boot.1-can boot
	char filesys[6];
};

struct segn{
	int flag;
	char filesys[6];
};

struct freetable{
	int bitmap_a[40]; //128 seg as a bit. 
};

struct map{
	int frees;
	struct freetable free[40];
};

struct bsmar{	//like ext2 fs's super block.
	int flag;
	int ectflag;
	struct map maps;
	char filesys[6];
	int version;
	int allsize1;
	int allsize2;
	int allsize3;
	int allsize4;
	int os;		//usually is 1--hariboteos
	int seg_a_bit;	//usually is 128 
};

struct FILED{
	int flag;
	char filename[30];
	char fileext[10];
	int fsegL;
	int fsegM;
	int fsegH;
	int flongL;
	int flongH;
	long flongl;
	char dir;
	char root[3];
};

struct FILEA{
	int flag;
	int longL;
	int longH;
	long longl;
};

#define segflag		0x6e676573	//seg1
#define bsmarflag	0x616d7362  //bsma
#define etcflag		0x31637465	//etc1
#define fileflag	0x656c6966	//file
#define dataflag	0x61746164	//data

struct rootdir{
	int flag;  //data
	struct FILED files[20];
};

struct log{
	int type;
	int shutflag;
};
