/** 
 * @file
 * @author D. Kevin McGrath
 * @author Marshal Horn
 * @date Created 7 Jan 2013
 * @date Last updated 12 Feb 2013
 *
 * @section DESCRIPTION
 * 
 * Includes functions for setting up and reading the hardware ADC on the attiny26.
 * 
 * @section HARDWARE
 * Target Device: ATTINY26L
 * 
 */
#ifndef LEDS_H
#define LEDS_H

#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>

#include "types.h"


void clear_array(void);

void set_array_green(unsigned char rows);
void set_array_blue(unsigned char rows);
void set_array_red(unsigned char rows);

void update_row( uint8_t red, uint8_t green, uint8_t blue );
void led_red( uint8_t x, uint8_t y );
void led_green( uint8_t x, uint8_t y );
void led_blue( uint8_t x, uint8_t y );
void led_off( void );


#endif

