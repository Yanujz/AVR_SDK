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

#ifndef IS_BIT_ON
#define IS_BIT_ON(var, bit) ((var) & (1 << (bit)))
#endif

#ifndef BIT_READ
#define BIT_READ(value, bit) (((value >> bit) & 0x01))
#endif

#ifndef BIT_SET
#define BIT_SET(value, bit) ((value |= (1 << bit)))
#endif

#ifndef BIT_CLR
#define BIT_CLR(value, bit) ((value) &= ~(1 << bit) )
#endif

#ifndef BIT_WR
#define BIT_WR(value, bit, bitvalue) (bitvalue ? BIT_SET(value, bit) : BIT_CLR(value, bit))
#endif

#ifndef BITMASK_CLR
#define BITMASK_CLR(reg, bitValue) ((reg) &= ~(bitValue))
#endif

#ifndef BITMASK_SET
#define BITMASK_SET(reg, bitValue) ((reg) |= (bitValue))
#endif

#ifndef BITMASK_READ
#define BITMASK_READ(reg, bitValue) ((reg) & (bitValue))
#endif

#ifndef BITMASK_CLR_SET
#define BITMASK_CLR_SET(reg, clr_val, set_val) do { \
  BITMASK_CLR(reg, clr_val); \
  BITMASK_SET(reg, set_val); \
} while (0)
#endif

#ifndef REG_CLR
#define REG_CLR(reg) ((reg) = (0x0))
#endif

#ifndef REG_SET
#define REG_SET(reg, val) ((reg) |= (val))
#endif

#ifndef REG_WR
#define REG_WR(reg, val) ((reg) = (val))
#endif

#define REG_READ_MASK(reg, mask) ((reg) & (mask))

