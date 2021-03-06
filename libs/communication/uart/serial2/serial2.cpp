#include "serial2.h"
#if defined(__SERIAL2_SUPPORT__)
Serial2 serial2;

Serial2::Serial2(): Serial(){}

void Serial2::begin(HW_UART baud)
{
    UCSRxA = (volatile u8t*)&UCSR2A;
    init(baud);
}

#endif
