/** 
 * @file
 * @author Matthew Shuman
 * @author Joey Tomlinson
 * @author Dan Albert
 * @date Created 8/5/09
 * @date Last updated 7/19/10
 * @version 1.1
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
 * Includes functions for setting up and reading the hardware ADC on the attiny26.
 * 
 * @section HARDWARE
 * Target Device: ATTINY26L
 * 
 */
#ifndef ADC_H
#define ADC_H

#include "types.h"

/**
 * ADC reads from ADC 0
 * 
 */
#define ADC_MUX_ADC0 	0x00

/**
 * ADC reads from ADC 1
 * 
 */
#define ADC_MUX_ADC1 	0x01

/**
 * ADC reads from ADC 2
 * 
 */
#define ADC_MUX_ADC2 	0x02

/**
 * ADC reads from ADC 3
 * 
 */
#define ADC_MUX_ADC3 	0x03

/**
 * ADC reads from ADC 4
 * 
 */
#define ADC_MUX_ADC4 	0x04

/**
 * ADC reads from ADC 5
 * 
 */
#define ADC_MUX_ADC5 	0x05

/**
 * ADC reads from ADC 6
 * 
 */
#define ADC_MUX_ADC6 	0x06

/**
 * ADC reads from ADC 7
 * 
 */
#define ADC_MUX_ADC7 	0x07

/**
 * ADC uses CK as ADC frequency.
 * 
 */
#define ADC_PRESCALER_1		0x00

/**
 * ADC uses CK/2 as ADC frequency.
 * 
 */
#define ADC_PRESCALER_2 	0x01

/**
 * ADC uses CK/2 as ADC frequency.
 * 
 */
#define ADC_PRESCALER_4 	0x02

/**
 * ADC uses CK/4 as ADC frequency.
 * 
 */
#define ADC_PRESCALER_8 	0x03

/**
 * ADC uses CK/16 as ADC frequency.
 * 
 */
#define ADC_PRESCALER_16	0x04

/**
 * ADC uses CK/32 as ADC frequency.
 * 
 */
#define ADC_PRESCALER_32	0x05

/**
 * ADC uses CK/64 as ADC frequency.
 * 
 */
#define ADC_PRESCALER_64	0x06

/**
 * ADC uses CK/128 as ADC frequency.
 * 
 */
#define ADC_PRESCALER_128	0x07

/**
 * Bit mask for ADC mux bits.
 * 
 */
#define ADC_MUX_MASK		0b00011111

/**
 * Bit mask for ADC prescaler bits.
 * 
 */
#define ADC_PRESCALER_MASK	0b00000111

/**
 * Bit mask for ADC reference bits.
 * 
 */
#define ADC_REF_MASK		0b11000000

/**
 * ADC right adjusts the result (2 bits in ADCH, 8 bits in ADCL)
 * 
 */
#define ADC_RIGHTADJUST	FALSE

/**
 * ADC left adjusts the result (8 bits in ADCH, 2 bits in ADCL)
 * 
 */
#define ADC_LEFTADJUST	TRUE

/**
 * ADC references VCC for AD conversions.
 * 
 */
#define ADC_REF_VCC		0b01000000

/**
 * ADC references the AREF pin for AD conversions.
 * 
 */
#define ADC_REF_AREF	0b00000000

/**
 * ADC references the internal 2.56V source for AD conversions.
 * 
 */
#define ADC_REF_25		0b11000000

/**
 * Set pin to use for adc input
 * 
 * @param Channel used to select pin to use for adc input.
 * See table 46 in the ATTINY26 datasheet for mux option
 *  
 * @see ADC_MUX_ADC0
 * @see ADC_MUX_ADC1 
 * @see ADC_MUX_ADC2 
 * @see ADC_MUX_ADC3 
 * @see ADC_MUX_ADC4 
 * @see ADC_MUX_ADC5 
 * @see ADC_MUX_ADC6 
 * @see ADC_MUX_ADC7 
 * @see ADC_MUX_ADC8 
 * @see ADC_MUX_ADC9 
 * @see ADC_MUX_ADC10
 */
