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

#include "comm_utils.h"

#ifdef __cplusplus
extern "C" {
#endif

uint32_t rbit_u32(uint32_t x);

uint16_t rbit_u16(uint16_t x);

uint8_t rbit_u8(uint8_t x);

void swap_bytes(uint8_t *v, size_t src, size_t dst);

void swap_endian(uint8_t *v, size_t size, SWAP_SIZE wordlen);

void swap_nibbles(uint8_t *v, size_t size);


void memcpy_swap(void* __restrict dst,
                 const void* __restrict src,
                 size_t size,
                 SWAP_SIZE word_len);

#ifdef __cplusplus
}
#endif
