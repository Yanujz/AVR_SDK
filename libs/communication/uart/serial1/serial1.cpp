#include "serial1.h"
#define __SERIAL1_SUPPORT__
#if defined(__AVR_ATmega48p__) ||  defined(__AVR_ATmega88P__) || defined(__AVR_ATmega328P__)
#undef __SERIAL1_SUPPORT__
#endif
#if defined(__SERIAL1_SUPPORT__)
Serial1 serial1;

Serial1::Serial1(): Serial(){}

void Serial1::begin(HW_UART baud)
{
	UCSRxA = (volatile u8t*)&UCSR1A;
	init(baud);
}
#endif //__SERIAL1_SUPPORT__
