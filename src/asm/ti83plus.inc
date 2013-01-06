;-----------------------------------------------------------------------------
; TI-83 Plus Include File by Brandon Wilson
;-----------------------------------------------------------------------------
; 06/27/2005
;-----------------------------------------------------------------------------
; This TI-83 Plus include file includes all known page 1Bh and page 1Fh ROM
;  calls as well as flag, keyboard, and character equates.
;-----------------------------------------------------------------------------

;Included for TASM Compatibility
;-------------------------------
#define equ .equ
#define EQU .equ
#define end .end
#define END .end

;System Variable Equates
;------------------------------
XSCLt									equ 2
YSCLt									equ 3
XMINt									equ 0Ah
XMAXt									equ 0Bh
YMINt									equ 0Ch
YMAXt									equ 0Dh
TMINt									equ 0Eh
TMAXt									equ 0Fh
THETMINt							equ 10h
THETMAXt							equ 11h
TBLMINt								equ 1Ah
PLOTSTARTt						equ 1Bh
NMAXt									equ 1Dh
NMINt									equ 1Fh
TBLSTEPt							equ 21h
TSTEPt								equ 22h
THETSTEPt							equ 23h
DELTAXt								equ 26h
DELTAYt								equ 27h
XFACTt								equ 28h
YFACTt								equ 29h
FINNt									equ 2Bh
FINIt									equ 2Ch
FINPVt								equ 2Dh
FINPMTt								equ 2Eh
FINFVt								equ 2Fh
FINPYt								equ 30h
FINCYt								equ 31h
PLOTSTEPt							equ 34h
XRESt									equ 36h

;Run indicators
;------------------------------------
busyPause							equ 10101010b
busyNormal						equ 11110000b

;Banked Call Equates/Macros
;-----------------------------------------------
rBR_CALL			equ 28h	;NEEDED FOR APPS
BRT_JUMP0			equ 50h
#define bcall(xxxx) rst 28h \ .dw xxxx
#define bjump(xxxx) call 50h \ .dw xxxx

;Common Restart Routines
;------------------------------
rOP1TOOP2							equ 08h
rFINDSYM							equ 10h
rPUSHREALO1						equ 18h
rMOV9TOOP1						equ 20h
rFPADD								equ 30h

;Error Handler Equates/Macros
;-------------------------------------------
APP_PUSH_ERRORH				equ 59h
APP_POP_ERRORH				equ 5Ch
#define AppOnErr(xxxx) ld hl,xxxx \ call 59h
#define AppOffErr call 5Ch

;Page 1Bh ROM Calls
;--------------------------------
_JErrorNo							equ 4000h
_FontHook							equ 4003h
_call_character_hook	equ 4006h ;calls character(localize) hook
_ldHLind							equ 4009h ;l=a=(hl),h=(hl+1)
_CpHLDE								equ 400Ch
_DivHLBy10						equ 400Fh
_DivHLByA							equ 4012h
_kdbScan							equ 4015h
_GetCSC								equ 4018h ;key board scan codes
_coorMon							equ 401Bh ;
_Mon									equ 401Eh ;system monitor, customized through the context vectors
_monForceKey					equ 4021h ;
_sendKPress						equ 4024h
_JForceCmdNoChar			equ 4027h
_JForceCmd						equ 402Ah ;
_sysErrHandler				equ 402Dh ;loads error context? sp=(onSP)
_newContext						equ 4030h ;(kbdKey)=0, loads context, restores page in 4000h-7fffh
_newContext0					equ 4033h ;loads context
_cxPutAway						equ 4036h ;
_cxPutAway2						equ 4039h ;same but also does a B_CALL CanAlphIns
_cxPPutAway						equ 403Ch
_cxSizeWind						equ 403Fh
_cxErrEP							equ 4042h
_cxMain								equ 4045h
_monErrHand						equ 4048h ;installs errorhandler to start of ROM call, loads error context, jumps to mon
_AppInit							equ 404Bh ;loads vector data at hl to cxMain and the rest of the vectors
_resetRam							equ 404Eh
_lcd_busy							equ 4051h ;wait till bit 1 of port 2 is set
_Min									equ 4054h ;op1 = lowest number between op1 and op2
_Max									equ 4057h ;op1 = highest number between op1 and op2 
_Trunc								equ 4060h
_InvSub								equ 4063h
_Times2								equ 4066h
_Plus1								equ 4069h ;op1=op1+1
_Minus1								equ 406Ch
_FPSub								equ 406Fh
_FPAdd								equ 4072h
_DToR									equ 4075h
_RToD									equ 4078h
_Cube									equ 407Bh
_TimesPt5							equ 407Eh
_FPSquare							equ 4081h
_FPMult								equ 4084h ;op1=op1*op2
_LJRND								equ 4087h ;adjusts op1 if 0s precede the actual number... rounding? when.
_InvOP1SC							equ 408Ah
_InvOP1S							equ 408Dh
_InvOP2S							equ 4090h
_frac									equ 4093h
_fprecip							equ 4096h
_fpdiv								equ 4099h
_SqRoot								EQU 409Ch
_RndGuard							EQU 409Fh
_RnFx									EQU 40A2h
_int									equ 40A5h
_Round								EQU 40A8h
_LnX									EQU 40ABh
_LogX									EQU 40AEh
_LJNORND							equ 40B1h ;like _LJRND but no rounding
_EToX									equ 40B4h
_TenX									equ 40B7h
_SinCosRad						equ 40BAh
_Sin									equ 40BDh
_cos									equ 40C0h
_Tan									equ 40C3h
_SinHCosH							equ 40C6h
_TanH									equ 40C9h
_cosh									equ 40CCh
_SinH									equ 40CFh
_ACosRad							equ 40D2h
_ATanRad							equ 40D5h
_ATan2Rad							equ 40D8h
_ASinRad							equ 40DBh
_ACos									equ 40DEh
_ATan									equ 40E1h
_ASin									equ 40E4h
_ATan2								equ 40E7h
_ATanH								equ 40EAh
_ASinH								equ 40EDh
_ACosH								equ 40F0h
_PtoR									equ 40F3h
_RToP									equ 40F6h
_HLTimes9							equ 40F9h
_CkOP1Cplx						equ 40FCh
_CkOP1Real						equ 40FFh
_Angle								equ 4102h
_COP1Set0							equ 4105h
_CpOP4OP3							equ 4108h
_Mov9OP2Cp						equ 410Bh
_AbsO1O2Cp						equ 410Eh
_cpop1op2							equ 4111h
_OP3ToOP4							equ 4114h
_OP1ToOP4							equ 4117h
_OP2ToOP4							equ 411Ah
_OP4ToOP2							equ 411Dh
_OP1ToOP3							equ 4123h
_OP5ToOP2							equ 4126h
_OP5ToOP6							equ 4129h
_OP5ToOP4							equ 412Ch
_OP1ToOP2							equ 412Fh
_OP6ToOP2							equ 4132h
_OP6ToOP1							equ 4135h
_OP4ToOP1							equ 4138h
_OP5ToOP1							equ 413Bh
_OP3ToOP1							equ 413Eh
_OP6ToOP5							equ 4141h
_OP4ToOP5							equ 4144h
_OP3ToOP5							equ 4147h
_OP2ToOP5							equ 414Ah
_OP2ToOP6							equ 414Dh
_OP1ToOP6							equ 4150h
_OP1ToOP5							equ 4153h
_OP2ToOP1							equ 4156h
_Mov11B								equ 4159h
_Mov10B								equ 415Ch
_Mov9B								equ 415Fh
_mov9B2								equ 4162h ;points to _mov9B
_Mov8B								equ 4165h
_Mov7B								equ 4168h
_Mov7B2								equ 416bh ;same pointer as _Mov7B
_OP2ToOP3							equ 416Eh
_OP4ToOP3							equ 4171h
_OP5ToOP3							equ 4174h
_OP4ToOP6							equ 4177h
_Mov9ToOP1						equ 417Ah
_Mov9OP1OP2						equ 417Dh
_Mov9ToOP2						equ 4180h
_MovFrOP1							equ 4183h
_OP4Set1							equ 4186h
_OP3Set1							equ 4189h
_OP2Set8							equ 418Ch
_OP2Set5							equ 418Fh
_OP2SetA							equ 4192h
_OP2Set4							equ 4195h
_OP2Set3							equ 4198h
_OP1Set1							equ 419Bh
_OP1Set4							equ 419Eh
_OP1Set3							equ 41A1h
_OP3Set2							equ 41A4h
_OP1Set2							equ 41A7h
_OP2Set2							equ 41AAh
_OP2Set1							equ 41ADh
_Zero16D							equ 41B0h
_OP5Set0							equ 41B3h
_OP4Set0							equ 41B6h
_OP3Set0							equ 41B9h
_OP2Set0							equ 41BCh
_OP1Set0							equ 41BFh
_OPSet0								equ 41C2h ;hl = location to write floating point 0
_ZeroOP1							equ 41C5h
_ZeroOP2							equ 41C8h
_ZeroOP3							equ 41CBh
_ZeroOP								equ 41CEh
_ClrLp								equ 41D1h
_ShRAcc								equ 41D4h ;move high nibble in a to low nibble
_ShLAcc								equ 41D7h ;move low nibble in a to high nibble
_ShR18								equ 41DAh ;insert a 0 nibble at high nibble of (hl), shift 9 bytes 1 nibble to right
_SHR18A								equ 41DDh ;insert low nibble in a at high nibble of (hl), shift 9 bytes 1 nibble to right
_SHR16								equ 41E0h ;insert a 0 nibble at highnibble of (hl), shift 8 bytes 1 nibble to right
_SHR14								equ 41E3h ;insert low nibble in a at high nibble of (hl), shift 7 bytes 1 nibble to right
_SHL16								equ 41E6h ;insert nibble of 0 in low nibble of (hl), shift 8 bytes (before and including (hl)) to the left 1 nibble
_SHL14								equ 41E9h ;insert low nibble of a in low nibble of (hl), shift 7 bytes (before and including (hl)) to the left 1 nibble
_SRDO1								equ 41ECh
_SHRDRND							equ 41EFh
_MANTPA								equ 41F2h ;adds the value of a to hl which points to the end of the bcd 7 bytes long
_ADDPROP							equ 41F5h ;adds the value of a to hl which points to the end of the bcd (b bytes long)
_ADDPROPLP						equ 41F8h ;adds the value of a and carry to hl which points to the end of the bcd (b bytes long)
_ADD16D 							equ 41FBh ;adds the bcd numbers at (hl-7) and (de-7)
_ADD14D								equ 41FEh ;adds the bcd numbers at (hl-6) and (de-6)
_SUB16D								equ 4201h ;subtracts bcd numbers at (hl-7) and (de-7)
_SUB14D								equ 4204h ;subtracts bcd numbers at (hl-6) and (de-6)
_OP2ExOP6							equ 4207h
_OP5ExOP6							equ 420Ah
_OP1ExOP5							equ 420Dh
_OP1ExOP6							equ 4210h
_OP2ExOP4							equ 4213h
_OP2ExOP5							equ 4216h
_OP1ExOP3							equ 4219h
_OP1ExOP4							equ 421Ch
_OP1ExOP2							equ 421Fh
_ExLp									equ 4222h
_CkOP1C0							equ 4225h
_CkOP1FP0							equ 4228h
_CkOP2FP0							equ 422Bh
_PosNo0Int						equ 422Eh
_CKPosInt							equ 4231h
_CKInt								equ 4234h
_CKOdd								equ 4237h
_CKOP1M								equ 423Ah
_GETCONOP1						equ 423Dh ;a=0 opX=57.29577951308232 (1 radian in degrees)
_GETCONOP2						equ 4240h ;a=1 opX=1.570796326794897 (90 deg = pi/2)
				  											;a=2 opX=.7853981633974483 (45 deg = pi/4)
				  											;a=3 opX=.4342944819032518 (log e)
				  											;a=4 opX=3.141592653589800 (pi)
				  											;a=5 opX=.0174532925199433 (pi/180 = 1 degree in radians)
				  											;a=6 opX=2.302585092994046 (ln 10)
