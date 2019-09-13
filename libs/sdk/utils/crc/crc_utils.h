#pragma once
#include <core.h>
enum class CRC16_CONST : u16 {
    DNP	    = 0x3D65, // DNP, IEC 870, M-BUS, wM-BUS, ...
    CCITT   = 0x1021, // X.25, V.41, HDLC FCS, Bluetooth, ...
    IBM	    = 0x8005, // ModBus, USB, Bisync, CRC-16, CRC-16-ANSI, ...
    T10_DIF = 0x8BB7, // SCSI DIF
    DECT    = 0x0589, // Cordeless Telephones
    ARINC   = 0xA02B  // ACARS Aplications
};


u8 CRC8(const u8  *data, u8  len);
u16 CRC16(const u8* buff, u8 len, CRC16_CONST std = CRC16_CONST::CCITT);
