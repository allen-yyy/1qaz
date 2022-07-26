#include "stdboot.h" 

int HsysMain(int);

void HariStartup()
{
	/* 将来HariMainの実行に先立って何かしたくなったら、ここに書き足す */

	int code=0;
	asm volatile("movl %%edx,%0":"=r"(code)); 
	HsysMain(code);
	
	asm volatile("movl $10,%edx;int $0x80;"); 
	/* 将来HariMainの終了後に何か処理をさせたくなったら、ここに書き足す */

	return;
}
