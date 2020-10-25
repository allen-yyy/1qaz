/* This is Haribote's libc
		name		date
		Allen		2020.10.19
		Allen		2020.10.24		printf putchar exit 
		*/ 
/*
		printf l18
		putchar l31
		exit l37

*/
#include "../apilib.h"
#include <stdio.h>
#include <stdarg.h> 
#include "com.haribote.libc.inc.h" 


int printf(char *format, ...)
{
	va_list ap;
	char s[1000];
	int i;
	
	va_start(ap,format);
	i = vsptintf(s,format,ap);
	api_putstr0(s);
	va_end(ap);
	return i;
}

int putchar(int c)
{
	api_putchar(c);
	return c;
}

void exit(int status)
{
	api_end();
}
