#include "stm32_swap_utils.h"

void hw_rbit32(uint8_t* v, size_t size)
{

  while (--size)
  {
    __ASM volatile ("rbit %0, %1"
                    : __CMSIS_GCC_OUT_REG(*v)
                    : __CMSIS_GCC_USE_REG(*v)
                    );
    v++;
  }
}


void hw_swap32(uint32_t* v, size_t size)
{
  while (--size)
  {
    __ASM volatile ("rev %0, %1"
                    : __CMSIS_GCC_OUT_REG(*v)
                    : __CMSIS_GCC_USE_REG(*v)
                    );
    v++;
  }
}

void hw_swap16(uint16_t* v, size_t size)
{
  while (--size)
  {
    __ASM volatile ("revsh %0, %1"
                    : __CMSIS_GCC_OUT_REG(*v)
                    : __CMSIS_GCC_USE_REG(*v)
                    );
    v++;
  }
}


void hw_memcpy_swap32(uint32_t* dst, const uint32_t* src, size_t size)
{
  while (--size)
  {

    *dst = *src++;
    __ASM volatile ("rev %0, %1"
                    : __CMSIS_GCC_OUT_REG(*dst)
                    : __CMSIS_GCC_USE_REG(*dst)
                    );
    dst++;
  }
}
