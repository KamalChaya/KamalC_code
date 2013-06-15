/** 
 * @file
 * @author Dan Albert
 * @date Created 7/16/2010
 * @date Last updated 7/16/10
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
 * Includes functions for getting and setting pins.
 * 
 */
#ifndef PINS_H
#define PINS_H

/**
 * Converts a pin number to a bit mask. Ex: PIN(4) would return 0b00010000
 */
#define PIN(x)				(1 << (x))

/**
 * Sets the specified pin in the provided buffer to high.
 */
#define SETPIN(addr, x)		(addr |= PIN(x))

/**
 * Sets the specified pin in the provided buffer to low.
 */
#define CLEARPIN(addr, x) 	(addr &= ~PIN(x))

/**
 * Sets the specified pins in the provided buffer to high.
 */
#define SETPINS(addr, mask)		(addr |= mask)

/**
 * Sets the specified pins in the provided buffer to low.
 */
#define CLEARPINS(addr, mask)	(addr &= ~mask)

/**
 * Gets the current value of the specified pin in the provided buffer.
 */
#define GETPIN(addr, x)	(addr & PIN(x))

#endif // PINS_H
