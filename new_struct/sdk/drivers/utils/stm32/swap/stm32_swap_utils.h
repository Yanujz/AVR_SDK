/*
	

	Author : Yanujz

	Created in : 03/31/2020

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

#include "io_cmsis_def.h"
#include "comm_utils.h"

#ifdef __cplusplus
extern "C" {
#endif

void hw_rbit32(uint8_t* v, size_t size);

void hw_swap32(uint32_t* v, size_t size);
void hw_swap16(uint16_t* v, size_t size);

void hw_memcpy_swap32(uint32_t* dst, const uint32_t* src, size_t size);

#ifdef __cplusplus
}
#endif
