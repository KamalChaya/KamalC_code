/*
	Author: Kamal Chaya
	Filename: clock.c (CHANGE back to wunder.c or change makefile).
	Description: Implements a binary clock on the wunderboard using polling.
	Date: DUE 5.3.2013
	Input: None
	Output: Binary clock on the LED arrays of the wunderboard.

 */
/**
 * @file wunder.c
 * @author Dan Albert
 * @author Marshal Horn
 * @date Created 12/15/2010
 * @date Last updated 1/20/2013
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

#include <util/delay.h>
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
#include "myitoa.h" 

// 9600 baud
#define BAUD_RATE 51

#define CPU_PRESCALE(n) (CLKPR = 0x80, CLKPR = (n))
 
#define LED_DELAY 0.1

//Define True/False 
#define TRUE 1
#define FALSE 0

void initialize( void )
{
	CPU_PRESCALE(0);
	
	USART_init(BAUD_RATE);
	USART_transmit('\f');	// Send form feed to clear the terminal.
	USART_send_string("WunderBoard initializing...\r\n");
	
	USART_send_string("\tSetting ADC prescaler and disabling free running mode...\r\n");
	setup_ADC(ADC_PRESCALER_32, FALSE);
	
	USART_send_string("\tEnabling ADC...\r\n");
	ADC_enable();
	
	USART_send_string("\tSetting ADC reference to Vcc...\r\n");
	ADC_set_reference(ADC_REF_VCC);
	
	// Configure IO //
	USART_send_string("\tConfiguring IO...\r\n");
	//DDRx corresponds to PORTx/PINx, dependng on direction of data flow -- PORT for output, PIN for input
	DDRA = 0x00;	// Buttons and switches
	DDRB = 0xE7;	// Red enable, green enable and audio out
	DDRC = 0xff;	// Discrete LEDs
	DDRE = 0x47;	// LED Column
	DDRF = 0x00;	// Accelerometer
	
	// Disable pullups and set outputs low //
	PORTA = 0x00;
	PORTB = 0x01;
	PORTC = 0x81;
	PORTE = 0x00;
	PORTF = 0x00;
	
	//Set OC1A to toggle
	TCCR1A = 0b01000000;
	// Clk/64 and CTC mode
	TCCR1B = 0b00001011;

	OCR1A = 24;

	USART_send_string("\tSetting SPI\r\n");
	
	//Set the SPI bus appropriately to use the LED array
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);

}

/*
  ADC Accelerometer channels:
  x-axis: ADC_MUX_ADC5
  y-axis: ADC_MUX_ADC6
  z-axis: ADC_MUX_ADC7
  
  It is recommended that you create your own macros for these 
  to more meaningful names.
 */

/************************************************************
 *******************		MAIN		*********************
 ***********************************************************/

#define CK1024 ((1 << CS00) | (1 << CS02))

/** This function needs to setup the variables used by TIMER0 Compare Match (CTC) mode
with a base clock frequency of clk/1024. This function should return a 1 if it fails and
a 0 if it does not. Remember, by default the Wunderboard runs at 8MHz for its system
clock. @return This function returns a 1 is unsuccessful, else return 0.*/
unsigned char initialize_TIMER0()
{
	//See chapter 13 in the data sheet, and look up each of these values in turn.
		
	/* Set the CTC mode */
	TCCR0A = 0b00000010;
	
	/* Set the Clock Frequency */
	TCCR0B = CK1024;
	
	/* Set initial count value */
	OCR0A = 255;
	
	return 0;
}

/** This function checks if TIMER0 has elapsed. 
@return This function should return a 1 if the timer has elapsed, else return 0*/
int check_TIMER0()
{
	//look at the TIFR0 register in the datasheet. 
	//Check if the bit is 1
	if (TIFR0 & (1 << OCF0A)) {
		TIFR0 |= (1 << OCF0A);
		TCNT0 = 0;
		return 1;
	}
	
	return 0;
}

