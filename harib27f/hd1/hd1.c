#include "apilib.h"
#include <stdio.h>
void HariMain(void)
{
	char *s[105*50];
	unsigned char * hdno = api_hd_no();
	sprintf(s,"%x",hdno);
	api_putstr0(s);
	
	
	
	api_end();	
}
