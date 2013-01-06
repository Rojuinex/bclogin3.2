define		BCALL xxxx rst 28h \ .dw xxxx

CALL  init
CALL  main
CALL  cleanUp
RET

bclUsr:    db 15h,"BCLogUsr",0h,0h
usrPropt:  db "NewUsr:",0h,0h,0h,0h
pwdPrompt: db "NewPwd:",0h,0h,0h,0h
usrStr:    db "Username:",0h,0h
pwdStr:    db "Password:",0h,0h
logo:      db 09h,08h,FFh,EDh,93h,F1h,93h,EDh,42h,24h,18h
name:      db "Login3.2",0h
copyright: db 08h,08h,00h,3Eh,41h,5Dh,51h,5Dh,41h,3Eh

initCont:
	BCALL _RunIndcOff
	RES	  donePrgm,(IY+doneFlags)
	LD    DE, 3700h
	LD    HL, logo
	BCALL _DisplayImage
	LD    HL, 3709h
	LD    (penCol), HL
	LD    HL, name
	BCALL _VPustS
	LD    DE, 3624h
	LD    HL, copyright
	BCALL _DisplayImage
	RET

quickCheck:
	BCALL _Mov9ToOp1
	BCALL _ChkFindSym
	RET

getString:
	LD    HL, saveSScreen + 1
	LD    B, 0
	NOP
	NOP
	CALL  getKey
	NOP
	NOP
	CP    5h
	JR    Z, Ah
	LD    (HL), A
	INC   B
	LD    A, 0
	BCALL _PutC
	JR    -15h
	LD    A, B
	LD    (saveSScreen), A
	RET

compareString:
	LD    A, (DE)
	CP    (HL)
	JR    NZ, Ch
	LD    B, A
	INC   HL
	INC   DE
	LD    A, (DE)
	CP    (HL)
	JR    NZ, 5h
	DJNZ  -8h
	LD    A, 1h
	RET
	LD    A, 0
	RET

moveString:
	LD    A, (DE)
	INC   A
	LD    B, A
	LD    A, (DE)
	LD    (HL), A
	INC   HL
	INC   DE
	DJNZ  -6h
	RET

shutDown:
	CALL  cleanUp
	BCALL _PowerOff

cleanUp:
	BCALL _ClrScrnFull
	BCALL _HomeUp
	LD    HL, bclUsr
	CALL  quickCheck
	RET   C
	LD    A, B
	OR    A
	RET   NZ
	BCALL _Archive
	RET

main:
	LD    HL, bclUsr
	CALL  quickCheck
	JR    C, 4h
	CALL  login
	RET

newUser:
	LD    HL, usrPropt
	BCALL _PutS
	CALL  getString
	LD    HL, appBackUpScreen
	LD    DE, saveSScreen
	CALL  moveString
	PUSH  HL
	BCALL _newline
	LD    HL, pwdPrompt
	BCALL _PutS
	CALL  getString
	POP   HL
	LD    DE, saveSScreen
	CALL  moveString

registerUser:
	LD    HL, appBackUpScreen
	LD    A, (appBackUpScreen)
	INC   A
	LD    B, 0
	LD    C, A
	ADD   HL, BC
	LD    A, (HL)
	INC   A
	ADD   A, C
	LD    L, A
	LD    H, 0
	PUSH  HL
	LD    HL, bclUsr
	BCALL _Mov9ToOP1
	POP   HL
	BCALL _CreateAppVar
	INC   DE
	INC   DE
	LD    HL, appBackUpScreen
	EX    DE, HL
	CALL  moveString
	CALL  moveString
	RET

login:
	LD    HL, usrStr
	BCALL _PutS
	CALL  _newline
	LD    HL, appBackUpScreen
	LD    DE, saveSScreen
	CALL  moveString
	PUSH  HL
	BCALL _newline
	LD    HL, pwdStr
	BCALL _PutS
	CALL  getString
	POP   HL
	LD    DE, saveSScreen
	CALL  moveString
	LD    HL, bclUsr
	CALL  quickCheck
	JP    C, newUser
	LD    A, B
	OR    A
	JR    Z, 9h
	BCALL _Unarchive
	LD    HL, bclUsr
	CALL  quickCheck

checkLogin:
	LD    HL, appBackUpScreen
	INC   DE
	INC   DE
	CALL  compareString
	OR    A
	JP    Z, shutDown
	INC   HL
	INC   DE
	CALL  compareString
	OR    A
	JP    Z, shutDown
	RET

getKey:
	PUSH  HL
	PUSH  BC
	BCALL _getkey
	RES   onInterrupt, (IY+onFlags)
	CP    0h
	JR    Z, -Bh
	POP   BC
	POP   HL

	PUSH  AF
	LD    A, 10h
	CP    B
	JR    NC, 4h
	POP   AF
	LD    A, 5h
	RET
	POP   AF

	CP    9h
	RET   NZ
	PUSH  AF
	LD    A, B
	OR    A
	JR    NZ, 4h
	POP   AF
	JP    getKey

	POP   AF
	DEC   B
	DEC   HL
	PUSH  AF
	PUSH  HL
	PUSH  BC
	LD    HL, curCol
	DEC   (HL)
	LD    A, 20h
	BCALL _PutMap
	POP   BC
	POP   HL
	POP   AF
	JP    getKey

init:
	BCALL _ClrScrnFull
	BCALL _HomeUp
	SET   lwrCaseActive, (IY+appLwrCaseFlag)
	CALL  initCont
	RET