/** This function takes two values, clock and count. The value of count should be copied
into OCR0A and the value of clock should be used to set CS02:0 in the TCCR0B register.
The TCNT0 variable should also be reset to 0 so that the new timer rate starts from 0.
@param [in] clock Insert Comment @param [in] count Insert Comment @return The function
returns a 1 or error and 0 on successful completion.*/
unsigned char set_TIMER0(unsigned char clock, unsigned char count)
{
	clock &= 0b00000111;
	TCCR0B = (TCCR0B & ~(0b111)) | clock;
	OCR0A = count;
	
	
	return 0;
}

/*
Function: 
	fillFinalBuf(int n, int base, int isTen, char * convBuf, char * finBug)
Description: 
	Takes the integer n, converts it to a character and stores it in the
	conversion buffer string. Then concatates it with the final buffer, so that the
	integer n in character form is in the final buffer. If the number passed is 
	a 1's place number, we concatenate a colon, as this is how a clock is shown.
Parameters:
	-int n: The number to convert with itoa
	-int base: the base that we want the number to be in as a C string
	-int dispColon: Used to determine if we need to show a colon in the string or not.
	-char * convBuf: The buffer used to convert the number
	-char * finBuf: The buffer used to finally store the number concatenated with convBuf.
PreConditions: 
	We have integer values (for time) to convert to strings).
PostConditions:
	None
 */
void fillFinalBuf(int n, int base, int dispColon, char * convBuf, char * finBuf) {
	//myItoA(n, 10, convBuf);
	itoa(n, convBuf, 10);
	strcat(finBuf, convBuf);
	
	if (dispColon == TRUE) 
		strcat(finBuf, ":");
}



int main(int argc, char **argv)
{	
	initialize();
	clear_array();
	initialize_TIMER0();
	
	char convBuf[30];
	char finBuf[30];

	char h10buf[3], h1buf[3], m10buf[3], m1buf[3], s10buf[3], s1buf[3];
	
	//set_TIMER0(CK1024, 127);
	//24 hr clock, init at 00:00:00
	
	while (1) {
		if (USART_available() && USART_receive() == 's') {
			
			while (1) {
				//USART_send_string("x");
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
										 I used a stopwatch and adjusted the value that
										 i iterates up to until it would be 1 second.
										 */
										 
										 
										 
										for (i = 0; i <= 35; i++) {
											while(!check_TIMER0());
											if (fourCntH1 == 3) {
												PORTE = 4; //For hours 1's place
												set_array_blue(h1);
												_delay_ms(LED_DELAY);
												set_array_blue(0);
														
												PORTE = 5; //For hours 10's place
												set_array_blue(h10);
												_delay_ms(LED_DELAY);
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
												PORTE = 5; //For hours 10's place
												set_array_blue(h10);
												_delay_ms(LED_DELAY);
												set_array_blue(0);	
												
												PORTE = 4; //For hours 1's place
												set_array_blue(h1);
												_delay_ms(LED_DELAY);
												set_array_blue(0);	
												
												PORTE = 3; //For minutes 10's place
												set_array_blue(m10);
												_delay_ms(LED_DELAY);
												set_array_blue(0);	
												
												PORTE = 2; //For minutes 1's place
												set_array_blue(m1);
												_delay_ms(LED_DELAY);
												set_array_blue(0);	
												
												PORTE = 1; //For seconds 10's place
												set_array_blue(s10);
												_delay_ms(LED_DELAY);
												set_array_blue(0);												
												
												PORTE = 0; //For seconds 1's place
												set_array_blue(s1); 
												_delay_ms(LED_DELAY);
												set_array_blue(0);
											}
											
											/*
											  Display Clock:
												We display h10, h1, m10, m1, then s10, and s1.
											 */
											//Concatenate the integers on to the final buffer
											

											
											itoa1(h10, h10buf);	
											itoa1(h1, h1buf);
											itoa1(m10, m10buf);
											itoa1(m1, m1buf);
											itoa1(s10, s10buf);
											itoa1(s1, s1buf);
											
												
											USART_send_string(h10buf);
											USART_send_string(h1buf);
											USART_send_string(":");
											USART_send_string(m10buf);
											USART_send_string(m1buf);
											USART_send_string(":");
											USART_send_string(s10buf);
											USART_send_string(s1buf);
												
											

											//The final buffer has the time, now show it on the screen
											USART_send_string("\t \r\n");																						
										}								
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
