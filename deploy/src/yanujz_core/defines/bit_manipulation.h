/*
	

	Author : Yanujz

	Created in : 01/09/2020

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

#ifndef is_bit_on
#define is_bit_on(var, bit) ((var)&(1<<(bit)))
#endif

#ifndef bitRead
#define bitRead(value, bit) (((value >> bit) & 0x01))
#endif

#ifndef bitSet
#define bitSet(value, bit) ((value |= (1 << bit)))
#endif

#ifndef bitClear
#define bitClear(value, bit) ((value) &= ~(1 << bit) )
#endif

#ifndef bitWrite
#define bitWrite(value, bit, bitvalue) (bitvalue ? bitSet(value, bit) : bitClear(value, bit))
#endif
