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
#define NAMELENMAX 256

struct seg1{
	int flag;
	int s_flag; //0-can't boot.1-can boot
	char filesys[6];
};

struct segn{
	int flag;
	int segn;
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
	int device;
	#define DEVTYPE_HD 1
	#define DEVTYPE_FD 2
	#define DEVTYPE_USB 3
	int allsize1;
	int allsize2;
	int allsize3;
	int allsize4;
	int os;		//usually is 1--hariboteos
	int seg_a_bit;	//usually is 128
	int status; //now fs status
	#define STATUS_CLEAN 1<<0
	#define STATUS_WRITE 1<<1
	#define STATUS_ERROR 1<<2
	//1742B free
	char pad1[2];
	
	int pad[435];
};

struct FILED{
	int flag;
	int fsegL;//use it*1
	int fsegM;//use it*512
	int fsegH;//use it*512,too
	int flongL;//use B
	int flongM;//use KB
	int flongH;//use KB,too
	char isdir;
	char root[3];
	int  sizeofthis;
	int filenamelen; 
	char filename[30];
};

struct FILEA{
	int flag;
	int longL;//use B
	int longH;//use KB
	long longl;//use KB,too
};

#define segflag		0x6e676573	//segn
#define bsmarflag	0x616d7362  //bsma
#define etcflag		0x31637465	//etc1
#define fileflag	0x656c6966	//file
#define dataflag	0x61746164	//data

struct rootdir{
	int flag;  //data
	struct FILED files[20];
};

struct log{
	int many;
	struct log_a logs[0];
};

struct log_a{
	int type;
	#define LOG_READ 1<<0
	#define LOG_WRITE 1<<1
	#define LOG_EXDEV 1<<1	
	int segA;//it*1
	int segB;//it*10
	int segC;//it*10
};
