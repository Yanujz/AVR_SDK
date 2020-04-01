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
#include <stdlib.h>
#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
  CRC32_IEEE802_3  = 0x02611DB7, // Ethernet, MPEG2
} CRC32_POLY;
uint32_t crc32(const uint8_t *data, const uint32_t size);

#ifdef __cplusplus
}
#endif
