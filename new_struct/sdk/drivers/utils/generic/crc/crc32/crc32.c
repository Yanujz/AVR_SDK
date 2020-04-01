#include "crc32.h"

uint32_t crc32(const uint8_t *data, const uint32_t size)
{
    uint32_t r = 0xFFFFFFFF;
    for(unsigned int i = 0; i < size; i++ ){
        r ^= data[i];
        for(int j = 0; j < 8; j++) {
            r = r & 1 ? (r >> 1) ^ 0xEDB88320 : r >> 1;	// faster implementation
            //r = (r>>1) ^ (0xEDB88320 * (r & 1));	// OLD implementation (slower)
        }
    }
    return r ^ 0xFFFFFFFF;
}
