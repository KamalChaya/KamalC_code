   1               		.file	"diskio.c"
   2               	__SREG__ = 0x3f
   3               	__SP_H__ = 0x3e
   4               	__SP_L__ = 0x3d
   5               	__CCP__  = 0x34
   6               	__tmp_reg__ = 0
   7               	__zero_reg__ = 1
  15               	.Ltext0:
  16               		.section	.text.select,"ax",@progbits
  18               	select:
  19               	.LFB5:
  20               	.LSM0:
  21               	/* prologue: function */
  22               	/* frame size = 0 */
  23               	.LSM1:
  24 0000 2898      		cbi 37-32,0
  25               	.LBB78:
  26               	.LBB79:
  27               	.LSM2:
  28 0002 82E3      		ldi r24,lo8(50)
  29 0004 8093 0000 		sts Timer2,r24
  30               	.LBB80:
  31               	.LBB81:
  32               	.LSM3:
  33               	/* #APP */
  34               	 ;  78 "diskio.c" 1
  35 0008 F894      		cli
  36               	 ;  0 "" 2
  37               	.LSM4:
  38               	/* #NOAPP */
  39 000a 8FEF      		ldi r24,lo8(-1)
  40 000c 8EBD      		out 78-32,r24
  41               	.L2:
  42               	.LSM5:
  43 000e 0DB4      		in __tmp_reg__,77-32
  44 0010 07FE      		sbrs __tmp_reg__,7
  45 0012 00C0      		rjmp .L2
  46               	.LSM6:
  47               	/* #APP */
  48               	 ;  81 "diskio.c" 1
  49 0014 7894      		sei
  50               	 ;  0 "" 2
  51               	.LSM7:
  52               	/* #NOAPP */
  53 0016 8EB5      		in r24,78-32
  54               	.LBE81:
  55               	.LBE80:
  56               	.LBB82:
  57               	.LBB83:
  58               	.LSM8:
  59 0018 9FEF      		ldi r25,lo8(-1)
  60               	.L6:
  61               	.LSM9:
  62               	/* #APP */
  63               	 ;  78 "diskio.c" 1
  64 001a F894      		cli
  65               	 ;  0 "" 2
  66               	.LSM10:
  67               	/* #NOAPP */
  68 001c 9EBD      		out 78-32,r25
  69               	.L3:
  70               	.LSM11:
  71 001e 0DB4      		in __tmp_reg__,77-32
  72 0020 07FE      		sbrs __tmp_reg__,7
  73 0022 00C0      		rjmp .L3
  74               	.LSM12:
  75               	/* #APP */
  76               	 ;  81 "diskio.c" 1
  77 0024 7894      		sei
  78               	 ;  0 "" 2
  79               	.LSM13:
  80               	/* #NOAPP */
  81 0026 8EB5      		in r24,78-32
  82               	.LBE83:
  83               	.LBE82:
  84               	.LSM14:
  85 0028 8F3F      		cpi r24,lo8(-1)
  86 002a 01F4      		brne .L4
  87 002c 21E0      		ldi r18,lo8(1)
  88 002e 30E0      		ldi r19,hi8(1)
  89 0030 00C0      		rjmp .L5
  90               	.L4:
  91               	.LSM15:
  92 0032 8091 0000 		lds r24,Timer2
  93 0036 8823      		tst r24
  94 0038 01F4      		brne .L6
  95 003a 00C0      		rjmp .L15
  96               	.L8:
  97               	.LBE79:
  98               	.LBE78:
  99               	.LBB84:
 100               	.LBB85:
 101               	.LBB86:
 102               	.LBB87:
 103               	.LSM16:
 104 003c 0DB4      		in __tmp_reg__,77-32
 105 003e 07FE      		sbrs __tmp_reg__,7
 106 0040 00C0      		rjmp .L8
 107               	.LSM17:
 108               	/* #APP */
 109               	 ;  81 "diskio.c" 1
 110 0042 7894      		sei
 111               	 ;  0 "" 2
 112               	.LSM18:
 113               	/* #NOAPP */
 114 0044 8EB5      		in r24,78-32
 115 0046 20E0      		ldi r18,lo8(0)
 116 0048 30E0      		ldi r19,hi8(0)
 117               	.L5:
 118               	.LBE87:
 119               	.LBE86:
 120               	.LBE85:
 121               	.LBE84:
 122               	.LSM19:
 123 004a 822F      		mov r24,r18
 124 004c 932F      		mov r25,r19
 125               	/* epilogue start */
 126 004e 0895      		ret
 127               	.L15:
 128               	.LBB91:
 129               	.LBB90:
 130               	.LSM20:
 131 0050 289A      		sbi 37-32,0
 132               	.LBB89:
 133               	.LBB88:
 134               	.LSM21:
 135               	/* #APP */
 136               	 ;  78 "diskio.c" 1
 137 0052 F894      		cli
 138               	 ;  0 "" 2
 139               	.LSM22:
 140               	/* #NOAPP */
 141 0054 8FEF      		ldi r24,lo8(-1)
 142 0056 8EBD      		out 78-32,r24
 143 0058 00C0      		rjmp .L8
 144               	.LBE88:
 145               	.LBE89:
 146               	.LBE90:
 147               	.LBE91:
 148               	.LFE5:
 150               		.section	.text.rcvr_datablock,"ax",@progbits
 152               	rcvr_datablock:
 153               	.LFB7:
 154               	.LSM23:
 155               	.LVL0:
 156               	/* prologue: function */
 157               	/* frame size = 0 */
 158 0000 E82F      		mov r30,r24
 159 0002 F92F      		mov r31,r25
 160               	.LSM24:
 161 0004 84E1      		ldi r24,lo8(20)
 162               	.LVL1:
 163 0006 8093 0000 		sts Timer1,r24
 164               	.LBB92:
 165               	.LBB93:
 166               	.LSM25:
 167 000a 9FEF      		ldi r25,lo8(-1)
 168               	.L19:
 169               	.LSM26:
 170               	/* #APP */
 171               	 ;  78 "diskio.c" 1
 172 000c F894      		cli
 173               	 ;  0 "" 2
 174               	.LSM27:
 175               	/* #NOAPP */
 176 000e 9EBD      		out 78-32,r25
 177               	.L17:
 178               	.LSM28:
 179 0010 0DB4      		in __tmp_reg__,77-32
 180 0012 07FE      		sbrs __tmp_reg__,7
 181 0014 00C0      		rjmp .L17
 182               	.LSM29:
 183               	/* #APP */
 184               	 ;  81 "diskio.c" 1
 185 0016 7894      		sei
 186               	 ;  0 "" 2
 187               	.LSM30:
 188               	/* #NOAPP */
 189 0018 8EB5      		in r24,78-32
 190               	.LVL2:
 191               	.LBE93:
 192               	.LBE92:
 193               	.LSM31:
 194 001a 8F3F      		cpi r24,lo8(-1)
 195 001c 01F4      		brne .L18
 196 001e 8091 0000 		lds r24,Timer1
 197               	.LVL3:
 198 0022 8823      		tst r24
 199 0024 01F4      		brne .L19
 200 0026 00C0      		rjmp .L20
 201               	.LVL4:
 202               	.L18:
 203               	.LSM32:
 204 0028 8E3F      		cpi r24,lo8(-2)
 205 002a 01F4      		brne .L20
 206               	.LSM33:
 207 002c 9FEF      		ldi r25,lo8(-1)
 208               	.L39:
 209 002e 9EBD      		out 78-32,r25
 210               	.L21:
 211 0030 0DB4      		in __tmp_reg__,77-32
 212 0032 07FE      		sbrs __tmp_reg__,7
 213 0034 00C0      		rjmp .L21
 214 0036 8EB5      		in r24,78-32
 215               	.LVL5:
 216 0038 8083      		st Z,r24
 217               	.LSM34:
 218 003a 9EBD      		out 78-32,r25
 219               	.L22:
 220 003c 0DB4      		in __tmp_reg__,77-32
 221 003e 07FE      		sbrs __tmp_reg__,7
 222 0040 00C0      		rjmp .L22
 223 0042 8EB5      		in r24,78-32
 224 0044 8183      		std Z+1,r24
 225               	.LSM35:
 226 0046 9EBD      		out 78-32,r25
 227               	.L23:
 228 0048 0DB4      		in __tmp_reg__,77-32
 229 004a 07FE      		sbrs __tmp_reg__,7
 230 004c 00C0      		rjmp .L23
 231 004e 8EB5      		in r24,78-32
 232 0050 8283      		std Z+2,r24
 233               	.LSM36:
 234 0052 9EBD      		out 78-32,r25
 235               	.L24:
 236 0054 0DB4      		in __tmp_reg__,77-32
 237 0056 07FE      		sbrs __tmp_reg__,7
 238 0058 00C0      		rjmp .L24
 239 005a 8EB5      		in r24,78-32
 240 005c 8383      		std Z+3,r24
 241               	.LSM37:
 242 005e 6450      		subi r22,lo8(-(-4))
 243 0060 7040      		sbci r23,hi8(-(-4))
 244               	.LVL6:
 245 0062 01F0      		breq .L25
 246               	.LSM38:
 247 0064 3496      		adiw r30,4
 248 0066 00C0      		rjmp .L39
 249               	.L25:
 250               	.LBB94:
 251               	.LBB95:
 252               	.LSM39:
 253               	/* #APP */
 254               	 ;  78 "diskio.c" 1
 255 0068 F894      		cli
 256               	 ;  0 "" 2
 257               	.LSM40:
 258               	/* #NOAPP */
 259 006a 8FEF      		ldi r24,lo8(-1)
 260 006c 8EBD      		out 78-32,r24
 261               	.L27:
 262               	.LSM41:
 263 006e 0DB4      		in __tmp_reg__,77-32
 264 0070 07FE      		sbrs __tmp_reg__,7
 265 0072 00C0      		rjmp .L27
 266               	.LSM42:
 267               	/* #APP */
 268               	 ;  81 "diskio.c" 1
 269 0074 7894      		sei
 270               	 ;  0 "" 2
 271               	.LSM43:
 272               	/* #NOAPP */
 273 0076 8EB5      		in r24,78-32
 274               	.LBE95:
 275               	.LBE94:
 276               	.LBB96:
 277               	.LBB97:
 278               	.LSM44:
 279               	/* #APP */
 280               	 ;  78 "diskio.c" 1
 281 0078 F894      		cli
 282               	 ;  0 "" 2
 283               	.LSM45:
 284               	/* #NOAPP */
 285 007a 8FEF      		ldi r24,lo8(-1)
 286 007c 8EBD      		out 78-32,r24
 287               	.L28:
 288               	.LSM46:
 289 007e 0DB4      		in __tmp_reg__,77-32
 290 0080 07FE      		sbrs __tmp_reg__,7
 291 0082 00C0      		rjmp .L28
 292               	.LSM47:
 293               	/* #APP */
 294               	 ;  81 "diskio.c" 1
 295 0084 7894      		sei
 296               	 ;  0 "" 2
 297               	.LSM48:
 298               	/* #NOAPP */
 299 0086 8EB5      		in r24,78-32
 300 0088 21E0      		ldi r18,lo8(1)
 301 008a 30E0      		ldi r19,hi8(1)
 302 008c 00C0      		rjmp .L29
 303               	.LVL7:
 304               	.L20:
 305               	.LSM49:
 306 008e 20E0      		ldi r18,lo8(0)
 307 0090 30E0      		ldi r19,hi8(0)
 308               	.L29:
 309               	.LBE97:
 310               	.LBE96:
 311               	.LSM50:
 312 0092 822F      		mov r24,r18
 313               	.LVL8:
 314 0094 932F      		mov r25,r19
 315               	/* epilogue start */
 316 0096 0895      		ret
 317               	.LFE7:
 319               		.section	.text.xmit_datablock,"ax",@progbits
 321               	xmit_datablock:
 322               	.LFB8:
 323               	.LSM51:
 324               	.LVL9:
 325               	/* prologue: function */
 326               	/* frame size = 0 */
 327 0000 E82F      		mov r30,r24
 328 0002 F92F      		mov r31,r25
 329               	.LBB98:
 330               	.LBB99:
 331               	.LSM52:
 332 0004 82E3      		ldi r24,lo8(50)
 333               	.LVL10:
 334 0006 8093 0000 		sts Timer2,r24
 335               	.LBB100:
 336               	.LBB101:
 337               	.LSM53:
 338               	/* #APP */
 339               	 ;  78 "diskio.c" 1
 340 000a F894      		cli
 341               	 ;  0 "" 2
 342               	.LSM54:
 343               	/* #NOAPP */
 344 000c 8FEF      		ldi r24,lo8(-1)
 345 000e 8EBD      		out 78-32,r24
 346               	.L41:
 347               	.LSM55:
 348 0010 0DB4      		in __tmp_reg__,77-32
 349 0012 07FE      		sbrs __tmp_reg__,7
 350 0014 00C0      		rjmp .L41
 351               	.LSM56:
 352               	/* #APP */
 353               	 ;  81 "diskio.c" 1
 354 0016 7894      		sei
 355               	 ;  0 "" 2
 356               	.LSM57:
 357               	/* #NOAPP */
 358 0018 8EB5      		in r24,78-32
 359               	.LBE101:
 360               	.LBE100:
 361               	.LBB102:
 362               	.LBB103:
 363               	.LSM58:
 364 001a 9FEF      		ldi r25,lo8(-1)
 365               	.L44:
 366               	.LSM59:
 367               	/* #APP */
 368               	 ;  78 "diskio.c" 1
 369 001c F894      		cli
 370               	 ;  0 "" 2
 371               	.LSM60:
 372               	/* #NOAPP */
 373 001e 9EBD      		out 78-32,r25
 374               	.L42:
 375               	.LSM61:
 376 0020 0DB4      		in __tmp_reg__,77-32
 377 0022 07FE      		sbrs __tmp_reg__,7
 378 0024 00C0      		rjmp .L42
 379               	.LSM62:
 380               	/* #APP */
 381               	 ;  81 "diskio.c" 1
 382 0026 7894      		sei
 383               	 ;  0 "" 2
 384               	.LSM63:
 385               	/* #NOAPP */
 386 0028 8EB5      		in r24,78-32
 387               	.LBE103:
 388               	.LBE102:
 389               	.LSM64:
 390 002a 8F3F      		cpi r24,lo8(-1)
 391 002c 01F0      		breq .L43
 392               	.LSM65:
 393 002e 8091 0000 		lds r24,Timer2
 394 0032 8823      		tst r24
 395 0034 01F4      		brne .L44
 396 0036 20E0      		ldi r18,lo8(0)
 397 0038 30E0      		ldi r19,hi8(0)
 398 003a 00C0      		rjmp .L45
 399               	.L43:
 400               	.LBE99:
 401               	.LBE98:
 402               	.LSM66:
 403               	/* #APP */
 404               	 ;  227 "diskio.c" 1
 405 003c F894      		cli
 406               	 ;  0 "" 2
 407               	/* #NOAPP */
 408 003e 6EBD      		out 78-32,r22
 409               	.L46:
 410 0040 0DB4      		in __tmp_reg__,77-32
 411 0042 07FE      		sbrs __tmp_reg__,7
 412 0044 00C0      		rjmp .L46
 413               	/* #APP */
 414               	 ;  227 "diskio.c" 1
 415 0046 7894      		sei
 416               	 ;  0 "" 2
 417               	.LSM67:
 418               	/* #NOAPP */
 419 0048 6D3F      		cpi r22,lo8(-3)
 420 004a 01F4      		brne .L47
 421 004c 21E0      		ldi r18,lo8(1)
 422 004e 30E0      		ldi r19,hi8(1)
 423 0050 00C0      		rjmp .L45
 424               	.L47:
 425 0052 90E0      		ldi r25,lo8(0)
 426               	.LVL11:
 427               	.L51:
 428               	.LSM68:
 429               	/* #APP */
 430               	 ;  231 "diskio.c" 1
 431 0054 F894      		cli
 432               	 ;  0 "" 2
 433               	/* #NOAPP */
 434 0056 8081      		ld r24,Z
 435 0058 8EBD      		out 78-32,r24
 436               	.L48:
 437 005a 0DB4      		in __tmp_reg__,77-32
 438 005c 07FE      		sbrs __tmp_reg__,7
 439 005e 00C0      		rjmp .L48
 440               	/* #APP */
 441               	 ;  231 "diskio.c" 1
 442 0060 7894      		sei
 443               	 ;  0 "" 2
 444               	.LSM69:
 445               	 ;  232 "diskio.c" 1
 446 0062 F894      		cli
 447               	 ;  0 "" 2
 448               	/* #NOAPP */
 449 0064 8181      		ldd r24,Z+1
 450 0066 8EBD      		out 78-32,r24
 451               	.L49:
 452 0068 0DB4      		in __tmp_reg__,77-32
 453 006a 07FE      		sbrs __tmp_reg__,7
 454 006c 00C0      		rjmp .L49
 455               	/* #APP */
 456               	 ;  232 "diskio.c" 1
 457 006e 7894      		sei
 458               	 ;  0 "" 2
 459               	.LSM70:
 460               	/* #NOAPP */
 461 0070 9150      		subi r25,lo8(-(-1))
 462 0072 01F0      		breq .L50
 463               	.LSM71:
 464 0074 3296      		adiw r30,2
 465 0076 00C0      		rjmp .L51
 466               	.L50:
 467               	.LSM72:
 468               	/* #APP */
 469               	 ;  234 "diskio.c" 1
 470 0078 F894      		cli
 471               	 ;  0 "" 2
 472               	/* #NOAPP */
 473 007a 8FEF      		ldi r24,lo8(-1)
 474 007c 8EBD      		out 78-32,r24
 475               	.L52:
 476 007e 0DB4      		in __tmp_reg__,77-32
 477 0080 07FE      		sbrs __tmp_reg__,7
 478 0082 00C0      		rjmp .L52
 479               	/* #APP */
 480               	 ;  234 "diskio.c" 1
 481 0084 7894      		sei
 482               	 ;  0 "" 2
 483               	.LSM73:
 484               	 ;  235 "diskio.c" 1
 485 0086 F894      		cli
 486               	 ;  0 "" 2
 487               	/* #NOAPP */
 488 0088 8FEF      		ldi r24,lo8(-1)
 489 008a 8EBD      		out 78-32,r24
 490               	.L53:
 491 008c 0DB4      		in __tmp_reg__,77-32
 492 008e 07FE      		sbrs __tmp_reg__,7
 493 0090 00C0      		rjmp .L53
 494               	/* #APP */
 495               	 ;  235 "diskio.c" 1
 496 0092 7894      		sei
 497               	 ;  0 "" 2
 498               	/* #NOAPP */
 499               	.LBB104:
 500               	.LBB105:
 501               	.LSM74:
 502               	/* #APP */
 503               	 ;  78 "diskio.c" 1
 504 0094 F894      		cli
 505               	 ;  0 "" 2
 506               	.LSM75:
 507               	/* #NOAPP */
 508 0096 8FEF      		ldi r24,lo8(-1)
 509 0098 8EBD      		out 78-32,r24
 510               	.L54:
 511               	.LSM76:
 512 009a 0DB4      		in __tmp_reg__,77-32
 513 009c 07FE      		sbrs __tmp_reg__,7
 514 009e 00C0      		rjmp .L54
 515               	.LSM77:
 516               	/* #APP */
 517               	 ;  81 "diskio.c" 1
 518 00a0 7894      		sei
 519               	 ;  0 "" 2
 520               	.LSM78:
 521               	/* #NOAPP */
 522 00a2 8EB5      		in r24,78-32
 523               	.LVL12:
 524 00a4 90E0      		ldi r25,lo8(0)
 525               	.LVL13:
 526 00a6 8F71      		andi r24,lo8(31)
 527 00a8 8530      		cpi r24,lo8(5)
 528 00aa 01F0      		breq .L55
 529 00ac 91E0      		ldi r25,lo8(1)
 530               	.L55:
 531 00ae 81E0      		ldi r24,lo8(1)
 532               	.LVL14:
 533 00b0 9827      		eor r25,r24
 534 00b2 292F      		mov r18,r25
 535 00b4 30E0      		ldi r19,lo8(0)
 536               	.L45:
 537               	.LBE105:
 538               	.LBE104:
 539               	.LSM79:
 540 00b6 822F      		mov r24,r18
 541 00b8 932F      		mov r25,r19
 542               	/* epilogue start */
 543 00ba 0895      		ret
 544               	.LFE8:
 546               		.section	.text.send_cmd,"ax",@progbits
 548               	send_cmd:
 549               	.LFB9:
 550               	.LSM80:
 551               	.LVL15:
 552 0000 DF92      		push r13
 553 0002 EF92      		push r14
 554 0004 FF92      		push r15
 555 0006 0F93      		push r16
 556 0008 1F93      		push r17
 557               	/* prologue: function */
 558               	/* frame size = 0 */
 559 000a D82E      		mov r13,r24
 560 000c E42E      		mov r14,r20
 561 000e F52E      		mov r15,r21
 562 0010 062F      		mov r16,r22
 563 0012 172F      		mov r17,r23
 564               	.LSM81:
 565 0014 87FF      		sbrs r24,7
 566 0016 00C0      		rjmp .L67
 567               	.LVL16:
 568               	.LSM82:
 569 0018 87E3      		ldi r24,lo8(55)
 570               	.LVL17:
 571 001a 40E0      		ldi r20,lo8(0)
 572 001c 50E0      		ldi r21,hi8(0)
 573 001e 60E0      		ldi r22,hlo8(0)
 574 0020 70E0      		ldi r23,hhi8(0)
 575 0022 00D0      		rcall send_cmd
 576               	.LSM83:
 577 0024 8230      		cpi r24,lo8(2)
 578               	.LVL18:
 579 0026 00F0      		brlo .+2
 580 0028 00C0      		rjmp .L68
 581               	.LSM84:
 582 002a 8FE7      		ldi r24,lo8(127)
 583               	.LVL19:
 584 002c D822      		and r13,r24
 585               	.LVL20:
 586               	.L67:
 587               	.LBB106:
 588               	.LBB107:
 589               	.LSM85:
 590 002e 289A      		sbi 37-32,0
 591               	.LBB108:
 592               	.LBB109:
 593               	.LSM86:
 594               	/* #APP */
 595               	 ;  78 "diskio.c" 1
 596 0030 F894      		cli
 597               	 ;  0 "" 2
 598               	.LSM87:
 599               	/* #NOAPP */
 600 0032 8FEF      		ldi r24,lo8(-1)
 601 0034 8EBD      		out 78-32,r24
 602               	.L69:
 603               	.LSM88:
 604 0036 0DB4      		in __tmp_reg__,77-32
 605 0038 07FE      		sbrs __tmp_reg__,7
 606 003a 00C0      		rjmp .L69
 607               	.LSM89:
 608               	/* #APP */
 609               	 ;  81 "diskio.c" 1
 610 003c 7894      		sei
 611               	 ;  0 "" 2
 612               	.LSM90:
 613               	/* #NOAPP */
 614 003e 8EB5      		in r24,78-32
 615               	.LBE109:
 616               	.LBE108:
 617               	.LBE107:
 618               	.LBE106:
 619               	.LSM91:
 620 0040 00D0      		rcall select
 621 0042 892B      		or r24,r25
 622 0044 01F4      		brne .L70
 623 0046 8FEF      		ldi r24,lo8(-1)
 624               	.LVL21:
 625 0048 00C0      		rjmp .L68
 626               	.LVL22:
 627               	.L70:
 628               	.LSM92:
 629               	/* #APP */
 630               	 ;  271 "diskio.c" 1
 631 004a F894      		cli
 632               	 ;  0 "" 2
 633               	/* #NOAPP */
 634 004c 8D2D      		mov r24,r13
 635 004e 8064      		ori r24,lo8(64)
 636 0050 8EBD      		out 78-32,r24
 637               	.L71:
 638 0052 0DB4      		in __tmp_reg__,77-32
 639 0054 07FE      		sbrs __tmp_reg__,7
 640 0056 00C0      		rjmp .L71
 641               	/* #APP */
 642               	 ;  271 "diskio.c" 1
 643 0058 7894      		sei
 644               	 ;  0 "" 2
 645               	.LSM93:
 646               	 ;  272 "diskio.c" 1
 647 005a F894      		cli
 648               	 ;  0 "" 2
 649               	/* #NOAPP */
 650 005c 812F      		mov r24,r17
 651 005e 9927      		clr r25
 652 0060 AA27      		clr r26
 653 0062 BB27      		clr r27
 654 0064 8EBD      		out 78-32,r24
 655               	.L72:
 656 0066 0DB4      		in __tmp_reg__,77-32
 657 0068 07FE      		sbrs __tmp_reg__,7
 658 006a 00C0      		rjmp .L72
 659               	/* #APP */
 660               	 ;  272 "diskio.c" 1
 661 006c 7894      		sei
 662               	 ;  0 "" 2
 663               	.LSM94:
 664               	 ;  273 "diskio.c" 1
 665 006e F894      		cli
 666               	 ;  0 "" 2
 667               	/* #NOAPP */
 668 0070 912F      		mov r25,r17
 669 0072 802F      		mov r24,r16
 670 0074 AA27      		clr r26
 671 0076 BB27      		clr r27
 672 0078 8EBD      		out 78-32,r24
 673               	.L73:
 674 007a 0DB4      		in __tmp_reg__,77-32
 675 007c 07FE      		sbrs __tmp_reg__,7
 676 007e 00C0      		rjmp .L73
 677               	/* #APP */
 678               	 ;  273 "diskio.c" 1
 679 0080 7894      		sei
 680               	 ;  0 "" 2
 681               	.LSM95:
 682               	 ;  274 "diskio.c" 1
 683 0082 F894      		cli
 684               	 ;  0 "" 2
 685               	/* #NOAPP */
 686 0084 BB27      		clr r27
 687 0086 A12F      		mov r26,r17
 688 0088 902F      		mov r25,r16
 689 008a 8F2D      		mov r24,r15
 690 008c 8EBD      		out 78-32,r24
 691               	.L74:
 692 008e 0DB4      		in __tmp_reg__,77-32
 693 0090 07FE      		sbrs __tmp_reg__,7
 694 0092 00C0      		rjmp .L74
 695               	/* #APP */
 696               	 ;  274 "diskio.c" 1
 697 0094 7894      		sei
 698               	 ;  0 "" 2
 699               	.LSM96:
 700               	 ;  275 "diskio.c" 1
 701 0096 F894      		cli
 702               	 ;  0 "" 2
 703               	/* #NOAPP */
 704 0098 EEBC      		out 78-32,r14
 705               	.L75:
 706 009a 0DB4      		in __tmp_reg__,77-32
 707 009c 07FE      		sbrs __tmp_reg__,7
 708 009e 00C0      		rjmp .L75
 709               	/* #APP */
 710               	 ;  275 "diskio.c" 1
 711 00a0 7894      		sei
 712               	 ;  0 "" 2
 713               	.LSM97:
 714               	/* #NOAPP */
 715 00a2 DD20      		tst r13
 716 00a4 01F4      		brne .L76
 717 00a6 85E9      		ldi r24,lo8(-107)
 718               	.LVL23:
 719 00a8 00C0      		rjmp .L77
 720               	.LVL24:
 721               	.L76:
 722               	.LSM98:
 723 00aa 88E0      		ldi r24,lo8(8)
 724 00ac D816      		cp r13,r24
 725 00ae 01F4      		brne .L78
 726 00b0 87E8      		ldi r24,lo8(-121)
 727               	.LVL25:
 728 00b2 00C0      		rjmp .L77
 729               	.LVL26:
 730               	.L78:
 731 00b4 81E0      		ldi r24,lo8(1)
 732               	.LVL27:
 733               	.L77:
 734               	.LSM99:
 735               	/* #APP */
 736               	 ;  279 "diskio.c" 1
 737 00b6 F894      		cli
 738               	 ;  0 "" 2
 739               	/* #NOAPP */
 740 00b8 8EBD      		out 78-32,r24
 741               	.L79:
 742 00ba 0DB4      		in __tmp_reg__,77-32
 743 00bc 07FE      		sbrs __tmp_reg__,7
 744 00be 00C0      		rjmp .L79
 745               	/* #APP */
 746               	 ;  279 "diskio.c" 1
 747 00c0 7894      		sei
 748               	 ;  0 "" 2
 749               	.LSM100:
 750               	/* #NOAPP */
 751 00c2 8CE0      		ldi r24,lo8(12)
 752               	.LVL28:
 753 00c4 D816      		cp r13,r24
 754 00c6 01F4      		brne .L96
 755               	.L80:
 756               	.LBB110:
 757               	.LBB111:
 758               	.LSM101:
 759               	/* #APP */
 760               	 ;  78 "diskio.c" 1
 761 00c8 F894      		cli
 762               	 ;  0 "" 2
 763               	.LSM102:
 764               	/* #NOAPP */
 765 00ca 8FEF      		ldi r24,lo8(-1)
 766 00cc 8EBD      		out 78-32,r24
 767               	.L82:
 768               	.LSM103:
 769 00ce 0DB4      		in __tmp_reg__,77-32
 770 00d0 07FE      		sbrs __tmp_reg__,7
 771 00d2 00C0      		rjmp .L82
 772               	.LSM104:
 773               	/* #APP */
 774               	 ;  81 "diskio.c" 1
 775 00d4 7894      		sei
 776               	 ;  0 "" 2
 777               	.LSM105:
 778               	/* #NOAPP */
 779 00d6 8EB5      		in r24,78-32
 780               	.L96:
 781 00d8 9AE0      		ldi r25,lo8(10)
 782               	.LVL29:
 783               	.LBE111:
 784               	.LBE110:
 785               	.LBB112:
 786               	.LBB113:
 787               	.LSM106:
 788 00da 2FEF      		ldi r18,lo8(-1)
 789               	.LVL30:
 790               	.L85:
 791               	.LSM107:
 792               	/* #APP */
 793               	 ;  78 "diskio.c" 1
 794 00dc F894      		cli
 795               	 ;  0 "" 2
 796               	.LSM108:
 797               	/* #NOAPP */
 798 00de 2EBD      		out 78-32,r18
 799               	.L83:
 800               	.LSM109:
 801 00e0 0DB4      		in __tmp_reg__,77-32
 802 00e2 07FE      		sbrs __tmp_reg__,7
 803 00e4 00C0      		rjmp .L83
 804               	.LSM110:
 805               	/* #APP */
 806               	 ;  81 "diskio.c" 1
 807 00e6 7894      		sei
 808               	 ;  0 "" 2
 809               	.LSM111:
 810               	/* #NOAPP */
 811 00e8 8EB5      		in r24,78-32
 812               	.LBE113:
 813               	.LBE112:
 814               	.LSM112:
 815 00ea 87FF      		sbrs r24,7
 816 00ec 00C0      		rjmp .L68
 817 00ee 9150      		subi r25,lo8(-(-1))
 818 00f0 01F4      		brne .L85
 819               	.L68:
 820               	.LVL31:
 821               	/* epilogue start */
 822               	.LSM113:
 823 00f2 1F91      		pop r17
 824 00f4 0F91      		pop r16
 825 00f6 FF90      		pop r15
 826 00f8 EF90      		pop r14
 827               	.LVL32:
 828 00fa DF90      		pop r13
 829               	.LVL33:
 830 00fc 0895      		ret
 831               	.LFE9:
 833               		.section	.text.disk_initialize,"ax",@progbits
 834               	.global	disk_initialize
 836               	disk_initialize:
 837               	.LFB10:
 838               	.LSM114:
 839               	.LVL34:
 840 0000 EF92      		push r14
 841 0002 FF92      		push r15
 842 0004 0F93      		push r16
 843 0006 1F93      		push r17
 844 0008 DF93      		push r29
 845 000a CF93      		push r28
 846 000c 00D0      		rcall .
 847 000e 00D0      		rcall .
 848 0010 CDB7      		in r28,__SP_L__
 849 0012 DEB7      		in r29,__SP_H__
 850               	/* prologue: function */
 851               	/* frame size = 4 */
 852               	.LSM115:
 853 0014 8823      		tst r24
 854 0016 01F0      		breq .L98
 855 0018 81E0      		ldi r24,lo8(1)
 856               	.LVL35:
 857 001a 00C0      		rjmp .L99
 858               	.LVL36:
 859               	.L98:
 860               	.LSM116:
 861 001c 8091 0000 		lds r24,Stat
 862               	.LVL37:
 863 0020 81FD      		sbrc r24,1
 864 0022 00C0      		rjmp .L117
 865               	.L100:
 866               	.LSM117:
 867 0024 85B1      		in r24,37-32
 868 0026 806C      		ori r24,lo8(-64)
 869 0028 85B9      		out 37-32,r24
 870               	.LSM118:
 871 002a 82E5      		ldi r24,lo8(82)
 872 002c 8CBD      		out 76-32,r24
 873 002e 8AE0      		ldi r24,lo8(10)
 874               	.LVL38:
 875               	.LBB114:
 876               	.LBB115:
 877               	.LSM119:
 878 0030 9FEF      		ldi r25,lo8(-1)
 879               	.L102:
 880               	.LSM120:
 881               	/* #APP */
 882               	 ;  78 "diskio.c" 1
 883 0032 F894      		cli
 884               	 ;  0 "" 2
 885               	.LSM121:
 886               	/* #NOAPP */
 887 0034 9EBD      		out 78-32,r25
 888               	.L101:
 889               	.LSM122:
 890 0036 0DB4      		in __tmp_reg__,77-32
 891 0038 07FE      		sbrs __tmp_reg__,7
 892 003a 00C0      		rjmp .L101
 893               	.LSM123:
 894               	/* #APP */
 895               	 ;  81 "diskio.c" 1
 896 003c 7894      		sei
 897               	 ;  0 "" 2
 898               	.LSM124:
 899               	/* #NOAPP */
 900 003e 2EB5      		in r18,78-32
 901               	.LBE115:
 902               	.LBE114:
 903               	.LSM125:
 904 0040 8150      		subi r24,lo8(-(-1))
 905 0042 01F4      		brne .L102
 906               	.LSM126:
 907 0044 40E0      		ldi r20,lo8(0)
 908 0046 50E0      		ldi r21,hi8(0)
 909 0048 60E0      		ldi r22,hlo8(0)
 910 004a 70E0      		ldi r23,hhi8(0)
 911 004c 00D0      		rcall send_cmd
 912               	.LVL39:
 913 004e 8130      		cpi r24,lo8(1)
 914 0050 01F0      		breq .+2
 915 0052 00C0      		rjmp .L103
 916               	.LSM127:
 917 0054 88EC      		ldi r24,lo8(-56)
 918 0056 8093 0000 		sts Timer1,r24
 919               	.LSM128:
 920 005a 88E0      		ldi r24,lo8(8)
 921 005c 4AEA      		ldi r20,lo8(426)
 922 005e 51E0      		ldi r21,hi8(426)
 923 0060 60E0      		ldi r22,hlo8(426)
 924 0062 70E0      		ldi r23,hhi8(426)
 925 0064 00D0      		rcall send_cmd
 926 0066 8130      		cpi r24,lo8(1)
 927 0068 01F0      		breq .+2
 928 006a 00C0      		rjmp .L104
 929 006c EC2E      		mov r14,r28
 930 006e FD2E      		mov r15,r29
 931 0070 0894      		sec
 932 0072 E11C      		adc r14,__zero_reg__
 933 0074 F11C      		adc r15,__zero_reg__
 934 0076 0E2D      		mov r16,r14
 935 0078 1F2D      		mov r17,r15
 936               	.LBB116:
 937               	.LBB117:
 938               	.LSM129:
 939 007a 9FEF      		ldi r25,lo8(-1)
 940               	.LBE117:
 941               	.LBE116:
 942               	.LSM130:
 943 007c 2C2F      		mov r18,r28
 944 007e 3D2F      		mov r19,r29
 945 0080 2B5F      		subi r18,lo8(-(5))
 946 0082 3F4F      		sbci r19,hi8(-(5))
 947               	.L106:
 948               	.LBB119:
 949               	.LBB118:
 950               	.LSM131:
 951               	/* #APP */
 952               	 ;  78 "diskio.c" 1
 953 0084 F894      		cli
 954               	 ;  0 "" 2
 955               	.LSM132:
 956               	/* #NOAPP */
 957 0086 9EBD      		out 78-32,r25
 958               	.L105:
 959               	.LSM133:
 960 0088 0DB4      		in __tmp_reg__,77-32
 961 008a 07FE      		sbrs __tmp_reg__,7
 962 008c 00C0      		rjmp .L105
 963               	.LSM134:
 964               	/* #APP */
 965               	 ;  81 "diskio.c" 1
 966 008e 7894      		sei
 967               	 ;  0 "" 2
 968               	.LSM135:
 969               	/* #NOAPP */
 970 0090 8EB5      		in r24,78-32
 971               	.LBE118:
 972               	.LBE119:
 973               	.LSM136:
 974 0092 E02F      		mov r30,r16
 975 0094 F12F      		mov r31,r17
 976 0096 8193      		st Z+,r24
 977 0098 0E2F      		mov r16,r30
 978 009a 1F2F      		mov r17,r31
 979 009c E217      		cp r30,r18
 980 009e F307      		cpc r31,r19
 981 00a0 01F4      		brne .L106
 982               	.LSM137:
 983 00a2 8B81      		ldd r24,Y+3
 984 00a4 8130      		cpi r24,lo8(1)
 985 00a6 01F0      		breq .+2
 986 00a8 00C0      		rjmp .L103
 987 00aa 8C81      		ldd r24,Y+4
 988 00ac 8A3A      		cpi r24,lo8(-86)
 989 00ae 01F0      		breq .+2
 990 00b0 00C0      		rjmp .L103
 991               	.L120:
 992               	.LSM138:
 993 00b2 8091 0000 		lds r24,Timer1
 994 00b6 8823      		tst r24
 995 00b8 01F0      		breq .L107
 996 00ba 89EA      		ldi r24,lo8(-87)
 997 00bc 40E0      		ldi r20,lo8(1073741824)
 998 00be 50E0      		ldi r21,hi8(1073741824)
 999 00c0 60E0      		ldi r22,hlo8(1073741824)
 1000 00c2 70E4      		ldi r23,hhi8(1073741824)
 1001 00c4 00D0      		rcall send_cmd
 1002 00c6 8823      		tst r24
 1003 00c8 01F4      		brne .L120
 1004               	.L107:
 1005               	.LSM139:
 1006 00ca 8091 0000 		lds r24,Timer1
 1007 00ce 8823      		tst r24
 1008 00d0 01F4      		brne .+2
 1009 00d2 00C0      		rjmp .L103
 1010 00d4 8AE3      		ldi r24,lo8(58)
 1011 00d6 40E0      		ldi r20,lo8(0)
 1012 00d8 50E0      		ldi r21,hi8(0)
 1013 00da 60E0      		ldi r22,hlo8(0)
 1014 00dc 70E0      		ldi r23,hhi8(0)
 1015 00de 00D0      		rcall send_cmd
 1016 00e0 8823      		tst r24
 1017 00e2 01F4      		brne .L103
 1018               	.LBB120:
 1019               	.LBB121:
 1020               	.LSM140:
 1021 00e4 9FEF      		ldi r25,lo8(-1)
 1022               	.L119:
 1023               	.LSM141:
 1024               	/* #APP */
 1025               	 ;  78 "diskio.c" 1
 1026 00e6 F894      		cli
 1027               	 ;  0 "" 2
 1028               	.LSM142:
 1029               	/* #NOAPP */
 1030 00e8 9EBD      		out 78-32,r25
 1031               	.L109:
 1032               	.LSM143:
 1033 00ea 0DB4      		in __tmp_reg__,77-32
 1034 00ec 07FE      		sbrs __tmp_reg__,7
 1035 00ee 00C0      		rjmp .L109
 1036               	.LSM144:
 1037               	/* #APP */
 1038               	 ;  81 "diskio.c" 1
 1039 00f0 7894      		sei
 1040               	 ;  0 "" 2
 1041               	.LSM145:
 1042               	/* #NOAPP */
 1043 00f2 8EB5      		in r24,78-32
 1044               	.LBE121:
 1045               	.LBE120:
 1046               	.LSM146:
 1047 00f4 EE2D      		mov r30,r14
 1048 00f6 FF2D      		mov r31,r15
 1049 00f8 8193      		st Z+,r24
 1050 00fa EE2E      		mov r14,r30
 1051 00fc FF2E      		mov r15,r31
 1052 00fe E017      		cp r30,r16
 1053 0100 F107      		cpc r31,r17
 1054 0102 01F4      		brne .L119
 1055               	.LSM147:
 1056 0104 8981      		ldd r24,Y+1
 1057 0106 86FD      		sbrc r24,6
 1058 0108 00C0      		rjmp .L111
 1059 010a 14E0      		ldi r17,lo8(4)
 1060               	.LVL40:
 1061 010c 00C0      		rjmp .L112
 1062               	.LVL41:
 1063               	.L111:
 1064 010e 1CE0      		ldi r17,lo8(12)
 1065               	.LVL42:
 1066 0110 00C0      		rjmp .L112
 1067               	.LVL43:
 1068               	.L104:
 1069               	.LSM148:
 1070 0112 89EA      		ldi r24,lo8(-87)
 1071 0114 40E0      		ldi r20,lo8(0)
 1072 0116 50E0      		ldi r21,hi8(0)
 1073 0118 60E0      		ldi r22,hlo8(0)
 1074 011a 70E0      		ldi r23,hhi8(0)
 1075 011c 00D0      		rcall send_cmd
 1076 011e 8230      		cpi r24,lo8(2)
 1077 0120 00F0      		brlo .L113
 1078 0122 01E0      		ldi r16,lo8(1)
 1079               	.LVL44:
 1080 0124 11E0      		ldi r17,lo8(1)
 1081               	.LVL45:
 1082 0126 00C0      		rjmp .L121
 1083               	.LVL46:
 1084               	.L113:
 1085 0128 09EA      		ldi r16,lo8(-87)
 1086               	.LVL47:
 1087 012a 12E0      		ldi r17,lo8(2)
 1088               	.LVL48:
 1089               	.L121:
 1090               	.LSM149:
 1091 012c 8091 0000 		lds r24,Timer1
 1092 0130 8823      		tst r24
 1093 0132 01F0      		breq .L115
 1094 0134 802F      		mov r24,r16
 1095 0136 40E0      		ldi r20,lo8(0)
 1096 0138 50E0      		ldi r21,hi8(0)
 1097 013a 60E0      		ldi r22,hlo8(0)
 1098 013c 70E0      		ldi r23,hhi8(0)
 1099 013e 00D0      		rcall send_cmd
 1100 0140 8823      		tst r24
 1101 0142 01F4      		brne .L121
 1102               	.L115:
 1103               	.LSM150:
 1104 0144 8091 0000 		lds r24,Timer1
 1105 0148 8823      		tst r24
 1106 014a 01F0      		breq .L103
 1107 014c 80E1      		ldi r24,lo8(16)
 1108 014e 40E0      		ldi r20,lo8(512)
 1109 0150 52E0      		ldi r21,hi8(512)
 1110 0152 60E0      		ldi r22,hlo8(512)
 1111 0154 70E0      		ldi r23,hhi8(512)
 1112 0156 00D0      		rcall send_cmd
 1113 0158 8111      		cpse r24,__zero_reg__
 1114               	.L103:
 1115 015a 10E0      		ldi r17,lo8(0)
 1116               	.L112:
 1117               	.LSM151:
 1118 015c 1093 0000 		sts CardType,r17
 1119               	.LBB122:
 1120               	.LBB123:
 1121               	.LSM152:
 1122 0160 289A      		sbi 37-32,0
 1123               	.LBB124:
 1124               	.LBB125:
 1125               	.LSM153:
 1126               	/* #APP */
 1127               	 ;  78 "diskio.c" 1
 1128 0162 F894      		cli
 1129               	 ;  0 "" 2
 1130               	.LSM154:
 1131               	/* #NOAPP */
 1132 0164 8FEF      		ldi r24,lo8(-1)
 1133 0166 8EBD      		out 78-32,r24
 1134               	.L116:
 1135               	.LSM155:
 1136 0168 0DB4      		in __tmp_reg__,77-32
 1137 016a 07FE      		sbrs __tmp_reg__,7
 1138 016c 00C0      		rjmp .L116
 1139               	.LSM156:
 1140               	/* #APP */
 1141               	 ;  81 "diskio.c" 1
 1142 016e 7894      		sei
 1143               	 ;  0 "" 2
 1144               	.LSM157:
 1145               	/* #NOAPP */
 1146 0170 8EB5      		in r24,78-32
 1147               	.LBE125:
 1148               	.LBE124:
 1149               	.LBE123:
 1150               	.LBE122:
 1151               	.LSM158:
 1152 0172 1123      		tst r17
 1153 0174 01F0      		breq .L117
 1154               	.LSM159:
 1155 0176 8091 0000 		lds r24,Stat
 1156 017a 8E7F      		andi r24,lo8(-2)
 1157 017c 8093 0000 		sts Stat,r24
 1158               	.LSM160:
 1159 0180 80E5      		ldi r24,lo8(80)
 1160 0182 8CBD      		out 76-32,r24
 1161               	.L117:
 1162               	.LSM161:
 1163 0184 8091 0000 		lds r24,Stat
 1164               	.L99:
 1165               	/* epilogue start */
 1166               	.LSM162:
 1167 0188 0F90      		pop __tmp_reg__
 1168 018a 0F90      		pop __tmp_reg__
 1169 018c 0F90      		pop __tmp_reg__
 1170 018e 0F90      		pop __tmp_reg__
 1171 0190 CF91      		pop r28
 1172 0192 DF91      		pop r29
 1173 0194 1F91      		pop r17
 1174               	.LVL49:
 1175 0196 0F91      		pop r16
 1176               	.LVL50:
 1177 0198 FF90      		pop r15
 1178 019a EF90      		pop r14
 1179 019c 0895      		ret
 1180               	.LFE10:
 1182               		.section	.text.disk_status,"ax",@progbits
 1183               	.global	disk_status
 1185               	disk_status:
 1186               	.LFB11:
 1187               	.LSM163:
 1188               	.LVL51:
 1189               	/* prologue: function */
 1190               	/* frame size = 0 */
 1191               	.LSM164:
 1192 0000 8823      		tst r24
 1193 0002 01F0      		breq .L132
 1194 0004 81E0      		ldi r24,lo8(1)
 1195               	.LVL52:
 1196 0006 0895      		ret
 1197               	.LVL53:
 1198               	.L132:
 1199               	.LSM165:
 1200 0008 8091 0000 		lds r24,Stat
 1201               	.LVL54:
 1202               	.LSM166:
 1203 000c 0895      		ret
 1204               	.LFE11:
 1206               		.section	.text.disk_read,"ax",@progbits
 1207               	.global	disk_read
 1209               	disk_read:
 1210               	.LFB12:
 1211               	.LSM167:
 1212               	.LVL55:
 1213 0000 0F93      		push r16
 1214               	.LVL56:
 1215 0002 CF93      		push r28
 1216 0004 DF93      		push r29
 1217               	/* prologue: function */
 1218               	/* frame size = 0 */
 1219 0006 C62F      		mov r28,r22
 1220 0008 D72F      		mov r29,r23
 1221               	.LSM168:
 1222 000a 8823      		tst r24
 1223 000c 01F0      		breq .+2
 1224 000e 00C0      		rjmp .L136
 1225               	.LVL57:
 1226 0010 0023      		tst r16
 1227               	.LVL58:
 1228 0012 01F4      		brne .+2
 1229 0014 00C0      		rjmp .L136
 1230               	.LSM169:
 1231 0016 8091 0000 		lds r24,Stat
 1232               	.LVL59:
 1233 001a 80FF      		sbrs r24,0
 1234 001c 00C0      		rjmp .L137
 1235 001e 03E0      		ldi r16,lo8(3)
 1236               	.LVL60:
 1237 0020 00C0      		rjmp .L138
 1238               	.LVL61:
 1239               	.L137:
 1240               	.LSM170:
 1241 0022 8091 0000 		lds r24,CardType
 1242 0026 83FD      		sbrc r24,3
 1243 0028 00C0      		rjmp .L139
 1244 002a 69E0      		ldi r22,9
 1245 002c 220F      	1:	lsl r18
 1246 002e 331F      		rol r19
 1247 0030 441F      		rol r20
 1248 0032 551F      		rol r21
 1249 0034 6A95      		dec r22
 1250 0036 01F4      		brne 1b
 1251               	.LVL62:
 1252               	.L139:
 1253               	.LSM171:
 1254 0038 0130      		cpi r16,lo8(1)
 1255 003a 01F4      		brne .L140
 1256               	.LSM172:
 1257 003c 81E1      		ldi r24,lo8(17)
 1258 003e 752F      		mov r23,r21
 1259 0040 642F      		mov r22,r20
 1260 0042 532F      		mov r21,r19
 1261 0044 422F      		mov r20,r18
 1262 0046 00D0      		rcall send_cmd
 1263               	.LVL63:
 1264 0048 8823      		tst r24
 1265 004a 01F4      		brne .L141
 1266 004c 8C2F      		mov r24,r28
 1267 004e 9D2F      		mov r25,r29
 1268 0050 60E0      		ldi r22,lo8(512)
 1269 0052 72E0      		ldi r23,hi8(512)
 1270 0054 00D0      		rcall rcvr_datablock
 1271 0056 00E0      		ldi r16,lo8(0)
 1272 0058 892B      		or r24,r25
 1273 005a 01F4      		brne .L141
 1274 005c 01E0      		ldi r16,lo8(1)
 1275 005e 00C0      		rjmp .L141
 1276               	.LVL64:
 1277               	.L140:
 1278               	.LSM173:
 1279 0060 82E1      		ldi r24,lo8(18)
 1280 0062 752F      		mov r23,r21
 1281 0064 642F      		mov r22,r20
 1282 0066 532F      		mov r21,r19
 1283 0068 422F      		mov r20,r18
 1284 006a 00D0      		rcall send_cmd
 1285               	.LVL65:
 1286 006c 8823      		tst r24
 1287 006e 01F4      		brne .L141
 1288               	.L149:
 1289               	.LSM174:
 1290 0070 8C2F      		mov r24,r28
 1291 0072 9D2F      		mov r25,r29
 1292 0074 60E0      		ldi r22,lo8(512)
 1293 0076 72E0      		ldi r23,hi8(512)
 1294 0078 00D0      		rcall rcvr_datablock
 1295 007a 892B      		or r24,r25
 1296 007c 01F0      		breq .L143
 1297               	.LSM175:
 1298 007e 0150      		subi r16,lo8(-(-1))
 1299 0080 01F0      		breq .L143
 1300               	.LSM176:
 1301 0082 C050      		subi r28,lo8(-(512))
 1302 0084 DE4F      		sbci r29,hi8(-(512))
 1303 0086 00C0      		rjmp .L149
 1304               	.L143:
 1305               	.LSM177:
 1306 0088 8CE0      		ldi r24,lo8(12)
 1307 008a 40E0      		ldi r20,lo8(0)
 1308 008c 50E0      		ldi r21,hi8(0)
 1309 008e 60E0      		ldi r22,hlo8(0)
 1310 0090 70E0      		ldi r23,hhi8(0)
 1311 0092 00D0      		rcall send_cmd
 1312               	.L141:
 1313               	.LBB126:
 1314               	.LBB127:
 1315               	.LSM178:
 1316 0094 289A      		sbi 37-32,0
 1317               	.LBB128:
 1318               	.LBB129:
 1319               	.LSM179:
 1320               	/* #APP */
 1321               	 ;  78 "diskio.c" 1
 1322 0096 F894      		cli
 1323               	 ;  0 "" 2
 1324               	.LSM180:
 1325               	/* #NOAPP */
 1326 0098 8FEF      		ldi r24,lo8(-1)
 1327 009a 8EBD      		out 78-32,r24
 1328               	.L145:
 1329               	.LSM181:
 1330 009c 0DB4      		in __tmp_reg__,77-32
 1331 009e 07FE      		sbrs __tmp_reg__,7
 1332 00a0 00C0      		rjmp .L145
 1333               	.LSM182:
 1334               	/* #APP */
 1335               	 ;  81 "diskio.c" 1
 1336 00a2 7894      		sei
 1337               	 ;  0 "" 2
 1338               	.LSM183:
 1339               	/* #NOAPP */
 1340 00a4 8EB5      		in r24,78-32
 1341               	.LBE129:
 1342               	.LBE128:
 1343               	.LBE127:
 1344               	.LBE126:
 1345               	.LSM184:
 1346 00a6 0023      		tst r16
 1347 00a8 01F0      		breq .L138
 1348 00aa 01E0      		ldi r16,lo8(1)
 1349               	.LVL66:
 1350 00ac 00C0      		rjmp .L138
 1351               	.LVL67:
 1352               	.L136:
 1353 00ae 04E0      		ldi r16,lo8(4)
 1354               	.LVL68:
 1355               	.L138:
 1356               	.LSM185:
 1357 00b0 802F      		mov r24,r16
 1358               	.LVL69:
 1359               	/* epilogue start */
 1360 00b2 DF91      		pop r29
 1361 00b4 CF91      		pop r28
 1362               	.LVL70:
 1363 00b6 0F91      		pop r16
 1364 00b8 0895      		ret
 1365               	.LFE12:
 1367               		.section	.text.disk_write,"ax",@progbits
 1368               	.global	disk_write
 1370               	disk_write:
 1371               	.LFB13:
 1372               	.LSM186:
 1373               	.LVL71:
 1374 0000 CF92      		push r12
 1375 0002 DF92      		push r13
 1376 0004 EF92      		push r14
 1377 0006 FF92      		push r15
 1378 0008 0F93      		push r16
 1379               	.LVL72:
 1380 000a CF93      		push r28
 1381 000c DF93      		push r29
 1382               	/* prologue: function */
 1383               	/* frame size = 0 */
 1384 000e C62F      		mov r28,r22
 1385 0010 D72F      		mov r29,r23
 1386 0012 C22E      		mov r12,r18
 1387 0014 D32E      		mov r13,r19
 1388 0016 E42E      		mov r14,r20
 1389 0018 F52E      		mov r15,r21
 1390               	.LSM187:
 1391 001a 8823      		tst r24
 1392 001c 01F0      		breq .+2
 1393 001e 00C0      		rjmp .L151
 1394               	.LVL73:
 1395 0020 0023      		tst r16
 1396               	.LVL74:
 1397 0022 01F4      		brne .+2
 1398 0024 00C0      		rjmp .L151
 1399               	.LSM188:
 1400 0026 8091 0000 		lds r24,Stat
 1401               	.LVL75:
 1402 002a 80FF      		sbrs r24,0
 1403 002c 00C0      		rjmp .L152
 1404 002e 03E0      		ldi r16,lo8(3)
 1405               	.LVL76:
 1406 0030 00C0      		rjmp .L153
 1407               	.LVL77:
 1408               	.L152:
 1409               	.LSM189:
 1410 0032 8091 0000 		lds r24,Stat
 1411 0036 82FF      		sbrs r24,2
 1412 0038 00C0      		rjmp .L154
 1413 003a 02E0      		ldi r16,lo8(2)
 1414               	.LVL78:
 1415 003c 00C0      		rjmp .L153
 1416               	.LVL79:
 1417               	.L154:
 1418               	.LSM190:
 1419 003e 8091 0000 		lds r24,CardType
 1420 0042 90E0      		ldi r25,lo8(0)
 1421 0044 83FD      		sbrc r24,3
 1422 0046 00C0      		rjmp .L155
 1423 0048 79E0      		ldi r23,9
 1424 004a CC0C      	1:	lsl r12
 1425 004c DD1C      		rol r13
 1426 004e EE1C      		rol r14
 1427 0050 FF1C      		rol r15
 1428 0052 7A95      		dec r23
 1429 0054 01F4      		brne 1b
 1430               	.LVL80:
 1431               	.L155:
 1432               	.LSM191:
 1433 0056 0130      		cpi r16,lo8(1)
 1434 0058 01F4      		brne .L156
 1435               	.LSM192:
 1436 005a 88E1      		ldi r24,lo8(24)
 1437 005c 7F2D      		mov r23,r15
 1438 005e 6E2D      		mov r22,r14
 1439 0060 5D2D      		mov r21,r13
 1440 0062 4C2D      		mov r20,r12
 1441 0064 00D0      		rcall send_cmd
 1442 0066 8823      		tst r24
 1443 0068 01F4      		brne .L157
 1444 006a 8C2F      		mov r24,r28
 1445 006c 9D2F      		mov r25,r29
 1446 006e 6EEF      		ldi r22,lo8(-2)
 1447 0070 00D0      		rcall xmit_datablock
 1448 0072 00E0      		ldi r16,lo8(0)
 1449 0074 00C0      		rjmp .L168
 1450               	.LVL81:
 1451               	.L156:
 1452               	.LSM193:
 1453 0076 8670      		andi r24,lo8(6)
 1454 0078 9070      		andi r25,hi8(6)
 1455 007a 892B      		or r24,r25
 1456 007c 01F0      		breq .L159
 1457 007e 402F      		mov r20,r16
 1458 0080 50E0      		ldi r21,lo8(0)
 1459               	.LVL82:
 1460 0082 60E0      		ldi r22,lo8(0)
 1461 0084 70E0      		ldi r23,hi8(0)
 1462               	.LVL83:
 1463 0086 87E9      		ldi r24,lo8(-105)
 1464 0088 00D0      		rcall send_cmd
 1465               	.LVL84:
 1466               	.L159:
 1467               	.LSM194:
 1468 008a 89E1      		ldi r24,lo8(25)
 1469 008c 7F2D      		mov r23,r15
 1470 008e 6E2D      		mov r22,r14
 1471 0090 5D2D      		mov r21,r13
 1472 0092 4C2D      		mov r20,r12
 1473 0094 00D0      		rcall send_cmd
 1474 0096 8823      		tst r24
 1475 0098 01F4      		brne .L157
 1476               	.L166:
 1477               	.LSM195:
 1478 009a 8C2F      		mov r24,r28
 1479 009c 9D2F      		mov r25,r29
 1480 009e 6CEF      		ldi r22,lo8(-4)
 1481 00a0 00D0      		rcall xmit_datablock
 1482 00a2 892B      		or r24,r25
 1483 00a4 01F0      		breq .L160
 1484               	.LSM196:
 1485 00a6 0150      		subi r16,lo8(-(-1))
 1486 00a8 01F0      		breq .L160
 1487               	.LSM197:
 1488 00aa C050      		subi r28,lo8(-(512))
 1489 00ac DE4F      		sbci r29,hi8(-(512))
 1490 00ae 00C0      		rjmp .L166
 1491               	.L160:
 1492               	.LSM198:
 1493 00b0 80E0      		ldi r24,lo8(0)
 1494 00b2 90E0      		ldi r25,hi8(0)
 1495 00b4 6DEF      		ldi r22,lo8(-3)
 1496 00b6 00D0      		rcall xmit_datablock
 1497               	.L168:
 1498 00b8 892B      		or r24,r25
 1499 00ba 01F4      		brne .L157
 1500 00bc 01E0      		ldi r16,lo8(1)
 1501               	.L157:
 1502               	.LBB130:
 1503               	.LBB131:
 1504               	.LSM199:
 1505 00be 289A      		sbi 37-32,0
 1506               	.LBB132:
 1507               	.LBB133:
 1508               	.LSM200:
 1509               	/* #APP */
 1510               	 ;  78 "diskio.c" 1
 1511 00c0 F894      		cli
 1512               	 ;  0 "" 2
 1513               	.LSM201:
 1514               	/* #NOAPP */
 1515 00c2 8FEF      		ldi r24,lo8(-1)
 1516 00c4 8EBD      		out 78-32,r24
 1517               	.L162:
 1518               	.LSM202:
 1519 00c6 0DB4      		in __tmp_reg__,77-32
 1520 00c8 07FE      		sbrs __tmp_reg__,7
 1521 00ca 00C0      		rjmp .L162
 1522               	.LSM203:
 1523               	/* #APP */
 1524               	 ;  81 "diskio.c" 1
 1525 00cc 7894      		sei
 1526               	 ;  0 "" 2
 1527               	.LSM204:
 1528               	/* #NOAPP */
 1529 00ce 8EB5      		in r24,78-32
 1530               	.LBE133:
 1531               	.LBE132:
 1532               	.LBE131:
 1533               	.LBE130:
 1534               	.LSM205:
 1535 00d0 0023      		tst r16
 1536 00d2 01F0      		breq .L153
 1537 00d4 01E0      		ldi r16,lo8(1)
 1538               	.LVL85:
 1539 00d6 00C0      		rjmp .L153
 1540               	.LVL86:
 1541               	.L151:
 1542 00d8 04E0      		ldi r16,lo8(4)
 1543               	.LVL87:
 1544               	.L153:
 1545               	.LSM206:
 1546 00da 802F      		mov r24,r16
 1547               	.LVL88:
 1548               	/* epilogue start */
 1549 00dc DF91      		pop r29
 1550 00de CF91      		pop r28
 1551               	.LVL89:
 1552 00e0 0F91      		pop r16
 1553 00e2 FF90      		pop r15
 1554 00e4 EF90      		pop r14
 1555 00e6 DF90      		pop r13
 1556 00e8 CF90      		pop r12
 1557               	.LVL90:
 1558 00ea 0895      		ret
 1559               	.LFE13:
 1561               		.section	.text.disk_ioctl,"ax",@progbits
 1562               	.global	disk_ioctl
 1564               	disk_ioctl:
 1565               	.LFB14:
 1566               	.LSM207:
 1567               	.LVL91:
 1568 0000 FF92      		push r15
 1569 0002 0F93      		push r16
 1570 0004 1F93      		push r17
 1571 0006 DF93      		push r29
 1572 0008 CF93      		push r28
 1573 000a CDB7      		in r28,__SP_L__
 1574 000c DEB7      		in r29,__SP_H__
 1575 000e 6097      		sbiw r28,16
 1576 0010 0FB6      		in __tmp_reg__,__SREG__
 1577 0012 F894      		cli
 1578 0014 DEBF      		out __SP_H__,r29
 1579 0016 0FBE      		out __SREG__,__tmp_reg__
 1580 0018 CDBF      		out __SP_L__,r28
 1581               	/* prologue: function */
 1582               	/* frame size = 16 */
 1583 001a 042F      		mov r16,r20
 1584 001c 152F      		mov r17,r21
 1585               	.LSM208:
 1586 001e 8823      		tst r24
 1587 0020 01F0      		breq .+2
 1588 0022 00C0      		rjmp .L170
 1589               	.LVL92:
 1590               	.LSM209:
 1591 0024 6530      		cpi r22,lo8(5)
 1592 0026 01F4      		brne .L171
 1593               	.LSM210:
 1594 0028 E42F      		mov r30,r20
 1595 002a F52F      		mov r31,r21
 1596 002c 8081      		ld r24,Z
 1597               	.LVL93:
 1598 002e 8230      		cpi r24,lo8(2)
 1599 0030 00F0      		brlo .L214
 1600               	.LVL94:
 1601 0032 8230      		cpi r24,lo8(2)
 1602 0034 01F0      		breq .+2
 1603 0036 00C0      		rjmp .L170
 1604               	.LSM211:
 1605 0038 81E0      		ldi r24,lo8(1)
 1606 003a E42F      		mov r30,r20
 1607 003c F52F      		mov r31,r21
 1608 003e 8183      		std Z+1,r24
 1609               	.L214:
 1610 0040 20E0      		ldi r18,lo8(0)
 1611               	.LVL95:
 1612 0042 00C0      		rjmp .L174
 1613               	.LVL96:
 1614               	.L171:
 1615               	.LSM212:
 1616 0044 8091 0000 		lds r24,Stat
 1617               	.LVL97:
 1618 0048 80FF      		sbrs r24,0
 1619 004a 00C0      		rjmp .L175
 1620 004c 23E0      		ldi r18,lo8(3)
 1621               	.LVL98:
 1622 004e 00C0      		rjmp .L174
 1623               	.LVL99:
 1624               	.L175:
 1625               	.LSM213:
 1626 0050 E62F      		mov r30,r22
 1627 0052 F0E0      		ldi r31,lo8(0)
 1628               	.LVL100:
 1629 0054 EF30      		cpi r30,15
 1630 0056 F105      		cpc r31,__zero_reg__
 1631 0058 00F4      		brsh .L176
 1632               	.LVL101:
 1633 005a E050      		subi r30,lo8(-(gs(.L186)))
 1634 005c F040      		sbci r31,hi8(-(gs(.L186)))
 1635               	.LVL102:
 1636 005e 0994      		ijmp
 1637               	.LVL103:
 1638               		.data
 1639               		.section .progmem.gcc_sw_table, "ax", @progbits
 1640               		.p2align 1
 1641               	.L186:
 1642               		.data
 1643               		.section .progmem.gcc_sw_table, "ax", @progbits
 1644               		.p2align 1
 1645 0000 00C0      		rjmp .L177
 1646 0002 00C0      		rjmp .L178
 1647 0004 00C0      		rjmp .L179
 1648 0006 00C0      		rjmp .L180
 1649 0008 00C0      		rjmp .L176
 1650 000a 00C0      		rjmp .L176
 1651 000c 00C0      		rjmp .L176
 1652 000e 00C0      		rjmp .L176
 1653 0010 00C0      		rjmp .L176
 1654 0012 00C0      		rjmp .L176
 1655 0014 00C0      		rjmp .L181
 1656 0016 00C0      		rjmp .L182
 1657 0018 00C0      		rjmp .L183
 1658 001a 00C0      		rjmp .L184
 1659 001c 00C0      		rjmp .L185
 1660               		.section	.text.disk_ioctl
 1661               	.LVL104:
 1662               	.L176:
 1663 0060 24E0      		ldi r18,lo8(4)
 1664               	.LVL105:
 1665 0062 00C0      		rjmp .L187
 1666               	.LVL106:
 1667               	.L177:
 1668               	.LSM214:
 1669 0064 00D0      		rcall select
 1670               	.LVL107:
 1671 0066 892B      		or r24,r25
 1672 0068 01F4      		brne .+2
 1673 006a 00C0      		rjmp .L188
 1674               	.LBB134:
 1675               	.LBB135:
 1676               	.LSM215:
 1677 006c 289A      		sbi 37-32,0
 1678               	.LBB136:
 1679               	.LBB137:
 1680               	.LSM216:
 1681               	/* #APP */
 1682               	 ;  78 "diskio.c" 1
 1683 006e F894      		cli
 1684               	 ;  0 "" 2
 1685               	.LSM217:
 1686               	/* #NOAPP */
 1687 0070 8FEF      		ldi r24,lo8(-1)
 1688 0072 8EBD      		out 78-32,r24
 1689               	.L189:
 1690               	.LSM218:
 1691 0074 0DB4      		in __tmp_reg__,77-32
 1692 0076 07FE      		sbrs __tmp_reg__,7
 1693 0078 00C0      		rjmp .L189
 1694               	.LSM219:
 1695               	/* #APP */
 1696               	 ;  81 "diskio.c" 1
 1697 007a 7894      		sei
 1698               	 ;  0 "" 2
 1699               	.LSM220:
 1700               	/* #NOAPP */
 1701 007c 8EB5      		in r24,78-32
 1702 007e 00C0      		rjmp .L212
 1703               	.LVL108:
 1704               	.L178:
 1705               	.LBE137:
 1706               	.LBE136:
 1707               	.LBE135:
 1708               	.LBE134:
 1709               	.LSM221:
 1710 0080 89E0      		ldi r24,lo8(9)
 1711 0082 40E0      		ldi r20,lo8(0)
 1712 0084 50E0      		ldi r21,hi8(0)
 1713 0086 60E0      		ldi r22,hlo8(0)
 1714 0088 70E0      		ldi r23,hhi8(0)
 1715 008a 00D0      		rcall send_cmd
 1716               	.LVL109:
 1717 008c 8823      		tst r24
 1718 008e 01F0      		breq .+2
 1719 0090 00C0      		rjmp .L188
 1720 0092 8C2F      		mov r24,r28
 1721 0094 9D2F      		mov r25,r29
 1722 0096 0196      		adiw r24,1
 1723 0098 60E1      		ldi r22,lo8(16)
 1724 009a 70E0      		ldi r23,hi8(16)
 1725 009c 00D0      		rcall rcvr_datablock
 1726 009e 892B      		or r24,r25
 1727 00a0 01F4      		brne .+2
 1728 00a2 00C0      		rjmp .L188
 1729               	.LSM222:
 1730 00a4 8981      		ldd r24,Y+1
 1731 00a6 8295      		swap r24
 1732 00a8 8695      		lsr r24
 1733 00aa 8695      		lsr r24
 1734 00ac 8370      		andi r24,lo8(3)
 1735 00ae 7A85      		ldd r23,Y+10
 1736 00b0 4985      		ldd r20,Y+9
 1737 00b2 8130      		cpi r24,lo8(1)
 1738 00b4 01F4      		brne .L190
 1739               	.LSM223:
 1740 00b6 872F      		mov r24,r23
 1741 00b8 90E0      		ldi r25,lo8(0)
 1742 00ba 0196      		adiw r24,1
 1743 00bc 342F      		mov r19,r20
 1744 00be 20E0      		ldi r18,lo8(0)
 1745 00c0 820F      		add r24,r18
 1746 00c2 931F      		adc r25,r19
 1747 00c4 A0E0      		ldi r26,lo8(0)
 1748 00c6 B0E0      		ldi r27,hi8(0)
 1749 00c8 3AE0      		ldi r19,10
 1750 00ca 880F      	1:	lsl r24
 1751 00cc 991F      		rol r25
 1752 00ce AA1F      		rol r26
 1753 00d0 BB1F      		rol r27
 1754 00d2 3A95      		dec r19
 1755 00d4 01F4      		brne 1b
 1756 00d6 E02F      		mov r30,r16
 1757 00d8 F12F      		mov r31,r17
 1758 00da 8083      		st Z,r24
 1759 00dc 9183      		std Z+1,r25
 1760 00de A283      		std Z+2,r26
 1761 00e0 B383      		std Z+3,r27
 1762 00e2 00C0      		rjmp .L187
 1763               	.L190:
 1764               	.LSM224:
 1765 00e4 4295      		swap r20
 1766 00e6 4695      		lsr r20
 1767 00e8 4695      		lsr r20
 1768 00ea 4370      		andi r20,lo8(3)
 1769 00ec 2885      		ldd r18,Y+8
 1770 00ee 30E0      		ldi r19,lo8(0)
 1771 00f0 220F      		lsl r18
 1772 00f2 331F      		rol r19
 1773 00f4 220F      		lsl r18
 1774 00f6 331F      		rol r19
 1775 00f8 240F      		add r18,r20
 1776 00fa 311D      		adc r19,__zero_reg__
 1777 00fc 2F5F      		subi r18,lo8(-(1))
 1778 00fe 3F4F      		sbci r19,hi8(-(1))
 1779 0100 8F81      		ldd r24,Y+7
 1780 0102 90E0      		ldi r25,lo8(0)
 1781 0104 8370      		andi r24,lo8(3)
 1782 0106 9070      		andi r25,hi8(3)
 1783 0108 982F      		mov r25,r24
 1784 010a 8827      		clr r24
 1785 010c 990F      		lsl r25
 1786 010e 990F      		lsl r25
 1787 0110 280F      		add r18,r24
 1788 0112 391F      		adc r19,r25
 1789 0114 40E0      		ldi r20,lo8(0)
 1790 0116 50E0      		ldi r21,hi8(0)
 1791 0118 8E81      		ldd r24,Y+6
 1792 011a 8F70      		andi r24,lo8(15)
 1793 011c 6B85      		ldd r22,Y+11
 1794 011e 661F      		rol r22
 1795 0120 6627      		clr r22
 1796 0122 661F      		rol r22
 1797 0124 860F      		add r24,r22
 1798 0126 8E5F      		subi r24,lo8(-(2))
 1799 0128 7370      		andi r23,lo8(3)
 1800 012a 770F      		lsl r23
 1801 012c 870F      		add r24,r23
 1802 012e 90E0      		ldi r25,lo8(0)
 1803 0130 0997      		sbiw r24,9
 1804 0132 00C0      		rjmp 2f
 1805 0134 220F      	1:	lsl r18
 1806 0136 331F      		rol r19
 1807 0138 441F      		rol r20
 1808 013a 551F      		rol r21
 1809 013c 8A95      	2:	dec r24
 1810 013e 02F4      		brpl 1b
 1811 0140 E02F      		mov r30,r16
 1812 0142 F12F      		mov r31,r17
 1813 0144 2083      		st Z,r18
 1814 0146 3183      		std Z+1,r19
 1815 0148 4283      		std Z+2,r20
 1816 014a 5383      		std Z+3,r21
 1817 014c 00C0      		rjmp .L212
 1818               	.LVL110:
 1819               	.L179:
 1820               	.LSM225:
 1821 014e 80E0      		ldi r24,lo8(512)
 1822 0150 92E0      		ldi r25,hi8(512)
 1823 0152 E42F      		mov r30,r20
 1824 0154 F52F      		mov r31,r21
 1825 0156 9183      		std Z+1,r25
 1826 0158 8083      		st Z,r24
 1827 015a 00C0      		rjmp .L212
 1828               	.L180:
 1829               	.LSM226:
 1830 015c 8091 0000 		lds r24,CardType
 1831 0160 F82E      		mov r15,r24
 1832 0162 82FF      		sbrs r24,2
 1833 0164 00C0      		rjmp .L191
 1834               	.LSM227:
 1835 0166 8DE8      		ldi r24,lo8(-115)
 1836 0168 40E0      		ldi r20,lo8(0)
 1837 016a 50E0      		ldi r21,hi8(0)
 1838 016c 60E0      		ldi r22,hlo8(0)
 1839 016e 70E0      		ldi r23,hhi8(0)
 1840 0170 00D0      		rcall send_cmd
 1841               	.LVL111:
 1842 0172 8823      		tst r24
 1843 0174 01F0      		breq .+2
 1844 0176 00C0      		rjmp .L188
 1845               	.LBB138:
 1846               	.LBB139:
 1847               	.LSM228:
 1848               	/* #APP */
 1849               	 ;  78 "diskio.c" 1
 1850 0178 F894      		cli
 1851               	 ;  0 "" 2
 1852               	.LSM229:
 1853               	/* #NOAPP */
 1854 017a 8FEF      		ldi r24,lo8(-1)
 1855 017c 8EBD      		out 78-32,r24
 1856               	.L192:
 1857               	.LSM230:
 1858 017e 0DB4      		in __tmp_reg__,77-32
 1859 0180 07FE      		sbrs __tmp_reg__,7
 1860 0182 00C0      		rjmp .L192
 1861               	.LSM231:
 1862               	/* #APP */
 1863               	 ;  81 "diskio.c" 1
 1864 0184 7894      		sei
 1865               	 ;  0 "" 2
 1866               	.LSM232:
 1867               	/* #NOAPP */
 1868 0186 8EB5      		in r24,78-32
 1869               	.LBE139:
 1870               	.LBE138:
 1871               	.LSM233:
 1872 0188 8C2F      		mov r24,r28
 1873 018a 9D2F      		mov r25,r29
 1874 018c 0196      		adiw r24,1
 1875 018e 60E1      		ldi r22,lo8(16)
 1876 0190 70E0      		ldi r23,hi8(16)
 1877 0192 00D0      		rcall rcvr_datablock
 1878 0194 892B      		or r24,r25
 1879 0196 01F4      		brne .+2
 1880 0198 00C0      		rjmp .L188
 1881 019a 80E3      		ldi r24,lo8(48)
 1882               	.LVL112:
 1883               	.LBB140:
 1884               	.LBB141:
 1885               	.LSM234:
 1886 019c 9FEF      		ldi r25,lo8(-1)
 1887               	.L194:
 1888               	.LSM235:
 1889               	/* #APP */
 1890               	 ;  78 "diskio.c" 1
 1891 019e F894      		cli
 1892               	 ;  0 "" 2
 1893               	.LSM236:
 1894               	/* #NOAPP */
 1895 01a0 9EBD      		out 78-32,r25
 1896               	.L193:
 1897               	.LSM237:
 1898 01a2 0DB4      		in __tmp_reg__,77-32
 1899 01a4 07FE      		sbrs __tmp_reg__,7
 1900 01a6 00C0      		rjmp .L193
 1901               	.LSM238:
 1902               	/* #APP */
 1903               	 ;  81 "diskio.c" 1
 1904 01a8 7894      		sei
 1905               	 ;  0 "" 2
 1906               	.LSM239:
 1907               	/* #NOAPP */
 1908 01aa 2EB5      		in r18,78-32
 1909               	.LBE141:
 1910               	.LBE140:
 1911               	.LSM240:
 1912 01ac 8150      		subi r24,lo8(-(-1))
 1913 01ae 01F4      		brne .L194
 1914               	.LSM241:
 1915 01b0 2B85      		ldd r18,Y+11
 1916 01b2 2295      		swap r18
 1917 01b4 2F70      		andi r18,lo8(15)
 1918 01b6 80E1      		ldi r24,lo8(16)
 1919 01b8 90E0      		ldi r25,hi8(16)
 1920 01ba A0E0      		ldi r26,hlo8(16)
 1921 01bc B0E0      		ldi r27,hhi8(16)
 1922               	.LVL113:
 1923 01be 00C0      		rjmp 2f
 1924 01c0 880F      	1:	lsl r24
 1925 01c2 991F      		rol r25
 1926 01c4 AA1F      		rol r26
 1927 01c6 BB1F      		rol r27
 1928 01c8 2A95      	2:	dec r18
 1929 01ca 02F4      		brpl 1b
 1930 01cc 00C0      		rjmp .L215
 1931               	.LVL114:
 1932               	.L191:
 1933               	.LSM242:
 1934 01ce 89E0      		ldi r24,lo8(9)
 1935 01d0 40E0      		ldi r20,lo8(0)
 1936 01d2 50E0      		ldi r21,hi8(0)
 1937 01d4 60E0      		ldi r22,hlo8(0)
 1938 01d6 70E0      		ldi r23,hhi8(0)
 1939 01d8 00D0      		rcall send_cmd
 1940               	.LVL115:
 1941 01da 8823      		tst r24
 1942 01dc 01F0      		breq .+2
 1943 01de 00C0      		rjmp .L188
 1944 01e0 8C2F      		mov r24,r28
 1945 01e2 9D2F      		mov r25,r29
 1946 01e4 0196      		adiw r24,1
 1947 01e6 60E1      		ldi r22,lo8(16)
 1948 01e8 70E0      		ldi r23,hi8(16)
 1949 01ea 00D0      		rcall rcvr_datablock
 1950 01ec 892B      		or r24,r25
 1951 01ee 01F4      		brne .+2
 1952 01f0 00C0      		rjmp .L188
 1953 01f2 2B85      		ldd r18,Y+11
 1954 01f4 4C85      		ldd r20,Y+12
 1955               	.LSM243:
 1956 01f6 F1FE      		sbrs r15,1
 1957 01f8 00C0      		rjmp .L195
 1958               	.LSM244:
 1959 01fa 441F      		rol r20
 1960 01fc 4427      		clr r20
 1961 01fe 441F      		rol r20
 1962 0200 842F      		mov r24,r20
 1963 0202 90E0      		ldi r25,lo8(0)
 1964 0204 0196      		adiw r24,1
 1965 0206 30E0      		ldi r19,lo8(0)
 1966 0208 2F73      		andi r18,lo8(63)
 1967 020a 3070      		andi r19,hi8(63)
 1968 020c 220F      		lsl r18
 1969 020e 331F      		rol r19
 1970 0210 820F      		add r24,r18
 1971 0212 931F      		adc r25,r19
 1972 0214 2E85      		ldd r18,Y+14
 1973 0216 2295      		swap r18
 1974 0218 2695      		lsr r18
 1975 021a 2695      		lsr r18
 1976 021c 2370      		andi r18,lo8(3)
 1977 021e 30E0      		ldi r19,lo8(0)
 1978 0220 2150      		subi r18,lo8(-(-1))
 1979 0222 3040      		sbci r19,hi8(-(-1))
 1980 0224 00C0      		rjmp 2f
 1981 0226 880F      	1:	lsl r24
 1982 0228 991F      		rol r25
 1983 022a 2A95      	2:	dec r18
 1984 022c 02F4      		brpl 1b
 1985 022e 00C0      		rjmp .L217
 1986               	.L195:
 1987               	.LSM245:
 1988 0230 842F      		mov r24,r20
 1989 0232 90E0      		ldi r25,lo8(0)
 1990 0234 8370      		andi r24,lo8(3)
 1991 0236 9070      		andi r25,hi8(3)
 1992 0238 F3E0      		ldi r31,3
 1993 023a 880F      	1:	lsl r24
 1994 023c 991F      		rol r25
 1995 023e FA95      		dec r31
 1996 0240 01F4      		brne 1b
 1997 0242 4295      		swap r20
 1998 0244 4695      		lsr r20
 1999 0246 4770      		andi r20,lo8(7)
 2000 0248 840F      		add r24,r20
 2001 024a 911D      		adc r25,__zero_reg__
 2002 024c 622F      		mov r22,r18
 2003 024e 70E0      		ldi r23,lo8(0)
 2004 0250 6C77      		andi r22,lo8(124)
 2005 0252 7070      		andi r23,hi8(124)
 2006 0254 7595      		asr r23
 2007 0256 6795      		ror r22
 2008 0258 7595      		asr r23
 2009 025a 6795      		ror r22
 2010 025c 6F5F      		subi r22,lo8(-(1))
 2011 025e 7F4F      		sbci r23,hi8(-(1))
 2012 0260 0196      		adiw r24,1
 2013 0262 00D0      		rcall __mulhi3
 2014               	.L217:
 2015 0264 A0E0      		ldi r26,lo8(0)
 2016 0266 B0E0      		ldi r27,hi8(0)
 2017               	.L215:
 2018 0268 E02F      		mov r30,r16
 2019 026a F12F      		mov r31,r17
 2020 026c 8083      		st Z,r24
 2021 026e 9183      		std Z+1,r25
 2022 0270 A283      		std Z+2,r26
 2023 0272 B383      		std Z+3,r27
 2024               	.LVL116:
 2025               	.L212:
 2026 0274 20E0      		ldi r18,lo8(0)
 2027               	.LVL117:
 2028 0276 00C0      		rjmp .L187
 2029               	.LVL118:
 2030               	.L181:
 2031               	.LSM246:
 2032 0278 8091 0000 		lds r24,CardType
 2033 027c E42F      		mov r30,r20
 2034 027e F52F      		mov r31,r21
 2035 0280 8083      		st Z,r24
 2036 0282 00C0      		rjmp .L212
 2037               	.L182:
 2038               	.LSM247:
 2039 0284 89E0      		ldi r24,lo8(9)
 2040 0286 00C0      		rjmp .L219
 2041               	.L183:
 2042               	.LSM248:
 2043 0288 8AE0      		ldi r24,lo8(10)
 2044               	.L219:
 2045 028a 40E0      		ldi r20,lo8(0)
 2046 028c 50E0      		ldi r21,hi8(0)
 2047 028e 60E0      		ldi r22,hlo8(0)
 2048 0290 70E0      		ldi r23,hhi8(0)
 2049 0292 00D0      		rcall send_cmd
 2050               	.LVL119:
 2051 0294 8823      		tst r24
 2052 0296 01F4      		brne .L188
 2053 0298 802F      		mov r24,r16
 2054 029a 912F      		mov r25,r17
 2055 029c 60E1      		ldi r22,lo8(16)
 2056 029e 70E0      		ldi r23,hi8(16)
 2057 02a0 00C0      		rjmp .L213
 2058               	.LVL120:
 2059               	.L184:
 2060               	.LSM249:
 2061 02a2 8AE3      		ldi r24,lo8(58)
 2062 02a4 40E0      		ldi r20,lo8(0)
 2063 02a6 50E0      		ldi r21,hi8(0)
 2064 02a8 60E0      		ldi r22,hlo8(0)
 2065 02aa 70E0      		ldi r23,hhi8(0)
 2066 02ac 00D0      		rcall send_cmd
 2067               	.LVL121:
 2068 02ae 8823      		tst r24
 2069 02b0 01F4      		brne .L188
 2070 02b2 E02F      		mov r30,r16
 2071 02b4 F12F      		mov r31,r17
 2072               	.LVL122:
 2073               	.LBB142:
 2074               	.LBB143:
 2075               	.LSM250:
 2076 02b6 9FEF      		ldi r25,lo8(-1)
 2077               	.LBE143:
 2078               	.LBE142:
 2079               	.LSM251:
 2080 02b8 202F      		mov r18,r16
 2081 02ba 312F      		mov r19,r17
 2082 02bc 2D5F      		subi r18,lo8(-(3))
 2083 02be 3F4F      		sbci r19,hi8(-(3))
 2084               	.L200:
 2085               	.LBB145:
 2086               	.LBB144:
 2087               	.LSM252:
 2088               	/* #APP */
 2089               	 ;  78 "diskio.c" 1
 2090 02c0 F894      		cli
 2091               	 ;  0 "" 2
 2092               	.LSM253:
 2093               	/* #NOAPP */
 2094 02c2 9EBD      		out 78-32,r25
 2095               	.LVL123:
 2096               	.L198:
 2097               	.LSM254:
 2098 02c4 0DB4      		in __tmp_reg__,77-32
 2099 02c6 07FE      		sbrs __tmp_reg__,7
 2100 02c8 00C0      		rjmp .L198
 2101               	.LSM255:
 2102               	/* #APP */
 2103               	 ;  81 "diskio.c" 1
 2104 02ca 7894      		sei
 2105               	 ;  0 "" 2
 2106               	.LSM256:
 2107               	/* #NOAPP */
 2108 02cc 8EB5      		in r24,78-32
 2109               	.LBE144:
 2110               	.LBE145:
 2111               	.LSM257:
 2112 02ce 8083      		st Z,r24
 2113 02d0 E217      		cp r30,r18
 2114 02d2 F307      		cpc r31,r19
 2115 02d4 01F0      		breq .L212
 2116               	.LVL124:
 2117               	.L199:
 2118 02d6 3196      		adiw r30,1
 2119 02d8 00C0      		rjmp .L200
 2120               	.LVL125:
 2121               	.L185:
 2122               	.LSM258:
 2123 02da 8DE8      		ldi r24,lo8(-115)
 2124 02dc 40E0      		ldi r20,lo8(0)
 2125 02de 50E0      		ldi r21,hi8(0)
 2126 02e0 60E0      		ldi r22,hlo8(0)
 2127 02e2 70E0      		ldi r23,hhi8(0)
 2128 02e4 00D0      		rcall send_cmd
 2129               	.LVL126:
 2130 02e6 8823      		tst r24
 2131 02e8 01F4      		brne .L188
 2132               	.LBB146:
 2133               	.LBB147:
 2134               	.LSM259:
 2135               	/* #APP */
 2136               	 ;  78 "diskio.c" 1
 2137 02ea F894      		cli
 2138               	 ;  0 "" 2
 2139               	.LSM260:
 2140               	/* #NOAPP */
 2141 02ec 8FEF      		ldi r24,lo8(-1)
 2142 02ee 8EBD      		out 78-32,r24
 2143               	.L201:
 2144               	.LSM261:
 2145 02f0 0DB4      		in __tmp_reg__,77-32
 2146 02f2 07FE      		sbrs __tmp_reg__,7
 2147 02f4 00C0      		rjmp .L201
 2148               	.LSM262:
 2149               	/* #APP */
 2150               	 ;  81 "diskio.c" 1
 2151 02f6 7894      		sei
 2152               	 ;  0 "" 2
 2153               	.LSM263:
 2154               	/* #NOAPP */
 2155 02f8 8EB5      		in r24,78-32
 2156               	.LBE147:
 2157               	.LBE146:
 2158               	.LSM264:
 2159 02fa 802F      		mov r24,r16
 2160 02fc 912F      		mov r25,r17
 2161 02fe 60E4      		ldi r22,lo8(64)
 2162 0300 70E0      		ldi r23,hi8(64)
 2163               	.L213:
 2164 0302 00D0      		rcall rcvr_datablock
 2165 0304 20E0      		ldi r18,lo8(0)
 2166               	.LVL127:
 2167 0306 892B      		or r24,r25
 2168 0308 01F4      		brne .L187
 2169               	.L188:
 2170 030a 21E0      		ldi r18,lo8(1)
 2171               	.LVL128:
 2172               	.L187:
 2173               	.LBB148:
 2174               	.LBB149:
 2175               	.LSM265:
 2176 030c 289A      		sbi 37-32,0
 2177               	.LBB150:
 2178               	.LBB151:
 2179               	.LSM266:
 2180               	/* #APP */
 2181               	 ;  78 "diskio.c" 1
 2182 030e F894      		cli
 2183               	 ;  0 "" 2
 2184               	.LSM267:
 2185               	/* #NOAPP */
 2186 0310 8FEF      		ldi r24,lo8(-1)
 2187 0312 8EBD      		out 78-32,r24
 2188               	.L203:
 2189               	.LSM268:
 2190 0314 0DB4      		in __tmp_reg__,77-32
 2191 0316 07FE      		sbrs __tmp_reg__,7
 2192 0318 00C0      		rjmp .L203
 2193               	.LSM269:
 2194               	/* #APP */
 2195               	 ;  81 "diskio.c" 1
 2196 031a 7894      		sei
 2197               	 ;  0 "" 2
 2198               	.LSM270:
 2199               	/* #NOAPP */
 2200 031c 8EB5      		in r24,78-32
 2201 031e 00C0      		rjmp .L174
 2202               	.LVL129:
 2203               	.L170:
 2204 0320 24E0      		ldi r18,lo8(4)
 2205               	.LVL130:
 2206               	.L174:
 2207               	.LBE151:
 2208               	.LBE150:
 2209               	.LBE149:
 2210               	.LBE148:
 2211               	.LSM271:
 2212 0322 822F      		mov r24,r18
 2213               	.LVL131:
 2214               	/* epilogue start */
 2215 0324 6096      		adiw r28,16
 2216 0326 0FB6      		in __tmp_reg__,__SREG__
 2217 0328 F894      		cli
 2218 032a DEBF      		out __SP_H__,r29
 2219 032c 0FBE      		out __SREG__,__tmp_reg__
 2220 032e CDBF      		out __SP_L__,r28
 2221 0330 CF91      		pop r28
 2222 0332 DF91      		pop r29
 2223 0334 1F91      		pop r17
 2224 0336 0F91      		pop r16
 2225               	.LVL132:
 2226 0338 FF90      		pop r15
 2227 033a 0895      		ret
 2228               	.LFE14:
 2230               		.section	.text.disk_timerproc,"ax",@progbits
 2231               	.global	disk_timerproc
 2233               	disk_timerproc:
 2234               	.LFB15:
 2235               	.LSM272:
 2236               	/* prologue: function */
 2237               	/* frame size = 0 */
 2238               	.LSM273:
 2239 0000 8091 0000 		lds r24,Timer1
 2240               	.LVL133:
 2241               	.LSM274:
 2242 0004 8823      		tst r24
 2243 0006 01F0      		breq .L221
 2244 0008 8150      		subi r24,lo8(-(-1))
 2245 000a 8093 0000 		sts Timer1,r24
 2246               	.L221:
 2247               	.LSM275:
 2248 000e 8091 0000 		lds r24,Timer2
 2249               	.LVL134:
 2250               	.LSM276:
 2251 0012 8823      		tst r24
 2252 0014 01F0      		breq .L222
 2253 0016 8150      		subi r24,lo8(-(-1))
 2254 0018 8093 0000 		sts Timer2,r24
 2255               	.L222:
 2256               	.LSM277:
 2257 001c 9091 0000 		lds r25,pv.1651
 2258               	.LVL135:
 2259               	.LSM278:
 2260 0020 83B1      		in r24,35-32
 2261 0022 8073      		andi r24,lo8(48)
 2262 0024 8093 0000 		sts pv.1651,r24
 2263               	.LSM279:
 2264 0028 9817      		cp r25,r24
 2265 002a 01F4      		brne .L228
 2266               	.LSM280:
 2267 002c 8091 0000 		lds r24,Stat
 2268               	.LVL136:
 2269               	.LSM281:
 2270 0030 95FF      		sbrs r25,5
 2271 0032 00C0      		rjmp .L224
 2272               	.LVL137:
 2273               	.LSM282:
 2274 0034 8460      		ori r24,lo8(4)
 2275               	.LVL138:
 2276 0036 00C0      		rjmp .L225
 2277               	.L224:
 2278               	.LSM283:
 2279 0038 8B7F      		andi r24,lo8(-5)
 2280               	.LVL139:
 2281               	.L225:
 2282               	.LSM284:
 2283 003a 94FF      		sbrs r25,4
 2284 003c 00C0      		rjmp .L226
 2285               	.LSM285:
 2286 003e 8360      		ori r24,lo8(3)
 2287               	.LVL140:
 2288 0040 00C0      		rjmp .L227
 2289               	.L226:
 2290               	.LSM286:
 2291 0042 8D7F      		andi r24,lo8(-3)
 2292               	.LVL141:
 2293               	.L227:
 2294               	.LSM287:
 2295 0044 8093 0000 		sts Stat,r24
 2296               	.LVL142:
 2297               	.L228:
 2298 0048 0895      		ret
 2299               	.LFE15:
 2301               		.section	.text.get_fattime,"ax",@progbits
 2302               	.global	get_fattime
 2304               	get_fattime:
 2305               	.LFB16:
 2306               	.LSM288:
 2307               	/* prologue: function */
 2308               	/* frame size = 0 */
 2309               	.LSM289:
 2310 0000 60E0      		ldi r22,lo8(0)
 2311 0002 70E0      		ldi r23,hi8(0)
 2312 0004 80E0      		ldi r24,hlo8(0)
 2313 0006 90E0      		ldi r25,hhi8(0)
 2314               	/* epilogue start */
 2315 0008 0895      		ret
 2316               	.LFE16:
 2318               		.data
 2321               	Stat:
 2322 0000 01        		.byte	1
 2323               		.lcomm pv.1651,1
 2324               		.lcomm Timer1,1
 2325               		.lcomm Timer2,1
 2326               		.lcomm CardType,1
 2431               	.Letext0:
