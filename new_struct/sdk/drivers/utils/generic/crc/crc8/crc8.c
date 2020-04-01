#include "crc8.h"


uint8_t crc8_ccitt(const uint8_t *data, uint8_t len)
{
    uint8_t  crc = 0x00;
    while (len--) {
        uint8_t  extract = *data++;
        for (uint8_t i = 0; i < 8; ++i)
        {
            uint8_t  sum = (crc ^ extract) & 0x01;
            crc >>= 1;
            if (sum) {
                crc ^= 0x8D;
            }
            extract >>= 1;
        }
    }
    return crc;
}

uint8_t crc8_maxim(const uint8_t* data, uint8_t len)
{
  uint8_t crc = 0xFF;
  while (len--)
  {
    crc ^= *data++;
    for (uint8_t bit = 8; bit > 0; --bit)
    {
      if (crc & 0x80) crc = (crc << 1) ^ 0x31;
      else crc <<= 1;

    }
  }
  return crc;
}

