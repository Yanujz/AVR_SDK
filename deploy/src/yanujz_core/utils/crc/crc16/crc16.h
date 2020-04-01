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
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

enum class CRC16_CONST : uint16_t {
    DNP	    = 0x3D65, // DNP, IEC 870, M-BUS, wM-BUS, ...
    CCITT   = 0x1021, // X.25, V.41, HDLC FCS, Bluetooth, ...
    IBM	    = 0x8005, // ModBus, USB, Bisync, CRC-16, CRC-16-ANSI, ...
    T10_DIF = 0x8BB7, // SCSI DIF
    DECT    = 0x0589, // Cordeless Telephones
    ARINC   = 0xA02B  // ACARS Aplications
};

uint16_t CRC16(const uint8_t* buff, uint8_t len, CRC16_CONST std = CRC16_CONST::CCITT);
