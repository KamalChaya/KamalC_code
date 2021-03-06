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
#define DEBUG

void initialize( void )
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
	PORTC = 0x81;
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

/************************************************************
 *******************		MAIN		*********************
 ***********************************************************/


int main(int argc, char **argv)
{
 
	initialize();
	clear_array();
while (1){
PORTC=PINA;
if (PORTC != 0b00000001){	
	USART_SendString("green");
	led_green(0,0);
	led_green(0,7);	
	led_green(7,0);	
	led_green(7,7);
	led_green (1,1);
	led_green (2,2);
	led_green (3,3);
	led_green (1,6);
	led_green (2,5);
	led_green (3,4);
	led_green (6,6);
	led_green (5,5);
	led_green (4,4);
	led_green (6,1);
	led_green (5,2);
	led_green (4,3);

}

	if (PORTC & 0b00000001){
USART_SendString ("Red");	
	clear_array();	
	led_red(0,0);
	led_red(0,7);	

	led_red(7,0);	
	led_red(7,7);
	led_red (1,1);
	led_red (2,2);
	led_red (3,3);
	led_red (1,6);
	led_red (2,5);
	led_red (3,4);
	led_red (6,6);
	led_red (5,5);
	led_red (4,4);
	led_red (6,1);
	led_red (5,2);
	led_red (4,3);
	}
	if (PORTC & 0b00100000){
	USART_SendString ("blue");	
	clear_array(); 
       	led_blue(0,0);
       	led_blue(0,7);  
	
        	led_blue(7,0);  
        	led_blue(7,7);
        	led_blue (1,1);
        	led_blue (2,2);
        	led_blue (3,3);
        	led_blue (1,6);
        	led_blue (2,5);
        	led_blue (3,4);
        	led_blue (6,6);
        	led_blue (5,5);
        	led_blue (4,4);
        	led_blue (6,1);
        	led_blue (5,2);
        	led_blue (4,3);
}
}
}
