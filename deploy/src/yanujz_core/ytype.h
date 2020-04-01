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
#include <stdint.h>
#include <stdlib.h>

/**
    * @brief Shortname of uint8_t
    */
#ifdef __cplusplus
using u8t = uint8_t;
using u8 = uint8_t;
#else
typedef  uint8_t u8t;
typedef  uint8_t u8;

#endif
/**
    * @brief Shortname of uint16_t
    */
#ifdef __cplusplus
using u16t = uint16_t;
using u16 = uint16_t;
#else
typedef  uint16_t u16t;
typedef  uint16_t u16;

#endif

/**
    * @brief Shortname of uint32_t
    */
#ifdef __cplusplus
using u32t = uint32_t;
using u32 = uint32_t;
#else
typedef  uint32_t u32t;
typedef  uint32_t u32;

#endif

/**
    * @brief Shortname of uint64_t
    */
#ifdef __cplusplus
using u64t = uint64_t;
using u64 = uint64_t;
#else
typedef  uint64_t u64t;
typedef  uint64_t u64;

#endif


#ifdef __cplusplus
using uint = unsigned int;
#else
typedef  unsigned int uint;
#endif

#ifdef __cplusplus
using uchar = unsigned char;
#else
typedef  unsigned char uchar;
#endif

