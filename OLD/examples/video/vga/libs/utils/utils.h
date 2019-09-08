#ifndef UTILS_H
#define UTILS_H
#include <stdio.h>
#include <macros.h>
#include <stdint.h>
#if defined(__STL_SUPPORT__)
#include <vector>
#endif
///@file

using namespace  std;


enum class SWAP_SIZE{
    NIBBLE,
    WORD = 2,
    DWORD = 4,
    QWORD = 8
};
#if defined(__STL_SUPPORT__)
void __swapBytes(vector<uint8_t> &v, size_t src, size_t dst);
void __swapEndian(vector<uint8_t> &v, size_t wordlen);
void __swapNibbles(vector<uint8_t> &v);
void __fill(vector<uint8_t> &v, uint8_t fill_byte, size_t size);
#endif

void __swapBytes(u8t *v, size_t src, size_t dst);
void __swapEndian(u8t *v, size_t size, size_t wordlen);

void __swapNibbles(u8t* src, size_t size);

void __fill(u8t &buff, u8t fill_byte, size_t currentSize, size_t size);

bool isInRange(size_t n, size_t first, size_t last);

//size_t __dicotomicSearch(void * );

#endif
