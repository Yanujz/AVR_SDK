#include "swap_utils.h"


uint32_t rbit_u32(register uint32_t x)
{
  x = (((x & 0xAAAAAAAA) >> 1) | ((x & 0x55555555) << 1));
  x = (((x & 0xCCCCCCCC) >> 2) | ((x & 0x33333333) << 2));
  x = (((x & 0xF0F0F0F0) >> 4) | ((x & 0x0F0F0F0F) << 4));
  x = (((x & 0xFF00FF00) >> 8) | ((x & 0x00FF00FF) << 8));
  return ((x >> 16) | (x << 16));
}

uint16_t rbit_u16(register uint16_t x)
{
  x = (((x & 0xAAAA) >> 1) | ((x & 0x5555) << 1));
  x = (((x & 0xCCCC) >> 2) | ((x & 0x3333) << 2));
  x = (((x & 0xF0F0) >> 4) | ((x & 0x0F0F) << 4));
  x = (((x & 0xFF00) >> 8) | ((x & 0x00FF) << 8));
  return x;
}

uint8_t rbit_u8(register uint8_t x)
{
  x = (((x & 0xAA) >> 1) | ((x & 0x55) << 1));
  x = (((x & 0xCC) >> 2) | ((x & 0x33) << 2));
  x = (((x & 0xF0) >> 4) | ((x & 0x0F) << 4));
  return x;
}


void swap_bytes(uint8_t *v, size_t src, size_t dst)
{
    uint8_t tmp = v[src];
    v[src] = v[dst];
    v[dst] = tmp;
}

void swap_endian(uint8_t *v, size_t size, SWAP_SIZE wordlen)
{
    for(size_t idx = 0; idx < size / wordlen; ++idx)
    {
        for(size_t j = 0; j < wordlen / 2; j++)
        {
            size_t src = (wordlen * idx) + j;
            size_t dst = (wordlen * idx) + (wordlen - 1) - j;
            swap_bytes(v, src, dst);
        }
    }
}

void swap_nibbles(uint8_t *v, size_t size)
{
    for(size_t i = 0; i < size; i++)
    {
        v[i] = ( (v[i] & 0x0F) << 4 | (v[i] & 0xF0) >> 4 );
    }
}

void memcpy_swap(void* __restrict dst , const void* __restrict src , size_t size, SWAP_SIZE word_len)
{
  while (size >= sizeof(int))
  {
    *(int*)dst = *(int*)src++;
    size -= sizeof(int);
  }

  //while(--size)
  //{
  //
  //}
  swap_endian(dst, size, word_len);

}