_PIDIV2								equ 4243h ;not code, but a pointer to:	.db 80h,15h,70h,79h,63h,26h,79h,48h,97h
_PIDIV4								equ 4246h ;				.db 7fh,78h,53h,98h,16h,33h,97h,44h,83h
_ExpToHex							equ 424Fh
_OP1ExpToDec					equ 4252h
_ckop2pos							equ 4255h
_CkOP1Pos							equ 4258h
_ClrOP2S							equ 425Bh
_ClrOP1S							equ 425Eh
_FDIV100							equ 4261h ;op1=op1/100
_FDIV10								equ 4264h ;op1=op1/10
_DecO1Exp							equ 4267h ;decrease exponent by 1, this can go from 0 to FF
_INCO1EXP							equ 426Ah ;op1=op1*10
_INCEXP								equ 426dh ;hl points to the floating point's exponent to be multiplied by 10
_CkValidNum						equ 4270h
_GETEXP								equ 4273h ;a=op1's exponent, carry set if negative exponent, z if e0
_HTimesL							equ 4276h
_EOP1NotReal					equ 4279h
_ThetaName						equ 427Ch
_RName								equ 427Fh
_REGEQNAME						equ 4282h
_RECURNNAME						equ 4285h
_XName								equ 4288h
_YName								equ 428Bh
_TName								equ 428Eh
_REALNAME							equ 4291h
_SETesTOfps						equ 4294h ;moves the word at fps to es
_markTableDirty				equ 4297h ;looks up table variable and marks VAT entry as "dirty" or selected
_OP1MOP2EXP						equ 429Ah ;op1's exponent = op1's expoent - op2's exponent
_OP1EXPMinusE					equ 429Dh ;a=(op1+1)-e
_CHKERRBREAK					equ 42A0h
_isA2ByteTok					equ 42A3h
_GETLASTENTRY					equ 42A6h
_GETLASTENTRYPTR			equ 42A9h
_REGCLRCHNG						equ 42ACh
_RESETWINTOP					equ 42AFh ;takes into account grfsplitoverride and grfsplit flags
_SetYUp								equ 42B2h ;loads 7 to port 10... what does this do?
_SetXUp								equ 42B5h ;loads 5 to port 10...
_ISO1NONTLSTorPROG		equ 42B8h ;checks if op1 contains a list, program, group, or appvar obj name
_ISO1NONTEMPLST				equ 42BBh ;checks if op1 contains a list (why would op1+1 contain 01, or 0d for a var name?)
_IS_A_LSTorCLST				equ 42BEh ;checks if a = 1 or 0Dh
_CHK_HL_999						equ 42C1h ;returns nc if less than 999, throws invalid dim error if greater than or equal to 999
_equ_or_newequ				equ 42C4h
_errd_op1notpos				equ 42C7h
_ErrD_OP1Not_R				equ 42CAh
_ErrD_OP1NotPosInt 		equ 42CDh
_ErrD_OP1_LE_0				equ 42D0h
_ErrD_OP1_0						equ 42D3h
_FINDSYM_GET_SIZE 		equ 42D6h ;like findsym, but on output hl is the size of the variable
_STO_STATVAR					equ 42d9h
_Rcl_StatVar					equ 42DCh
_CkOP2Real						equ 42DFh
_GET_X_INDIRECT				equ 42E2h ;what ever this is, it uses the imathptrX locations
_MemChk								equ 42E5h
_CMPPRGNAMLEN1				equ 42E8h ;what do these do?
_CMPPRGNAMLEN					equ 42EBh
_FINDPROGSYM					equ 42EEh ;find the program whose name is in op1 (see chkfindsym in SDK)
_ChkFindSym						equ 42F1h
_FindSym							equ 42F4h
_InsertMem						equ 42F7h
_INSERTMEMA						equ 42FAh ;not sure how this differs from insertmem
_EnoughMem						equ 42FDh
_CMPMEMNEED						equ 4300h
_CREATEPVAR4					equ 4303h
_CREATEPVAR3					equ 4306h
_CREATEVAR3						equ 4309h
_CreateCplx						equ 430Ch
_CreateReal						equ 430Fh
_CreateTempRList			equ 4312h
_CreateRList					equ 4315h
_CREATETCLIST					equ 4318h
_CreateCList					equ 431Bh
_CreateRMat						equ 4321h
_CreateTempString			equ 4324h
_CreateStrng					equ 4327h
_Create0Equ						equ 432Ah
_CreateTempEqu				equ 432Dh
_CreateEqu						equ 4330h
_CreatePict						equ 4333h
_CreateGDB						equ 4336h
_CreateProg						equ 4339h
_CHKDEL								equ 433Ch
_CHKDELA							equ 433Fh
_ADJPARSER						equ 4342h
_ADJMATH							equ 4345h
_ADJM7								equ 4348h
_DELMEMA							equ 434Bh
_GET_FORM_NUM					equ 434Eh
_DelVar								equ 4351h
_DELVARIO							equ 4354h
_DelMem								equ 4357h
_DELVAR3D							equ 435Ah
_DELVAR3C							equ 435Dh
_DELVAR3DC						equ 4360h ;may be incorrect
_DataSizeA						equ 4369h
_DataSize							equ 436Ch
_POPMCPLXO1						equ 436Fh
_POPMCPLX							equ 4372h
_MOVCPLX							equ 4375h
_popOP5								equ 4378h
_popOP3								equ 437Bh
_popOP1								equ 437Eh
_PopRealO6						equ 4381h
_PopRealO5						equ 4384h
_PopRealO4						equ 4387h
_PopRealO3						equ 438Ah
_PopRealO2						equ 438Dh
_PopRealO1						equ 4390h
_PopReal							equ 4393h
_FPOPCPLX							equ 4396h
_FPOPREAL							equ 4399h
_FPOPFPS							equ 439Ch
_DeallocFPS						equ 439Fh
_DeallocFPS1					equ 43a2h
_AllocFPS							equ 43A5h
_AllocFPS1						equ 43A8h
_PushRealO6						equ 43ABh
_PushRealO5						equ 43AEh
_PushRealO4						equ 43B1h
_PushRealO3						equ 43B4h
_PushRealO2						equ 43B7h
_PushRealO1						equ 43BAh
_PushReal							equ 43BDh
_PushOP5							equ 43C0h
_PushOP3							equ 43C3h
_PUSHMCPLXO3					equ 43C6h
_PushOP1							equ 43C9h
_PUSHMCPLXO1					equ 43CCh
_PUSHMCPLX						equ 43CFh
_ExMCplxO1						equ 43D2h
_Exch9								equ 43D5h
_CpyTo1FPS11					equ 43D8h
_CpyTo2FPS5						equ 43DBh
_CpyTo1FPS5						equ 43DEh
_CpyTo2FPS6						equ 43E1h
_CpyTo1FPS6						equ 43E4h
_CpyTo2FPS7						equ 43E7h
_CpyTo1FPS7						equ 43EAh
_CpyTo1FPS8						equ 43EDh
_CpyTo2FPS8						equ 43F0h
_CpyTo1FPS10					equ 43F3h
_CpyTo1FPS9						equ 43F6h
_CpyTo2FPS4						equ 43F9h
_CpyTo6FPS3						equ 43FCh
_CpyTo6FPS2						equ 43FFh
_CpyTo2FPS3						equ 4402h
_CPYCTO1FPS3					equ 4405h
_CpyTo1FPS3						equ 4408h
_CPYFPS3							equ 440Bh
_CpyTo1FPS4						equ 440Eh
_CpyTo3FPS2						equ 4411h
_CpyTo5FPST						equ 4414h
_CpyTo6FPST						equ 4417h
_CpyTo4FPST						equ 441Ah
_CpyTo3FPST						equ 441Dh
_CpyTo2FPST						equ 4420h
_CpyTo1FPST						equ 4423h
_CPYFPST							equ 4426h
_CpyStack							equ 4429h
_CpyTo3FPS1						equ 442Ch
_CpyTo2FPS1						equ 442Fh
_CpyTo1FPS1						equ 4432h
_CPYFPS1							equ 4435h
_CpyTo2FPS2						equ 4438h
_CpyTo1FPS2						equ 443Bh
_CPYFPS2							equ 443Eh
_CpyO3ToFPST					equ 4441h
_CpyO2ToFPST					equ 4444h
_CpyO6ToFPST					equ 4447h
_CpyO1ToFPST					equ 444Ah
_CpyToFPST						equ 444Dh
_CpyToStack						equ 4450h
_CpyO3ToFPS1					equ 4453h
_CpyO5ToFPS1					equ 4456h
_CpyO2ToFPS1					equ 4459h
_CpyO1ToFPS1					equ 445Ch
_CpyToFPS1						equ 445Fh
_CpyO2ToFPS2					equ 4462h
_CpyO3ToFPS2					equ 4465h
_CpyO6ToFPS2					equ 4468h
_CpyO1ToFPS2					equ 446Bh
_CpyToFPS2						equ 446Eh
_CpyO5ToFPS3					equ 4471h
_CpyO2ToFPS3					equ 4474h
_CpyO1ToFPS3					equ 4477h
_CpyToFPS3						equ 447Ah
_CpyO1ToFPS6					equ 447Dh
_CpyO1ToFPS7					equ 4480h
_CpyO1ToFPS5					equ 4483h
_CpyO2ToFPS4					equ 4486h
_CpyO1ToFPS4					equ 4489h
_ErrNotEnoughMem 			equ 448Ch
_FPSMINUS9						equ 448Fh
_HLMINUS9							equ 4492h
_ErrOverflow					equ 4495h
_ErrDivBy0						equ 4498h
_ErrSingularMat				equ 449Bh
_ErrDomain						equ 449Eh
_ErrIncrement					equ 44A1h
_ErrNon_Real					equ 44A4h
_ErrSyntax						equ 44A7h
_ErrDataType					equ 44AAh
_ErrArgument					equ 44ADh
_ErrDimMismatch				equ 44B0h
_ErrDimension					equ 44B3h
_ErrUndefined					equ 44B6h
_ErrMemory						equ 44B9h
_ErrInvalid						equ 44BCh
_ErrBreak							equ 44BFh
_ErrStat							equ 44C2h
_ErrSignChange				equ 44C5h
_ErrIterations				equ 44C8h
_ErrBadGuess					equ 44CBh
_ErrTolTooSmall				equ 44CEh
_ErrStatPlot					equ 44D1h
_ErrLinkXmit					equ 44D4h
_JError								equ 44D7h
_noErrorEntry					equ 44DAh
_pushErrorHandleR			equ 44DDh
_popErrorHandleR			equ 44E0h
_strcopy							equ 44E3h
_strCat								equ 44E6h
_isInSet							equ 44E9h
_sDone								equ 44ECh
_serrort							equ 44EFh
_sNameEq							equ 44F2h
_sUnderScr						equ 44F5h
_sFAIL								equ 44F8h
_sName								equ 44FBh
_sOK									equ 44FEh
_PutMap								equ 4501h
_PutC									equ 4504h
_DispHL								equ 4507h
_PutS									equ 450Ah
_putpsb								equ 450Dh
_PutPS								equ 4510h
_wputps								equ 4513h
_putbuf								equ 4516h
_putbuf1							equ 4519h
_wputc								equ 451Ch
_wputs								equ 451Fh
_wputsEOL							equ 4522h ;displays string in HL in big font, and uses ... if too long
_wdispEOL							equ 4525h
_whomeup							equ 4528h
_setNumWindow					equ 452Bh ;based on current cursor position, sets winleft and similar (for input prompts)
_newline							equ 452Eh
_moveDown							equ 4531h
_scrollUp							equ 4534h
_shrinkWindow					equ 4537h
_moveUp								equ 453Ah
_scrollDown						equ 453Dh
_ClrLCDFull						equ 4540h
_ClrLCD								equ 4543h
_ClrScrnFull					equ 4546h
_ClrScrn							equ 4549h
_ClrTxtShd						equ 454Ch
_ClrWindow						equ 454Fh
_EraseEOL							equ 4552h
_EraseEOW							equ 4555h
_HomeUp								equ 4558h
_getcurloc						equ 455Bh
_VPutMap							equ 455Eh
_VPutS								equ 4561h
_VPutSN								equ 4564h
_vputsnG							equ 4567h
_vputsnT							equ 456Ah
_RunIndicOn						equ 456Dh
_RunIndicOff					equ 4570h
_saveCmdShadow				equ 4573h
_saveShadow						equ 4576h
_rstrShadow						equ 4579h
_rstrpartial					equ 457Ch
_rstrCurRow						equ 457Fh
_rstrUnderMenu				equ 4582h
_rstrbotrow						equ 4585h
_saveTR								equ 4588h ;save top right corner of LCD so 2nd arrow can be displayed, indicinuse flag must be set
_restoreTR						equ 458bh ;restore top right corner of LCD destroyed by an arrow. indicinuse flag must be set
_GetKeyPress					equ 458Eh
_GetTokLen						equ 4591h ;input: hl=pointer to token. output: a=lenght of string, hl=pointer to string on page 1
_GET_TOK_STRNG				equ 4594h ;input: hl=pointer to token. output: op3=string of the token, a=length of string
_GETTOKSTRING					equ 4597h ;input: DE=token. output: hl=pointer to the string on page 1
_PUTBPATBUF2					equ 459Ah
_PUTBPATBUF						equ 459Dh
_putbPAT							equ 45A0h
_putcCheckScrolL			equ 45A3h
_DispEOL							equ 45A6h
_fdispEOL							equ 45A9h
_MAKEROWCMD						equ 45ACh
_TOTOSTRP							equ 45AFh
_SETVARNAME						equ 45B2h
_DispDone							equ 45B5h
_finishoutput					equ 45B8h
_curBlink							equ 45BBh
_CursorOff						equ 45BEh
_hideCursor						equ 45C1h
_CursorOn							equ 45C4h
_showCursor						equ 45C7h
_KeyToString					equ 45CAh
_PULLDOWNCHK					equ 45CDh ;something wrong here
_MenuCatCommon				equ 45D0h
_ZIfCatalog						equ 45D3h
_ZIfMatrixMenu				equ 45D6h ;_loadCurCat
_LoadMenuNum					equ 45D9h
_LoadMenuNumL					equ 45DCh
_MenCatRet						equ 45DFh ;restores display as though a menu were just cleared (restores some flags too)
_MenuEdKey						equ 45E5h
_notalphnum						equ 45EBh
_SaveSavedFlags				equ 45EEh
_SetMenuFlags					equ 45F1h
_RstrSomeFlags				equ 45F4h
_RstrOScreen					equ 45F7h ;restores saveSScreen to the display
_SaveOScreen					equ 45FAh ;stores display in saveSScreen
_dispListName					equ 45FDh ;_SeeIfErrorCx
_AdrMRow							equ 4606h
_AdrMEle							equ 4609h
_GETMATOP1A						equ 460Ch
_GETM1TOOP1						equ 460Fh
_GETM1TOP1A						equ 4612h
_GetMToOP1						equ 4615h
_PUTTOM1A							equ 4618h
_PUTTOMA1							equ 461Bh
_PutToMat							equ 461Eh
_MAT_EL_DIV						equ 4621h
_CMATFUN							equ 4624h
_ROWECH_POLY					equ 4627h
_ROWECHELON						equ 462Ah
_AdrLEle							equ 462Dh
_GETL1TOOP1						equ 4630h
_GETL1TOP1A						equ 4633h
_GetLToOP1						equ 4636h
_GETL1TOOP2						equ 4639h
_GETL1TOP2A						equ 463Ch
_GETL2TOP1A						equ 463Fh
_PUTTOLA1							equ 4642h
_PutToL								equ 4645h
_MAXMINLST						equ 4648h
_LLOW									equ 464Bh
_LHIGH								equ 464Eh
_LSUM									equ 4651h
CUMSUM								equ 4654h
_ToFrac								equ 4657h
_SEQSET								equ 465Ah
_SEQSOLVE							equ 465Dh
_CMP_NUM_INIT					equ 4660h
_BinOPExec						equ 4663h
_EXMEAN1							equ 4666h
_SET2MVLPTRS					equ 4669h
_SETMAT1							equ 466Ch
_CREATETLIST					equ 466Fh
_UnOPExec							equ 4672h
_ThreeExec						equ 4675h
_RESTOREERRNO					equ 4678h
_FourExec							equ 467Bh
_FiveExec							equ 467Eh
_CPYTO2ES1						equ 4681h
_CPYTO6ES1						equ 4684h
_CPYTO1ES1						equ 4687h
_CPYTO3ES1						equ 468Ah
_CPYTO3ES2						equ 468Dh
_CPYTO2ES2						equ 4690h
_CPYTO1ES2						equ 4693h
_CPYTO2ES3						equ 4696h
_CPYTO1ES3						equ 4699h
_CPYTO3ES4						equ 469Ch
_CPYTO6ES3						equ 469Fh
_CPYTO2ES4						equ 46A2h
_CPYTO1ES4						equ 46A5h
_CPYTO2ES5						equ 46A8h
_CPYTO1ES5						equ 46ABh
_CPYTO4EST						equ 46AEh
_CPYTO2EST						equ 46B1h
_CPYTO1EST						equ 46B4h
_CPYTO2ES6						equ 46B7h
_CPYTO1ES6						equ 46BAh
_CPYTO2ES7						equ 46BDh
_CPYTO1ES7						equ 46C0h
_CPYTO2ES8						equ 46C3h
_CPYTO1ES8						equ 46C6h
_CPYTO1ES9						equ 46C9h
_CPYTO2ES9						equ 46CCh
_CPYTO2ES10						equ 46CFh
_CPYTO1ES10						equ 46D2h
_CPYTO2ES11						equ 46D5h
_CPYTO1ES11						equ 46D8h
_CPYTO2ES12						equ 46DBh
_CPYTO1ES12						equ 46DEh
_CPYTO2ES13						equ 46E1h
_CPYTO1ES13						equ 46E4h
_CPYTO1ES14						equ 46E7h
_CPYTO1ES16						equ 46EAh
_CPYTO1ES17						equ 46EDh
_CPYTO1ES18						equ 46F0h
_CPYTO1ES15						equ 46F3h
_CPYTO2ES15						equ 46F6h
_CPYO1TOEST						equ 46F9h
_CPYO1TOES1						equ 46FCh
_CPYO6TOES1						equ 46FFh
_CPYO6TOES3						equ 4702h
_CPYO1TOES2						equ 4705h
_CPYO2TOES2						equ 4708h
_CPYO1TOES3						equ 470Bh
_CPYO1TOES4						equ 470Dh
_CPYO1TOES5						equ 4711h
_CPYO1TOES6						equ 4714h
_CPYO1TOES7						equ 4717h
_CPYO2TOES4						equ 471Ah
_CPYO2TOES5						equ 471Dh
_CPYO2TOES6						equ 4720h
_CPYO2TOES7						equ 4723h
_CPYO2TOES8						equ 4726h
_CPYO2TOES9						equ 4729h
_CPYO1TOES8						equ 472Ch
_CPYO1TOES9						equ 472Fh
_CPYO1TOES10					equ 4732h
_CPYO1TOES11					equ 4735h
_CPYO1TOES12					equ 4738h
_CPYO1TOES13					equ 473Bh
_CPYO1TOES14					equ 473Eh
_CPYO1TOES15					equ 4741h
_EVALF3A		equ 4744h
_GetK			equ 4747h ;?
_setTitlE		equ 474Ah
_dispVarVal		equ 474Dh
_RecallEd		equ 4750h ;_setupBuffer
_createNumEditBuf	equ 4753h
;4756h
_CallCommon		equ 4759h
_CommonKeys		equ 475Ch
_Leftmore		equ 475Fh
_fDel			equ 4762h
_fClear			equ 4765h
_finsDisp		equ 4768h ;Michael says _FinsDisp02 equ 4768h (something's not right)
_FinsDisp02		equ 476Bh ;_setIndicator
_closeeditbufnor	equ 476Eh
_releaseBuffer		equ 4771h
_varnameToOP1hl		equ 4774h
_nameToOP1		equ 4777h
_numPPutAway		equ 477Ah
_numRedisp		equ 477Dh
_numError02		equ 4780h
_Load_SFont		equ 4783h
_SFont_Len		equ 4786h
_InitNumVec		equ 4789h
_SetXXOP1		equ 478Ch
_SetXXOP2		equ 478Fh
_SetXXXXOP2		equ 4792h
_UCLineS		equ 4795h
_CLine			equ 4798h
_CLineS			equ 479Bh
_XRootY			equ 479Eh
_YToX			equ 47A1h
_ZmStats		equ 47A4h
_POINT_STAT_HLP		equ 47A7h
_DRAWSPLOT		equ 47AAh
_INITNEWTRACEP		equ 47ADh
_SPLOTCOORD		equ 47B0h
_SPLOTRIGHT		equ 47B3h
_SPLOTLEFT		equ 47B6h
_CMPBOXINFO		equ 47B9h
_NEXTPLOT		equ 47BCh
_PREVPLOT		equ 47BFh
_CLRPREVPLOT		equ 47C2h
_PUT_INDEX_LST		equ 47C5h
_GET_INDEX_LST		equ 47C8h
_HEAP_SORT		equ 47CBh
_StoGDB2		equ 47CEh
_RclGDB2		equ 47D1h
_CircCmd		equ 47D4h
_GrphCirc		equ 47D7h
_Mov18B			equ 47DAh
_DarkLine		equ 47DDh
_ILine			equ 47E0h
_IPoint			equ 47E3h
_XYRNDBOTH		equ 47E5h
_XYRND			equ 47E8h
_CheckTOP		equ 47ECh
_CheckXY		equ 47EFh
_DarkPnt		equ 47F2h
_CPointS		equ 47F5h
_WTOV			equ 47F8h
_VtoWHLDE		equ 47FBh
_Xitof			equ 47FEh
_YftoI			equ 4801h
_XftoI			equ 4804h
_TraceOff		equ 4807h
_GrRedisp		equ 480Ah
_GDISPTOKEN		equ 480Dh
_GRDECODA		equ 4810h
_LABCOOR		equ 4813h
_COORDISP		equ 4816h ;draws X & Y coordinates (or R and theta if PolarGC)
_TMPEQUNOSRC		equ 4819h
_GRLABELS		equ 481Ch
_YPIXSET		equ 481Fh
_XPIXSET		equ 4822h
_COPYRNG		equ 4825h
_VALCUR			equ 4828h
_GRPUTAWAY		equ 482Bh
_RSTGFLAGS		equ 482Eh
_GRReset		equ 4831h
_XYCENT			equ 4834h
_ZOOMXYCMD		equ 4837h
_CPTDELY		equ 483Ah
_CPTDELX		equ 483Dh
_SetFuncM		equ 4840h
_SetSeqM		equ 4843h
_SetPolM		equ 4846h
_SetParM		equ 4849h
_ZmInt			equ 484Ch
_ZmDecml		equ 484Fh
_ZmPrev			equ 4852h
_ZmUsr			equ 4855h
_SETUZM			equ 4858h
_ZmFit			equ 485Bh
_ZmSquare		equ 485Eh
_ZmTrig			equ 4861h
_SetXMinMax		equ 4864h
_ZooDefault		equ 4867h
_GrBufCpy		equ 486Ah
_DRAWSPLITLINE		equ 486Dh
_RestoreDisp		equ 4870h
_FNDDB			equ 4873h
_AllEq			equ 4876h
_fndallseleq		equ 4879h
_NEXTEQ			equ 487Ch
_PREVEQ			equ 487Fh
_BLINKGCUR		equ 4882h
_NBCURSOR		equ 4885h
_STATMARK		equ 4888h
_CHKTEXTCURS		equ 488Bh
_Regraph		equ 488Eh
_DOREFFLAGS02		equ 4891h ;something wrong here
INITNSEQ		equ 4894h
_YRES			equ 4897h ;_PLOTPTXY2
_Ceiling		equ 489Ah ;ceil(OP1)
_PutXY			equ 489Dh ;draws X & Y coordinates (regardless of PolarGC)
_PUTEQUNO		equ 48A0h
_PDspGrph		equ 48A3h
_HorizCmd		equ 48A6h
_VertCmd		equ 48A9h
_LineCmd		equ 48ACh
_UnLineCmd		equ 48AFh
_PointCmd		equ 48B2h
_PixelTest		equ 48B5h
_PixelCmd  		equ 48B8h
_TanLnF			equ 48BBh
_DRAWCMD_INIT		equ 48BEh
_DrawCmd		equ 48C1h
_SHADECMD		equ 48C4h
_InvCmd			equ 48C7h
_STATSHADE		equ 48CAh
_dspmattable		equ 48CDh
_dsplsts		equ 48D0h
_closeEditBuf		equ 48D3h
_parseEditBuf		equ 48D6h
_putsm			equ 48D9h
_DspCurTbl		equ 48DCh
_DSPGRTBL		equ 48DFh
_zeroTemplate		equ 48E2h
_settblrefs		equ 48E5h
_dispTblBot		equ 48E8h
_DispTblTop		equ 48EBh
_dispTblbody		equ 48EEh
_VPUTBLANK		equ 48F1h
_TBLTRACE		equ 48F4h
_dispListNameY		equ 48F7h
_CurNameLength		equ 48FAh
_NameToBuf		equ 48FDh
_jpromptcursor		equ 4900h
_BufLeft		equ 4903h
_BufRight		equ 4906h
_bufInsert		equ 4909h
_bufQueueChar		equ 490Ch
_BufReplace		equ 490Fh
_BufDelete		equ 4912h
_BUFPEEK		equ 4915h
_BUFPEEK1		equ 4918h
_BUFPEEK2		equ 491Bh
_BUFPEEK3		equ 491Eh
_BufToBtm		equ 4921h
_setupEditEqu		equ 4924h
_BufToTop		equ 4927h
_isEditFull		equ 492Ah
_IsEditEmpty		equ 492Dh
_IsAtTop		equ 4930h
_IsAtBtm		equ 4933h
_BufClear		equ 4936h
_JcursorFirst		equ 4939h
_JcursorLast		equ 493Ch
_CursorLeft		equ 493Fh
_cursorRight		equ 4942h
_cursorUp		equ 4945h
_CursorDown		equ 4948h
_cursorToOffset		equ 494Bh
_InsDisp		equ 494Eh
_FDISPBOL1		equ 4951h
_FDISPBOL		equ 4954h
_DispEOW		equ 4957h
_DispHead		equ 495Ah
_DispTail		equ 495Dh
_PutTokString		equ 4960h
_setupEditCmd		equ 4963h
_setEmptyEditEqu	equ 4966h
_SetEmptyEditPtr	equ 4969h
_CloseEditEqu		equ 496Ch
_GetPrevTok		equ 496Fh
_getkey			equ 4972h
_canIndic		equ 4975h
_LCD_DRIVERON		equ 4978h 
_DFMIN2			equ 497Bh
_formDisp		equ 497Eh
_formMatrix		equ 4981h
_wscrollLeft		equ 4984h
_wscrollUp		equ 4987h
_wscrollDown		equ 498Ah
_wscrollRight		equ 498Dh
_FormEReal		equ 4990h
_formERealTOK		equ 4993h
_FormDCplx		equ 4996h
_FormReal		equ 4999h
_formScrollUp		equ 499Ch
_setwinabove		equ 499Fh
_disarmScroll		equ 49A2h
_OP1toEdit		equ 49A5h
_MinToEdit		equ 49A8h
_rclVarToEdit		equ 49ABh
_rclVarToEditPtR	equ 49AEh
_RCLENTRYTOEDIT		equ 49B1h
_rclToQueue		equ 49B4h ;recalls bytes at OP1 into edit buffer
_FORMTOTOK		equ 49B7h
_DISP_INTERVAL		equ 49BAh
_DisplstName		equ 49BDh
_dispSLstNameHL		equ 49C0h
_EditEqu		equ 49C3h
_closeEquField		equ 49C6h
_AutoSelect		equ 49C9h
_DISPYEOS		equ 49CCh
_dispNumEOS		equ 49CFh
_setupdispeq		equ 49D2h
_DispForward		equ 49D5h
_DispYPrompt2		equ 49D8h
_stringwidth		equ 49DBh
_dispErrorScreen	equ 49DEh ;displays top row of error screen (error message)
_POPCX			equ 49E1h ;moves 14 bytes at cxPrev to cxMain, 15th byte goes to replace appflags
_loadnoeentry		equ 49E4h
_SaveScreen		equ 49E7h
_RETSCREEN		equ 49EAh
_RetScreenErr		equ 49EDh
_CheckSplitFlag		equ 49F0h
_SolveRedisp		equ 49F3h
_SolveDisp		equ 49F6h
_itemName		equ 49F9h
_SetNorm_Vals		equ 49FCh
;49FFh
_ConvKeyToTok		equ 4A02h
;4A05h
;4A08h
_TokToKey		equ 4A0Bh
;4A0Eh
_GETVARCMD		equ 4A11h
_SendVarCmd		equ 4A14h
;4A17h
keyscnlnk		equ 4A1Ah
;4A1Dh
_DelRes			equ 4A20h
_ConvLcToLr		equ 4A23h
_RedimMat		equ 4A26h
_IncLstSize		equ 4A29h
_InsertList		equ 4A2Ch
_dellistel		equ 4A2Fh
_EditProg		equ 4A32h
_CloseProg		equ 4A35h
_ClrGraphRef		equ 4A38h
_FixTempCnt		equ 4A3Bh
_SAVEDATA		equ 4A3Eh
_RESTOREDATA		equ 4A41h
_FindAlphaUp		equ 4A44h
_FindAlphaDn		equ 4A47h
_CmpSyms		equ 4A4Ah
_CREATETEMP		equ 4A4Dh
_CleanAll		equ 4A50h
_MoveToNextSym		equ 4A53h ;input: hl=pointer to type byte of VAT entry. output: hl = pointer to next entry's type byte
_ConvLrToLc		equ 4A56h
_TblScreenDn		equ 4A59h ;something is not right here
_TblScreenUp		equ 4A5Ch
_SCREENUP		equ 4A5Fh
_ScreenUpDown		equ 4A62h
_ZifRclHandler		equ 4A65h
_zifrclkapp		equ 4A68h
_rclkeyRtn		equ 4A6Bh
_RCLKEY			equ 4A6Bh
_RCLREGEQ_CALL		equ 4A6Eh
_RCLREGEQ		equ 4A71h
_initNamePrompt		equ 4A74h
_NamePrompt2		equ 4A77h
_CATALOGCHK		equ 4A7Ah
_clrTR			equ 4A7Dh
_QUAD			equ 4A80h
_GRAPHQUAD		equ 4A83h
_BC2NOREAL		equ 4A86h
;4A89h 
_ErrNonReal		equ 4A8Ch
_WRITE_TEXT		equ 4A8Fh
_FORSEQINIT		equ 4A92h
_GRPHPARS		equ 4A95h
_PLOTPARS		equ 4A98h
_ParseInp		equ 4A9Bh
_PARSEOFF		equ 4A9Eh
_PARSESCAN		equ 4AA1h
_GETPARSE		equ 4AA4h
_SAVEPARSE		equ 4AA7h
_InitPFlgs		equ 4AAAh
_CKENDLINERR		equ 4AADh
_OP2Set60		equ 4AB0h
_GETSTATPTR		equ 4AB3h
_CMP_STATPTR		equ 4AB6h
_VARSYSADR		equ 4AB9h
_StoSysTok		equ 4ABCh
_StoAns			equ 4ABFh
_StoTheta		equ 4AC2h
_StoR			equ 4AC5h
_StoY			equ 4AC8h
_StoN			equ 4ACBh
_StoT			equ 4ACEh
_StoX			equ 4AD1h
_StoOther		equ 4AD4h
_RclAns			equ 4AD7h
_RclY			equ 4ADAh
_RclN			equ 4ADDh
_RclX			equ 4AE0h
_RclVarSym		equ 4AE3h
_RclSysTok		equ 4AE6h
_StMatEl		equ 4AE9h
_STLSTVECEL		equ 4AECh
_ConvOP1		equ 4AEFh
_Find_Parse_Formula	equ 4AF2h
_PARSE_FORMULA		equ 4AF5h
;4AF8h
;4AFBh
;4AFEh
;4B01h
;4B04h
;4B07h
;4B0Ah
_CreatePair		equ 4B0Dh
_PUSHNUM		equ 4B10h
_INCCURPCERREND		equ 4B13h
_ERREND			equ 4B16h
_COMMAERRF		equ 4B19h
_COMMAERR		equ 4B1Ch
_STEQARG2		equ 4B1Fh
_STEQARG		equ 4B22h
_INPARG			equ 4B25h
_STEQARG3		equ 4B28h
_NXTFETCH		equ 4B2Bh
_CKFETCHVAR		equ 4B2Eh
_FETCHVARA		equ 4B31h
_FETCHVAR		equ 4B34h
_CKENDLIN		equ 4B37h
_CKENDEXP		equ 4B3Ah
_CKPARSEND		equ 4B3Dh
_STOTYPEARG		equ 4B40h
_ConvDim		equ 4B43h
_ConvDim00		equ 4B46h
_AHEADEQUAL		equ 4B49h
_PARSAHEADS		equ 4B4Ch
_PARSAHEAD		equ 4B4Fh
_AnsName		equ 4B52h
_STOCMPREALS		equ 4B55h
_GETDEPTR		equ 4B58h
_PUSH2BOPER		equ 4B5Bh ;push the value in bc onto the operator stack
_POP2BOPER		equ 4B5Eh ;pop 2 bytes on the operator stack to bc
_PUSHOPER		equ 4B61h ;push the value in a onto the operator stack
_POPOPER		equ 4B64h ;pop 1 byte on the operator stack to a
_FIND_E_UNDEF		equ 4B67h
_STTMPEQ		equ 4B6Ah
_FINDEOL		equ 4B6Dh
_BRKINC			equ 4B70h
_INCFETCH		equ 4B73h
_CURFETCH		equ 4B76h
_Random			equ 4B79h
_StoRand		equ 4B7Ch
_RandInit		equ 4B7Fh
_resetStacks		equ 4B82h ;(onsp)->(errsp), (fpbase)->(fps), (opbase)->(ops)
_Factorial		equ 4B85h
_YONOFF			equ 4B88h
_EQSELUNSEL		equ 4B8Bh
_ITSOLVER		equ 4B8Eh
_GRITSOLVER		equ 4B91h
_ITSOLVERB		equ 4B94h
_ITSOLVERNB		equ 4B97h
_ExTest_INT		equ 4B9Ah
_DIST_FUN		equ 4BADh
_LogGamma		equ 4BA0h
_OneVar			equ 4BA3h
_ONEVARS_0		equ 4BA6h
_ORDSTAT		equ 4BA9h
_INITSTATANS2		equ 4BACh
_ANOVA_SPEC		equ 4BAFh
_OutputExpr		equ 4BB2h
_CentCursor		equ 4BB5h
_TEXT			equ 4BB8h
_FINISHSPEC		equ 4BBBh
_TRCYFUNC		equ 4BBEh
_RCL_SEQ_X		equ 4BC1h
_RCLSEQ2		equ 4BC4h
_GRPPutAway		equ 4BC7h
_CKVALDELX		equ 4BCAh
_CKVALDELTA		equ 4BCDh
_GrBufClr		equ 4BD0h
_GRBUFCPY_V		equ 4BD3h
_FNDSELEQ		equ 4BD6h
_CLRGRAPHXY		equ 4BD9h
_NEDXT_Y_STYLE		equ 4BDCh
_PLOTPT			equ 4BDFh
_NEWINDEP		equ 4BE2h
_Axes			equ 4BE5h
_setPenX		equ 4BE8h
_setPenY		equ 4BEBh
_setPenT		equ 4BEEh
_TAN_EQU_DISP		equ 4BF1h
_PutAns			equ 4BF4h
_DispOP1A		equ 4BF7h
_MATHTANLN		equ 4BFAh
_ENDDRAW		equ 4BFDh
_SetTblGraphDraw	equ 4C00h
;4C03h
;4C06h
;4C09h
;4C0Ch
;4C0Fh
;4C12h
;4C15h
;4C18h
;4C1Bh
;4C1Eh
;4C21h
;4C24h
;4C27h
;4C2Ah
;4C2Dh
_MemClear		equ 4C30h
_MemSet			equ 4C33h
_ReloadAppEntryVecs	equ 4C36h
_PointOn		equ 4C39h
;4C3Ch
_StrLength		equ 4C3Fh
;4C42h
_getRomPage		equ 4C45h
_FindAppUp		equ 4C48h
_FindAppDn		equ 4C4Bh
_FindApp		equ 4C4Eh
_ExecuteApp		equ 4C51h
;4C54h
;4C57h
;4C5Ah
;4C5Dh
_IBounds		equ 4C60h
_IOffset		equ 4C63h
_DrawCirc2		equ 4C66h
_CanAlphIns		equ 4C69h
cxRedisp		equ 4C6Ch
_GetBaseVer		equ 4C6Fh
_OPSet0DE		equ 4C72h ;loads a floating point 0 to location de 
_AppGetCbl		equ 4C75h
_AppGetCalc		equ 4C78h
_SaveDisp		equ 4C7Bh
_SetIgnoreKey  		equ 4C7Eh ;set 1,(iy+28h) / ret
_SetSendThisKeyBack	equ 4C81h ;set 2,(iy+28h) / ld (kbdKey),a / ret
_DisableApd		equ 4C84h
_EnableApd		equ 4C87h ;set apdable,(iy+apdflags)
;4C8Ah 
_set2IY34		equ 4C8Dh ;set 2,(iy+34) / ret
_forcecmd		equ 4C90h
_ApdSetup		equ 4C93h
_Get_NumKey		equ 4C96h
;4C99h
;4C9Ch
;4C9Fh
_ReleaseSedit		equ 4CA2h
_initsmalleditline	equ 4CA5h
_startsmalledit		equ 4CA8h
;4CABh
_SGetTokString		equ 4CAEh
_LoadPattern	 	equ 4CB1h
_SStringLength		equ 4CB4h
;?
_initsmalleditBox	equ 4CDBh
;?
_ClearRow		equ 4CEDh
;?
_AppScreenUpDown	equ 4D26h
_AppScreenUpDown1	equ 4D29h
;?
_initsmalleditlinevar	equ 4D2Fh
_initsmalleditlineop1	equ 4D32h
_initsmalleditboxvar	equ 4D35h
_initsmalleditboxop1	equ 4D38h
;?
_AppStartMouse		equ 4D47h
_AppEraseMouse		equ 4D53h
;?
_ClearRect		equ 4D5Ch
_InvertRect		equ 4D5Fh
_FillRect		equ 4D62h
_AppUpdateMouse		equ 4D65h
;?
_initcellbox		equ 4D6Eh
_drawcell		equ 4D71h
;?
_invertcell		equ 4D77h
_setcelloverride	equ 4D7Ah
_DrawRectBorder		equ 4D7Dh
_ClearCell		equ 4D80h
_covercell		equ 4D83h
_EraseRectBorder	equ 4D86h
_FillRectPattern	equ 4D89h
_DrawRectBorderClear	equ 4D8Ch
;?
_IBoundsFull		equ 4D98h
_DisplayImage		equ 4D9Bh
:?
_CPoint			equ 4DC8h
_DeleteApp		equ 4DCBh
_setmodecellflag	equ 4DD1h
_resetmodecellflag	equ 4DD4h
_ismodecellset		equ 4DD7h
_getmodecellflag	equ 4DDAh
;?
_CellBoxManager		equ 4DE0h
_startnewcell		equ 4DE3h
;?
_CellCursorHandle	equ 4DE9h
;?
_ClearCurCell		equ 4DF2h
_drawcurcell		equ 4DF5h
_invertcurcell		equ 4DF8h
_covercurcell		equ 4DFBh
_BlinkCell		equ 4DFEh
_BlinkCellNoLookUp	equ 4E01h
_BlinkCurCell		equ 4E04h
_BlinkCellToOn		equ 4E07h
_BlinkCellToOnNoLookUp	equ 4E0Ah
_BlinkCurCellToOn	equ 4E0Dh
_BlinkCellToOff		equ 4E10h
_BlinkCellToOffNoLookUp equ 4E13h
_BlinkCurCellToOff	equ 4E16h
;?
_startsmalleditreturn	equ 4E1Fh
;?
_CellkHandle		equ 4E28h
_errchkalphabox		equ 4E2Bh
;?
_eraseallcells		equ 4E3Ah
_iscurmodecellset	equ 4E3Dh
;?
_initalphabox		equ 4E43h
;?
_drawblnkcell		equ 4E4Ch
_ClearBlnkCell		equ 4E4Fh
_invertblnkcell		equ 4E52h
;?
_CreateAppVar		equ 4E6Ah
_CreateProtProg		equ 4E6Dh
;?
_ExecutePrgm		equ 4E7Ch
;?
_RecAByteIO		equ 4F03h
_SrchVLstUp		equ 4F0Fh
_SrchVLstDn		equ 4F12h
;?
_FlashWriteDisable	equ 4F3Ch
;?
_Disp			equ 4F45h
;4F48h
;4F4Bh
;4F4Eh
_GetHookByte		equ 4F51h
;4F54h
_cursorhook		equ 4F57h
;4F5Ah
;4F5Dh
_setCursorHook		equ 46F0h ;enable cursor hook
;4F63h
_SetGetKeyHook		equ 4F66h
_ClrCursorHook		equ 4F69h
;4F6Ch
_ClrRawKeyHook  equ 4F6Fh
;4F72h
;4F75h
_getkeyhook		equ 4F78h
_SetGetcscHook		equ 4F7Bh
_ClrGetKeyHook		equ 4F7Eh
;4F81h run link assist hook?
;4F84h enable link assist hook?
;4F87h disable link assist hook?
;4F8Ah 
;4F8Dh enable catalog hook
;4F90h disable catalog hook
;4F93h enable character hook
;4F96h loads 0109h to localLanguage and resets bit 1 of iy+35h
_SetTokenHook		equ 4F99h
_ClearTokenHook		equ 4F9Ch
;4F9Fh ld hl,92c6 / ld a,(92c5) / res 2,a / cp (hl) / ret
;4FA2h hl=11*(92fc)+92c9 / ld a,(hl) / and Fh / cp 2 / ret
;4FA5h
_Bit_VertSplit		equ 4FA8h
_SetcxMainHook		equ 4FABh
_ClrHomeScreenHook	equ 4FAEh
_SetWindowHook		equ 4FB1h ;enable wind/tblset/tvmsol cxMain hook
;4FB4h disable wind/tblset/tvmsol cxMain hook 
_SetGraphModeHook equ   4FB7h;enable graph cxMain hook
;4FBAh disable graph cxMain
_DelVarArc		equ 4FC6h
_DelVarNoArc		equ 4FC9h
_SetAllPlots		equ 4FCCh
_SetYeditHook     	equ 4FCFh  ;enable cxMain y= hook
;4FD2h disable cxMain y= hook
_Arc_Unarc		equ 4FD8h
_Archive      equ 4FDBh
_Unarchive    equ 4FDEh
;4FDEh takes ROM page in a as input
_SetFontHook		equ 4FE4h
_ClrFontHook		equ 4FE7h
_SetRegraphHook		equ 4FEAh
;4FEDh disable graphing hook
;4FF0h
_SetTraceHook		equ 4FF3h
;4FF6h
;4FF9h
;4FFCh
;4FFFh
_JForceGraphNoKey	equ 5002h
_JForceGraphKey		equ 5005h
_PowerOff		equ 5008h
_GetKeyRetOff		equ 500Bh ;same as getkey, only returns kOff if 2nd+on is pressed 
;500Eh
;5011h
_ArcChk			equ 5014h
_FlashToRam		equ 5017h
_LoadDEIndPaged		equ 501Ah
_LoadCIndPaged		equ 501Dh
_SetupPagedPtr		equ 5020h
_PagedGet		equ 5023h
_SetParserHook		equ 5026h
_ClearParserHook	equ 5029h
_SetAppChangeHook 	equ 502Ch
_ClearAppChangeHook	equ 502Fh
;5032h enable graphics hook
;5035h disable graphics hook
;5038h
;503Bh
;503Eh
;5041h
;5044h enable catalog hook
;5047h disable catalog hook
;504Ah enable mode cxMain hook
;504Dh disable mode cxMain hook
;5050h
;5053h
;5056h
;5059h
;505Ch
;505Fh
;5062h
_dispMenuTitle		equ 5065h
;506Bh enable putaway hook
;506Eh disable putaway hook
_BufCpy			equ 5071h
_BufClr			equ 5074h
;5077h
;507Ah
;507Dh
;5080h
_SetMenuHook		equ 5083h
_ClearMenuHook		equ 5086h
_getBCOffsetIX		equ 5089h ;ld a,(ix+bc); ix and bc preserved
;508Ch
_ForceFullScreen	equ 508Fh
_FindAppNumPages	equ 509Bh
_FormBase		equ 50AAh
;?
_Chk_Batt_Low		equ 50B3h
;?
_GetAppBasePage		equ 50BCh ;input: a=one of an app's pages. output: a=app's first page
_SetExSpeed		equ 50BFh
;?
_SetLinkHook		equ 50CEh
;50D1h
_TwoVarSet		equ 50D4h
;?
_GetSysInfo		equ 50DDh
;?
_NZIf83Plus		equ 50E0h
;?
_InvertTextInsMode	equ 5122h
;?
_ClrWindowAndFlags	equ 517Fh
;?
_IsOP1ResID		equ 51B8h
;?
_ChkHelpHookVer		equ 51CAh
_Disp32			equ 51CDh
;?
_LoadA5			equ 5242h
;?
_EnableUSBHook		equ 528Ah
_DisableUSBHook		equ 528Dh

;Page 1Fh ROM Calls
;--------------------------------
bootbtf			equ 8000h
;8000h
;8003h
;8006h
;8009h
;800Ch
;800Fh
;8012h
;8015h
_MD5Final		equ 8018h
_RSAValidate		equ 801Bh
_cmpStr			equ 801Eh ;BigNumCompare
_WriteAByte		equ 8021h
_EraseFlash		equ 8024h
_ZeroToCertificate	equ 802Ah
_GetCertificateEnd	equ 802Dh
_Mult8By8		equ 8042h
_Mult16By8		equ 8045h
_Div16By8		equ 8048h
_Div16By16		equ 804Bh
_LoadAIndPaged		equ 8051h
_GetCertificateStart	equ 8057h
_GetFieldSize		equ 805Ah
_EraseCertificateSector equ 8060h
_getSerial		equ 807Eh ;GetCalcSerial
;8081h ;definitely a routine
_EraseFlashPage		equ 8084h
_WriteFlashUnsafe	equ 8087h
_dispBootVer		equ 808Ah
_MD5Init		equ 808Dh
_MD5Update		equ 8090h
;8093h ;definitely a routine
;8096h ;definitely a routine
;8099h ;definitely a routine
_CheckOSValidated	equ 809Ch
_SetupAppPubKey		equ 809Fh
_SigModR		equ 80A2h
_TransformHash		equ 80A5h
;80A8h ;definitely a routine
;80ABh ;definitely a routine
;80AEh ;can't figure it out, deals with certificate page
_Div32By16		equ 80B1h
;80B4h ;can't figure it out, deals with flash a lot
_getBootVer		equ 80B7h
_getHardwareVersion	equ 80BAh
_xorA			equ 80BDh ;xor a
_bignumpowermod17	equ 80C0h
_WriteFlash		equ 80C9h
_SetFlashLowerBound	equ 80CFh

;RAM Equates
;--------------------------------
ramStart		equ 8000h
appData			equ 8000h
ramCode			equ 8100h
ramCodeEnd		equ 822Fh
baseAppBrTab		equ 8230h ;table of base pages for apps on page <20
bootTemp		equ 8251h
appSearchPage		equ 82A3h
tempSwapArea		equ 82A5h
appID			equ 838Dh
ramReturnData		equ 83EDh
arcInfo			equ 83EEh
savedArcInfo		equ 8406h
appInfo			equ 8432h
appBank_jump		equ 843Ch
appPage			equ 843Eh
kbdScanCode		equ 843Fh
kbdKey			equ 8844h
kbdGetKy		equ 8445h
keyExtend		equ 8446h
EXTECHO			equ keyExtend
contrast		equ 8447h
apdSubTimer		equ 8448h
apdTimer		equ 8449h
curTime			equ 844Ah
curRow			equ 844Bh
curCol			equ 844Ch
curOffset		equ 844Dh
curUnder		equ 844Eh
curY			equ 844Fh
curType			equ 8450h
curXRow			equ 8451h
prevDData		equ 8452h
lFont_record		equ 845Ah
sFont_record		equ 8462h
tokVarPtr		equ 846Ah
tokLen			equ 846Ch
indicMem		equ 846Eh ;eight bytes used by _saveTR and _restoreTR to store image in top right corner
indicCounter		equ 8476h
indicBusy		equ 8477h
OP1			equ 8478h
OP1M			equ 847Ah
OP2			equ 8483h
OP2M			equ 8485h
OP2EXT			equ 848Ch
OP3			equ 848Eh
OP3M			equ 8490h
OP4			equ 8499h
OP4M			equ 849Bh
OP5			equ 84A4h
OP5M			equ 84A6h
OP6			equ 84AFh
OP6M			equ 84B1h
OP6EXT			equ 84B8h
progToEdit		equ 84BFh
nameBuff		equ 84C7h
equ_edit_save		equ 84D2h
iMathPtr1		equ 84D3h
iMathPtr2		equ 84D5h
iMathPtr3		equ 84D7h
iMathPtr4		equ 84D9h
iMathPtr5		equ 84DBh
chkDelPtr1		equ 84DDh
chkDelPtr2		equ 84DFh
insDelPtr		equ 84E1h
upDownPtr		equ 84E3h
fOutDat			equ 84E5h
asm_data_ptr1		equ 84EBh
asm_data_ptr2		equ 84EDh
asm_sym_ptr1		equ 84EFh
asm_sym_ptr2		equ 84F1h
asm_ram			equ 84F3h
asm_ind_call		equ 8507h
textShadow		equ 8508h
textShadCur		equ 8588h
textShadTop		equ 858Ah
textShadAlph		equ 858Bh
textShadIns		equ 858Ch
cxMain			equ 858Dh
cxPPutAway		equ 858Fh
cxPutAway		equ 8591h
cxErrorEP		equ 8595h
cxSizeWind		equ 8597h
cxPage			equ 8599h
cxCurApp		equ 859Ah
cxPrev			equ 859Bh ;12 bytes are shadows of cxMain through cxCurApp and appFlags
monQH			equ 85AAh
monQT			equ 85ABh
monQueue		equ 85ACh
onSP			equ 85BCh
promptRow		equ 85C0h
promptCol		equ 85C1h
promptIns		equ 85C2h
promptShift		equ 85C3h
promptRet		equ 85C4h
promptValid		equ 85C6h
promptTop		equ 85C8h
promptCursor		equ 85CAh
promptTail		equ 85CCh
promptBtm		equ 85CEh
varType			equ 85D0h
varCurrent		equ 85D1h
varClass		equ 85D9h
CatalogCurrent		equ 85DAh ;word at this location starting with 6007h corresponds to what is highlighted in catalog
menuActive		equ 85DCh
menuAppDepth		equ 85DDh
MenuCurrent		equ 85DEh
ProgCurrent		equ 85E8h
userMenuSA		equ 85FEh
ioPrompt		equ 865Fh
dImageWidth		equ 8660h
ioFlag			equ 8670h
sndRecState		equ 8672h
ioErrState		equ 8673h
header			equ 8674h
ioData			equ 867Dh
ioNewData		equ 8689h
bakHeader		equ 868Bh
penCol			equ 86D7h
penRow			equ 86D8h
rclQueue		equ 86D9h
rclQueueEnd		equ 86DBh
errNo			equ 86DDh
errSP			equ 86DEh
errOffset		equ 86E0h
saveSScreen		equ 86ECh
bstCounter		equ 89EEh
flags			equ 89F0h
appFlagsAddr		equ 89FDh
statVars		equ 8A3Ah
anovaf_vars		equ 8C17h
infVars			equ 8C4Dh
curGStyle		equ 8D17h
curGY			equ 8D18h
curGX			equ 8D19h
curGY2			equ 8D1Ah
curGX2			equ 8D1Bh
freeSaveY		equ 8D1Ch
freeSaveX		equ 8D1Dh
XOffset			equ 8DA1h
YOffset			equ 8DA2h
lcdTallP		equ 8DA3h
pixWideP		equ 8DA4h
pixWide_m_1		equ 8DA5h
pixWide_m_2		equ 8DA6h
lastEntryPTR		equ 8DA7h ;pointer to the next available byte in the entry stack
lastEntryStk		equ 8DA9h ;the start of entry stack (note last entry is not in the stack, it is in the program '#'.)  This is a stack of strings.  first 2 bytes are length, followed by string. 2nd from last entry is first in this stack.
numLastEntries		equ 8E29h ;number of entries you can back-track through minus one
currLastEntry		equ 8E2Ah ;counter used by OS to keep tract of which entry was just displayed by pressing 2nd+enter
curInc			equ 8E67h 
uXmin			equ 8E7Eh
uXmax			equ 8E87h
uXscl			equ 8E90h
uYmin			equ 8E99h
uYmax			equ 8EA2h
uYscl			equ 8EABh
uThetMin		equ 8EB4h
uThetMax		equ 8EBDh
uThetStep		equ 8EC6h
uTmin			equ 8ECFh
uTmax			equ 8ED8h
uTStep			equ 8EE1h
uPlotStart		equ 8EEAh
unMax			equ 8EF3h
uu0			equ 8EFCh
uv0			equ 8F05h
unMin			equ 8F0Eh
uu02			equ 8F17h
uv02			equ 8F20h
uw0			equ 8F29h
uPlotStep		equ 8F32h
uXres			equ 8F3Bh
uw02			equ 8F44h
Xmin			equ 8F50h
Xmax			equ 8F59h
Xscl			equ 8F62h
Ymin			equ 8F6Bh
Ymax			equ 8F74h
Yscl			equ 8F7Dh
ThetaMin		equ 8F86h
ThetaMax		equ 8F8Fh
ThetaStep		equ 8F98h
TminPar			equ 8FA1h
TmaxPar			equ 8FAAh
Tstep			equ 8FB3h
PlotStart		equ 8FBCh
nMax			equ 8FC5h
u0			equ 8FCEh
v0			equ 8FD7h
nMin			equ 8FE0h
u02			equ 8FE9h
v02			equ 8FF2h
w0			equ 8FFBh
PlotStep		equ 9004h
XresO			equ 900Dh
w02			equ 9016h
un1			equ 901Fh
un2			equ 9028h
vn1			equ 9031h
vn2			equ 903Ah
wn1			equ 9043h
wn2			equ 904Ch
fin_N			equ 9055h
fin_I			equ 905Eh
fin_PV			equ 9067h
fin_PMT			equ 9070h
fin_FV			equ 9079h
fin_PY			equ 9082h
fin_CY			equ 908Bh
cal_N			equ 9094h
cal_I			equ 909Dh
cal_PV			equ 90A6h
cal_PMT			equ 90AFh
cal_FV			equ 90B8h
cal_PY			equ 90C1h
smallEditRAM		equ 90D3h
XFact			equ 913Fh
YFact			equ 9148h
Xres_int		equ 9151h
deltaX			equ 9152h
deltaY			equ 915Bh
shortX			equ 9164h
shortY			equ 916Dh
lower			equ 9176h
upper			equ 917Fh
XOutSym			equ 918Ch
XOutDat			equ 918Eh
YOutSym			equ 9190h
YOutDat			equ 9192h
inputSym		equ 9194h
inputDat		equ 9196h
prevData		equ 9198h
TblMin			equ 92B3h
TblStep			equ 92BCh
ES			equ 9302h ;bottom of the es
EST			equ 9305h ;current height of the es
plotSScreen		equ 9340h
seed1			equ 9640h
seed2			equ 9649h
cmdShadow		equ 966Eh
cmdShadCur		equ 96EEh
cmdShadAlph		equ 96F0h
cmdShadIns		equ 96F1h
cmdCursor		equ 96F2h
editTop			equ 96F4h
editCursor		equ 96F6h
editTail		equ 96F8h
editBtm			equ 96FAh
editSym			equ 9706h
editDat			equ 9708h
y1LineType		equ 9776h ;these bytes define the line type for functions which are graphed
y2LineType		equ 9777h
y3LineType		equ 9778h
y4LineType		equ 9779h
y5LineType		equ 977Ah
y6LineType		equ 977Bh
y7LineType		equ 977Ch
y8LineType		equ 977Dh
y9LineType		equ 977Eh
y0LineType		equ 977Fh
para1LineType		equ 9780h
para2LineType		equ 9781h
para3LineType		equ 9782h
para4LineType		equ 9783h
para5LineType		equ 9784h
para6LineType		equ 9785h
polar1LineType		equ 9786h
polar2LineType		equ 9787h
polar3LineType		equ 9788h
polar4LineType		equ 9789h
polar5LineType		equ 978Ah
polar6LineType		equ 978Bh
secULineType		equ 978Ch
secVLineType		equ 978Dh
secWLineType		equ 978Eh
winTop			equ 97A5h
winBtm			equ 97A6h
winLeftEdge		equ 97A7h
winLeft			equ 97A8h
winAbove		equ 97AAh
winRow			equ 97ACh
winCol			equ 97AEh
fmtDigits		equ 97B0h
fmtString		equ 97B1h
fmtConv			equ 97F2h
fmtLeft			equ 9804h
fmtIndex		equ 9806h
fmtMatSym		equ 9808h
fmtMatMem		equ 980Ah
EQS			equ 980Ch
tSymPtr1		equ 9818h
tSymPtr2		equ 981Ah
chkDelPtr3		equ 981Ch
chkDelPtr4		equ 981Eh
tempMem			equ 9820h
fpBase			equ 9822h
FPS			equ 9824h
OPBase			equ 9826h
OPS			equ 9828h
pTempCnt		equ 982Ah
cleanTmp		equ 982Ch
pTemp                   equ 982Eh ;end of symbol table
progPtr			equ 9830h
newDataPtr		equ 9832h
pagedCount		equ 9834h
pagedPN			equ 9835h
pagedGetPtr		equ 9836h
pagedPutPtr		equ 9838h
pagedBuf		equ 983Ah
appErr1			equ 984Dh
appErr2			equ 985Ah
flashByte1		equ 9867h
flashByte2		equ 9868h
freeArcBlock		equ 9869h
arcPage			equ 986Bh
arcPtr			equ 986Ch
appRawKeyHandle		equ 9870h
appBackUpScreen		equ 9872h
customHeight		equ 9B72h
localLanguage		equ 9B73h
;9B78h some hook
cursorHookPtr		equ 9B7Ch
;9B80h some hook
rawKeyHookPtr		equ 9B84h
rawKeyHookPtrPage	equ 9B86h ;1 byte - page hook is on
getKeyHookPtr		equ 9B88h
cxMainHookPtr		equ 9B8Ch
;9B90h cxMain Wind/TblSet/TVMSol hook
;9B94h cxMain Graph hook
;9B98h cxMain y= hook
fontHookPtr		equ 9B9Ch
;9BA0h graphing hook
;9BA4h graphics hook
;9BA8h tracer hook
parserHookPtr EQU 9BACh
;9BB0h app change hook
;9BB4h catalog hook
;9BB8h cxMain mode hook
;9BBCh putaway hook
;9BC0h cxMain stat hook
;9BC4h catalog? hook ; are there two?
tokenHookPtr		equ 9BC8h
;9BCCh character hook
restartClr		equ 9BD0h ;link hook?
baseAppBrTab2		equ 9C06h ;table of base pages for apps on page >=20; there are two because the SE added new pages.
localTokStr		equ 9D65h
keyForStr		equ 9D76h
keyToStrRam		equ 9D77h
sedMonSp		equ 9D88h
bpSave			equ 9D8Ah
userMem			equ 9D95h
symTable		equ 0FE66h

;System Flags
;----------------------------------------------------------------------
ioDelFlag		equ 0h
inDelete		equ 0		;1 = DELETE SCREEN 

trigFlags		equ 0h	;Trigonometry mode settings
trigDeg			equ 2		;1=degrees, 0=radians

kbdFlags		equ 0h	;Keyboard scan
kbdSCR			equ 3		;1=scan code ready
kbdKeyPress		equ 4		;1=key has been pressed

doneFlags		equ 0h	;display "Done"
donePrgm		equ 5		;1=display "Done" after prgm
;----------------------------------------------------------------------
editFlags		equ 1h
editOpen		equ 2		;1=edit buffer is open

ansFlags		equ 1
AnsScroll		equ 3		;1=answer can scroll, seems must be reset in order to move about edit buffer

monFlags		equ 1h	 ;monitor flags
monAbandon		equ 4		;1=don't start any long process in put away (#715)
;----------------------------------------------------------------------
plotFlags		equ 2h	;plot generation flags
plotLoc 		equ 1		;0=bkup & display, 1=display only
plotDisp		equ 2		;1=plot is in display, 0=text in display

grfModeFlags	EQU 2h	;graph mode settings
grfFuncM		equ 4		;1=function graph
grfPolarM		equ 5		;1=polar graph
grfParamM		equ 6		;1=parametric graph
grfRecurM		equ 7		;1=RECURSION graph
;----------------------------------------------------------------------
graphFlags		equ 3h
graphDraw		equ 0		;0=graph is valid, 1=redraw graph(dirty)
graphCursor		equ 2
;----------------------------------------------------------------------
grfDBFlags		equ 4h
grfDot			equ 0		;0=line, 1=dot
grfSimul		equ 1		;0=sequential, 1=simultaneous
grfGrid 		equ 2		;0=no grid, 1=grid
grfPolar		equ 3		;0=rectangular, 1=polar coordinates
grfNoCoord		equ 4		;0=display coordinates, 1=off
grfNoAxis		equ 5		;0=axis, 1=no axis
grfLabel		equ 6		;0=off, 1=axis label
;----------------------------------------------------------------------
textFlags		equ 5h	;Text output flags
textEraseBelow		equ 1		;1=erase line below small char
textScrolled		equ 2		;1=screen scrolled
textInverse		EQU 3		;1=display inverse bit-map
textInsMode		EQU 4		;0=overstrike, 1=insert mode
;----------------------------------------------------------------------
ParsFlag2		equ 7h	;PARSER flags
numOP1			equ 0		;1=RESULT IN OP1, 0=NO RESULT
;----------------------------------------------------------------------
newDispF		equ 8h	;Derivative mode flags
preClrForMode		equ 0		;1=HELP BLINK ON MODE SCREEN

apdFlags		equ 8h	;Automatic power-down
apdAble 		equ 2		;1=APD enabled
apdRunning		equ 3		;1=APD clock running
;----------------------------------------------------------------------
web_err_mask		equ 60h
;----------------------------------------------------------------------
onFlags 		equ 9h	;on key flags
onRunning		equ 3		;1=calculator is running
onInterrupt		equ 4		;1=on key interrupt request

statFlags		equ 9h	;statistics flags
statsValid		equ 6		;1=stats are valid
;----------------------------------------------------------------------
fmtFlags		equ 0Ah	;numeric format flags
fmtExponent		equ 0	 	;1=show exponent, 0=no exponent
fmtEng			equ 1	 	;1=engineering notion, 0=scientific
fmtHex			equ 2	 	;1=hexadecimal
fmtOct			equ 3	 	;1=octal
fmtBin			equ 4	 	;1=binary

numMode			equ 0Ah
fmtReal			equ 5
fmtRect			equ 6
fmtPolar		equ 7

realMode		equ 5
rectMode		equ 6
polarMode		equ 7
;					;if Hex and Oct both = 1
;					; then Bin=0 means >Frac
;					; Bin=1 means >DMS
fmtBaseMask		equ  00011100b	; mask to base flags
fmtBaseShift		equ  2		; offset to base flags
;
;       CHECK IF THESE ARE USED BY NUMFORM,
;
;               	equ  6
;               	equ  7
;----------------------------------------------------------------------
fmtOverride		equ 0Bh	;copy of fmtFlags with conversion override
;----------------------------------------------------------------------
fmtEditFlags		equ 0Ch	;numeric editing flags
fmtEdit			equ 0		;1=format number for editing

curFlags		equ 0Ch	;Cursor
curAble 		equ 2		;1=cursor flash is enabled
curOn			equ 3		;1=cursor is showing
curLock 		equ 4		;1=cursor is locked off

cmdFlags		equ 0Ch	;command editor flags
cmdVirgin		equ 5		;1=nothing has been typed in cmd bfr
;----------------------------------------------------------------------
appFlags		equ 0Dh	;application flags
appWantIntrpt		equ 0		;1=want ON key interrupts
appTextSave		equ 1		;1=save characters in textShadow
appAutoScroll		equ 2		;1=auto-scroll text on last line
appMenus		equ 3		;1=process keys that bring up menus, 0=check Lock menu flag
appLockMenus		equ 4		;1=ignore menu keys, 0=switch to home screen and bring up menu
appCurGraphic		equ 5		;1=graphic cursor
appCurWord		equ 6		;1=text cursor covers entire word
appExit 		equ 7		;1=application handles [EXIT] key itself

appWantIntrptF		equ 1<<appWantIntrpt
appTextSaveF		equ 1<<appTextSave
appAutoScrollF		equ 1<<appAutoScroll
appMenusF		equ 1<<appMenus
appLockMenusF		equ 1<<appLockMenus
appCurGraphicF		equ 1<<appCurGraphic
appCurWordF		equ 1<<appCurWord
appExitF		equ 1<<appExit
;----------------------------------------------------------------------
seqFlags		equ 0Fh	;Sequential Graph flags
webMode			equ 0		;0 = NORMAL SEQ MODE, 1 = WEB MODE
webVert			equ 1
sequv			equ 2		;U vs V
seqvw			equ 3		;V vs W
sequw			equ 4		;U vs W
;----------------------------------------------------------------------
promptFlags		equ 11h	;prompt line flags
promptEdit		equ 0		;1=editing in prompt buffer
;----------------------------------------------------------------------
indicFlags		equ 12h	;Indicator flags
indicRun		equ 0		;1=run indicator ON
indicInUse		equ 1		;indicator save area in use=1, free=0 ;resetting will disable 2nd while in _getkey
indicOnly		equ 2		;interrupt handler only checks run indicator

shiftFlags		equ 12h	;[2nd] and [ALPHA] flags
shift2nd		equ 3		;1=[2nd] has been pressed
shiftAlpha		equ 4		;1=[ALPHA] has been pressed
shiftLwrAlph		equ 5		;1=lower case, 0=upper case
shiftALock		equ 6		;1=alpha lock has been pressed
shiftKeepAlph		equ 7		;1=cannot cancel alpha shift
;----------------------------------------------------------------------
tblFlags		equ 13h	;table flags.
autoFill		equ 4		;1=prompt, 0=fillAuto
autoCalc		equ 5		;1=prompt, 0=CalcAuto
reTable			equ 6		;0=table is ok, 1=must recompute table.
;----------------------------------------------------------------------
sGrFlags		equ 14h
grfSplit		equ 0		;1=Split Graph, 0=Normal
vertSplit		equ 1		;1=Vertical (left-right) Split
grfSChanged		equ 2		;1=Graph just changed Split <-> normal
grfSplitOverride	equ 3		;1 = ignore graph split flag if set
write_on_graph		equ 4		;1 = TEXT OR EQU WRITING TO GRAPH SCREEN
g_style_active		equ 5		;1 = GRAPH STYLES ARE ENABLED, USE THEM
cmp_mod_box		equ 6		;1 = DOING MOD BOX PLOT COMPUTATION
textWrite		equ 7
;----------------------------------------------------------------------
newIndicFlags		equ 15h
extraIndic		equ 0
saIndic			equ 1
;----------------------------------------------------------------------
smartFlags		equ 17h
smarter_mask		equ 3
smarter_test		equ 1
smartGraph		equ 0
smartGraph_inv		equ 1
;----------------------------------------------------------------------
varTypeMask		equ 1Fh	;is this a flag byte?
varGraphRef		equ 6
;----------------------------------------------------------------------
asm_Flag1		equ 21h	;ASM CODING
asm_Flag2		equ 22h	;ASM CODING
asm_Flag3		equ 23h	;ASM CODING
;----------------------------------------------------------------------
getSendFlg		equ 24h
comFailed		equ 1		;1 = Get/Send Communication Failed

appLwrCaseFlag		equ 24h
lwrCaseActive		equ 3
;----------------------------------------------------------------------
groupFlags		equ 26h
inGroup			equ 1		;1 = IN GROUP CONTEXT
;----------------------------------------------------------------------
APIFlg			equ 28h
appAllowContext		equ 0           ;App wants context changes to happen
;1 set to ignore a key after returning from rawkeyhook
;2 set to 
;3
;4
;5
;6
;7 set if you wish _getkey to return koff instead of turning the calc off, see _GetKeyRetOff 
;----------------------------------------------------------------------
apiFlg3			equ 2Ah
;----------------------------------------------------------------------
apiFlg4			equ 2Bh
fullScrnDraw		equ 2		;DRAW INTO LAST ROW/COL OF SCREEN
;----------------------------------------------------------------------
xapFlag0		equ 2Eh	;external app flags
xapFlag1		equ 2Fh
xapFlag2		equ 30h
xapFlag3		equ 31h
;----------------------------------------------------------------------
fontFlags		equ 32h
fracDrawLFont		equ 2
fracTallLFont		equ 3
customFont		equ 7
;----------------------------------------------------------------------
hookflags1		equ 33h
;----------------------------------------------------------------------
hookflags2		equ 34h
rawkeyflag		equ 5
;----------------------------------------------------------------------
hookflags3		equ 35h
;----------------------------------------------------------------------
hookflags4		equ 36h
;----------------------------------------------------------------------
plotFlag3		equ 3Ch  
bufferOnly		equ 0
useFastCirc		equ 4

;Character Font Equates  
;-------------------------------
LrecurN			equ 001h
LrecurU			equ 002h
LrecurV			equ 003h
LrecurW			equ 004h
Lconvert		equ 005h
LsqUp			equ 006h
LsqDown			equ 007h
Lintegral		equ 008h
Lcross			equ 009h
LboxIcon 		equ 00Ah
LcrossIcon 		equ 00Bh
LdotIcon 		equ 00Ch
LsubT   		equ 00Dh ;small capital T for parametric mode.
LcubeR  		equ 00Eh ;slightly different 3 for cubed root.
LhexF			equ 00Fh
Lroot			equ 010h
Linverse		equ 011h
Lsquare			equ 012h
Langle			equ 013h
Ldegree			equ 014h
Lradian			equ 015h
Ltranspose		equ 016h
LLE			equ 017h
LNE			equ 018h
LGE			equ 019h
Lneg			equ 01Ah
Lexponent		equ 01Bh
Lstore			equ 01Ch
Lten			equ 01Dh
LupArrow		equ 01Eh
LdownArrow		equ 01Fh
Lspace			equ 020h
Lexclam			equ 021h
Lquote			equ 022h
Lpound			equ 023h
Lfourth			equ 024h
Lpercent		equ 025h
Lampersand		equ 026h
Lapostrophe		equ 027h
LlParen			equ 028h
LrParen			equ 029h
Lasterisk		equ 02Ah
LplusSign		equ 02Bh
Lcomma			equ 02Ch
Ldash			equ 02Dh
Lperiod			equ 02Eh
Lslash			equ 02Fh
L0			equ 030h
L1			equ 031h
L2			equ 032h
L3			equ 033h
L4			equ 034h
L5			equ 035h
L6			equ 036h
L7			equ 037h
L8			equ 038h
L9			equ 039h
Lcolon			equ 03Ah
Lsemicolon		equ 03Bh
LLT			equ 03Ch
LEQ			equ 03Dh
LGT			equ 03Eh
Lquestion		equ 03Fh
LatSign			equ 040h
LcapA			equ 041h
LcapB			equ 042h
LcapC			equ 043h
LcapD			equ 044h
LcapE			equ 045h
LcapF			equ 046h
LcapG			equ 047h
LcapH			equ 048h
LcapI			equ 049h
LcapJ			equ 04Ah
LcapK			equ 04Bh
LcapL			equ 04Ch
LcapM			equ 04Dh
LcapN			equ 04Eh
LcapO			equ 04Fh
LcapP			equ 050h
LcapQ			equ 051h
LcapR			equ 052h
LcapS			equ 053h
LcapT			equ 054h
LcapU			equ 055h
LcapV			equ 056h
LcapW			equ 057h
LcapX			equ 058h
LcapY			equ 059h
LcapZ			equ 05Ah
Ltheta			equ 05Bh
Lbackslash		equ 05Ch
LrBrack			equ 05Dh
Lcaret			equ 05Eh
Lunderscore		equ 05Fh
Lbackquote		equ 060h
La			equ 061h
Lb			equ 062h
Lc			equ 063h
Ld			equ 064h
Le			equ 065h
Lf			equ 066h
Lg			equ 067h
Lh			equ 068h
Li			equ 069h
Lj			equ 06Ah
Lk			equ 06Bh
Ll			equ 06Ch
Lm			equ 06Dh
Ln			equ 06Eh
Lo			equ 06Fh
Lp			equ 070h
Lq			equ 071h
Lr			equ 072h
Ls			equ 073h
Lt			equ 074h
Lu			equ 075h
Lv			equ 076h
Lw			equ 077h
Lx			equ 078h
Ly			equ 079h
Lz			equ 07Ah
LlBrace			equ 07Bh
Lbar			equ 07Ch
LrBrace			equ 07Dh
Ltilde			equ 07Eh
LinvEQ			equ 07Fh
Lsub0			equ 080h
Lsub1			equ 081h
Lsub2			equ 082h
Lsub3			equ 083h
Lsub4			equ 084h
Lsub5			equ 085h
Lsub6			equ 086h
Lsub7			equ 087h
Lsub8			equ 088h
Lsub9			equ 089h
LcapAAcute		equ 08Ah
LcapAGrave		equ 08Bh
LcapACaret		equ 08Ch
LcapADier		equ 08Dh
LaAcute			equ 08Eh
LaGrave			equ 08Fh
LaCaret			equ 090h
LaDier			equ 091h
LcapEAcute		equ 092h
LcapEGrave		equ 093h
LcapECaret		equ 094h
LcapEDier		equ 095h
LeAcute			equ 096h
LeGrave			equ 097h
LeCaret			equ 098h
LeDier			equ 099h
LcapIAcute		equ 09Ah
LcapIGrave		equ 09Bh
LcapICaret		equ 09Ch
LcapIDier		equ 09Dh
LiAcute			equ 09Eh
LiGrave			equ 09Fh
LiCaret			equ 0A0h
LiDier			equ 0A1h
LcapOAcute		equ 0A2h
LcapOGrave		equ 0A3h
LcapOCaret		equ 0A4h
LcapODier		equ 0A5h
LoAcute			equ 0A6h
LoGrave			equ 0A7h
LoCaret			equ 0A8h
LoDier			equ 0A9h
LcapUAcute		equ 0AAh
LcapUGrave		equ 0ABh
LcapUCaret		equ 0ACh
LcapUDier		equ 0ADh
LuAcute			equ 0AEh
LuGrave			equ 0AFh
LuCaret			equ 0B0h
LuDier			equ 0B1h
LcapCCed		equ 0B2h
LcCed			equ 0B3h
LcapNTilde		equ 0B4h
LnTilde			equ 0B5h
Laccent			equ 0B6h
Lgrave			equ 0B7h
Ldieresis		equ 0B8h
LquesDown		equ 0B9h
LexclamDown		equ 0BAh
Lalpha			equ 0BBh
Lbeta			equ 0BCh
Lgamma			equ 0BDh
LcapDelta		equ 0BEh
Ldelta			equ 0BFh
Lepsilon		equ 0C0h
LlBrack 		equ 0C1h
Llambda			equ 0C2h
Lmu			equ 0C3h
Lpi			equ 0C4h
Lrho			equ 0C5h
LcapSigma		equ 0C6h
Lsigma			equ 0C7h
Ltau			equ 0C8h
Lphi			equ 0C9h
LcapOmega		equ 0CAh
LxMean			equ 0CBh
LyMean			equ 0CCh
LsupX			equ 0CDh
Lellipsis		equ 0CEh
Lleft			equ 0CFh
Lblock			equ 0D0h
Lper			equ 0D1h
Lhyphen			equ 0D2h
Larea			equ 0D3h
Ltemp			equ 0D4h
Lcube			equ 0D5h
Lenter			equ 0D6h
LimagI			equ 0D7h
Lphat			equ 0D8h
Lchi			equ 0D9h
LstatF			equ 0DAh
Llne			equ 0DBh
LlistL			equ 0DCh
LfinanN 		equ 0DDh
L2_r_paren 		equ 0DEh
LblockArrow     	equ 0DFh
LcurO   		equ 0E0h
LcurO2  		equ 0E1h
LcurOcapA       	equ 0E2h
LcurOa  		equ 0E3h
LcurI   		equ 0E4h
LcurI2  		equ 0E5h
LcurIcapA       	equ 0E6h
LcurIa  		equ 0E7h
LGline          	equ 0E8h ; = 0
LGthick         	equ 0E9h ; = 1
LGabove			equ 0EAh ; = 2
LGbelow			equ 0EBh ; = 3
LGpath			equ 0ECh ; = 4
LGanimate		equ 0EDh ; = 5
LGdot			equ 0EEh ; = 6
LUpBlk			equ 0EFh ;Up arrow and Block in solver
LDnBlk			equ 0F0h ;Down arrow and Block in solver
LcurFull		equ 0F1h ;note: must be last char (PutMap checks)

;Keypress Equates
;-------------------------------
kRight			equ 001h
kLeft			equ 002h
kUp			equ 003h
kDown			equ 004h
kEnter			equ 005h
kAlphaEnter		equ 006h
kAlphaUp		equ 007h
kAlphaDown		equ 008h
kClear			equ 009h
kDel			equ 00Ah
kIns			equ 00Bh
kRecall			equ 00Ch
kLastEnt		equ 00Dh
kBOL			equ 00Eh
kEOL			equ 00Fh

kSelAll			equ 010h
kUnselAll		equ 011h
kLtoTI82		equ 012h
kBackup			equ 013h
kRecieve		equ 014h
kLnkQuit		equ 015h
kTrans			equ 016h
kRename			equ 017h
kOverw			equ 018h
kOmit			equ 019h
kCont			equ 01Ah
kSendID			equ 01Bh
kSendSW			equ 01Ch
kYes			equ 01Dh
kNoWay			equ 01Eh
kvSendType		equ 01Fh
kOverWAll		equ 020h
kNo			equ 025h
kKReset			equ 026h
kApp			equ 027h
kDoug			equ 028h
kListflag		equ 029h
menuStart		equ 02Bh
kAreYouSure		equ 02Bh
kAppsMenu		equ 02Ch
kPrgm			equ 02Dh
kZoom			equ 02Eh
kDraw			equ 02Fh
kSPlot			equ 030h
kStat			equ 031h
kMath			equ 032h
kTest			equ 033h
kChar			equ 034h
kVars			equ 035h
kMem			equ 036h
kMatrix			equ 037h
kDist			equ 038h
kAngle			equ 039h
kList			equ 03Ah
kCalc			equ 03Bh
kFin			equ 03Ch
menuEnd			equ kFin
kCatalog		equ 03Eh
kInputDone		equ 03Fh
kOff			equ kInputDone
kQuit			equ 040h
appStart		equ kQuit
kLinkIO			equ 041h
kMatrixEd		equ 042h
kStatEd			equ 043h
kGraph			equ 044h
kMode			equ 045h
kPrgmEd			equ 046h ;PROGRAM EDIT
kPrgmCr			equ 047h ;PROGRAM CREATE
kWindow			equ 048h ;RANGE EDITOR
kYequ			equ 049h ;EQUATION EDITOR
kTable			equ 04Ah ;TABLE EDITOR
kTblSet			equ 04Bh ;TABLE SET
kChkRAM			equ 04Ch ;CHECK RAM
kDelMem			equ 04Dh ;DELETE MEM
kResetMem		equ 04Eh ;RESET MEM
kResetDef		equ 04Fh ;RESET DEFAULT
kPrgmInput		equ 050h ;PROGRAM INPUT
kZFactEd		equ 051h ;ZOOM FACTOR EDITOR
kError			equ 052h ;ERROR
kSolveTVM		equ 053h ;TVM SOLVER
kSolveRoot		equ 054h ;SOLVE EDITOR
kStatP			equ 055h ;stat plot
kInfStat		equ 056h ;Inferential Statistic
kFormat			equ 057h ;FORMAT
kExtApps		equ 058h ;External Applications.     NEW
kNewApps		equ 059h ;New Apps for Cerberus.
append			equ kNewApps
echoStart1		equ 05Ah
kTrace			equ 05Ah
kZFit			equ 05Bh
kZIn			equ 05Ch
kZOut			equ 05Dh
kZPrev			equ 05Eh
kBox			equ 05Fh
kDecml			equ 060h
kSetZm			equ 061h
kSquar			equ 062h
kStd			equ 063h
kTrig			equ 064h
kUsrZm			equ 065h
kZSto			equ 066h
kZInt			equ 067h
kZStat			equ 068h
echoStart2		equ 069h
kSelect			equ 069h
kCircl			equ 06Ah
kClDrw			equ 06Bh
kLine			equ 06Ch
kPen			equ 06Dh
kPtChg			equ 06Eh
kPtOff			equ 06Fh
kPtOn			equ 070h
kVert			equ 071h
kHoriz			equ 072h
kText			equ 073h
kTanLn			equ 074h
kEval			equ 075h
kInters			equ 076h
kDYDX			equ 077h
kFnIntg			equ 078h
kRootG			equ 079h
kDYDT			equ 07Ah
kDXDT			equ 07Bh
kDRDo			equ 07Ch
KGFMin			equ 07Dh
KGFMax			equ 07Eh
EchoStart		equ 07Fh
kListName		equ 07Fh
kAdd			equ 080h
kSub			equ 081h
kMul			equ 082h
kDiv			equ 083h
kExpon			equ 084h
kLParen			equ 085h
kRParen			equ 086h
kLBrack			equ 087h
kRBrack			equ 088h
kShade			equ 089h
kStore			equ 08Ah
kComma			equ 08Bh
kChs			equ 08Ch
kDecPnt			equ 08Dh
k0			equ 08Eh
k1			equ 08Fh
k2			equ 090h
k3			equ 091h
k4			equ 092h
k5			equ 093h
k6			equ 094h
k7			equ 095h
k8			equ 096h
k9			equ 097h
kEE			equ 098h
kSpace			equ 099h
kCapA			equ 09Ah
kCapB			equ 09Bh
kCapC			equ 09Ch
kCapD			equ 09Dh
kCapE			equ 09Eh
kCapF			equ 09Fh
kCapG			equ 0A0h
kCapH			equ 0A1h
kCapI			equ 0A2h
kCapJ			equ 0A3h
kCapK			equ 0A4h
kCapL			equ 0A5h
kCapM			equ 0A6h
kCapN			equ 0A7h
kCapO			equ 0A8h
kCapP			equ 0A9h
kCapQ			equ 0AAh
kCapR			equ 0ABh
kCapS			equ 0ACh
kCapT			equ 0ADh
kCapU			equ 0AEh
kCapV			equ 0AFh
kCapW			equ 0B0h
kCapX			equ 0B1h
kCapY			equ 0B2h
kCapZ			equ 0B3h
kVarx			equ 0B4h
kPi			equ 0B5h
kInv			equ 0B6h
kSin			equ 0B7h
kASin			equ 0B8h
kCos			equ 0B9h
kACos			equ 0BAh
kTan			equ 0BBh
kATan			equ 0BCh
kSquare			equ 0BDh
kSqrt			equ 0BEh
kLn			equ 0BFh
kExp			equ 0C0h
kLog			equ 0C1h
kALog			equ 0C2h
kToABC			equ 0C3h
kClrTbl			equ 0C4h
kAns			equ 0C5h
kColon			equ 0C6h
kNDeriv			equ 0C7h
kFnInt			equ 0C8h
kRoot			equ 0C9h
kQuest			equ 0CAh
kQuote			equ 0CBh
kTheta			equ 0CCh
kIf			equ 0CDh
kThen			equ 0CEh
kElse			equ 0CFh
kFor			equ 0D0h
kWhile			equ 0D1h
kRepeat			equ 0D2h
kEnd			equ 0D3h
kPause			equ 0D4h
kLbl			equ 0D5h
kGoto			equ 0D6h
kISG			equ 0D7h
kDSL			equ 0D8h
kMenu			equ 0D9h
kExec			equ 0DAh
kReturn			equ 0DBh
kStop			equ 0DCh
kInput			equ 0DDh
kPrompt			equ 0DEh
kDisp			equ 0DFh
kDispG			equ 0E0h
kDispT			equ 0E1h
kOutput			equ 0E2h
kGetKey			equ 0E3h
kClrHome		equ 0E4h
kPrtScr			equ 0E5h
kSinH			equ 0E6h
kCosH			equ 0E7h
kTanH			equ 0E8h
kASinH			equ 0E9h
kACosH			equ 0EAh
kATanH			equ 0EBh
kLBrace			equ 0ECh
kRBrace			equ 0EDh
kI			equ 0EEh
kCONSTeA		equ 0EFh
kPlot3			equ 0F0h
kFMin			equ 0F1h
kFMax			equ 0F2h
kL1A			equ 0F3h
kL2A			equ 0F4h
kL3A			equ 0F5h
kL4A			equ 0F6h
kL5A			equ 0F7h
kL6A			equ 0F8h
kunA			equ 0F9h
kvnA			equ 0FAh
kwnA			equ 0FBh

;THIS KEY MEANS THAT IT IS A 2 BYTE KEYCODE
;THERE ARE 2 OF THESE KEYS; BE CAREFUL WITH USAGE
;------------------------------------------------
kExtendEcho2		equ 0FCh

;THIS KEY MEANS THAT THE KEY PRESS IS ONE THAT ECHOS
;INTO A BUFFER, AND IT IS A 2 BYTE KEY CODE, GO LOOK AT
;(EXTECHO) FOR THE KEY VALUE 
;------------------------------------------------------
kExtendEcho		equ 0FEh

kE1BT			equ 0
kDrawInv		equ kE1BT
kDrawF			equ kE1BT+1
kPixelOn		equ kE1BT+2
kPixelOff		equ kE1BT+3
kPxlTest		equ kE1BT+4
kRCGDB			equ kE1BT+5
kRCPic			equ kE1BT+6
kSTGDB			equ kE1BT+7
kSTPic			equ kE1BT+8
kAbs			equ kE1BT+9
kTEqu			equ kE1BT+10 ;==
kTNoteQ			equ kE1BT+11 ;<>
kTGT			equ kE1BT+12 ;>
kTGTE			equ kE1BT+13 ;>=
kTLT			equ kE1BT+14 ;<
kTLTE			equ kE1BT+15 ;<=
kAnd			equ kE1BT+16
kOr			equ kE1BT+17
kXor			equ kE1BT+18
kNot			equ kE1BT+19
kLR1			equ kE1BT+20
kXRoot			equ kE1BT+21
kCube			equ kE1BT+22
kCbRt			equ kE1BT+23 ;Cube ROOT
kToDec			equ kE1BT+24
kCubicR			equ kE1BT+25
kQuartR			equ kE1BT+26
kPlot1			equ kE1BT+27
kPlot2			equ kE1BT+28
kRound			equ kE1BT+29
kIPart			equ kE1BT+30
kFPart			equ kE1BT+31
kInt			equ kE1BT+32
kRand			equ kE1BT+33
kNPR			equ kE1BT+34
kNCR			equ kE1BT+35
kXFactorial		equ kE1BT+36
kRad			equ kE1BT+37
kDegr			equ kE1BT+38 ;DEGREES CONV
kAPost			equ kE1BT+39
kToDMS			equ kE1BT+40
kRToPo			equ kE1BT+41 ;R
kRToPr			equ kE1BT+42
kPToRx			equ kE1BT+43
kPToRy			equ kE1BT+44
kRowSwap		equ kE1BT+45
kRowPlus		equ kE1BT+46
kTimRow			equ kE1BT+47
kTRowP			equ kE1BT+48
kSortA			equ kE1BT+49
kSortD			equ kE1BT+50
kSeq			equ kE1BT+51
kMin			equ kE1BT+52
kMax			equ kE1BT+53
kMean			equ kE1BT+54
kMedian			equ kE1BT+55
kSum			equ kE1BT+56
kProd			equ kE1BT+57
kDet			equ kE1BT+58
kTransp			equ kE1BT+59
kDim			equ kE1BT+60
kFill			equ kE1BT+61
kIdent			equ kE1BT+62
kRandm			equ kE1BT+63
kAug			equ kE1BT+64
kOneVar			equ kE1BT+65
kTwoVar			equ kE1BT+66
kLR			equ kE1BT+67
kLRExp			equ kE1BT+68
kLRLn			equ kE1BT+69
kLRPwr			equ kE1BT+70
kMedMed			equ kE1BT+71
kQuad			equ kE1BT+72
kClrLst			equ kE1BT+73
kHist			equ kE1BT+74
kxyLine			equ kE1BT+75
kScatter		equ kE1BT+76
kmRad			equ kE1BT+77
kmDeg			equ kE1BT+78
kmNormF			equ kE1BT+79
kmSci			equ kE1BT+80
kmEng			equ kE1BT+81
kmFloat			equ kE1BT+82
kFix			equ kE1BT+83
kSplitOn		equ kE1BT+84
kFullScreen		equ kE1BT+85
kStndrd			equ kE1BT+86
kParam			equ kE1BT+87
kPolar			equ kE1BT+88
kSeqG			equ kE1BT+89
kAFillOn		equ kE1BT+90
kAFillOff		equ kE1BT+91
kACalcOn		equ kE1BT+92
kACalcOff		equ kE1BT+93
kFNOn			equ kE1BT+94
kFNOff			equ kE1BT+95
kPlotsOn		equ kE1BT+96
kPlotsOff		equ kE1BT+97
kPixelChg		equ kE1BT+98
kSendMBL		equ kE1BT+99
kRecvMBL		equ kE1BT+100
kBoxPlot		equ kE1BT+101
kBoxIcon		equ kE1BT+102
kCrossIcon		equ kE1BT+103
kDotIcon		equ kE1BT+104
kE2BT			equ kE1BT+105
kSeqential		equ kE2BT
kSimulG			equ kE2BT+1
kPolarG			equ kE2BT+2
kRectG			equ kE2BT+3
kCoordOn		equ kE2BT+4
kCoordOff		equ kE2BT+5
kDrawLine		equ kE2BT+6
kDrawDot		equ kE2BT+7
kAxisOn			equ kE2BT+8
kAxisOff		equ kE2BT+9
kGridOn			equ kE2BT+10
kGridOff		equ kE2BT+11
kLblOn			equ kE2BT+12
kLblOff			equ kE2BT+13
kL1			equ kE2BT+14
kL2			equ kE2BT+15
kL3			equ kE2BT+16
kL4			equ kE2BT+17
kL5			equ kE2BT+18
kL6			equ kE2BT+19

;These keys are laid on top of existing keys to
;enable localization in the inferential stats editor.
;----------------------------------------------------
kinfData		equ kL1
kinfStats		equ kL1+1
kinfYes			equ kL1+2
kinfNo			equ kL1+3
kinfCalc		equ kL1+4
kinfDraw		equ kL1+5
kinfAlt1ne		equ kL1+6
kinfAlt1lt		equ kL1+7
kinfAlt1gt		equ kL1+8
kinfAlt2ne		equ kL1+9
kinfAlt2lt		equ kL1+10
kinfAlt2gt		equ kL1+11
kinfAlt3ne		equ kL1+12
kinfAlt3lt		equ kL1+13
kinfAlt3gt		equ kL1+14
kinfAlt4ne		equ kL1+15
kinfAlt4lt		equ kL1+16
kinfAlt4gt		equ kL1+17
kinfAlt5ne		equ kL1+18
kinfAlt5lt		equ kL1+19
kinfAlt5gt		equ kL1+20
kinfAlt6ne		equ kL1+21
kinfAlt6lt		equ kL1+22
kinfAlt6gt		equ kL1+23
kMatA			equ kE2BT+20
kMatB			equ kE2BT+21
kMatC			equ kE2BT+22
kMatD			equ kE2BT+23
kMatE			equ kE2BT+24
kXmin			equ kE2BT+25
kXmax			equ kE2BT+26
kXscl			equ kE2BT+27
kYmin			equ kE2BT+28
kYmax			equ kE2BT+29
kYscl			equ kE2BT+30
kTmin			equ kE2BT+31
kTmax			equ kE2BT+32
kTStep			equ kE2BT+33
kOmin			equ kE2BT+34
kOmax			equ kE2BT+35
kOStep			equ kE2BT+36
ku0			equ kE2BT+37
kv0			equ kE2BT+38
knMin			equ kE2BT+39
knMax			equ kE2BT+40
kDeltaY			equ kE2BT+41
kDeltaX			equ kE2BT+42
kZXmin			equ kE2BT+43
kZXmax			equ kE2BT+44
kZXscl			equ kE2BT+45
kZYmin			equ kE2BT+46
kZYmax			equ kE2BT+47
kZYscl			equ kE2BT+48
kZTmin			equ kE2BT+49
kZTmax			equ kE2BT+50
kZTStep			equ kE2BT+51
kZOmin			equ kE2BT+52
kZOmax			equ kE2BT+53
kZOStep			equ kE2BT+54
kZu0			equ kE2BT+55
kZv0			equ kE2BT+56
kZnMin			equ kE2BT+57
kZnMax			equ kE2BT+58
kDelLast		equ kE2BT+59
kSinReg			equ kE2BT+60
kConstE			equ kE2BT+61
kPic1			equ kE2BT+62
kPic2			equ kE2BT+63
kPic3			equ kE2BT+64
kDelVar			equ kE2BT+65
kGetCalc		equ kE2BT+66
kRealM			equ kE2BT+67
kPolarM			equ kE2BT+68
kRectM			equ kE2BT+69
kuv			equ kE2BT+70 ;U vs V
kvw			equ kE2BT+71 ;V vs W
kuw			equ kE2BT+72 ;U vs W
kFinPMTend		equ kE2BT+73
kFinPMTbeg		equ kE2BT+74
kGraphStyle		equ kE2BT+75
kExprOn			equ kE2BT+76
kExprOff		equ kE2BT+77
kStatA			equ kE2BT+78
kStatB			equ kE2BT+79
kStatC			equ kE2BT+80
kCorr			equ kE2BT+81
kStatD			equ kE2BT+82
kStatE			equ kE2BT+83
kRegEq			equ kE2BT+84
kMinX			equ kE2BT+85
kQ1			equ kE2BT+86
kMD			equ kE2BT+87
kQ3			equ kE2BT+88
kMaxX			equ kE2BT+89
kStatX1			equ kE2BT+90
kStatY1			equ kE2BT+91
kStatX2			equ kE2BT+92
kStatY2			equ kE2BT+93
kStatX3			equ kE2BT+94
kStatY3			equ kE2BT+95
kTblMin			equ kE2BT+96
kTblStep		equ kE2BT+97
kSetupLst		equ kE2BT+98
kClrAllLst		equ kE2BT+99
kLogistic		equ kE2BT+100
kZTest			equ kE2BT+101
kTTest			equ kE2BT+102
k2SampZTest		equ kE2BT+103
k2SampTTest		equ kE2BT+104
k1PropZTest		equ kE2BT+105
k2PropZTest		equ kE2BT+106
kChiTest		equ kE2BT+107
k2SampFTest		equ kE2BT+108
kZIntVal		equ kE2BT+109
kTIntVal		equ kE2BT+110
k2SampTInt		equ kE2BT+111
k2SampZInt		equ kE2BT+112
k1PropZInt		equ kE2BT+113
k2PropZInt		equ kE2BT+114
kDNormal		equ kE2BT+115
kInvNorm		equ kE2BT+116
kDT			equ kE2BT+117
kChi			equ kE2BT+118
kDF			equ kE2BT+119
kBinPDF			equ kE2BT+120
kBinCDF			equ kE2BT+121
kPoiPDF			equ kE2BT+122
kPoiCDF			equ kE2BT+123
kun			equ kE2BT+124
kvn			equ kE2BT+125
kwn			equ kE2BT+126
kRecn			equ kE2BT+127
kPlotStart		equ kE2BT+128
kZPlotStart		equ kE2BT+129 ;recursion n
kXFact			equ kE2BT+130 ;PlotStart
kYFact			equ kE2BT+131 ;ZPlotStart
kANOVA			equ kE2BT+132 ;XFact
kMaxY			equ kE2BT+133 ;YFact
kWebOn			equ kE2BT+134 ;MinY
kWebOff			equ kE2BT+135 ;MaxY
kTblInput		equ kE2BT+136 ;WEB ON
kGeoPDF			equ kE2BT+137 ;WEB OFF
kGeoCDF			equ kE2BT+138 ;WEB OFF
kShadeNorm		equ kE2BT+139
kShadeT			equ kE2BT+140
kShadeChi		equ kE2BT+141
kShadeF			equ kE2BT+142
kPlotStep		equ kE2BT+143
kZPlotStep		equ kE2BT+144
kLinRegtTest		equ kE2BT+145
KMGT			equ kE2BT+146 ;VERT SPLIT
kSelectA		equ kE2BT+147
kZFitA			equ kE2BT+148
kE2BT_End		equ kZFitA

;More 2 Byte Keys 
;------------------------------------
kE2BT2			equ 0
kGDB1			equ kE2BT2
kGDB2			equ kE2BT2+1
kGDB3			equ kE2BT2+2
kY1			equ kE2BT2+3
kY2			equ kE2BT2+4
kY3			equ kE2BT2+5
kY4			equ kE2BT2+6
kY5			equ kE2BT2+7
kY6			equ kE2BT2+8
kY7			equ kE2BT2+9
kY8			equ kE2BT2+10
kY9			equ kE2BT2+11
kY0			equ kE2BT2+12
kX1T			equ kE2BT2+13
kY1T			equ kE2BT2+14
kX2T			equ kE2BT2+15
kY2T			equ kE2BT2+16
kX3T			equ kE2BT2+17
kY3T			equ kE2BT2+18
kX4T			equ kE2BT2+19
kY4T			equ kE2BT2+20
kX5T			equ kE2BT2+21
kY5T			equ kE2BT2+22
kX6T			equ kE2BT2+23
kY6T			equ kE2BT2+24
kR1			equ kE2BT2+25
kR2			equ kE2BT2+26
kR3			equ kE2BT2+27
kR4			equ kE2BT2+28
kR5			equ kE2BT2+29
kR6			equ kE2BT2+30
kGDB4			equ kE2BT2+31
kGDB5			equ kE2BT2+32
kGDB6			equ kE2BT2+33
kPic4			equ kE2BT2+34
kPic5			equ kE2BT2+35
kPic6			equ kE2BT2+36
kGDB7			equ kE2BT2+37
kGDB8			equ kE2BT2+38
kGDB9			equ kE2BT2+39
kGDB0			equ kE2BT2+40
kPic7			equ kE2BT2+41
kPic8			equ kE2BT2+42
kPic9			equ kE2BT2+43
kPic0			equ kE2BT2+44
kStatN			equ kE2BT2+45
kXMean			equ kE2BT2+46
kConj			equ kE2BT2+47
kReal			equ kE2BT2+48
kFAngle			equ kE2BT2+49
kLCM			equ kE2BT2+50
kGCD			equ kE2BT2+51
kRandInt		equ kE2BT2+52
kRandNorm		equ kE2BT2+53
kToPolar		equ kE2BT2+54
kToRect			equ kE2BT2+55
kYMean			equ kE2BT2+56
kStdX			equ kE2BT2+57
kStdX1			equ kE2BT2+58
kw0			equ kE2BT2+59
kMatF			equ kE2BT2+60
kMatG			equ kE2BT2+61
kMatRH			equ kE2BT2+62
kMatI			equ kE2BT2+63
kMatJ			equ kE2BT2+64
kYMean1			equ kE2BT2+65
kStdY			equ kE2BT2+66
kStdY1			equ kE2BT2+67
kMatToLst		equ kE2BT2+68
kLstToMat		equ kE2BT2+69
kCumSum			equ kE2BT2+70
kDeltaLst		equ kE2BT2+71
kStdDev			equ kE2BT2+72
kVariance		equ kE2BT2+73
kLength			equ kE2BT2+74
kEquToStrng		equ kE2BT2+75
kStrngToEqu		equ kE2BT2+76
kExpr			equ kE2BT2+77
kSubStrng		equ kE2BT2+78
kInStrng		equ kE2BT2+79
kStr1			equ kE2BT2+80
kStr2			equ kE2BT2+81
kStr3			equ kE2BT2+82
kStr4           	equ kE2BT2+83
kStr5           	equ kE2BT2+84
kStr6           	equ kE2BT2+85
kStr7           	equ kE2BT2+86
kStr8           	equ kE2BT2+87
kStr9           	equ kE2BT2+88
kStr0           	equ kE2BT2+89
kFinN           	equ kE2BT2+90
kFinI           	equ kE2BT2+91
kFinPV          	equ kE2BT2+92
kFinPMT         	equ kE2BT2+93
kFinFV          	equ kE2BT2+94
kFinPY          	equ kE2BT2+95
kFinCY          	equ kE2BT2+96
kFinFPMT        	equ kE2BT2+97
kFinFI          	equ kE2BT2+98
kFinFPV         	equ kE2BT2+99
kFinFN          	equ kE2BT2+100
kFinFFV         	equ kE2BT2+101
kFinNPV         	equ kE2BT2+102
kFinIRR         	equ kE2BT2+103
kFinBAL         	equ kE2BT2+104
kFinPRN         	equ kE2BT2+105
kFinINT         	equ kE2BT2+106
kSumX           	equ kE2BT2+107
kSumX2          	equ kE2BT2+108
kFinToNom       	equ kE2BT2+109
kFinToEff       	equ kE2BT2+110
kFinDBD         	equ kE2BT2+111
kStatVP         	equ kE2BT2+112
kStatZ          	equ kE2BT2+113
kStatT          	equ kE2BT2+114
kStatChi        	equ kE2BT2+115
kStatF          	equ kE2BT2+116
kStatDF         	equ kE2BT2+117
kStatPhat       	equ kE2BT2+118
kStatPhat1      	equ kE2BT2+119
kStatPhat2      	equ kE2BT2+120
kStatMeanX1     	equ kE2BT2+121
kStatMeanX2     	equ kE2BT2+122
kStatStdX1      	equ kE2BT2+123
kStatStdX2      	equ kE2BT2+124
kStatStdXP		equ kE2BT2+125
kStatN1			equ kE2BT2+126
kStatN2			equ kE2BT2+127
kStatLower		equ kE2BT2+128
kStatUpper		equ kE2BT2+129
kuw0			equ kE2BT2+130
kImag			equ kE2BT2+131
kSumY			equ kE2BT2+132
kXres			equ kE2BT2+133
kStat_s			equ kE2BT2+134
kSumY2			equ kE2BT2+135
kSumXY			equ kE2BT2+136
kuXres			equ kE2BT2+137
kModBox			equ kE2BT2+138
kNormProb		equ kE2BT2+139
kNormalPDF		equ kE2BT2+140
kTPDF			equ kE2BT2+141
kChiPDF			equ kE2BT2+142
kFPDF			equ kE2BT2+143
kMinY			equ kE2BT2+144 ;MinY
kRandBin		equ kE2BT2+145
kRef			equ kE2BT2+146
kRRef			equ kE2BT2+147
kLRSqr			equ kE2BT2+148
kBRSqr			equ kE2BT2+149
kDiagOn			equ kE2BT2+150
kDiagOff		equ kE2BT2+151
kun1			equ kE2BT2+152 ;FOR RCL USE WHEN GOTTEN FROM 82
kvn1			equ kE2BT2+153 ;FOR RCL USE WHEN GOTTEN FROM 82
k83_00End		equ kvn1 ;end of original keys...
kArchive		equ k83_00End + 1
kUnarchive		equ k83_00End + 2
kAsm			equ k83_00End + 3 ;Asm(
kAsmPrgm		equ k83_00End + 4 ;AsmPrgm
kAsmComp		equ k83_00End + 5 ;AsmComp(
kcapAAcute		equ k83_00End + 6
kcapAGrave		equ k83_00End + 7
kcapACaret		equ k83_00End + 8
kcapADier		equ k83_00End + 9
kaAcute			equ k83_00End + 10
kaGrave			equ k83_00End + 11
kaCaret			equ k83_00End + 12
kaDier			equ k83_00End + 13
kcapEAcute		equ k83_00End + 14
kcapEGrave		equ k83_00End + 15
kcapECaret		equ k83_00End + 16
kcapEDier		equ k83_00End + 17
keAcute			equ k83_00End + 18
keGrave			equ k83_00End + 19
keCaret			equ k83_00End + 20
keDier			equ k83_00End + 21
kcapIAcute		equ k83_00End + 22
kcapIGrave		equ k83_00End + 23
kcapICaret		equ k83_00End + 24
kcapIDier		equ k83_00End + 25
kiAcute			equ k83_00End + 26
kiGrave			equ k83_00End + 27
kiCaret			equ k83_00End + 28
kiDier			equ k83_00End + 29
kcapOAcute		equ k83_00End + 30
kcapOGrave		equ k83_00End + 31
kcapOCaret		equ k83_00End + 32
kcapODier		equ k83_00End + 33
koAcute			equ k83_00End + 34
koGrave			equ k83_00End + 35
koCaret			equ k83_00End + 36
koDier			equ k83_00End + 37
kcapUAcute		equ k83_00End + 38
kcapUGrave		equ k83_00End + 39
kcapUCaret		equ k83_00End + 40
kcapUDier		equ k83_00End + 41
kuAcute			equ k83_00End + 42
kuGrave			equ k83_00End + 43
kuCaret			equ k83_00End + 44
kuDier			equ k83_00End + 45
kcapCCed		equ k83_00End + 46
kcCed			equ k83_00End + 47
kcapNTilde		equ k83_00End + 48
knTilde			equ k83_00End + 49
kaccent			equ k83_00End + 50
kgrave			equ k83_00End + 51
kdieresis		equ k83_00End + 52
kquesDown		equ k83_00End + 53
kexclamDown     	equ k83_00End + 54
kalpha          	equ k83_00End + 55
kbeta           	equ k83_00End + 56
kgamma          	equ k83_00End + 57
kcapDelta		equ k83_00End + 58
kdelta			equ k83_00End + 59
kepsilon		equ k83_00End + 60
klambda			equ k83_00End + 61
kmu			equ k83_00End + 62
kpi2			equ k83_00End + 63
krho			equ k83_00End + 64
kcapSigma		equ k83_00End + 65
ksigma			equ k83_00End + 66
ktau			equ k83_00End + 67
kphi			equ k83_00End + 68
kcapOmega		equ k83_00End + 69
kphat			equ k83_00End + 70
kchi2			equ k83_00End + 71
kstatF2			equ k83_00End + 72
kLa			equ k83_00End + 73
kLb			equ k83_00End + 74
kLc			equ k83_00End + 75
kLd			equ k83_00End + 76
kLe			equ k83_00End + 77
kLf			equ k83_00End + 78
kLg			equ k83_00End + 79
kLh			equ k83_00End + 80
kLi			equ k83_00End + 81
kLj			equ k83_00End + 82
kLk			equ k83_00End + 83
kLl			equ k83_00End + 84
kLm			equ k83_00End + 85
kLsmalln		equ k83_00End + 86
kLo			equ k83_00End + 87
kLp			equ k83_00End + 88
kLq			equ k83_00End + 89
kLsmallr		equ k83_00End + 90
kLs			equ k83_00End + 91
kLt			equ k83_00End + 92
kLu			equ k83_00End + 93
kLv			equ k83_00End + 94
kLw			equ k83_00End + 95
kLx			equ k83_00End + 96
kLy			equ k83_00End + 97
kLz			equ k83_00End + 98
kGarbageC		equ k83_00End + 99 ;GarbageCollect
kE2BT2_End		equ kGarbageC

;TI-83 Plus Context Equates
;---------------------------------------------
cxCmd			equ kQuit ;home screen
cxMatEdit		equ kMatrixEd ;matrix editor
cxPrgmEdit		equ kPrgmEd ;program editor
cxEquEdit		equ kYequ ;equation editor
cxGrRange		equ kWindow ;graph range editor
cxGrZfact		equ kZFactEd ;graph zoom factors editor
cxGraph			equ kGraph ;graph mode
cxStatEdit		equ kStatEd ;statistics list editor
cxPrgmInput		equ kPrgmInput ;programmed input
cxError			equ kError ;error handler
cxLinkIO		equ kLinkIO ;LINK I/O interface
cxMem			equ kResetMem ;reset memory
cxDefMem		equ kResetDef ;reset default
cxRAMApp		equ kChkRAM ;RAM usage screen
cxMode			equ kMode ;mode settings screen
cxErase			equ kDelMem ;memory erase
cxPrgmCreate		equ kPrgmCr ;PROGRAM CREATE
cxTableEditor		equ kTable ;TABLE EDITOR
cxTableSet		equ kTblSet ;TABLE SET UP
cxStatPlot		equ kStatP ;STAT PLOTS
cxInfStat		equ kInfStat ;Inferential Statistic
cxFormat		equ kFormat ;FORMAT CONTEXT
cxSolveTVM		equ kSolveTVM ;Solve TVM
cxSolveRoot		equ kSolveRoot ;Solve Root
lastOldApp		equ kExtApps ;external applications
cxextapps		equ kExtApps
cxNewApps		equ kNewApps ;new cerberus applications
cxGroup			equ cxNewApps+0 ;1st new app.
cxUnGroup		equ cxNewApps+1 ;2nd new app.
lastNewApp		equ cxUnGroup ;last new app for this ver

;Scan Code Equates
;-------------------------------
skDown			equ 01h
skLeft			equ 02h
skRight			equ 03h
skUp			equ 04h
skEnter			equ 09h
skAdd			equ 0Ah
skSub			equ 0Bh
skMul			equ 0Ch
skDiv			equ 0Dh
skPower			equ 0Eh
skClear			equ 0Fh
skChs			equ 11h
sk3			equ 12h
sk6			equ 13h
sk9			equ 14h
skRParen		equ 15h
skTan			equ 16h
skVars			equ 17h
skDecPnt		equ 19h
sk2			equ 1Ah
sk5			equ 1Bh
sk8			equ 1Ch
skLParen		equ 1Dh
skCos			equ 1Eh
skPrgm			equ 1Fh
skStat			equ 20h
sk0			equ 21h
sk1			equ 22h
sk4			equ 23h
sk7			equ 24h
skComma			equ 25h
skSin			equ 26h
skMatrix		equ 27h
skGraphvar		equ 28h
skStore			equ 2Ah
skLn			equ 2Bh
skLog			equ 2Ch
skSquare		equ 2Dh
skRecip			equ 2Eh
skMath			equ 2Fh
skAlpha			equ 30h
skGraph			equ 31h
skTrace			equ 32h
skZoom			equ 33h
skWindow		equ 34h
skYEqu			equ 35h
sk2nd			equ 36h
skMode			equ 37h
skDel			equ 38h

;Tokens
;----------------------------------------------------
EOSSTART		equ 0

;DISPLAY CONVERSIONS COME IMMEDIATELY BEFORE 'TSTORE'
;
DCONV			equ 01h
;
tToDMS			equ DCONV ;01h
tToDEC			equ DCONV+1 ;02h
tToAbc			equ DCONV+2 ;03h > A b/c
;
tStore			equ DCONV+3 ;04h Lstore 01
;
tBoxPlot		equ 05h
;
BRACKS			equ 06h
;
tLBrack			equ BRACKS ;06h '['
tRBrack			equ BRACKS+1 ;07h ']'
tLBrace			equ BRACKS+2 ;08h '{'
tRBrace			equ BRACKS+3 ;09h '}'
;
tPOST1			equ BRACKS+4
;
tFromRad		equ tPOST1 ;0Ah Lradian
tFromDeg		equ tPOST1+1 ;0Bh Ldegree
tRecip			equ tPOST1+2 ;0Ch Linverse
tSqr			equ tPOST1+3 ;0Dh Lsquare
tTrnspos		equ tPOST1+4 ;0Eh Ltranspose
tCube			equ tPOST1+5 ;0Fh '^3'
;
tLParen			equ 10h ;10h '('
tRParen			equ 11h ;11h ')'
;
IMUN			equ 12h
;
tRound			equ IMUN ;12h 'round'
tPxTst			equ IMUN+1 ;13h 'PXL-TEST'
tAug			equ IMUN+2 ;14h 'aug'
tRowSwap		equ IMUN+3 ;15h 'rSwap'
tRowPlus		equ IMUN+4 ;16h 'rAdd'
tmRow			equ IMUN+5 ;17h 'multR'
tmRowPlus		equ IMUN+6 ;18h 'mRAdd'
tMax			equ IMUN+7 ;19h 'max'
tMin			equ IMUN+8 ;1Ah 'min'
tRToPr			equ IMUN+9 ;1Bh 'R>Pr
tRToPo			equ IMUN+10 ;1Ch 'R>Po
tPToRx			equ IMUN+11 ;1Dh 'P>Rx
tPToRy			equ IMUN+12 ;1Eh 'P>Ry
tMedian			equ IMUN+13 ;1Fh 'MEDIAN
tRandM			equ IMUN+14 ;20h 'randM'
tMean			equ IMUN+15 ;21h
tRoot			equ IMUN+16 ;22h 'ROOT'
tSeries			equ IMUN+17 ;23h 'seq'
tFnInt			equ IMUN+18 ;24h 'fnInt'
tNDeriv			equ IMUN+19 ;25h 'fnIr'
tEvalF			equ IMUN+20 ;26h
tFmin			equ IMUN+21 ;27h
tFmax			equ IMUN+22 ;28h
;
tEOSEL			equ IMUN+23
;
tSpace			equ tEOSEL ;29h ' '
tString			equ tEOSEL+1 ;2Ah '"'
tComma			equ tEOSEL+2 ;2Bh ','
;
tii			equ 2Ch ;i

;Postfix Functions
;-----------------------------------------
tPost			equ 2Dh
;
tFact			equ tPost ;2Dh '!'
;
tCubicR			equ 2Eh
tQuartR			equ 2Fh

;Number Tokens 
;---------------------------------------
NUMS			equ 30h
;
t0			equ NUMS ;30h
t1			equ NUMS+1 ;31h
t2			equ NUMS+2 ;32h
t3			equ NUMS+3 ;33h
t4			equ NUMS+4 ;34h
t5			equ NUMS+5 ;35h
t6			equ NUMS+6 ;36h
t7			equ NUMS+7 ;37h
t8			equ NUMS+8 ;38h
t9			equ NUMS+9 ;39h
tDecPt			equ NUMS+10 ;3Ah
tee			equ NUMS+11 ;3Bh

;Binary OP
;-------------------------------------------
tOr			equ 3Ch ;3Ch '_or_'
tXor			equ 3Dh ;3Dh
;
tColon			equ 3Eh ;3Eh ':'
tEnter			equ 3Fh ;3Fh Lenter
;
tAnd			equ 40h ;40h '_and_'

;Letter Tokens
;--------------------------------------
LET			equ 41h
tA			equ LET ;41h
tB			equ LET+1 ;42h
tC			equ LET+2 ;43h
tD			equ LET+3 ;44h
tE			equ LET+4 ;45h
tF			equ LET+5 ;46h
tG			equ LET+6 ;47h
tH			equ LET+7 ;48h
tI			equ LET+8 ;49h
tJ			equ LET+9 ;4Ah
tK			equ LET+10 ;4Bh
tL			equ LET+11 ;4Ch
tM			equ LET+12 ;4Dh
tN			equ LET+13 ;4Eh
tO			equ LET+14 ;4Fh
tP			equ LET+15 ;50h
tQ			equ LET+16 ;51h
tR			equ LET+17 ;52h
tS			equ LET+18 ;53h
tT			equ LET+19 ;54h
tU			equ LET+20 ;55h
tV			equ LET+21 ;56h
tW			equ LET+22 ;57h
tX			equ LET+23 ;58h
tY			equ LET+24 ;59h
tZ			equ LET+25 ;5Ah
tTheta			equ LET+26 ;5Bh

;These Var Tokens Are 1st Of A Double Token
;------------------------------------------

vToks			equ LET+27

;User Matrix Token, 2nd Token Needed For Name
;
tVarMat			equ vToks ;5Ch
;
;User List Token, 2nd Token Needed For Name
;
tVarLst			equ vToks+1 ;5Dh
;
;User Equation Token, 2nd Token Needed For Name
;
tVarEqu			equ vToks+2 ;5Eh
tProg			equ vToks+3 ;5Fh
;
;User Pict Token, 2nd Token Needed For Name
;
tVarPict		equ vToks+4 ;60h
;
;User GDB Token, 2nd Token Needed For Name
;
tVarGDB			equ vToks+5 ;61h
tVarOut			equ vToks+6 ;62h
tVarSys			equ vToks+7 ;63h

;Mode Setting Commands
;-------------------------------------------------
MODESA			equ vToks+8 ;64h
tRad			equ MODESA ;64h 'Radian'
tDeg			equ MODESA+1 ;65h 'Degree'
tNormF			equ MODESA+2 ;66h 'Normal'
tSci			equ MODESA+3 ;67h 'Sci'
tEng			equ MODESA+4 ;68h 'Eng'
tFloat			equ MODESA+5 ;69h 'Float'
CMPS			equ 6Ah
tEQ			equ CMPS ;6Ah '=='
tLT			equ CMPS+1 ;6Bh '<'
tGT			equ CMPS+2 ;6Ch '>'
tLE			equ CMPS+3 ;6Dh LLE
tGE			equ CMPS+4 ;6Eh LGE
tNE			equ CMPS+5 ;6Fh LNE

;Binary OP
;---------------------------------------
tAdd			equ 70h ;70h '+'
tSub			equ 71h ;71h '-'
tAns			equ 72h ;72h

;Mode Setting Commands
;-------------------------------------------------------
MODES			equ 73h
tFix			equ MODES ;73h 'Fix_'
tSplitOn		equ MODES+1 ;74h
tFullScreen		equ MODES+2 ;75h
tStndrd			equ MODES+3 ;76h 'Func'
tParam			equ MODES+4 ;77h 'Param'
tPolar			equ MODES+5 ;78h 'Pol'
tSeqG			equ MODES+6 ;79h
tAFillOn		equ MODES+7 ;7Ah 'AUTO FILL ON'
tAFillOff		equ MODES+8 ;7Bh
tACalcOn		equ MODES+9 ;7Ch
tACalcOff		equ MODES+10 ;7Dh 'AutoFill OFF'

;Graph Format Tokens Are 2 Byte Tokens
;----------------------------------------
tGFormat		equ MODES+11 ;7Eh
tBoxIcon		equ 7Fh
tCrossIcon		equ 80h
tDotIcon		equ 81h

;(More) Binary OP
;---------------------------------------
tMul			equ 82h ;82h '*'
tDiv			equ 83h ;83h '/'

;Some Graph Commands
;------------------------------------------------------
GRCMDS			equ 84h
tTrace			equ GRCMDS ; 84h 'Trace'
tClDrw			equ GRCMDS+1 ; 85h 'ClDrw'
tZoomStd		equ GRCMDS+2 ; 86h 'ZStd'
tZoomtrg		equ GRCMDS+3 ; 87h 'Ztrg'
tZoomBox		equ GRCMDS+4 ; 88h 'ZBOX'
tZoomIn			equ GRCMDS+5 ; 89h 'ZIn'
tZoomOut		equ GRCMDS+6 ; 8Ah 'ZOut'
tZoomSqr		equ GRCMDS+7 ; 8Bh 'ZSqr'
tZoomInt		equ GRCMDS+8 ; 8Ch 'ZInt'
tZoomPrev		equ GRCMDS+9 ; 8Dh 'ZPrev'
tZoomDec		equ GRCMDS+10 ; 8Eh 'ZDecm'
tZoomStat		equ GRCMDS+11 ; 8Fh 'ZStat
tUsrZm			equ GRCMDS+12 ; 90h 'ZRcl'
tPrtScrn		equ GRCMDS+13 ; 91h 'PrtScrn'
tZoomSto		equ GRCMDS+14 ; 92h  ZOOM STORE
tText			equ GRCMDS+15 ; 93h

;Binary OP (Combination & Permutation)
;-------------------------------------------------
tnPr			equ GRCMDS+16 ;94h '_nPr_'
tnCr			equ GRCMDS+17 ;95h '_nCr_'

;More Graph Commands
;--------------------------------------------------
tYOn			equ GRCMDS+18 ;96h 'FnOn_'
tYOff			equ GRCMDS+19 ;97h 'FnOff_'
tStPic			equ GRCMDS+20 ;98h 'StPic_'
tRcPic			equ GRCMDS+21 ;99h 'RcPic_'
tStoDB			equ GRCMDS+22 ;9Ah 'StGDB_'
tRclDB			equ GRCMDS+23 ;9Bh 'RcGDB_'
tLine			equ GRCMDS+24 ;9Ch 'Line'
tVert			equ GRCMDS+25 ;9Dh 'Vert_'
tPtOn			equ GRCMDS+26 ;9Eh 'PtOn'
tPtOff			equ GRCMDS+27 ;9Fh 'PtOff'

;Token A0 Cannot Be An EOS Function Since Low MULT=A0 Already
;------------------------------------------------------------
tPtChg			equ GRCMDS+28 ;A0h 'PtChg'
tPXOn			equ GRCMDS+29 ;A1h
tPXOff			equ GRCMDS+30 ;A2h
tPXChg			equ GRCMDS+31 ;A3h
tShade			equ GRCMDS+32 ;A4h 'Shade'
tCircl			equ GRCMDS+33 ;A5h 'Circl'
tHorz			equ GRCMDS+34 ;A6h 'HORIZONTAL'
tTanLn			equ GRCMDS+35 ;A7h 'TanLn'
tDrInv			equ GRCMDS+36 ;A8h 'DrInv_'
tDrawF			equ GRCMDS+37 ;A9h 'DrawF_'
tVarStrng		equ 0AAh

;Functions with No Arguments                                    
;--------------------------------------------------
NOARG			equ 0ABh
tRand			equ NOARG ;ABh 'rand'
tPi			equ NOARG+1 ;ACh  Lpi
tGetKey			equ NOARG+2 ;ADh 'getKy'
tAPost			equ tGetKey+1 ;APOSTROPHY
tQuest			equ tAPost+1 ;QUESTION MARK
UNARY			equ tQuest+1 ;B0h
tChs			equ UNARY ;B0h
tInt			equ UNARY+1 ;B1h
tAbs			equ UNARY+2 ;B2h
tDet			equ UNARY+3 ;B3h
tIdent			equ UNARY+4 ;B4h
tDim			equ UNARY+5 ;B5h
tSum			equ UNARY+6 ;B6h
tProd			equ UNARY+7 ;B7h
tNot			equ UNARY+8 ;B8h
tIPart			equ UNARY+9 ;B9h
tFPart			equ UNARY+10 ;BAh

;New 2 Byte Tokens
;------------------------------------------
t2ByteTok		equ 0BBh
UNARYLR			equ UNARY+12
tSqrt			equ UNARYLR ;BCh
tCubRt			equ UNARYLR+1 ;BDh
tLn			equ UNARYLR+2 ;BEh
tExp			equ UNARYLR+3 ;BFh
tLog			equ UNARYLR+4 ;C0h
tALog			equ UNARYLR+5 ;C1h
tSin			equ UNARYLR+6 ;C2h
tASin			equ UNARYLR+7 ;C3h
tCos			equ UNARYLR+8 ;C4h
tACos			equ UNARYLR+9 ;C5h
tTan			equ UNARYLR+10 ;C6h
tATan			equ UNARYLR+11 ;C7h
tSinH			equ UNARYLR+12 ;C8h
tASinH			equ UNARYLR+13 ;C9h
tCoshH			equ UNARYLR+14 ;CAh
tACosH			equ UNARYLR+15 ;CBh
tTanH			equ UNARYLR+16 ;CCh
tATanH			equ UNARYLR+17 ;CDh

;Some Programming Commands
;------------------------------------------------------
PROGTOK			equ UNARYLR+18
tIf			equ PROGTOK ;CEh
tThen			equ PROGTOK+1 ;CFh
tElse			equ PROGTOK+2 ;D0h
tWhile			equ PROGTOK+3 ;D1h
tRepeat			equ PROGTOK+4 ;D2h
tFor			equ PROGTOK+5 ;D3h
tEnd			equ PROGTOK+6 ;D4h
tReturn			equ PROGTOK+7 ;D5h
tLbl			equ PROGTOK+8 ;D6h 'Lbl_'
tGoto			equ PROGTOK+9 ;D7h 'Goto_'
tPause			equ PROGTOK+10 ;D8h 'Pause_'
tStop			equ PROGTOK+11 ;D9h 'Stop'
tISG			equ PROGTOK+12 ;DAh 'IS>'
tDSL			equ PROGTOK+13 ;DBh 'DS<'
tInput			equ PROGTOK+14 ;DCh 'Input_'
tPrompt			equ PROGTOK+15 ;DDh 'Prompt_'
tDisp			equ PROGTOK+16 ;DEh 'Disp_'
tDispG			equ PROGTOK+17 ;DFh 'DispG'
tOutput			equ PROGTOK+18 ;E0h 'Outpt'
tClLCD			equ PROGTOK+19 ;E1h 'ClLCD'
tConst			equ PROGTOK+20 ;E2h 'Fill'
tSortA			equ PROGTOK+21 ;E3h 'sortA_'
tSortD			equ PROGTOK+22 ;E4h 'sortD_'
tDispTab		equ PROGTOK+23 ;E5h 'Disp Table
tMenu			equ PROGTOK+24 ;E6h 'Menu'
tSendMBL		equ PROGTOK+25 ;E7h 'SEND'
tGetMBL			equ PROGTOK+26 ;E8h 'GET'

;Stat Plot Commands
;------------------------------------------------------
statPCmd		equ PROGTOK+27
tPlotOn			equ statPCmd ;E9h ' PLOTSON'
tPlotOff		equ statPCmd+1 ;EAh ' PLOTSOFF
tListName		equ 0EBh ;LIST DESIGNATOR
tPlot1			equ 0ECh
tPlot2			equ 0EDh
tPlot3			equ 0EEh
tUnused01		equ 0EFh ;available?
tPower			equ 0F0h ;'^'
tXRoot			equ 0F1h ;LsupX,Lroot
STATCMD			equ 0F2h
tOneVar			equ STATCMD ;F2h 'OneVar_'
tTwoVar			equ STATCMD+1 ;F3h
tLR			equ STATCMD+2 ;F4h 'LinR(A+BX
tLRExp			equ STATCMD+3 ;F5h 'ExpR_'
tLRLn			equ STATCMD+4 ;F6h 'LnR_'
tLRPwr			equ STATCMD+5 ;F7h 'PwrR_'
tMedMed			equ STATCMD+6 ;F8h
tQuad			equ STATCMD+7 ;F9h
tClrLst			equ STATCMD+8 ;FAh 'CLEAR LIST
tClrTbl			equ STATCMD+9 ;FBh CLEAR TABLE
tHist			equ STATCMD+10 ;FCh 'Hist_'
txyLine			equ STATCMD+11 ;FDh 'xyline_'
tScatter		equ STATCMD+12 ;FEh 'Scatter_'
tLR1			equ STATCMD+13 ;FFh 'LINR(AX+B

;2nd Half Of Graph Format Tokens
;----------------------------------------------
;           Format settings commands
;
GFMT			equ 0
tSeq			equ GFMT ; 'SeqG'
tSimulG			equ GFMT+1 ; 'SimulG'
tPolarG			equ GFMT+2 ; 'PolarGC'
tRectG			equ GFMT+3 ; 'RectGC'
tCoordOn		equ GFMT+4 ; 'CoordOn'
tCoordOff		equ GFMT+5 ; 'CoordOff'
tDrawLine		equ GFMT+6 ; 'DrawLine'
tDrawDot		equ GFMT+7 ; 'DrawDot'
tAxisOn			equ GFMT+8 ; 'AxesOn'
tAxisOff		equ GFMT+9 ; 'AxesOff'
tGridOn			equ GFMT+10 ; 'GridOn'
tGridOff		equ GFMT+11 ; 'GridOff'
tLblOn			equ GFMT+12 ; 'LabelOn'
tLblOff			equ GFMT+13 ; 'LabelOff'
tWebOn			equ GFMT+14 ; 'WebOn'
tWebOff			equ GFMT+15 ; 'WebOFF'
tuv			equ GFMT+16 ; U vs V
tvw			equ GFMT+17 ; V vs W
tuw			equ GFMT+18 ; U vs W

;2nd Half Of User Matrix Tokens
;-------------------------------------
tMatA			equ 00h ;MAT A
tMatB			equ 01h ;MAT B
tMatC			equ 02h ;MAT C
tMatD			equ 03h ;MAT D
tMatE			equ 04h ;MAT E
tMatF			equ 05h ;MAT F
tMatG			equ 06h ;MAT G
tMatH			equ 07h ;MAT H
tMatI			equ 08h ;MAT I
tMatJ			equ 09h ;MAT J

;2nd Half Of User List Tokens
;--------------------------------------
tL1			equ 00h ;LIST 1
tL2			equ 01h ;LIST 2
tL3			equ 02h ;LIST 3
tL4			equ 03h ;LIST 4
tL5			equ 04h ;LIST 5
tL6			equ 05h ;LIST 6

;2nd Half Of User Equation Tokens
;----------------------------------
;  "Y" EQUATIONS HAVE BIT 4 SET
;
tY1			equ 10h ;Y1
tY2			equ 11h ;Y2
tY3			equ 12h ;Y3
tY4			equ 13h ;Y4
tY5			equ 14h ;Y5
tY6			equ 15h ;Y6
tY7			equ 16h ;Y7
tY8			equ 17h ;Y8
tY9			equ 18h ;Y9
tY0			equ 19h ;Y0

;Param Equations Have Bit 5 Set
;-----------------------------------
tX1T			equ 20h ;X1t
tY1T			equ 21h ;Y1t
tX2T			equ 22h ;X2t
tY2T			equ 23h ;Y2t
tX3T			equ 24h ;X3t
tY3T			equ 25h ;Y3t
tX4T			equ 26h ;X4t
tY4T			equ 27h ;Y4t
tX5T			equ 28h ;X5t
tY5T			equ 29h ;Y5t
tX6T			equ 2Ah ;X6t
tY6T			equ 2Bh ;Y6t

;Polar Equations Have Bit 6 Set
;----------------------------------
tR1			equ 40h ;R1
tR2			equ 41h ;R2
tR3			equ 42h ;R3
tR4			equ 43h ;R4
tR5			equ 44h ;R5
tR6			equ 45h ;R6

;Recursion Equations Have Bit 7 Set
;----------------------------------
tun			equ 80h ;Un
tvn			equ 81h ;Vn
twn			equ 82h ;Wn

;2nd Half Of User Picture Tokens
;------------------------------------
tPic1			equ 00h ;PIC1
tPic2			equ 01h ;PIC2
tPic3			equ 02h ;PIC3
tPic4			equ 03h ;PIC4
tPic5			equ 04h ;PIC5
tPic6			equ 05h ;PIC6
tPic7			equ 06h ;PIC7
tPic8			equ 07h ;PIC8
tPic9			equ 08h ;PIC9
tPic0			equ 09h ;PIC0

;2nd Half Of User Graph Database Tokens
;--------------------------------------
tGDB1			equ 00h ;GDB1
tGDB2			equ 01h ;GDB2
tGDB3			equ 02h ;GDB3
tGDB4			equ 03h ;GDB4
tGDB5			equ 04h ;GDB5
tGDB6			equ 05h ;GDB6
tGDB7			equ 06h ;GDB7
tGDB8			equ 07h ;GDB8
tGDB9			equ 08h ;GDB9
tGDB0			equ 09h ;GDB0

;2nd Half Of String Vars
;------------------------------
tStr1			equ 00h
tStr2			equ 01h
tStr3			equ 02h
tStr4			equ 03h
tStr5			equ 04h
tStr6			equ 05h
tStr7			equ 06h
tStr8			equ 07h
tStr9			equ 08h
tStr0			equ 09h

;2nd Half Of System Output Only Variables
;-----------------------------------------------------------------
;OPEN			equ 00h
tRegEq			equ 01h ;REGRESSION EQUATION
tStatN			equ 02h ;STATISTICS N
tXMean			equ 03h ;X MEAN
tSumX			equ 04h ;SUM(X)
tSumXSqr		equ 05h ;SUM(X^2)
tStdX			equ 06h ;STANDARD DEV X
tStdPX			equ 07h ;STANDARD DEV POP X
tMinX			equ 08h ;Min X VALUE
tMaxX			equ 09h ;Max X VALUE
tMinY			equ 0Ah ;Min Y VALUE
tMaxY			equ 0Bh ;Max Y VALUE
tYmean			equ 0Ch ;Y MEAN
tSumY			equ 0Dh ;SUM(Y)
tSumYSqr		equ 0Eh ;SUM(Y^2)
tStdY			equ 0Fh ;STANDARD DEV Y
tStdPY			equ 10h ;STANDARD DEV POP Y
tSumXY			equ 11h ;SUM(XY)
tCorr			equ 12h ;CORRELATION
tMedX			equ 13h ;MED(X)
tQ1			equ 14h ;1ST QUADRANT OF X
tQ3			equ 15h ;3RD QUADRANT OF X
tQuadA			equ 16h ;1ST TERM OF QUAD POLY REG/ Y-INT
tQuadB			equ 17h ;2ND TERM OF QUAD POLY REG/ SLOPE
tQuadC			equ 18h ;3RD TERM OF QUAD POLY REG
tCubeD			equ 19h ;4TH TERM OF CUBIC POLY REG
tQuartE			equ 1Ah ;5TH TERM OF QUART POLY REG
tMedX1			equ 1Bh ;x1 FOR MED-MED
tMedX2			equ 1Ch ;x2 FOR MED-MED
tMedX3			equ 1Dh ;x3 FOR MED-MED
tMedY1			equ 1Eh ;y1 FOR MED-MED
tMedY2			equ 1Fh ;y2 FOR MED-MED
tMedY3			equ 20h ;y3 FOR MED-MED
tRecurn			equ 21h	;RECURSION N
tStatP			equ 22h
tStatZ			equ 23h
tStatT			equ 24h
tStatChi		equ 25h
tStatF			equ 26h
tStatDF			equ 27h
tStatPhat		equ 28h
tStatPhat1		equ 29h
tStatPhat2		equ 2Ah
tStatMeanX1		equ 2Bh
tStatStdX1		equ 2Ch
tStatN1			equ 2Dh
tStatMeanX2		equ 2Eh
tStatStdX2		equ 2Fh
tStatN2			equ 30h
tStatStdXP		equ 31h
tStatLower		equ 32h
tStatUpper		equ 33h
tStat_s			equ 34h
tLRSqr			equ 35h ;r^2
tBRSqr			equ 36h ;R^2

;These next tokens are only used to access the data
;they are display only and the user cannot access them at all
;------------------------------------------------------------
tF_DF			equ 37h ;ANOFAV FACTOR DF
tF_SS			equ 38h ;ANOFAV FACTOR SS
tF_MS			equ 39h ;ANOFAV FACTOR MS
tE_DF			equ 3Ah ;ANOFAV ERROR DF
tE_SS			equ 3Bh ;ANOFAV ERROR SS
tE_MS			equ 3Ch ;ANOFAV ERROR MS

;2nd Half Of System Input/Output Variables
;------------------------------------------------
;      SYSTEM VARIABLE EQUATES
;
tuXscl			equ 0
tuYscl			equ 1
tXscl			equ 2
tYscl			equ 3
tRecuru0		equ 4 ;U 1ST INITIAL COND
tRecurv0		equ 5 ;V 1ST INITIAL COND
tun1			equ 6 ;U(N-1); NOT USED
tvn1			equ 7 ;V(N-1); NOT USED
tuRecuru0		equ 8 ;
tuRecurv0		equ 9 ;
tXmin			equ 0Ah
tXmax			equ 0Bh
tYmin			equ 0Ch
tYmax			equ 0Dh
tTmin			equ 0Eh
tTmax			equ 0Fh
tThetaMin		equ 10h
tThetaMax		equ 11h
tuXmin			equ 12h
tuXmax			equ 13h
tuYmin			equ 14h
tuYmax			equ 15h
tuThetMin		equ 16h
tuThetMax		equ 17h
tuTmin			equ 18h
tuTmax			equ 19h
tTblMin			equ 1Ah
tPlotStart		equ 1Bh
tuPlotStart		equ 1Ch
tnMax			equ 1Dh
tunMax			equ 1Eh
tnMin			equ 1Fh
tunMin			equ 20h
tTblStep		equ 21h
tTStep			equ 22h
tThetaStep		equ 23h
tuTStep			equ 24h
tuThetStep		equ 25h
tDeltaX			equ 26h
tDeltaY			equ 27h
tXFact			equ 28h
tYFact			equ 29h
tTblInput		equ 2Ah
tFinN			equ 2Bh
tFinI			equ 2Ch
tFinPV			equ 2Dh
tFinPMT			equ 2Eh
tFinFV			equ 2Fh
tFinPY			equ 30h
tFinCY			equ 31h
tRecurw0		equ 32h ;w0(1)
tuRecurw0		equ 33h
tPlotStep		equ 34h
tuPlotStep		equ 35h
tXres			equ 36h
tuXres			equ 37h
tRecuru02		equ 38h ;u0(2)
tuRecuru02		equ 39h
tRecurv02		equ 3Ch ;v0(2)
tuRecurv02		equ 3Dh
tRecurw02		equ 3Eh ;w0(2)
tuRecurw02		equ 3Fh

;2nd Byte Of t2ByteTok Tokens
;------------------------------
tFinNPV			equ 00h
tFinIRR			equ 01h
tFinBAL			equ 02h
tFinPRN			equ 03h
tFinINT			equ 04h
tFinToNom		equ 05h
tFinToEff		equ 06h
tFinDBD			equ 07h
tLCM			equ 08h
tGCD			equ 09h
tRandInt		equ 0Ah
tRandBin		equ 0Bh
tSubStrng		equ 0Ch
tStdDev			equ 0Dh
tVariance		equ 0Eh
tInStrng		equ 0Fh
tDNormal		equ 10h
tInvNorm		equ 11h
tDT			equ 12h
tChI			equ 13h
tDF			equ 14h
tBINPDF			equ 15h
tBINCDF			equ 16h
tPOIPDF			equ 17h
tPOICDF			equ 18h
tGEOPDF			equ 19h
tGEOCDF			equ 1Ah
tNormalPDF		equ 1Bh
tTPDF			equ 1Ch
tChiPDF			equ 1Dh
tFPDF			equ 1Eh
tRandNorm		equ 1Fh
tFinFPMT		equ 20h
tFinFI			equ 21h
tFinFPV			equ 22h
tFinFN			equ 23h
tFinFFV			equ 24h
tConj			equ 25h
tReal			equ 26h
tImag			equ 27h
tAngle			equ 28h
tCumSum			equ 29h
tExpr			equ 2Ah
tLength			equ 2Bh
tDeltaLst		equ 2Ch
tRef			equ 2Dh
tRRef			equ 2Eh
tToRect			equ 2Fh
tToPolar		equ 30h
tConste			equ 31h
tSinReg			equ 32h
tLogistic		equ 33h
tLinRegTTest		equ 34h
tShadeNorm		equ 35h
tShadeT			equ 36h
tShadeChi		equ 37h
tShadeF			equ 38h
tMatToLst		equ 39h
tLstToMat		equ 3Ah
tZTest			equ 3Bh
tTTest			equ 3Ch
t2SampZTest		equ 3Dh
t1PropZTest		equ 3Eh
t2PropZTest		equ 3Fh
tChiTest		equ 40h
tZIntVal		equ 41h
t2SampZInt		equ 42h
t1PropZInt		equ 43h
t2PropZInt		equ 44h
tGraphStyle		equ 45h
t2SampTTest		equ 46h
t2SampFTest		equ 47h
tTIntVal		equ 48h
t2SampTInt		equ 49h
tSetupLst		equ 4Ah
tFinPMTend		equ 4Bh
tFinPMTbeg		equ 4Ch
tRealM			equ 4Dh
tPolarM			equ 4Eh
tRectM			equ 4Fh
tExprOn			equ 50h
tExprOff		equ 51h
tClrAllLst		equ 52h
tGetCalc		equ 53h
tDelVar			equ 54h
tEquToStrng		equ 55h
tStrngToEqu		equ 56h
tDelLast		equ 57h
tSelect			equ 58h
tANOVA			equ 59h
tModBox			equ 5Ah
tNormProb		equ 5Bh
tMGT			equ 64h ;VERTICAL SPLIT
tZFit			equ 65h ;ZOOM FIT
tDiag_on		equ 66h ;DIANOSTIC DISPLAY ON
tDiag_off		equ 67h ;DIANOSTIC DISPLAY OFF
tOkEnd2v0		equ 67h ;end of 2byte tokens for version 0.
tArchive		equ 68h ;archive
tUnarchive		equ 69h ;unarchive
tasm			equ 6Ah
tasmComp		equ 6Bh	;asm compile
tasmPrgm		equ 6Ch	;signifies a program is asm
tasmCmp			equ 6Dh	;asm program is compiled
tLcapAAcute		equ 6Eh
tLcapAGrave		equ 6Fh
tLcapACaret		equ 70h
tLcapADier		equ 71h
tLaAcute		equ 72h
tLaGrave		equ 73h
tLaCaret		equ 74h
tLaDier			equ 75h
tLcapEAcute		equ 76h
tLcapEGrave		equ 77h
tLcapECaret		equ 78h
tLcapEDier		equ 79h
tLeAcute		equ 7Ah
tLeGrave		equ 7Bh
tLeCaret		equ 7Ch
tLeDier			equ 7Dh
tLcapIGrave		equ 7Fh
tLcapICaret		equ 80h
tLcapIDier		equ 81h
tLiAcute		equ 82h
tLiGrave		equ 83h
tLiCaret		equ 84h
tLiDier			equ 85h
tLcapOAcute		equ 86h
tLcapOGrave		equ 87h
tLcapOCaret		equ 88h
tLcapODier		equ 89h
tLoAcute		equ 8Ah
tLoGrave		equ 8Bh
tLoCaret		equ 8Ch
tLoDier			equ 8Dh
tLcapUAcute		equ 8Eh
tLcapUGrave		equ 8Fh
tLcapUCaret		equ 90h
tLcapUDier		equ 91h
tLuAcute		equ 92h
tLuGrave		equ 93h
tLuCaret		equ 94h
tLuDier			equ 95h
tLcapCCed		equ 96h
tLcCed			equ 97h
tLcapNTilde		equ 98h
tLnTilde		equ 99h
tLaccent		equ 9Ah
tLgrave			equ 9Bh
tLdieresis		equ 9Ch
tLquesDown		equ 9Dh
tLexclamDown		equ 9Eh
tLalpha			equ 9Fh
tLbeta			equ 0A0h
tLgamma			equ 0A1h
tLcapDelta		equ 0A2h
tLdelta			equ 0A3h
tLepsilon		equ 0A4h
tLlambda		equ 0A5h
tLmu			equ 0A6h
tLpi			equ 0A7h
tLrho			equ 0A8h
tLcapSigma		equ 0A9h
tLphi			equ 0ABh
tLcapOmega		equ 0ACh
tLphat			equ 0ADh
tLchi			equ 0AEh
tLstatF			equ 0AFh
tLa			equ 0B0h
tLb			equ 0B1h
tLc			equ 0B2h
tLd			equ 0B3h
tLsmalle		equ 0B4h
tLf			equ 0B5h
tLsmallg		equ 0B6h
tLh			equ 0B7h
tLi			equ 0B8h
tLj			equ 0B9h
tLk			equ 0BAh
tLl			equ 0BCh
tLm			equ 0BDh
tLsmalln		equ 0BEh
tLo			equ 0BFh
tLp			equ 0C0h
tLq			equ 0C1h
tLsmallr		equ 0C2h
tLs			equ 0C3h
tLsmallt		equ 0C4h
tLu			equ 0C5h
tLv			equ 0C6h
tLw			equ 0C7h
tLx			equ 0C8h
tLy			equ 0C9h
tLz			equ 0CAh
tLsigma			equ 0CBh
tLtau			equ 0CCh
tLcapIAcute		equ 0CDh
tGarbagec		equ 0CEh
LastToken		equ 0CEh ;tLAST TOKEN IN THIS VERSION...

;Data Type Equates                                                    
;---------------------------------------------------------------------
RealObj			equ 0
ListObj			equ 1
MatObj			equ 2
EquObj			equ 3
StrngObj		equ 4
ProgObj			equ 5
ProtProgObj		equ 6
PictObj			equ 7
GDBObj			equ 8
UnknownObj		equ 9
UnknownEquObj		equ 0Ah
NewEquObj		equ 0Bh
CplxObj			equ 0Ch
CListObj		equ 0Dh
UndefObj		equ 0Eh
WindowObj		equ 0Fh
ZStoObj			equ 10h
TblRngObj		equ 11h
LCDObj			equ 12h
BackupObj		equ 13h
AppObj			equ 14h	;application, only used in menus/link
AppVarObj		equ 15h	;application variable
TempProgObj		equ 16h ;program, home deletes when finished
GroupObj		equ 17h ;group.

;I/O Equates                                                          
;---------------------------------------------------
D0D1_bits		equ 03h
D0LD1L			equ 03h
D0LD1H			equ 01h
D0HD1L			equ 02h
D0HD1H			equ 00h
bport			equ 0 ;4-bit link port (I/O) 

;Device Codes
;-----------------------------------------------------------------
TI82DEV			equ 82h
PC82DEV			equ 02h
MAC82DEV		equ 12h
TI83FDEV		equ 73h
LINK83FDEV		equ 23h
TI83DEV			equ 83h
PC83DEV			equ 03h
MAC83DEV		equ 13h
TI85DEV			equ 95h ;different than real 85 so me talk
PC85DEV			equ 05h
MAC85DEV		equ 15h
TI73DEV			equ 74h ;device x3 is always an 83
PC73DEV			equ 07h
MAC73DEV		equ 17h
LINK73FDEV		equ 23h
PC83FDEV		equ 23h

;System Error Codes                                                  
;-----------------------------------------------------------
E_EDITF			equ 7 ;allow re-entering application
E_EDIT			equ 1<<E_EDITF
E_Mask			equ 7Fh
E_Overflow		equ 1+E_EDIT
E_DivBy0		equ 2+E_EDIT
E_SingularMat		equ 3+E_EDIT
E_Domain		equ 4+E_EDIT
E_Increment		equ 5+E_EDIT
E_Break			equ 6+E_EDIT
E_NonReal		equ 7+E_EDIT
E_Syntax		equ 8+E_EDIT
E_DataType		equ 9+E_EDIT
E_Argument		equ 10+E_EDIT
E_DimMismatch		equ 11+E_EDIT
E_Dimension		equ 12+E_EDIT
E_Undefined		equ 13+E_EDIT
E_Memory		equ 14+E_EDIT
E_Invalid		equ 15+E_EDIT
E_IllegalNest		equ 16+E_EDIT
E_Bound			equ 17+E_EDIT
E_GraphRange		equ 18+E_EDIT
E_Zoom			equ 19+E_EDIT
E_Label			equ 20
E_Stat			equ 21
E_Solver		equ 22+E_EDIT
E_Singularity		equ 23+E_EDIT
E_SignChange		equ 24+E_EDIT
E_Iterations		equ 25+E_EDIT
E_BadGuess		equ 26+E_EDIT
E_StatPlo		equ 27
E_TolTooSmall		equ 28+E_EDIT
E_Reserved		equ 29+E_EDIT
E_Mode			equ 30+E_EDIT
E_LnkErr		equ 31+E_EDIT
E_LnkMemErr		equ 32+E_EDIT
E_LnkTransErr		equ 33+E_EDIT
E_LnkDupErr		equ 34+E_EDIT
E_LnkMemFull		equ 35+E_EDIT
E_Unknown		equ 36+E_EDIT
E_Scale			equ 37+E_EDIT
E_IdNotFound		equ 38
E_NoMode		equ 39+E_EDIT
E_Validation		equ 40
E_Length		equ 41+E_EDIT
E_Application		equ 42+E_EDIT
E_AppErr1		equ 43+E_EDIT
E_AppErr2		equ 44+E_EDIT
E_ExpiredApp		equ 45
E_BadAdd		equ 46
E_Archived		equ 47+E_EDIT
E_Version		equ 48
E_ArchFull		equ 49
E_Variable		equ 50+E_EDIT
E_Duplicate		equ 51+E_EDIT
HigErrNum		equ 51
;Obsolete error numbers 34 ;first LINK error
E_LinkIOChkSum		equ 34
E_LinkIOTimeOut		equ 35
E_LinkIOBusy		equ 36
E_LinkIOVer		equ 37

;Equates To RAM Locations For Stat Vars
;----------------------------------------------------------------
FPLEN			equ 9 ;Length of a floating-point number.
StatN			equ statVars
XMean			equ StatN + FPLEN
SumX			equ XMean + FPLEN
SumXSqr			equ SumX + FPLEN
StdX			equ SumXSqr + FPLEN
StdPX			equ StdX + FPLEN
MinX			equ StdPX + FPLEN
MaxX			equ MinX + FPLEN
MinY			equ MaxX + FPLEN
MaxY			equ MinY + FPLEN
YMean			equ MaxY + FPLEN
SumY			equ YMean + FPLEN
SumYSqr			equ SumY + FPLEN
StdY			equ SumYSqr + FPLEN
StdPY			equ StdY + FPLEN
SumXY			equ StdPY + FPLEN
Corr			equ SumXY + FPLEN
MedX			equ Corr + FPLEN
Q1			equ MedX + FPLEN
Q3			equ Q1 + FPLEN
QuadA			equ Q3 + FPLEN
QuadB			equ QuadA + FPLEN
QuadC			equ QuadB + FPLEN
CubeD			equ QuadC + FPLEN
QuartE			equ CubeD + FPLEN
MedX1			equ QuartE + FPLEN
MedX2			equ MedX1 + FPLEN
MedX3			equ MedX2 + FPLEN
MedY1			equ MedX3 + FPLEN
MedY2			equ MedY1 + FPLEN
MedY3			equ MedY2 + FPLEN
PStat			equ MedY3 + 2*FPLEN
ZStat			equ PStat + FPLEN
TStat			equ ZStat + FPLEN
ChiStat			equ TStat + FPLEN
FStat			equ ChiStat + FPLEN
DF			equ FStat + FPLEN
Phat			equ DF + FPLEN
Phat1			equ Phat + FPLEN
Phat2			equ Phat1 + FPLEN
MeanX1			equ Phat2 + FPLEN
StdX1			equ MeanX1 + FPLEN
StatN1			equ StdX1 + FPLEN
MeanX2			equ StatN1 + FPLEN
StdX2			equ MeanX2 + FPLEN
StatN2			equ StdX2 + FPLEN
StdXP2			equ StatN2 + FPLEN
SLower			equ StdXP2 + FPLEN
SUpper			equ SLower + FPLEN
SStat			equ SUpper + FPLEN
F_DF			equ anovaf_vars
F_SS			equ F_DF + FPLEN
F_MS			equ F_SS + FPLEN
E_DF			equ F_MS + FPLEN
E_SS			equ E_DF + FPLEN
E_MS			equ E_SS + FPLEN