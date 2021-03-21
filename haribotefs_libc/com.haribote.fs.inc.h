/* This Haribote's FS h file
        name    	Date
		Allen		2020.10.6
		Allen		2020.10.17    	FDINFO FILED DATE FS_NAME
		Allen		2020.10.19		date s1 sn go bsmar fren root
		Allen		2020.11.6		R_FLAG DA_FLAG FD_FLAG
		Allen		2020.11.22		R_FLAG DA_FLAG FD_FLAG S_FLAG E_FLAG
		Allen		2020.12.16		log LOG_COPY LOG_WRITE LOG_READ
*/
//#include "bootpack.h"
#include "dpi.h"
#define FS_NAME "hafs"

struct fren {
	int addrH;
	int addrL;
	long size;
};

struct map {
	int frens;
	struct fren[256];
};

struct go {
	char filesystem[5];
	int s_long;
};

struct s1 {
	int E_flag;
	int E_n;
	int E_type;
	struct go go_s1;
};

struct sn {
	int s_flag;
	int s_n;
	struct go gos;
};

struct bsmar {
	int m_flag;
	int st_flag;
	int hd_j_s1;
	int hd_j_s2;
	struct map map1;
};

struct date {
	int y1,y2;
	int m,day;
};
struct FDINFO {
	int fd_flag;
	int filenamel;
	char *filename;
	int fileextl;
	char *fileext;
	int s1,s2,off;
	int fs1,fs2,foff;
	int type;
	struct date cdate; //创建
	struct date gdate; //访问
	struct date wdate; //修改
	int fsize1,fsize2,fsize3;
	char root1[3];
	char root2[3];
	char Adn;
};

struct FILED {
	int da_flag;
	int fl1,fl2,fl3;
	int n_s[3];
	int s1,s2,off;
	int ab_flag;
	char *data;
	int ab_flag1;
	int n_s1,n_s2,n_off;
};

struct root {
	int r_flag;
	int s_n;
	struct FDINFO files[];
};

#define R_FLAG 0x52525252
#define DA_FLAG 0x44414441
#define FD_FLAG 0x46444644
#define S_FLAG 0x53535353
#define E_FLAG 0x45454545
#define R_FLAG 0x52525252

struct log {
	char log[0x30];
	int type;
};

#define LOG_COPY 0x1
#define LOG_WRITE 0x2
#define LOG_READ 0x3 

void write_bs(int *p);
void write_s1(int *p);
void write_tab(int *p,int size);
void write_bsmar(int *p);
void write_sn(int *p,int n);
//write_tab(p,16);
void write_filesys(int *p);
//write_sn(p,3);
//write_tab(p,16);
void write_log(int *p);

#define E_BOOT 0x1
#define E_UNBOOT 0x20
