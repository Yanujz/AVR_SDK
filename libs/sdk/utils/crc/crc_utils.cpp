#include <crc_utils.h>
u8t CRC8(const u8t *data, u8t len) {
    u8t  crc = 0x00;
    while (len--) {
	u8t  extract = *data++;
	for (u8t tempI = 8; tempI; tempI--) {
	    u8t  sum = (crc ^ extract) & 0x01;
	    crc >>= 1;
	    if (sum) {
		crc ^= 0x8C;
	    }
	    extract >>= 1;
	}
    }
    return crc;
}


