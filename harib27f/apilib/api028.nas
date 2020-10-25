[FORMAT "WCOFF"]
[INSTRSET "i486p"]
[BITS 32]
[FILE "api028.nas"]

		GLOBAL	_api_hd_no

[SECTION .text]

_api_hd_no:		; int api_getlang(void);
		MOV		EDX,28
		INT		0x40
		RET