void ADC_set_channel(uint8_t channel);

/**
 * Set ADC register to either left or right adjust the bits.
 * 
 * @param leftAdjust
 * ADC_LEFTADJUST Sets the ADC result to left adjust mode (8 bits in ADCH, 2 bits in ADCL)
 * ADC_RIGHTADJUST Sets the ADC result to right adjust mode (2 bits in ADCH, 8 bits in ADCL)
 *
 * @see ADC_LEFTADJUST
 * @see ADC_RIGHTADJUST
 * 
 */
void ADC_set_adjust(BOOL left_adjust);

/**
 * Select the ADC clock prescaler.
 * 
 * @param prescale The value to put into the prescaler register.
 * 
 */
void ADC_set_prescaler(uint8_t prescale);

/**
 * Puts the ADC in free running mode.
 * 
 * @param free_run TRUE enables free running mode.
 * 
 * @see ADC_PRESCALER_2
 * @see ADC_PRESCALER_4
 * @see ADC_PRESCALER_8
 * @see ADC_PRESCALER_16
 * @see ADC_PRESCALER_32
 * @see ADC_PRESCALER_64
 * @see ADC_PRESCALER_128
 */
void ADC_set_free_running(BOOL free_run);

/**
 * Sets the reference that the ADC will compare to.
 * 
 * @param reference The reference for analog comparison.
 *
 * @see ADC_REF_VCC
 * @see ADC_REF_AREF
 * @see ADC_REF_25
 * 
 */
void ADC_set_reference(uint8_t reference);

/**
 * Enables the analog conversion complete interrupt.
 * 
 */
void ADC_enable_interrupt();

/**
 * Disables the analog conversion complete interrupt.
 * 
 */
void ADC_disable_interrupt();

/**
 * Enables the ADC.
 * 
 */
void ADC_enable();

/**
 * Disables the ADC.
 * 
 */
void ADC_disable();

/**
 * Begins an analog conversion.
 * 
 */
void ADC_start();

/**
 * Clears the analog conversion complete flag after an analog conversion.
 * 
 */
void ADC_finish();

/**
 * Tests the analog conversion complete flag.
 * 
 * @return The current state of the AD conversion.
 */
BOOL ADC_done();

/**
 * Initializes ADC, allowing the user to set useful ADC options during initialization.
 * 
 * @param prescale ADC clock frequency is set to sys_clk/prescaler
 * See table 47 in the ATTINY26 datasheet for prescaler options
 * @param freeRun set to 1 to enable free running mode
 */
void setup_ADC(uint8_t prescale, BOOL free_run);

/**
 * Preforms a blocking hardware ADC read.
 * If you need to use processor cycles while the ADC is being read,
 * consider using adc interrupts.
 * 
 * @param channel Selects which ADC channel to read.
 * @return 8-bit ADC value.
 */
uint8_t read_ADC(uint8_t channel);

/**
 * Reads the ADC multiple times and returns the average ADC value.
 * 
 * @param channel Selects which ADC channel to read.
 * @param samples The number of samples to take.
 * @return Averaged 8-bit ADC reading.
 */
uint8_t read_ADC_averaged(uint8_t channel, uint8_t samples);

/**
 * Preforms a blocking hardware ADC read.
 * If you need to use processor cycles while the ADC is being read,
 * consider using adc interrupts.
 * 
 * @param channel Selects which ADC channel to read.
 * @return 10-bit ADC value.
 */
uint16_t read_precise_ADC(uint8_t channel);

/**
 * Reads the ADC multiple times and returns the average ADC value.
 * 
 * @param channel Selects which ADC channel to read.
 * @param samples The number of samples to take.
 * @return Averaged 10-bit ADC reading.
 */
uint16_t read_precise_ADC_averaged(uint8_t channel, uint8_t samples);

#endif // ADC_H

