[FORMAT "WCOFF"]
[INSTRSET "i486p"]
[OPTIMIZE 1]
[OPTION 1]
[BITS 32]
	EXTERN	_HsysMain
[FILE "startup.ca"]
[SECTION .text]
	GLOBAL	_HariStartup
_HariStartup:
	PUSH	EBP
	MOV	EBP,ESP
	MOV	EAX,EDX
	PUSH	EAX
	CALL	_HsysMain
	MOV	EDX,10
	INT 0x80
	LEAVE
	RET
