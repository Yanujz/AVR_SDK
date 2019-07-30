#include "serial3.h"
#define __SERIAL3_SUPPORT__
#if defined(__AVR_ATmega48p__) ||  defined(__AVR_ATmega88P__) || defined(__AVR_ATmega328P__)
#undef __SERIAL3_SUPPORT__
#endif
#if defined(__SERIAL3_SUPPORT__)
Serial3 serial3;
Serial3::Serial3(): Serial(){}

void Serial3::begin(HW_UART baud)
{
	UCSRxA = (volatile u8t*)&UCSR3A;
	Serial::init(baud);
}
#endif
