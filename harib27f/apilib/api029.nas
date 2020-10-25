[FORMAT "WCOFF"]
[INSTRSET "i486p"]
[BITS 32]
[FILE "api028.nas"]

		GLOBAL	_port_read

[SECTION .text]

_port_read:		; int api_getlang(void);
		MOV		EDI,[ESP + 4]
		MOV		ESI,[ESP + 8]
		MOV		EBP,[ESP + 12]
		MOV		EDX,29
		INT		0x40
		RET
