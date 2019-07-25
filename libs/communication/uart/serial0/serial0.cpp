#include "serial0.h"
Serial0 serial0;

void Serial0::begin(HW_UART baud)
{
	UCSRxA = (volatile u8t*)&UCSR0A;
	Serial::init(baud);
}



// /home/zetes/Documents/GitHub/AVR_SDK/libs/communication/uart/
