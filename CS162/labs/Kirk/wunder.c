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

// 9600 baud
#define BAUD_RATE 51

#define CPU_PRESCALE(n) (CLKPR = 0x80, CLKPR = (n))


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

#define CK1024 ((1<<CS02) | (1<<CS00))

/** This function needs to setup the variables used by TIMER0 Compare Match (CTC) mode
with a base clock frequency of clk/1024. This function should return a 1 if it fails and
a 0 if it does not. Remember, by default the Wunderboard runs at 8MHz for its system
clock. @return This function returns a 1 is unsuccessful, else return 0.*/
unsigned char initialize_TIMER0()
{
	//See chapter 13 in the data sheet, and look up each of these values in turn.
		
	/* Set the CTC mode */
	TCCR0A = (1<<WGM01);
	
	/* Set the Clock Frequency */
	TCCR0B = CK1024;
	
	/* Set initial count value */
	OCR0A = 255;
	
	return 1;
}

/** This function checks if TIMER0 has elapsed. 
@return This function should return a 1 if the timer has elapsed, else return 0*/
unsigned char check_TIMER0()
{
	//look at the TIFR0 register in the datasheet.
	if(TIFR0 &(1<<OCF0A))
	{
		TIFR0 |= (1<<OCF0A);
		return 1;
	}
	else{
		return 0;
	}
}

/** This function takes two values, clock and count. The value of count should be copied
into OCR0A and the value of clock should be used to set CS02:0 in the TCCR0B register.
The TCNT0 variable should also be reset to 0 so that the new timer rate starts from 0.
@param [in] clock Insert Comment @param [in] count Insert Comment @return The function
returns a 1 or error and 0 on successful completion.*/
unsigned char set_TIMER0(unsigned char clock, unsigned char count)
{
	OCR0A = count; //maximum value it counts to
	TCCR0B &= ~(0b00000111); //inverting the cs02 cs01 and cs00 values in the TCCR0B register
	TCCR0B |= clock; //setting TCCR0B register values that the user defines.
	return 1;
}

int num_digits(int n, int b)
{
    int dig = 1; //at one to account for null character

    if(n < 0)
        n = abs(n);

    while(n > 0)
        {
            n=(n/b);
            dig++;
        }
    return dig;
}

int myitoa(int num, char* string, int base) //switch int to ascii and input in passed array
{
    int num1; //temp value for digits
    int t = 0; //temp value for array number input
    int digits = 0;  //number to calculate space in array and values to be put in said space
    
    num1 = num;

    while(num1 > 0)
    {
        num1 = (num1 / base);
        digits++;
    }

    int x = digits-1;

    while (num > 0)
    {
        t = (num % base);
        string[x] = t + '0';
        x--;
        num = num / base;
    }
    return 1;
}


int main(int argc, char **argv)
{
	initialize();
	clear_array();
	
	//uint8_t ticks,seconds,minutes,hours;
	
	//char buffer[20];
	
	enum state 
	{
		running,
		idle,
		sample,
	};
	
	enum state printstate = idle;

	initialize_TIMER0();
	set_TIMER0(CK1024,255);
	
	
	int q = 0; //seconds counter
	int w = 0;
	int o = 0; //total seconds counter
	int num;
	int base = 10;
   char *string;
   //char *tempstring;

    //string = (char *) malloc(sizeof(char) *num_digits(num, base));
    // array, typeset, allocating memory, typeset array size function

    //myitoa(num, string, base);
    


	while(1){	
		int i;	
		
		for(int h2 = 0; h2 < 2; h2++)
		{
			for(int h = 0; h < 10; h++)
			{
				for(int m2 = 0; m2 < 6; m2++)
				{
					for(int m = 0; m < 10; m++)
					{
						for(int s2 = 0; s2 < 6; s2++)
						{
							for(int s = 0; s < 10; s++)
							{								
								string = (char *) malloc(sizeof(char) *10);								
								o++;
								
								
								if(o == 3600)
								{
									o = 0;
									w++;
								}
								myitoa(o,string,base);
								USART_send_string("Seconds: ");
								USART_send_string(string);
								USART_send_string("\r\n");
								free(string);	
								q++;
								
								if(q == 60)
								{
									q = 0;
								}
								for(i= 0; i <= 30; i)
								{
									if(check_TIMER0() == 1)
									{
										i++;
									}	
																	
									
									PORTE = 0;
									set_array_red(s);
									_delay_ms(2);
									
									PORTE = 1;
									set_array_red(s2);
									_delay_ms(2);

									PORTE = 2;
									set_array_red(m);
									_delay_ms(2);

									PORTE = 3;
									set_array_red(m2);
									_delay_ms(2);

									PORTE = 4;
									set_array_red(h);
									_delay_ms(2);

									PORTE = 5;
									set_array_red(h2);
									_delay_ms(2);
									
									num = s;
									
									switch (printstate)
									{
									case idle:
										if(USART_available() && USART_receive() == 's')
										{
											printstate = running;
										}
										break;
									case running:
										if(check_TIMER0())
										{
											printstate = sample;
										}
										break;
			 						case sample:			 																	
										if(i == 30)
										{	
											USART_send_string(string);
											USART_send_string("\r\n");								 																		
											/*USART_send_string("Hours: ");
											USART_send_string(itoa(w,buffer,10));
											USART_send_string(" ");											
											USART_send_string("Minutes: ");
											USART_send_string(itoa((o/60),buffer,10));
											USART_send_string(" ");										
											USART_send_string("Seconds: ");			 								
			 								USART_send_string(itoa(q,buffer,10));
			 								USART_send_string("\r\n");*/
			 								//free(string);
			 							}
			 							if(USART_available() && USART_receive() == 's')
			 							{
											USART_send_string("Device Idle\r\n");			 		
			 								printstate = idle;
			 							}
									}

									if(h2 == 1 && h == 3)
									{
										//here set a value to change between am and pm

										h2 = 0;
										h = 0;
										m2 = 0;
										m = 0;
										s2 = 0;
										s = 0;
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
	
