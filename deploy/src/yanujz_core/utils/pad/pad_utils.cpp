#include "pad_utils.h"


void pad_with(u8t &buff, size_t buf_size, size_t new_size, u8t fill_byte)
{
    size_t lastIndex = buf_size;
    buff = *(uint8_t*) realloc(&buff, new_size);
    size_t newIndex = (lastIndex + new_size);
    for(size_t i = lastIndex; i < newIndex; ++i ){
        *(&buff+i) = fill_byte;
    }
}



#if defined(__STL_SUPPORT__)
using namespace std;
void pad_with(std::vector<uint8_t> &v, uint8_t fill_byte, size_t new_size)
{
    size_t lastIndex = v.size();
    v.resize(new_size);
    size_t newIndex = (lastIndex + new_size);
    for(size_t i = lastIndex; i < newIndex; ++i ){
        v.push_back(fill_byte);
    }
}
#endif
