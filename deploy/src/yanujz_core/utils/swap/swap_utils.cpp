#include "swap_utils.h"

void swap_bytes(u8t *v, size_t src, size_t dst)
{
    u8t tmp = v[src];
    v[src] = v[dst];
    v[dst] = tmp;
}

void swap_endian(u8t *v, size_t size, size_t wordlen)
{
    for(size_t idx = 0; idx < size/wordlen; idx++) {
        for(size_t j = 0; j<wordlen/2; j++) {
            size_t src = (wordlen*idx)+j;
            size_t dst = (wordlen*idx)+(wordlen-1)-j;
            swap_bytes(v, src, dst);
        }
    }
}

void swap_nibbles(u8t *v, size_t size)
{
    for(size_t i = 0; i < size; i++) {
        v[i] = ( (v[i] & 0x0F) << 4 | (v[i] & 0xF0) >> 4 );
    }
}



#if defined(__STL_SUPPORT__)
using namespace std;
void swap_bytes(std::vector<uint8_t> &v, size_t src, size_t dst)
{
    swap_bytes(v.data(), src, dst);
}

void swap_endian(std::vector<uint8_t> &v, size_t wordlen)
{
    swap_endian(v.data(), v.size(), wordlen);
}

void swap_nibbles(std::vector<uint8_t> &v)
{
    swap_nibbles(v.data(), v.size());
}


#endif
