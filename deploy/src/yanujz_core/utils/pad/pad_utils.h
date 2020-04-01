/*
	

	Author : Yanujz

	Created in : 01/11/2020

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
#include "../../defines/defines.h"
#include "../../ytype.h"

#if defined(__STL_SUPPORT__)
#include <vector>
#endif

void pad_with(u8t &buff, size_t buf_size, size_t new_size, u8t fill_byte);

#if defined(__STL_SUPPORT__)
void pad_with(std::vector<uint8_t> &v, uint8_t fill_byte, size_t new_size);
#endif
