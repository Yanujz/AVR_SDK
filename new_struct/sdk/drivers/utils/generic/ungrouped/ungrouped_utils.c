#include "ungrouped_utils.h"
#include <string.h>

void u16ToArr(uint8_t *dst, uint16_t value)
{
  memcpy(dst, &value, sizeof(uint16_t));
}

void u32ToArr(uint8_t *dst, uint32_t value)
{
  memcpy(dst, &value, sizeof(uint32_t));
}

void u64ToArr(uint8_t *dst, uint64_t value)
{
  memcpy(dst, &value, sizeof(uint64_t));
}

int check_for_endianness()
{
  unsigned int x = 1;
  char *c = (char*) &x;
  return (int)*c;
}

