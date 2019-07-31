#include "serial3.h"

#if defined(__SERIAL3_SUPPORT__)
Serial3 serial3;
Serial3::Serial3(): Serial(){}

void Serial3::begin(HW_UART baud)
{
	UCSRxA = (volatile u8t*)&UCSR3A;
	Serial::init(baud);
}
#endif // __SERIAL3_SUPPORT__
