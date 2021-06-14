#include <stdio.h>
#include <windows.h>
char optmatch(const char *script, const char *opt); 
int main(int argc,char **argv) 
{
	int i=1;
	int innum = argc;
	UCHAR *p;
	while ((p = *++argv) != NULL) {
		//if (*p != '@') {
			//r = ++q;
			//while ((*q++ = *p++) != '\0') {
				//i//f (q - script0 >= SIZ_SCRIPT - 4)
				//	errend(2); /* script too long */
			//}
			//if (q - r > 255 + 1)
			//	errend(3); /* script too long */
			//*(r - 1) = (q - r) - 1;
			continue;} 
		//}
	for (;;) {
		if (*p == '\0')
			break;
		if (cmdmatch(p, "copy")) {
			p = (UCHAR *) cmd_copy(p);
			continue;
		}
		//if (cmdmatch(p, "ovrcopy")) {
		//	p = (UCHAR *) cmd_ovrcopy(p);
		//	continue;
		//}
		if (cmdmatch(p, "create")) {
			p = (UCHAR *) cmd_create(p);
			continue;
		}
		//if (cmdmatch(p, "ovrcreate")) {
		//	p = (UCHAR *) cmd_ovrcreate(p);
		//	continue;
		//}
		if (cmdmatch(p, "delete")) {
			p = (UCHAR *) cmd_delete(p);
			continue;
		}
		//if (cmdmatch(p, "setattr")) {
		//	p = (UCHAR *) cmd_setattr(p);
		//	continue;
		//}
		if (cmdmatch(p, "wbinimg")) {
			p = (UCHAR *) cmd_wbinimg(p);
			continue;
		}
		//if (cmdmatch(p, "release")) {
		//	p = (UCHAR *) cmd_release(p);
		//	continue;
		//}
		//if (cmdmatch(p, "writedata")) {
		//	p = (UCHAR *) cmd_writedata(p);
		//	continue;
		//}
		//if (cmdmatch(p, "list")) {
		//	p = (UCHAR *) cmd_list(p);
		//	continue;
		//}
		//if (cmdmatch(p, "copyall")) {
		//	p = (UCHAR *) cmd_copyall(p);
		//	continue;
		//}
		//if (cmdmatch(p, "exe2bin")) {
		//	p = (UCHAR *) cmd_exe2bin(p);
			//continue;
		//}
		/*if (cmdmatch(p, "opt")) {
			p += *p + 2;
			continue;
		}*/ 
		if (optmatch(p, "imgin")) {
			p = (UCHAR *) opt_imgin(p);
			continue;
		}
		//if (optmatch(p, "vsiz")) {
		//	p = (UCHAR *) opt_vsiz(p);
			//continue;
		//}
		if (optmatch(p, "imgout")) {
			p = (UCHAR *) opt_imgout(p);
			continue;
		}
		//if (optmatch(p, "binin")) {
		//	p = (UCHAR *) opt_binin(p);
		//	continue;
		//}
		/*if (optmatch(p, "binout")) {
			p = (UCHAR *) opt_binout(p);
			continue;
		}
		if (optmatch(p, "_path")) {
			p = (UCHAR *) opt_bpath(p);
			continue;
		}
		if (optmatch(p, "bias")) {
			p = (UCHAR *) opt_bias(p);
			continue;
		}*/ 
		if (cmdmatch(p, "/*")) {
			i = 1;
			do {
				p += *p + 2;
				if (*p == '\0')
					//errend(9); /* comment nesting error */
				if (cmdmatch(p, "/*"))
					i++;
				if (cmdmatch(p, "*/"))
					i--;
			} while (i > 0);
			p += *p + 2;
			continue;
		}
		fputs("script syntax error. : ", stderr);
		fputs(p + 1, stderr);
		//errend(8); /* script syntax error */
	}
	 
	return 0;
}

char optmatch(const char *script, const char *opt)
{
	script++;
	for (;;) {
		if (*opt == '\0') {
			if (*script == ':')
				return 1;
			break;
		}
		if (*opt != *script)
			break;
		opt++;
		script++;
	}
	return 0;
}

const UCHAR *cmd_copy(const char *cmd)
{
	char nocmp = 0;
	cmd += *cmd + 2;
	if (optmatch(cmd, "nocmp")) {
		cmd += *cmd + 2;
		nocmp = 1;
	}
	if (optmatch(cmd, "from") == 0)
		errend(10); /* copy command error */
	readfile(pathfix(cmd + (4 + 2), 0), 0x0f);
	cmd += *cmd + 2;
	if (nocmp)
		len_filebuf = autodecomp2(SIZ_FILEBUF, filebuf0, len_filebuf);
	if (optmatch(cmd, "to") == 0)
		//errend(10); /* copy command error */
	writefile(pathfix(cmd + (2 + 2), 1), 2, -1, 0x07);
	return cmd + (*cmd + 2);
}

