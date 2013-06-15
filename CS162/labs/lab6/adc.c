   1               		.file	"adc.c"
   2               	__SREG__ = 0x3f
   3               	__SP_H__ = 0x3e
   4               	__SP_L__ = 0x3d
   5               	__CCP__  = 0x34
   6               	__tmp_reg__ = 0
   7               	__zero_reg__ = 1
  15               	.Ltext0:
  16               		.section	.text.ADC_set_channel,"ax",@progbits
  17               	.global	ADC_set_channel
  19               	ADC_set_channel:
  20               	.LFB2:
  21               	.LSM0:
  22               	.LVL0:
  23               	/* prologue: function */
  24               	/* frame size = 0 */
  25               	.LSM1:
  26 0000 ECE7      		ldi r30,lo8(124)
  27 0002 F0E0      		ldi r31,hi8(124)
  28 0004 9081      		ld r25,Z
  29 0006 907E      		andi r25,lo8(-32)
  30 0008 9083      		st Z,r25
  31               	.LSM2:
  32 000a 9081      		ld r25,Z
  33 000c 8F71      		andi r24,lo8(31)
  34               	.LVL1:
  35 000e 892B      		or r24,r25
  36 0010 8083      		st Z,r24
  37               	/* epilogue start */
  38               	.LSM3:
  39 0012 0895      		ret
  40               	.LFE2:
  42               		.section	.text.ADC_set_adjust,"ax",@progbits
  43               	.global	ADC_set_adjust
  45               	ADC_set_adjust:
  46               	.LFB3:
  47               	.LSM4:
  48               	.LVL2:
  49               	/* prologue: function */
  50               	/* frame size = 0 */
  51               	.LSM5:
  52 0000 8130      		cpi r24,lo8(1)
  53 0002 01F4      		brne .L4
  54               	.LSM6:
  55 0004 8091 7C00 		lds r24,124
  56               	.LVL3:
  57 0008 8062      		ori r24,lo8(32)
  58 000a 00C0      		rjmp .L7
  59               	.LVL4:
  60               	.L4:
  61               	.LSM7:
  62 000c 8091 7C00 		lds r24,124
  63               	.LVL5:
  64 0010 8F7D      		andi r24,lo8(-33)
  65               	.L7:
  66 0012 8093 7C00 		sts 124,r24
  67 0016 0895      		ret
  68               	.LFE3:
  70               		.section	.text.ADC_set_prescaler,"ax",@progbits
  71               	.global	ADC_set_prescaler
  73               	ADC_set_prescaler:
  74               	.LFB4:
  75               	.LSM8:
  76               	.LVL6:
  77               	/* prologue: function */
  78               	/* frame size = 0 */
  79               	.LSM9:
  80 0000 EAE7      		ldi r30,lo8(122)
  81 0002 F0E0      		ldi r31,hi8(122)
  82 0004 9081      		ld r25,Z
  83 0006 987F      		andi r25,lo8(-8)
  84 0008 9083      		st Z,r25
  85               	.LSM10:
  86 000a 9081      		ld r25,Z
  87 000c 8770      		andi r24,lo8(7)
  88               	.LVL7:
  89 000e 892B      		or r24,r25
  90 0010 8083      		st Z,r24
  91               	/* epilogue start */
  92               	.LSM11:
  93 0012 0895      		ret
  94               	.LFE4:
  96               		.section	.text.ADC_set_free_running,"ax",@progbits
  97               	.global	ADC_set_free_running
  99               	ADC_set_free_running:
 100               	.LFB5:
 101               	.LSM12:
 102               	.LVL8:
 103               	/* prologue: function */
 104               	/* frame size = 0 */
 105               	.LSM13:
 106 0000 8823      		tst r24
 107 0002 01F0      		breq .L11
 108               	.LSM14:
 109 0004 8091 7B00 		lds r24,123
 110               	.LVL9:
 111 0008 8B7F      		andi r24,lo8(-5)
 112 000a 8093 7B00 		sts 123,r24
 113               	.LSM15:
 114 000e 8091 7B00 		lds r24,123
 115 0012 8D7F      		andi r24,lo8(-3)
 116 0014 8093 7B00 		sts 123,r24
 117               	.LSM16:
 118 0018 8091 7B00 		lds r24,123
 119 001c 8E7F      		andi r24,lo8(-2)
 120 001e 8093 7B00 		sts 123,r24
 121               	.LSM17:
 122 0022 8091 7A00 		lds r24,122
 123 0026 8062      		ori r24,lo8(32)
 124 0028 00C0      		rjmp .L14
 125               	.LVL10:
 126               	.L11:
 127               	.LSM18:
 128 002a 8091 7A00 		lds r24,122
 129               	.LVL11:
 130 002e 8F7D      		andi r24,lo8(-33)
 131               	.L14:
 132 0030 8093 7A00 		sts 122,r24
 133 0034 0895      		ret
 134               	.LFE5:
 136               		.section	.text.ADC_set_reference,"ax",@progbits
 137               	.global	ADC_set_reference
 139               	ADC_set_reference:
 140               	.LFB6:
 141               	.LSM19:
 142               	.LVL12:
 143               	/* prologue: function */
 144               	/* frame size = 0 */
 145               	.LSM20:
 146 0000 9091 7C00 		lds r25,124
 147 0004 9F73      		andi r25,lo8(63)
 148 0006 9093 7C00 		sts 124,r25
 149               	.LSM21:
 150 000a 9091 7C00 		lds r25,124
 151 000e 807C      		andi r24,lo8(-64)
 152               	.LVL13:
 153 0010 892B      		or r24,r25
 154 0012 8093 7C00 		sts 124,r24
 155               	.LBB32:
 156               	.LBB33:
 157               	.LSM22:
 158 0016 8091 7A00 		lds r24,122
 159 001a 8064      		ori r24,lo8(64)
 160 001c 8093 7A00 		sts 122,r24
 161               	.L16:
 162               	.LBE33:
 163               	.LBE32:
 164               	.LBB34:
 165               	.LBB35:
 166               	.LSM23:
 167 0020 8091 7A00 		lds r24,122
 168               	.LBE35:
 169               	.LBE34:
 170               	.LSM24:
 171 0024 84FF      		sbrs r24,4
 172 0026 00C0      		rjmp .L16
 173               	.LBB36:
 174               	.LBB37:
 175               	.LSM25:
 176 0028 8091 7A00 		lds r24,122
 177 002c 8061      		ori r24,lo8(16)
 178 002e 8093 7A00 		sts 122,r24
 179               	/* epilogue start */
 180               	.LBE37:
 181               	.LBE36:
 182               	.LSM26:
 183 0032 0895      		ret
 184               	.LFE6:
 186               		.section	.text.ADC_enable_interrupt,"ax",@progbits
 187               	.global	ADC_enable_interrupt
 189               	ADC_enable_interrupt:
 190               	.LFB7:
 191               	.LSM27:
 192               	/* prologue: function */
 193               	/* frame size = 0 */
 194               	.LSM28:
 195 0000 EAE7      		ldi r30,lo8(122)
 196 0002 F0E0      		ldi r31,hi8(122)
 197 0004 8081      		ld r24,Z
 198 0006 8860      		ori r24,lo8(8)
 199 0008 8083      		st Z,r24
 200               	/* epilogue start */
 201               	.LSM29:
 202 000a 0895      		ret
 203               	.LFE7:
 205               		.section	.text.ADC_disable_interrupt,"ax",@progbits
 206               	.global	ADC_disable_interrupt
 208               	ADC_disable_interrupt:
 209               	.LFB8:
 210               	.LSM30:
 211               	/* prologue: function */
 212               	/* frame size = 0 */
 213               	.LSM31:
 214 0000 EAE7      		ldi r30,lo8(122)
 215 0002 F0E0      		ldi r31,hi8(122)
 216 0004 8081      		ld r24,Z
 217 0006 877F      		andi r24,lo8(-9)
 218 0008 8083      		st Z,r24
 219               	/* epilogue start */
 220               	.LSM32:
 221 000a 0895      		ret
 222               	.LFE8:
 224               		.section	.text.ADC_enable,"ax",@progbits
 225               	.global	ADC_enable
 227               	ADC_enable:
 228               	.LFB9:
 229               	.LSM33:
 230               	/* prologue: function */
 231               	/* frame size = 0 */
 232               	.LSM34:
 233 0000 EAE7      		ldi r30,lo8(122)
 234 0002 F0E0      		ldi r31,hi8(122)
 235 0004 8081      		ld r24,Z
 236 0006 8068      		ori r24,lo8(-128)
 237 0008 8083      		st Z,r24
 238               	/* epilogue start */
 239               	.LSM35:
 240 000a 0895      		ret
 241               	.LFE9:
 243               		.section	.text.ADC_disable,"ax",@progbits
 244               	.global	ADC_disable
 246               	ADC_disable:
 247               	.LFB10:
 248               	.LSM36:
 249               	/* prologue: function */
 250               	/* frame size = 0 */
 251               	.LSM37:
 252 0000 EAE7      		ldi r30,lo8(122)
 253 0002 F0E0      		ldi r31,hi8(122)
 254 0004 8081      		ld r24,Z
 255 0006 8F77      		andi r24,lo8(127)
 256 0008 8083      		st Z,r24
 257               	/* epilogue start */
 258               	.LSM38:
 259 000a 0895      		ret
 260               	.LFE10:
 262               		.section	.text.ADC_start,"ax",@progbits
 263               	.global	ADC_start
 265               	ADC_start:
 266               	.LFB11:
 267               	.LSM39:
 268               	/* prologue: function */
 269               	/* frame size = 0 */
 270               	.LSM40:
 271 0000 EAE7      		ldi r30,lo8(122)
 272 0002 F0E0      		ldi r31,hi8(122)
 273 0004 8081      		ld r24,Z
 274 0006 8064      		ori r24,lo8(64)
 275 0008 8083      		st Z,r24
 276               	/* epilogue start */
 277               	.LSM41:
 278 000a 0895      		ret
 279               	.LFE11:
 281               		.section	.text.ADC_finish,"ax",@progbits
 282               	.global	ADC_finish
 284               	ADC_finish:
 285               	.LFB12:
 286               	.LSM42:
 287               	/* prologue: function */
 288               	/* frame size = 0 */
 289               	.LSM43:
 290 0000 EAE7      		ldi r30,lo8(122)
 291 0002 F0E0      		ldi r31,hi8(122)
 292 0004 8081      		ld r24,Z
 293 0006 8061      		ori r24,lo8(16)
 294 0008 8083      		st Z,r24
 295               	/* epilogue start */
 296               	.LSM44:
 297 000a 0895      		ret
 298               	.LFE12:
 300               		.section	.text.ADC_done,"ax",@progbits
 301               	.global	ADC_done
 303               	ADC_done:
 304               	.LFB13:
 305               	.LSM45:
 306               	/* prologue: function */
 307               	/* frame size = 0 */
 308               	.LSM46:
 309 0000 8091 7A00 		lds r24,122
 310 0004 90E0      		ldi r25,lo8(0)
 311 0006 24E0      		ldi r18,4
 312 0008 9695      	1:	lsr r25
 313 000a 8795      		ror r24
 314 000c 2A95      		dec r18
 315 000e 01F4      		brne 1b
 316               	.LSM47:
 317 0010 8170      		andi r24,lo8(1)
 318               	/* epilogue start */
 319 0012 0895      		ret
 320               	.LFE13:
 322               		.section	.text.setup_ADC,"ax",@progbits
 323               	.global	setup_ADC
 325               	setup_ADC:
 326               	.LFB14:
 327               	.LSM48:
 328               	.LVL14:
 329               	/* prologue: function */
 330               	/* frame size = 0 */
 331               	.LBB38:
 332               	.LBB39:
 333               	.LSM49:
 334 0000 9091 7A00 		lds r25,122
 335 0004 987F      		andi r25,lo8(-8)
 336 0006 9093 7A00 		sts 122,r25
 337               	.LSM50:
 338 000a 9091 7A00 		lds r25,122
 339 000e 8770      		andi r24,lo8(7)
 340               	.LVL15:
 341 0010 892B      		or r24,r25
 342 0012 8093 7A00 		sts 122,r24
 343               	.LBE39:
 344               	.LBE38:
 345               	.LBB40:
 346               	.LBB41:
 347               	.LSM51:
 348 0016 6623      		tst r22
 349 0018 01F0      		breq .L34
 350               	.LSM52:
 351 001a 8091 7B00 		lds r24,123
 352 001e 8B7F      		andi r24,lo8(-5)
 353 0020 8093 7B00 		sts 123,r24
 354               	.LSM53:
 355 0024 8091 7B00 		lds r24,123
 356 0028 8D7F      		andi r24,lo8(-3)
 357 002a 8093 7B00 		sts 123,r24
 358               	.LSM54:
 359 002e 8091 7B00 		lds r24,123
 360 0032 8E7F      		andi r24,lo8(-2)
 361 0034 8093 7B00 		sts 123,r24
 362               	.LSM55:
 363 0038 8091 7A00 		lds r24,122
 364 003c 8062      		ori r24,lo8(32)
 365 003e 00C0      		rjmp .L37
 366               	.L34:
 367               	.LSM56:
 368 0040 8091 7A00 		lds r24,122
 369 0044 8F7D      		andi r24,lo8(-33)
 370               	.L37:
 371 0046 8093 7A00 		sts 122,r24
 372 004a 0895      		ret
 373               	.LBE41:
 374               	.LBE40:
 375               	.LFE14:
 377               		.section	.text.read_ADC,"ax",@progbits
 378               	.global	read_ADC
 380               	read_ADC:
 381               	.LFB15:
 382               	.LSM57:
 383               	.LVL16:
 384               	/* prologue: function */
 385               	/* frame size = 0 */
 386               	.LBB42:
 387               	.LBB43:
 388               	.LSM58:
 389 0000 9091 7C00 		lds r25,124
 390 0004 907E      		andi r25,lo8(-32)
 391 0006 9093 7C00 		sts 124,r25
 392               	.LSM59:
 393 000a 9091 7C00 		lds r25,124
 394 000e 8F71      		andi r24,lo8(31)
 395               	.LVL17:
 396 0010 892B      		or r24,r25
 397 0012 8093 7C00 		sts 124,r24
 398               	.LBE43:
 399               	.LBE42:
 400               	.LBB44:
 401               	.LBB45:
 402               	.LSM60:
 403 0016 8091 7C00 		lds r24,124
 404 001a 8F7D      		andi r24,lo8(-33)
 405 001c 8093 7C00 		sts 124,r24
 406               	.LBE45:
 407               	.LBE44:
 408               	.LBB46:
 409               	.LBB47:
 410               	.LSM61:
 411 0020 8091 7A00 		lds r24,122
 412 0024 8064      		ori r24,lo8(64)
 413 0026 8093 7A00 		sts 122,r24
 414               	.L39:
 415               	.LBE47:
 416               	.LBE46:
 417               	.LBB48:
 418               	.LBB49:
 419               	.LSM62:
 420 002a 8091 7A00 		lds r24,122
 421               	.LBE49:
 422               	.LBE48:
 423               	.LSM63:
 424 002e 84FF      		sbrs r24,4
 425 0030 00C0      		rjmp .L39
 426               	.LBB50:
 427               	.LBB51:
 428               	.LSM64:
 429 0032 8091 7A00 		lds r24,122
 430 0036 8061      		ori r24,lo8(16)
 431 0038 8093 7A00 		sts 122,r24
 432               	.LBE51:
 433               	.LBE50:
 434               	.LSM65:
 435 003c 8091 7800 		lds r24,120
 436               	.LVL18:
 437               	.LSM66:
 438 0040 9091 7900 		lds r25,121
 439               	.LVL19:
 440               	.LVL20:
 441               	/* epilogue start */
 442               	.LSM67:
 443 0044 0895      		ret
 444               	.LFE15:
 446               		.section	.text.read_ADC_averaged,"ax",@progbits
 447               	.global	read_ADC_averaged
 449               	read_ADC_averaged:
 450               	.LFB16:
 451               	.LSM68:
 452               	.LVL21:
 453 0000 FF92      		push r15
 454 0002 0F93      		push r16
 455 0004 1F93      		push r17
 456 0006 CF93      		push r28
 457 0008 DF93      		push r29
 458               	/* prologue: function */
 459               	/* frame size = 0 */
 460 000a F82E      		mov r15,r24
 461 000c 062F      		mov r16,r22
 462               	.LSM69:
 463 000e 10E0      		ldi r17,lo8(0)
 464               	.LVL22:
 465 0010 C0E0      		ldi r28,lo8(0)
 466 0012 D0E0      		ldi r29,hi8(0)
 467               	.LVL23:
 468 0014 00C0      		rjmp .L43
 469               	.LVL24:
 470               	.L44:
 471               	.LSM70:
 472 0016 8F2D      		mov r24,r15
 473 0018 00D0      		rcall read_ADC
 474 001a C80F      		add r28,r24
 475 001c D11D      		adc r29,__zero_reg__
 476               	.LSM71:
 477 001e 1F5F      		subi r17,lo8(-(1))
 478               	.LVL25:
 479               	.L43:
 480 0020 1017      		cp r17,r16
 481 0022 00F0      		brlo .L44
 482 0024 8C2F      		mov r24,r28
 483 0026 9D2F      		mov r25,r29
 484 0028 602F      		mov r22,r16
 485 002a 70E0      		ldi r23,lo8(0)
 486 002c 00D0      		rcall __udivmodhi4
 487 002e 862F      		mov r24,r22
 488               	/* epilogue start */
 489               	.LSM72:
 490 0030 DF91      		pop r29
 491 0032 CF91      		pop r28
 492               	.LVL26:
 493 0034 1F91      		pop r17
 494               	.LVL27:
 495 0036 0F91      		pop r16
 496               	.LVL28:
 497 0038 FF90      		pop r15
 498               	.LVL29:
 499 003a 0895      		ret
 500               	.LFE16:
 502               		.section	.text.read_precise_ADC,"ax",@progbits
 503               	.global	read_precise_ADC
 505               	read_precise_ADC:
 506               	.LFB17:
 507               	.LSM73:
 508               	.LVL30:
 509               	/* prologue: function */
 510               	/* frame size = 0 */
 511               	.LBB52:
 512               	.LBB53:
 513               	.LSM74:
 514 0000 9091 7C00 		lds r25,124
 515 0004 907E      		andi r25,lo8(-32)
 516 0006 9093 7C00 		sts 124,r25
 517               	.LSM75:
 518 000a 9091 7C00 		lds r25,124
 519 000e 8F71      		andi r24,lo8(31)
 520               	.LVL31:
 521 0010 892B      		or r24,r25
 522 0012 8093 7C00 		sts 124,r24
 523               	.LBE53:
 524               	.LBE52:
 525               	.LBB54:
 526               	.LBB55:
 527               	.LSM76:
 528 0016 8091 7C00 		lds r24,124
 529 001a 8F7D      		andi r24,lo8(-33)
 530 001c 8093 7C00 		sts 124,r24
 531               	.LBE55:
 532               	.LBE54:
 533               	.LBB56:
 534               	.LBB57:
 535               	.LSM77:
 536 0020 8091 7A00 		lds r24,122
 537 0024 8064      		ori r24,lo8(64)
 538 0026 8093 7A00 		sts 122,r24
 539               	.L47:
 540               	.LBE57:
 541               	.LBE56:
 542               	.LBB58:
 543               	.LBB59:
 544               	.LSM78:
 545 002a 8091 7A00 		lds r24,122
 546               	.LBE59:
 547               	.LBE58:
 548               	.LSM79:
 549 002e 84FF      		sbrs r24,4
 550 0030 00C0      		rjmp .L47
 551               	.LBB60:
 552               	.LBB61:
 553               	.LSM80:
 554 0032 8091 7A00 		lds r24,122
 555 0036 8061      		ori r24,lo8(16)
 556 0038 8093 7A00 		sts 122,r24
 557               	.LBE61:
 558               	.LBE60:
 559               	.LSM81:
 560 003c 2091 7800 		lds r18,120
 561 0040 3091 7900 		lds r19,(120)+1
 562               	.LSM82:
 563 0044 822F      		mov r24,r18
 564 0046 932F      		mov r25,r19
 565               	/* epilogue start */
 566 0048 0895      		ret
 567               	.LFE17:
 569               		.section	.text.read_precise_ADC_averaged,"ax",@progbits
 570               	.global	read_precise_ADC_averaged
 572               	read_precise_ADC_averaged:
 573               	.LFB18:
 574               	.LSM83:
 575               	.LVL32:
 576 0000 FF92      		push r15
 577 0002 0F93      		push r16
 578 0004 1F93      		push r17
 579 0006 CF93      		push r28
 580 0008 DF93      		push r29
 581               	/* prologue: function */
 582               	/* frame size = 0 */
 583 000a F82E      		mov r15,r24
 584 000c 062F      		mov r16,r22
 585               	.LSM84:
 586 000e 10E0      		ldi r17,lo8(0)
 587               	.LVL33:
 588 0010 C0E0      		ldi r28,lo8(0)
 589 0012 D0E0      		ldi r29,hi8(0)
 590               	.LVL34:
 591 0014 00C0      		rjmp .L51
 592               	.LVL35:
 593               	.L52:
 594               	.LSM85:
 595 0016 8F2D      		mov r24,r15
 596 0018 00D0      		rcall read_precise_ADC
 597 001a C80F      		add r28,r24
 598 001c D91F      		adc r29,r25
 599               	.LSM86:
 600 001e 1F5F      		subi r17,lo8(-(1))
 601               	.LVL36:
 602               	.L51:
 603 0020 1017      		cp r17,r16
 604 0022 00F0      		brlo .L52
 605 0024 8C2F      		mov r24,r28
 606 0026 9D2F      		mov r25,r29
 607 0028 602F      		mov r22,r16
 608 002a 70E0      		ldi r23,lo8(0)
 609 002c 00D0      		rcall __udivmodhi4
 610 002e 862F      		mov r24,r22
 611 0030 972F      		mov r25,r23
 612               	/* epilogue start */
 613               	.LSM87:
 614 0032 DF91      		pop r29
 615 0034 CF91      		pop r28
 616               	.LVL37:
 617 0036 1F91      		pop r17
 618               	.LVL38:
 619 0038 0F91      		pop r16
 620               	.LVL39:
 621 003a FF90      		pop r15
 622               	.LVL40:
 623 003c 0895      		ret
 624               	.LFE18:
 778               	.Letext0:
