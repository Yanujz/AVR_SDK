/*
	

	Author : Yanujz

	Created in : 03/23/2020

    Copyright (C) 2020  Yanujz

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

	You may contact the author by:
		e-mail: yanujz@live.it
*/
#pragma once
#include <stdio.h>
#include <stdint.h>

//#include "swap_utils.h"
#ifdef __cplusplus
extern "C" {
#endif

void u16ToArr(uint8_t *dst, uint16_t value);

void u32ToArr(uint8_t *dst, uint32_t value);

void u64ToArr(uint8_t *dst, uint64_t value);

/*
   Function check_for_endianness() returns 1, if architecture
   is little endian, 0 in case of big endian.
 */
int check_for_endianness();








#ifdef __cplusplus
}
#endif





