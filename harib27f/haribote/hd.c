#include "bootpack.h"
#include <stdio.h>
typedef	unsigned char		u8;
u8	hd_status;

void inthandler2e(int *esp){	/*
	 * Interrupts are cleared when the host
	 *   - reads the Status Register,
	 *   - issues a reset, or
	 *   - writes to the Command Register.
	 */
	io_out8(PIC1_OCW2,0x62);
	io_out8(PIC0_OCW2,0x62);
	char s[33]; 
	struct BOOTINFO *binfo = (struct BOOTINFO *) ADR_BOOTINFO; 
	u8 *pNrDrives = (u8*)(0x475);
	hd_status = io_in8(0x1f7);
    boxfill8(binfo->vram, binfo->scrnx, COL8_000000, 0, 0, 32 * 8 - 1, 15);
    sprintf(s,"INT 2E (IRQ-14) : hd  %d %d",*pNrDrives,hd_status);
	putfonts8_asc(binfo->vram, binfo->scrnx, 0, 0, COL8_FFFFFF, s);
	go_HRB_know();
	
}
