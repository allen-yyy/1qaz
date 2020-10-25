[FORMAT "WCOFF"]
[INSTRSET "i486p"]
[BITS 32]
[FILE "api030.nas"]

		GLOBAL	_io_out8

[SECTION .text]

_io_out8:		; int api_getlang(void);
		MOV		EDI,[ESP + 4]
		MOV		ESI,[ESP + 8]

		MOV		EDX,30
		INT		0x40
		RET
