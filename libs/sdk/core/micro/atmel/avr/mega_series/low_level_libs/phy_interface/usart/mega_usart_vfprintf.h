#pragma once
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
//#include <strutil.h>
#include <core.h>

#if defined(__MEGA_SERIES__)

using namespace core::mega::uart;
namespace yanujz {

    inline char* utoa(char *__dst, u8t size, unsigned int val, u8t base){
	u8t chr;

	u8t i = size-2;
	//__dst[size-1] = 0;

	do{
	    chr = val % base;

	    if (chr > 9) {
		chr = chr - 10 + 'a';
	    } else {
		chr+= '0';
	    }
	    __dst[i] = (char) chr;

	    --i;
	}while (val /= base);


	return &__dst[i+1];

    }

    inline char* itoa(char *__dst, u8t size, int val, u8t  base){
	//u8t chr;

	u8t i = size-2;
	//__dst[size-1] = 0;
	bool neg = false;
	if(val < 0){
	    val = toABS(val);
	    neg = true;
	}
	__dst = yanujz::utoa(__dst, i, val, base);
	if(neg){
	    *(--__dst) = '-';
	}
	return __dst;
    }
    //FIXME remove static index
#if defined(__FLOAT_SUPPORT__)
    inline char* ftoa(float n, char *__dst, int afterpoint){
	//const float pow10[] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000 };
	int iPart = toInt(n);
	unsigned int fPart = ((n - toInt(n)) * 10000);

	char * b = yanujz::itoa(__dst, 32, fPart, 10);
	if(__dst+31 - b < afterpoint--){
	    while (afterpoint--) {
		*(--b) = '0';
	    }
	}
	*(--b) = '.';
	b = yanujz::itoa(__dst, 31 - (__dst+30 - b), iPart , 10);

	return b;
    }
#endif
#undef getc
    inline u8t getc(volatile u8t* UCSRxA){
	loop_until_bit_is_set(*UCSRxA, RXCx);
	return *UART_UDRx_REG_OFFSET(UCSRxA);
    }

#undef putc
    inline void putc(u8t c, volatile u8t *UCSRxA){
	loop_until_bit_is_set(*UCSRxA, UDREx);
	*UART_UDRx_REG_OFFSET(UCSRxA) = c;\
    }

#undef puts
    inline void puts(const char *str, volatile u8t *UCSRxA){
	while (*str) {
	    yanujz::putc(*str++, UCSRxA);
	}
    }

    extern void vfprintf(volatile u8t* __stream, const char *fmt, va_list arg) __attribute__ ((noinline));

   // extern void printf(const char* fmt, ...);

    extern void printf(volatile u8t* __stream, const char* fmt, ...);


}

#endif
