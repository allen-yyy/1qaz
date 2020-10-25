[FORMAT "WCOFF"]
[INSTRSET "i486p"]
[BITS 32]
[FILE "api031.nas"]

		GLOBAL	_wait_int

[SECTION .text]

_wait_int:		; int api_getlang(void);


		MOV		EDX,31
		INT		0x40
		RET
