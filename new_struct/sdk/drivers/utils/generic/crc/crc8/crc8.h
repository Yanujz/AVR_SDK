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

#ifdef __cplusplus
extern "C" {
#endif
typedef enum
{
  CRC8_ATM_POLY   = 0x07, // ATM HEC
  CRC8_CCITT_POLY = 0x8D, // 1-Wire bus
  CRC8_MAXIM_POLY = 0x31, // 1-Wire bus
  CRC8_GEN_POLY   = 0xD5, // General
  CRC8_SAE_POLY   = 0x1F  // SAE J1850
} CRC8_POLY;

uint8_t crc8_ccitt(const uint8_t *data, uint8_t len);

uint8_t crc8_maxim(const uint8_t *data, uint8_t len);

// TODO
//uint8_t crc8_generic(const uint8_t *data, uint8_t len,
//                     uint8_t init_val, uint8_t poly, uint8_t shift_dir);
#ifdef __cplusplus
}
#endif
