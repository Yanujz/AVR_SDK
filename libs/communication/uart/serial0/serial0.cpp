#include "serial0.h"
Serial0 serial0;

Serial0::Serial0(): Serial(){}

void Serial0::begin(HW_UART baud)
{
	UCSRxA = (volatile u8t*)&UCSR0A;
	Serial::init(baud);
}

