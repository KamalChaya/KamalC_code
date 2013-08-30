/** 
 * @file types.h
 * @author Dan Albert
 * @date Created 7/16/2010
 * @date Last updated 7/19/10
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
 * Includes some standard type definitions (ex. bool, true, false).
 * 
 */
#ifndef TYPES_H
#define TYPES_H

#ifndef BOOL
/**
 * A typedef to mimic C++'s bool.
 */
typedef uint8_t BOOL;
#endif // BOOL

#ifndef FALSE
/**
 * A value to be used with the typedef BOOL.
 * @see BOOL
 */
#define FALSE 0
#endif // FALSE

#ifndef TRUE
/**
 * A value to be used with the typedef BOOL.
 * @see BOOL
 */
#define TRUE !FALSE
#endif // TRUE

/**
 * Forces a value to TRUE or FALSE for use with BOOL.
 * @see BOOL
 * @see TRUE
 * @see FALSE
 */
#define BOOL(x) (x ? TRUE : FALSE)

#endif // TYPES_H