#include "serial1.h"
#if defined(__SERIAL1_SUPPORT__)
Serial1 serial1;

Serial1::Serial1(): Serial(){}

void Serial1::begin(HW_UART baud)
{
	UCSRxA = (volatile u8t*)&UCSR1A;
	init(baud);
}
#endif //__SERIAL1_SUPPORT__
