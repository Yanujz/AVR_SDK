#pragma once
#include <core.h>
#include <common_typedef.h>
#include <common_macros.h>
#include <string.h>


enum class SWAP_SIZE{
    NIBBLE,
    WORD = 2,
    DWORD = 4,
    QWORD = 8
};

enum ENDIANNESS_TYPE
{
    BIG,
    LITTLE
};

void swapBytes(u8 *v, size_t src, size_t dst);
void swapEndian(u8 *v, size_t size, size_t wordlen);

void swapNibbles(u8* src, size_t size);

void fill(u8 &buff, u8 fill_byte, size_t currentSize, size_t size);

bool isInRange(size_t n, size_t first, size_t last);

void u16ToArr(u8* dst, u16 value);
void u32ToArr(u8* dst, u32 value);
void u64ToArr(u8* dst, u64 value);


/*
   Function check_for_endianness() returns 1, if architecture
   is little endian, 0 in case of big endian.
 */
int check_for_endianness();