DEFINED SYMBOLS
                            *ABS*:00000000 adc.c
C:\Users\Kamal\AppData\Local\Temp/cchVFRgp.s:2      *ABS*:0000003f __SREG__
C:\Users\Kamal\AppData\Local\Temp/cchVFRgp.s:3      *ABS*:0000003e __SP_H__
C:\Users\Kamal\AppData\Local\Temp/cchVFRgp.s:4      *ABS*:0000003d __SP_L__
C:\Users\Kamal\AppData\Local\Temp/cchVFRgp.s:5      *ABS*:00000034 __CCP__
C:\Users\Kamal\AppData\Local\Temp/cchVFRgp.s:6      *ABS*:00000000 __tmp_reg__
C:\Users\Kamal\AppData\Local\Temp/cchVFRgp.s:7      *ABS*:00000001 __zero_reg__
C:\Users\Kamal\AppData\Local\Temp/cchVFRgp.s:19     .text.ADC_set_channel:00000000 ADC_set_channel
C:\Users\Kamal\AppData\Local\Temp/cchVFRgp.s:45     .text.ADC_set_adjust:00000000 ADC_set_adjust
C:\Users\Kamal\AppData\Local\Temp/cchVFRgp.s:73     .text.ADC_set_prescaler:00000000 ADC_set_prescaler
C:\Users\Kamal\AppData\Local\Temp/cchVFRgp.s:99     .text.ADC_set_free_running:00000000 ADC_set_free_running
C:\Users\Kamal\AppData\Local\Temp/cchVFRgp.s:139    .text.ADC_set_reference:00000000 ADC_set_reference
C:\Users\Kamal\AppData\Local\Temp/cchVFRgp.s:189    .text.ADC_enable_interrupt:00000000 ADC_enable_interrupt
C:\Users\Kamal\AppData\Local\Temp/cchVFRgp.s:208    .text.ADC_disable_interrupt:00000000 ADC_disable_interrupt
C:\Users\Kamal\AppData\Local\Temp/cchVFRgp.s:227    .text.ADC_enable:00000000 ADC_enable
C:\Users\Kamal\AppData\Local\Temp/cchVFRgp.s:246    .text.ADC_disable:00000000 ADC_disable
C:\Users\Kamal\AppData\Local\Temp/cchVFRgp.s:265    .text.ADC_start:00000000 ADC_start
C:\Users\Kamal\AppData\Local\Temp/cchVFRgp.s:284    .text.ADC_finish:00000000 ADC_finish
C:\Users\Kamal\AppData\Local\Temp/cchVFRgp.s:303    .text.ADC_done:00000000 ADC_done
C:\Users\Kamal\AppData\Local\Temp/cchVFRgp.s:325    .text.setup_ADC:00000000 setup_ADC
C:\Users\Kamal\AppData\Local\Temp/cchVFRgp.s:380    .text.read_ADC:00000000 read_ADC
C:\Users\Kamal\AppData\Local\Temp/cchVFRgp.s:449    .text.read_ADC_averaged:00000000 read_ADC_averaged
C:\Users\Kamal\AppData\Local\Temp/cchVFRgp.s:505    .text.read_precise_ADC:00000000 read_precise_ADC
C:\Users\Kamal\AppData\Local\Temp/cchVFRgp.s:572    .text.read_precise_ADC_averaged:00000000 read_precise_ADC_averaged

UNDEFINED SYMBOLS
__udivmodhi4
