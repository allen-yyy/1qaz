/*
	Name: com.haribote.fs.user.h
	Copyright: 
	Author: Alklen
	Date: 01/01/22 10:51
	Description: hafs for os2fs
*/

#define HAFS_VERSION "HAFS1" 

struct handle_s{
	int num;
	int node;
	char *buf;
	int pos;
};

/*open flag*/
#define RDWT 1	//read write
#define RDOY 2	//only read
#define WTOY 4	//only write
