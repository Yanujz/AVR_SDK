#include "crc16.h"

uint16_t CRC16(const uint8_t* buff, uint8_t len, CRC16_CONST std)
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
        crc = (crc >> 1) ^ (int)(std);
      else  crc >>= 1;
  }
    } while (--len);

    crc = ~crc;
    data = crc;
    crc = (crc << 8) | (data >> 8 & 0xff);

    return (crc);
}
