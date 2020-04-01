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
#include "cast.h"
#include "bit_manipulation.h"
#include "prepoc_math.h"


#ifndef SIZE_OF_ARRAY
#define SIZE_OF_ARRAY(x) ((sizeof(x)/sizeof(x[0])) & 0xFFFFFFFF)
#endif

#ifndef ELEMENT_IN_ARRAY
#define ELEMENT_IN_ARRAY(x)  (*(&x + 1) - x)
#endif

#ifndef ABS
#define ABS(N) ((N<0)?(-N):(N))
#endif

#ifdef __cplusplus
#ifndef __toABS__
#define __toABS__
//constexpr unsigned int toABS(int x){
//    return ((x<0)?(-x):(x));
//}
#endif
#endif

#ifndef LO8
#define LO8(x) (x & 0xFF)
#endif

#ifndef HI8
#define HI8(x) ((x >> 8) & 0xFF)
#endif

#ifndef LO16
#define LO16(x) (x & 0xFFFF)
#endif

#ifndef HI16
#define HI16(x) ((x >> 16) & 0xFFFF)
#endif

#ifndef LO32
#define LO32(x) (x & 0xFFFFFFFF)
#endif

#ifndef HI32
#define HI32(x) ((x >> 32) & 0xFFFFFFFF)
#endif

#ifndef WEAK
#define WEAK __attribute__((weak))
#endif

#ifndef PACKED
#define PACKED __attribute__((packed))
#endif

#ifndef SECTION
#define SECTION(x) __attribute__ ((section (x)))
#endif

#ifndef UNUSED
#define UNUSED(x) (void)(x)
#endif

#ifndef IS_IN_RANGE
#define IS_IN_RANGE(x, y, z)(x >= y && x <= z)
#endif

#ifndef AND_VALUE
#define AND_VALUE(var, mask) (var & mask)
#endif
