/* This Haribote's FS h file
        name    	Date
		Allen		2020.10.6
		Allen		2020.10.17    	FDINFO FILED DATE FS_NAME
		Allen		2020.10.19		date s1 sn go bsmar fren root
*/
#include "bootpack.h"
#define FS_NAME "hafs"

struct fren{
	int addrH;
	int addrL;
	long size;
};

struct map{
	int frens;
	struct fren[]; 
};

struct go{
	char *filesystem;
	int s_long;	
};

struct s1{
	int E_flag;
	int E_n;
	int E_type;
	struct go go_s1;
};

struct sn{
	int s_flag;
	int s_n;
	struct go gos;
};

struct bsmar{
	int m_flag;
	int st_flag;
	int hd_j_s1;
	int hd_j_s2;
	struct map map1;
};

struct date
{
	int y1,y2;
	int m,day;
};
struct FDINFO
{
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

struct FILED
{
	int da_flag;
	int fl1,fl2,fl3;
	int n_s[3];
	int s1,s2,off;
	int ab_flag;
	char *data;
	int ab_flag1;
	int n_s1,n_s2,n_off;
};

struct root{
	int r_flag;
	struct FDINFO files[];
	int s_n;
};

	
																							                                            
