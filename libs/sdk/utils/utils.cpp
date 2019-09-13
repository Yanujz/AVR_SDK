#include "utils.h"



void swapBytes(u8 *v, size_t src, size_t dst)
{
	u8 tmp = v[src];
	v[src] = v[dst];
	v[dst] = tmp;
}

void swapEndian(u8 *v, size_t size, size_t wordlen)
{
	for(size_t idx = 0; idx < size/wordlen; idx++) {
		for(size_t j = 0; j<wordlen/2; j++) {
			size_t src = (wordlen*idx)+j;
			size_t dst = (wordlen*idx)+(wordlen-1)-j;
			swapBytes(v, src, dst);
		}
	}
}



void swapNibbles(u8 *src, size_t size)
{
	for(size_t i = 0; i < size; ++i) {
		src[i] = ( (src[i] & 0x0F) << 4 | (src[i] & 0xF0) >> 4 );
	}
}

void fill(u8 &buff, u8 fill_byte, size_t currentSize, size_t size)
{
	size_t lastIndex = currentSize;
	buff = *(uint8_t*) realloc(&buff, size);
	size_t newIndex = (lastIndex+size);
	for(size_t i = lastIndex; i < newIndex; ++i ){
		*(&buff+i) = fill_byte;
	}
}




bool isInRange(size_t n, size_t first, size_t last)
{
	if(n >= first && n <= last){
		return true;
	}
	return false;
}


void u16ToArr(u8 *dst, u16 value)
{

}

void u32ToArr(u8 *dst, u32 value)
{
	memcpy(dst, &value, sizeof (u32));
}



void u64ToArr(u8 *dst, u64 value)
{

}

int check_for_endianness()
{
	unsigned int x = 1;
	char *c = (char*) &x;
	return (int)*c;
}


