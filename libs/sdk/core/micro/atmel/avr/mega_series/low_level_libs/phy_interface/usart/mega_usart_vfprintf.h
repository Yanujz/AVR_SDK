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
using namespace core::mega::common_typef;
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
  inline u8 getc(USART usart){
	loop_until_bit_is_set(((USART_TypeDef*)usart)->UCSRA, RXCx);
	return ((USART_TypeDef*)usart)->UDR;
  }

#undef putc
  inline void putc(USART usart, u8t c){
	loop_until_bit_is_set(((USART_TypeDef*)usart)->UCSRA, UDREx);
	((USART_TypeDef*)usart)->UDR = c;
  }


#undef puts
  inline void puts(USART usart, const char *str){
	while (*str) {
	  yanujz::putc(usart, *str++ );
	}
  }

  extern void vfprintf(USART __stream, const char *fmt, va_list arg) __attribute__ ((noinline));


  extern void printf(USART __stream, const char* fmt, ...);


}

#endif
