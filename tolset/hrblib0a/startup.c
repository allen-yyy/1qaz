#include "stdboot.h" 

int HsysMain(int);

void HariStartup()
{
	/* ����HariMain�̎��s�ɐ旧���ĉ����������Ȃ�����A�����ɏ������� */

	int code=0;
	asm volatile("movl %%edx,%0":"=r"(code)); 
	HsysMain(code);
	
	asm volatile("movl $10,%edx;int $0x80;"); 
	/* ����HariMain�̏I����ɉ������������������Ȃ�����A�����ɏ������� */

	return;
}
