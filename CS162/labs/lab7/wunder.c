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
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
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
volatile enum {IDLE, RUNNING, SAMPLE_ADCS} state;
ISR(TIMER0_COMPA_vect){
static int8_t ticks = 0;
ticks++;
if(ticks >= 30){
state = SAMPLE_ADCS;
ticks = 0;
}
}
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
*******************	 MAIN	 *********************
***********************************************************/
#define CK1024 ((1<<CS02)|(1<<CS00))
unsigned char initialize_TIMER0()
{
//See chapter 13 in the data sheet, and look up each of these values in turn.

/* Set the CTC mode */
TCCR0A = 0b00000010;

/* Set the Clock Frequency */
TCCR0B = CK1024;

/* Set initial count value */
OCR0A = 255;
TCNT0 = 0;
TIMSK0 |= 0b00000010;
return 0;
}
unsigned char check_TIMER0()
{
//look at the TIFR0 register in the datasheet.
if(TIFR0 & (1 << OCF0A)){
TIFR0 |= (1 << OCF0A);
return 1;
}
else{
return 0;
} 
}
unsigned char set_TIMER0(unsigned char clock, unsigned char count)
{	
TCCR0A = (1 << WGM01);	
TCCR0B = (1 << CS02 ) | (1 << CS00 );
OCR0A = count;
return 0;
}
int main(int argc, char **argv){
unsigned char str[10];
unsigned char rcv;
initialize();
clear_array();
initialize_TIMER0();
state = IDLE;
uint8_t seconds = 0b00000000, minutes = 0b00000000, hours = 0b00000000;
while(1){
switch(state){
case IDLE:
if(USART_available()){
if(USART_receive()=='s'){
state=RUNNING;
}
}
break;
case RUNNING:
sei();
if(USART_available()){
if(USART_receive()=='s')
cli();
state=IDLE;
}
if(seconds==60){
minutes++;
seconds = 0;
}
if(minutes==60){
hours++;
minutes = 0;
}
if(hours == 24){
hours = 0;
}
PORTE = 0;
set_array_red(seconds);
_delay_ms(5);
PORTE = 1;
set_array_green(minutes);
_delay_ms(5);
PORTE = 2;
set_array_blue(hours);
_delay_ms(5);
break;
case SAMPLE_ADCS:
seconds++;
TCNT0 = 0;
state = RUNNING;
break;
}
}
}