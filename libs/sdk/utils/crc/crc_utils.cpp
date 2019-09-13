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



u16 CRC16(const u8 *buff, u8 len, CRC16_CONST std)
{
    unsigned char i;
    unsigned int data;
    unsigned int crc = 0xffff;

    if (len == 0)
	return (~crc);

    do
    {
	for (i=0, data=(unsigned int)0xff & *buff++;
	     i < 8;
	     i++, data >>= 1)
	{
	    if ((crc & 0x0001) ^ (data & 0x0001))
		crc = (crc >> 1) ^ toInt(std);
	    else  crc >>= 1;
	}
    } while (--len);

    crc = ~crc;
    data = crc;
    crc = (crc << 8) | (data >> 8 & 0xff);

    return (crc);
}