DEFINED SYMBOLS
                            *ABS*:00000000 diskio.c
C:\Users\Kamal\AppData\Local\Temp/ccwP4Q7F.s:2      *ABS*:0000003f __SREG__
C:\Users\Kamal\AppData\Local\Temp/ccwP4Q7F.s:3      *ABS*:0000003e __SP_H__
C:\Users\Kamal\AppData\Local\Temp/ccwP4Q7F.s:4      *ABS*:0000003d __SP_L__
C:\Users\Kamal\AppData\Local\Temp/ccwP4Q7F.s:5      *ABS*:00000034 __CCP__
C:\Users\Kamal\AppData\Local\Temp/ccwP4Q7F.s:6      *ABS*:00000000 __tmp_reg__
C:\Users\Kamal\AppData\Local\Temp/ccwP4Q7F.s:7      *ABS*:00000001 __zero_reg__
C:\Users\Kamal\AppData\Local\Temp/ccwP4Q7F.s:18     .text.select:00000000 select
C:\Users\Kamal\AppData\Local\Temp/ccwP4Q7F.s:2324   .bss:00000002 Timer2
C:\Users\Kamal\AppData\Local\Temp/ccwP4Q7F.s:152    .text.rcvr_datablock:00000000 rcvr_datablock
C:\Users\Kamal\AppData\Local\Temp/ccwP4Q7F.s:2323   .bss:00000001 Timer1
C:\Users\Kamal\AppData\Local\Temp/ccwP4Q7F.s:321    .text.xmit_datablock:00000000 xmit_datablock
C:\Users\Kamal\AppData\Local\Temp/ccwP4Q7F.s:548    .text.send_cmd:00000000 send_cmd
C:\Users\Kamal\AppData\Local\Temp/ccwP4Q7F.s:836    .text.disk_initialize:00000000 disk_initialize
C:\Users\Kamal\AppData\Local\Temp/ccwP4Q7F.s:2321   .data:00000000 Stat
C:\Users\Kamal\AppData\Local\Temp/ccwP4Q7F.s:2325   .bss:00000003 CardType
C:\Users\Kamal\AppData\Local\Temp/ccwP4Q7F.s:1185   .text.disk_status:00000000 disk_status
C:\Users\Kamal\AppData\Local\Temp/ccwP4Q7F.s:1209   .text.disk_read:00000000 disk_read
C:\Users\Kamal\AppData\Local\Temp/ccwP4Q7F.s:1370   .text.disk_write:00000000 disk_write
C:\Users\Kamal\AppData\Local\Temp/ccwP4Q7F.s:1564   .text.disk_ioctl:00000000 disk_ioctl
C:\Users\Kamal\AppData\Local\Temp/ccwP4Q7F.s:2233   .text.disk_timerproc:00000000 disk_timerproc
                             .bss:00000000 pv.1651
C:\Users\Kamal\AppData\Local\Temp/ccwP4Q7F.s:2304   .text.get_fattime:00000000 get_fattime

UNDEFINED SYMBOLS
__mulhi3
__do_copy_data
__do_clear_bss
