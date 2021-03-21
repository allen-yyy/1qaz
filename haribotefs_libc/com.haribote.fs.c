/* This Haribote's FS c file
		name       Date
		Allen      2020.10.6
		Allen      2021.1.20	disk_check
		Allen	   2021.1.21	disk_check
*/ 
#include "com.haribote.fs.inc.h"

void s1_alloc(struct s1 *a_s1)
{
	a_s1->E_flag = E_FLAG;
	a_s1->E_n = 1;
}

int disk_check(int *disk)
{
	*disk+=512;
	//s1
	struct s1 *ds1=disk;
}

BOOL mkfs()
{
	int *p;
	
	
	write_bs(p);
	write_s1(p);
	write_tab(p,16);
	write_bsmar(p);
	write_sn(p,2);
	write_tab(p,16);
	write_filesys(p);
	write_sn(p,3);
	write_tab(p,16);
	write_log(p);
	hd_write(p,0,0);
	
	return TURE;
}

void write_bs(int *p)
{
	p[0x1fe]=0x55;
	p[0x1ff]=0xaa;
	return;
}

void write_s1(int *p)
{
	struct s1 *ws1;
	ws1->E_flag = E_FLAG;
	ws1->E_n = 0;
	ws1->E_type = E_BOOT;
	ws1->go_s1.filesystem = FS_NAME;
	ws1->go_s1.s_long = sizeof(struct s1);
	
	memcpy(p+512,ws1,sizeof(struct s1));
	return;
}

void write_tab(int *p,int size)
{
	return;
}
void write_bsmar(int *p)
{
	struct bsmar *rbsmar;
	rbsmar->hd_j_s1 = 0;
	rbsmar->hd_j_s2 = 0;
	rbsmar->map1.frens = -1;
	rbsmar->m_flag = R_FLAG;
	return;
}

void write_sn(int *p,int n)
{
	return;
}
