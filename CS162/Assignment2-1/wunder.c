 /*
 Author: Kamal Chaya
 Filename: wunder.c
 Date: DUE 4.21.2013
 Description: Creates a binary clock using the LED array of the wunderboard.
 Input: None
 Output: A 24 hour clock in binary format on the wunderboards LED array
 
 */
 
 /*
 * @file wunder.c
 * @author Dan Albert
 * @date Created 12/15/2010
 * @date Last updated 12/15/2010
 * @version 1.0
 *
 * @section LICENSE
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * @section DESCRIPTION
 * 
 * This program will test the various components of the Wunderboard when used
 * with the corresponding host test script.
 * 
 */

#include <pthread.h>
#include <avr/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "adc.h"
#include "diskio.h"
#include "types.h"
#include "usart.h"
#include "leds.h"

// 9600 baud
#define BAUD_RATE 51

#define CPU_PRESCALE(n) (CLKPR = 0x80, CLKPR = (n))

#define CPU_SCALE_FCTR 1304.61


void initialize()
{
	CPU_PRESCALE(0);
	
	USART_Init(BAUD_RATE);
	USART_Transmit('\f');	// Send form feed to clear the terminal.
	USART_SendString("WunderBoard initializing...\r\n");
	
	USART_SendString("\tSetting ADC prescaler and disabling free running mode...\r\n");
	SetupADC(ADC_PRESCALER_32, FALSE);
	
	USART_SendString("\tEnabling ADC...\r\n");
	ADCEnable();
	
	USART_SendString("\tSetting ADC reference to Vcc...\r\n");
	ADCSetReference(ADC_REF_VCC);
	
	// Configure IO //
	USART_SendString("\tConfiguring IO...\r\n");
	//DDRx corresponds to PORTx/PINx, dependng on direction of data flow -- PORT for output, PIN for input
	DDRA = 0x00;	// Buttons and switches
	DDRB = 0xE7;	// Red enable, green enable and audio out
	DDRC = 0xff;	// Discrete LEDs
	DDRE = 0x47;	// LED Column
	DDRF = 0x00;	// Accelerometer
	
	// Disable pullups and set outputs low //
	PORTA = 0x00;
	PORTB = 0x01;
	PORTE = 0x00;
	PORTF = 0x00;
	
	//Set OC1A to toggle
	TCCR1A = 0b01000000;
	// Clk/64 and CTC mode
	TCCR1B = 0b00001011;

	OCR1A = 24;

	USART_SendString("\tSetting SPI\r\n");
	
	//Set the SPI bus appropriately to use the LED array
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);

}


int main(int argc, char **argv)
{
	DSTATUS status;
	uint8_t buffer[512];
	unsigned char recv;
	
	initialize();

	clearArray();

	_delay_ms(200);
	_delay_ms(200);
	_delay_ms(200);
	_delay_ms(200);
	_delay_ms(200);
	
	//24 hr clock, init at 00:00:00
	

	
	
	
	while (1) {
		//s1 and s10 are the ones and 10s places for seconds (respectively).
		int i = 0, s1 = 0, s10 = 0;
	
		//m1 and m10 are the 1's and 10's places for minutes (respectively).
		int m1 = 0, m10 = 0;
	
		//h1 and h10 are the 1's and 10's places for hours (respectively).
		int h1 = 0, h10 = 0;
		
		/*
		 We need to track the number of times that h1 is equal to 4. The first time, 
		 is when the hour is 4. The second time, is when the hour is 14,
		 and the third is when the hour is 24. As soon as 
		 we get 24 (ie as soon as the fourcount value = 3), we need to roll over
		 to 00:00:00. 
		 */
		int fourCntH1 = 0;
		
		
		for (h10 = 0; h10 <= 2; h10++) {
			for (h1 = 0; h1 <= 9; h1++) {
				if (h1 == 4)
					fourCntH1++;
			
				for (m10 = 0; m10 <= 5; m10++) {
					for (m1 = 0; m1 <= 9; m1++) {
						for (s10 = 0; s10 <= 5; s10++) {
							for (s1 = 0; s1 <= 9; s1++) {
								/*
									Although we use _delay_ms(0.1) 6 times,
									which means the execution should take 0.6
									seconds for each iteration (and .6*1667 = 1000ms
									for the entire loop), the CPU cannot execute
									the instructions this fast. The CPU actually
									takes 4600 ms to execute the 
									entire loop below (this was timed with a stopwatch). 
									
									If 1667 iterations equals 4600 ms for the CPU,
									then 362.39 iterations equals 1000 ms for the CPU.
									1667 - 362.39 = 1304.61, thus we define
									CPU_SCALE_FCTR as 1304.61 (see top for this 
									macro def.), and subtract it from 1667. 
									Thus, we will only iterate
									approximately 362 times.
									
									// i <= (1667 - CPU_SCALE_FCTR)
								 */
								for (i = 0; i <= (1667 - CPU_SCALE_FCTR); i++) {
								
									if (fourCntH1 == 3) {
										PORTE = 4; //For hours 1's place
										set_array_blue(h1);
										_delay_ms(0.1);
										set_array_blue(0);
										
										PORTE = 5; //For hours 10's place
										set_array_blue(h10);
										_delay_ms(0.1);
										set_array_blue(0);
										
										/*
										 Set all the values that the for loops
										 iterate through so that they do not
										 satisfy their for loops conditions.
										 This will make the program break out 
										 of all the nested for loops, and so
										 the clock must roll over to 00:00:00
										 
										 THe actual values they are assigned to
										 do not matter as long as they do NOT 
										 satisfy the for loop conditions.
										 */
										
										s1 = 10;
										s10 = 6;
										m1 = 10;
										m10 = 6;
										h1 = 10;
										h10 = 3;
										i = 2000;	
									}
									
									else {
										PORTE = 0; //For seconds 1's place
										set_array_blue(s1); 
										_delay_ms(0.1);
										set_array_blue(0);
										
										PORTE = 1; //For seconds 10's place
										set_array_blue(s10);
										_delay_ms(0.1);
										set_array_blue(0);
										
										PORTE = 2; //For minutes 1's place
										set_array_blue(m1);
										_delay_ms(0.1);
										set_array_blue(0);
										
										PORTE = 3; //For minutes 10's place
										set_array_blue(m10);
										_delay_ms(0.1);
										set_array_blue(0);
										
										PORTE = 4; //For hours 1's place
										set_array_blue(h1);
										_delay_ms(0.1);
										set_array_blue(0);
										
										PORTE = 5; //For hours 10's place
										set_array_blue(h10);
										_delay_ms(0.1);
										set_array_blue(0);
									}
								}
							}
						}
					}
				}
			}
		}
	}

	return 0;
}	
