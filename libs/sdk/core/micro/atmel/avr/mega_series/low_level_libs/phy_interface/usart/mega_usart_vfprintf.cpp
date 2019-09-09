#include <mega_usart_vfprintf.h>

/*
* This part isn't really completed!
* There're stuff that works just as is.
* Please make me perfect.
*
*
* 09/09/2019 - Yanujz.
*/

#if defined(__MEGA_SERIES__)
namespace yanujz {

  void printf(USART __stream, const char *fmt, ...)
  {
	va_list arg;
	va_start(arg,fmt);
	yanujz::vfprintf(__stream, fmt, arg);
	va_end(arg);
  }

  void vfprintf(USART __stream, const char *fmt, va_list arg)
  {
	char ch, char_temp;
	char* string_temp = nullptr;
	char buffer[32] = {0};
	//u8t i;
	//int int_temp;
	while ( (ch = *fmt++) ) {
	  if ( ch == '%' ) {
		switch (ch = *fmt++) {
		case 'c':
		  char_temp = va_arg(arg, int);
		  yanujz::putc(__stream, char_temp);
		  continue;
		case 's':
		  string_temp = va_arg(arg, char*);
		  break;
		case 'd':
		  string_temp = yanujz::itoa(buffer, sizeOfArray(buffer), va_arg(arg, int), 10);
		  break;
		case 'u':
		  string_temp = yanujz::utoa(buffer, SIZE_OF_ARRAY(buffer), va_arg(arg, unsigned int), 10);
		  break;
		case 'x':
		  string_temp = yanujz::utoa(buffer, SIZE_OF_ARRAY(buffer), va_arg(arg, unsigned int), 16);
		  break;
		  //case 'X':
		  //	string_temp = yanujz::utoa(buffer, SIZE_OF_ARRAY(buffer), va_arg(arg, unsigned int), 16);
		  //	string_temp = yanujz::strToUpper(string_temp);
		  //	break;
		case 'p':
		  string_temp = yanujz::utoa(buffer, SIZE_OF_ARRAY(buffer), (uintptr_t)va_arg(arg, void*), 16);
		  break;
#if defined(__FLOAT_SUPPORT__)
		case 'f':
		  string_temp = yanujz::ftoa(va_arg(arg, double), buffer, 4);
		  break;
#endif
		}
		yanujz::puts(__stream, string_temp);
	  }
	  else {
		yanujz::putc(__stream, ch);
	  }
	}
  }




}
#endif
