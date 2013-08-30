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

/************************************************************
 *******************		MAIN		*********************
 ***********************************************************/


int main(int argc, char **argv)
{
	initialize();
	clear_array();

	while(1){
		if((PINA) & (1<<0)){
		USART_send_string("\Button 0 is pressed.\r\n");
	}	
	
	if((PINA) & (1<<1)){
		USART_send_string("\Button 1 is pressed.\r\n");
	}
	
	if((PINA) & (1<<2)){
		USART_send_string("\Button 2 is pressed.\r\n");
	}
	
	if((PINA) & (1<<3)){
		USART_send_string("\Button 3 is pressed.\r\n");
	}
	
	if((PINA) & (1<< 4)){
		USART_send_string("\Button 4 is pressed.\r\n");
	}
	
	if((PINA) & (1<<5)){
		USART_send_string("\Button 5 is pressed.\r\n");
	}
	
	if((PINA) & (1<<6)){
		USART_send_string("\Button 6 is pressed.\r\n");
	}
	
	if((PINA) & (1<<7)){
		USART_send_string("\Button 7 is pressed.\r\n");
	}

		if(!(PINA)){
		for(int i = 0; i < 8; i++){
			PORTE = i;
	
			if(i == 0|i == 7) set_array_green(0b10000001);
			if(i == 1|i == 6) set_array_green(0b01000010);
			if(i == 2|i == 5) set_array_green(0b00100100);
			if(i == 3|i == 4) set_array_green(0b00011000);
			clear_array();
		   }}
		
		if((PINA)&(1<<1)){ 
		for(int i = 0; i < 8; i++){
			PORTE = i;
       			
			if(i == 0|i == 7) set_array_red(0b10000001);
			if(i == 1|i == 6) set_array_red(0b01000010);
			if(i == 2|i == 5) set_array_red(0b00100100);
			if(i == 3|i == 4) set_array_red(0b00011000);
			clear_array();
			}}
			
		if((PINA)&(1<<5)){
		for(int i = 0; i < 8; i++){
			PORTE = i;
       			
			if(i == 0|i == 7) set_array_blue(0b10000001);
			if(i == 1|i == 6) set_array_blue(0b01000010);
			if(i == 2|i == 5) set_array_blue(0b00100100);
			if(i == 3|i == 4) set_array_blue(0b00011000);
			clear_array();
		   }}
	}
	
	return 0;
}	
