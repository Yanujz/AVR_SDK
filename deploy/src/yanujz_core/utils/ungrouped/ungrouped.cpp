#include "ungrouped.h"
#include <string.h>

void u16ToArr(u8 *dst, u16 value)
{
    memcpy(dst, &value, sizeof(u16));
}

void u32ToArr(u8 *dst, u32 value)
{
    memcpy(dst, &value, sizeof(u32));
}

void u64ToArr(u8 *dst, u64 value)
{
    memcpy(dst, &value, sizeof(u64));
}

int check_for_endianness()
{
    unsigned int x = 1;
    char *c = (char*) &x;
    return (int)*c;
}
