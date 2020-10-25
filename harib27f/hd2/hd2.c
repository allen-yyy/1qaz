#include "apilib.h"
#include <stdio.h>
#include "type.h"
#include "hd.h"
u8 hdbuf[512*2];
void print_identify_info(u16* hdinfo);
void hd_cmd_out(struct hd_cmd* cmd);
void HariMain(void) {
	struct hd_cmd cmd;

	char s[61];
	cmd.device  = MAKE_DEVICE_REG(0, 0, 0);
	cmd.command = ATA_IDENTIFY;
	hd_cmd_out(&cmd);
	wait_int();
	port_read(0x170, hdbuf, 512);
	sprintf(s,"%lx",hdbuf);
	api_putstr0(s);
	print_identify_info((u16*)hdbuf);


	api_end();
}
void hd_cmd_out(struct hd_cmd* cmd) {
	/**
	 * For all commands, the host must first check if BSY=1,
	 * and should proceed no further unless and until BSY=0
	 */


	/* Activate the Interrupt Enable (nIEN) bit */
	io_out8(REG_DEV_CTRL, 0);
	/* Load required parameters in the Command Block Registers */
	io_out8(REG_FEATURES, cmd->features);
	io_out8(REG_NSECTOR,  cmd->count);
	io_out8(REG_LBA_LOW,  cmd->lba_low);
	io_out8(REG_LBA_MID,  cmd->lba_mid);
	io_out8(REG_LBA_HIGH, cmd->lba_high);
	io_out8(REG_DEVICE,   cmd->device);
	/* Write the command code to the Command Register */
	io_out8(REG_CMD,     cmd->command);
}
void print_identify_info(u16* hdinfo) {
	int i, k;
	char s[64];
	char y[65];

	struct iden_info_ascii {
		int idx;
		int len;
		char * desc;
	} iinfo[] = {{10, 20, "HD SN"}, /* Serial number in ASCII */
		{27, 40, "HD Model"} /* Model number in ASCII */
	};

	for (k = 0; k < sizeof(iinfo)/sizeof(iinfo[0]); k++) {
		char * p = (char*)&hdinfo[iinfo[k].idx];
		for (i = 0; i < iinfo[k].len/2; i++) {
			s[i*2+1] = *p++;
			s[i*2] = *p++;
		}
		s[i*2] = 0;
		sprintf(y,"%s: %s\n", iinfo[k].desc, s);
		api_putstr0(y);
	}

	int capabilities = hdinfo[49];
	sprintf(y,"LBA supported: %s\n",
	        (capabilities & 0x0200) ? "Yes" : "No");
	api_putstr0(y);
	int cmd_set_supported = hdinfo[83];
	sprintf(y,"LBA48 supported: %s\n",
	        (cmd_set_supported & 0x0400) ? "Yes" : "No");
	api_putstr0(y);
	int sectors = ((int)hdinfo[61] << 16) + hdinfo[60];
	sprintf(y,"HD size: %dMB\n", sectors * 512 / 1000000);
	api_putstr0(y);
}
