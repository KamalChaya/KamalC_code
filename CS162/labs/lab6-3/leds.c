   1               		.file	"leds.c"
   2               	__SREG__ = 0x3f
   3               	__SP_H__ = 0x3e
   4               	__SP_L__ = 0x3d
   5               	__CCP__  = 0x34
   6               	__tmp_reg__ = 0
   7               	__zero_reg__ = 1
  15               	.Ltext0:
  16               		.section	.text.set_array_green,"ax",@progbits
  17               	.global	set_array_green
  19               	set_array_green:
  20               	.LFB6:
  21               	.LSM0:
  22               	.LVL0:
  23               	/* prologue: function */
  24               	/* frame size = 0 */
  25               	/* epilogue start */
  26               	.LSM1:
  27 0000 0895      		ret
  28               	.LFE6:
  30               		.section	.text.set_array_blue,"ax",@progbits
  31               	.global	set_array_blue
  33               	set_array_blue:
  34               	.LFB7:
  35               	.LSM2:
  36               	.LVL1:
  37               	/* prologue: function */
  38               	/* frame size = 0 */
  39               	/* epilogue start */
  40               	.LSM3:
  41 0000 0895      		ret
  42               	.LFE7:
  44               		.section	.text.set_array_red,"ax",@progbits
  45               	.global	set_array_red
  47               	set_array_red:
  48               	.LFB8:
  49               	.LSM4:
  50               	.LVL2:
  51               	/* prologue: function */
  52               	/* frame size = 0 */
  53               	/* epilogue start */
  54               	.LSM5:
  55 0000 0895      		ret
  56               	.LFE8:
  58               		.section	.text.clear_array,"ax",@progbits
  59               	.global	clear_array
  61               	clear_array:
  62               	.LFB9:
  63               	.LSM6:
  64               	/* prologue: function */
  65               	/* frame size = 0 */
  66               	/* epilogue start */
  67               	.LSM7:
  68 0000 0895      		ret
  69               	.LFE9:
  71               		.section	.text.update_row,"ax",@progbits
  72               	.global	update_row
  74               	update_row:
  75               	.LFB10:
  76               	.LSM8:
  77               	.LVL3:
  78               	/* prologue: function */
  79               	/* frame size = 0 */
  80               	/* epilogue start */
  81               	.LSM9:
  82 0000 0895      		ret
  83               	.LFE10:
  85               		.section	.text.led_red,"ax",@progbits
  86               	.global	led_red
  88               	led_red:
  89               	.LFB11:
  90               	.LSM10:
  91               	.LVL4:
  92               	/* prologue: function */
  93               	/* frame size = 0 */
  94               	/* epilogue start */
  95               	.LSM11:
  96 0000 0895      		ret
  97               	.LFE11:
  99               		.section	.text.led_green,"ax",@progbits
 100               	.global	led_green
 102               	led_green:
 103               	.LFB12:
 104               	.LSM12:
 105               	.LVL5:
 106               	/* prologue: function */
 107               	/* frame size = 0 */
 108               	/* epilogue start */
 109               	.LSM13:
 110 0000 0895      		ret
 111               	.LFE12:
 113               		.section	.text.led_blue,"ax",@progbits
 114               	.global	led_blue
 116               	led_blue:
 117               	.LFB13:
 118               	.LSM14:
 119               	.LVL6:
 120               	/* prologue: function */
 121               	/* frame size = 0 */
 122               	/* epilogue start */
 123               	.LSM15:
 124 0000 0895      		ret
 125               	.LFE13:
 127               		.section	.text.led_off,"ax",@progbits
 128               	.global	led_off
 130               	led_off:
 131               	.LFB14:
 132               	.LSM16:
 133               	/* prologue: function */
 134               	/* frame size = 0 */
 135               	/* epilogue start */
 136               	.LSM17:
 137 0000 0895      		ret
 138               	.LFE14:
 228               	.Letext0:
DEFINED SYMBOLS
                            *ABS*:00000000 leds.c
C:\Users\Kamal\AppData\Local\Temp/cccn3c8U.s:2      *ABS*:0000003f __SREG__
C:\Users\Kamal\AppData\Local\Temp/cccn3c8U.s:3      *ABS*:0000003e __SP_H__
C:\Users\Kamal\AppData\Local\Temp/cccn3c8U.s:4      *ABS*:0000003d __SP_L__
C:\Users\Kamal\AppData\Local\Temp/cccn3c8U.s:5      *ABS*:00000034 __CCP__
C:\Users\Kamal\AppData\Local\Temp/cccn3c8U.s:6      *ABS*:00000000 __tmp_reg__
C:\Users\Kamal\AppData\Local\Temp/cccn3c8U.s:7      *ABS*:00000001 __zero_reg__
C:\Users\Kamal\AppData\Local\Temp/cccn3c8U.s:19     .text.set_array_green:00000000 set_array_green
C:\Users\Kamal\AppData\Local\Temp/cccn3c8U.s:33     .text.set_array_blue:00000000 set_array_blue
C:\Users\Kamal\AppData\Local\Temp/cccn3c8U.s:47     .text.set_array_red:00000000 set_array_red
C:\Users\Kamal\AppData\Local\Temp/cccn3c8U.s:61     .text.clear_array:00000000 clear_array
C:\Users\Kamal\AppData\Local\Temp/cccn3c8U.s:74     .text.update_row:00000000 update_row
C:\Users\Kamal\AppData\Local\Temp/cccn3c8U.s:88     .text.led_red:00000000 led_red
C:\Users\Kamal\AppData\Local\Temp/cccn3c8U.s:102    .text.led_green:00000000 led_green
C:\Users\Kamal\AppData\Local\Temp/cccn3c8U.s:116    .text.led_blue:00000000 led_blue
C:\Users\Kamal\AppData\Local\Temp/cccn3c8U.s:130    .text.led_off:00000000 led_off

NO UNDEFINED SYMBOLS
