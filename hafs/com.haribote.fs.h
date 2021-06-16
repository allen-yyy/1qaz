/*
	Name: com.haribote.fs.h
	Copyright: 
	Author: Allen
	Date: 14/06/21 17:56
	Description: 
*/

#define FS_NAME "HAFS1"
#define SEG_LONG 2048
#define BLOCK_LONG 1048

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
	long segL;
	long segM;
	long segH;
	long freelongL; 
	long freelongM;
	long freelongH;
};

struct map{
	int frees;
	struct freetable[0xff];
};

struct bsmar{
	int flag;
	char stflag;
	struct map maps; 
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

#define segflag "segn"
#define etcflag "etc1"
#define fileflag "file"
#define dataflag "data"

struct rootdir{
	int flag;  //data
	struct FILED files[20];
};

struct log{
	int type;
	int shutflag;
};
