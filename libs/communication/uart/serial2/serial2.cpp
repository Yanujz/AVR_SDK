#include "serial2.h"
#define __SERIAL2_SUPPORT__
#if defined(__AVR_ATmega48p__) ||  defined(__AVR_ATmega88P__) || defined(__AVR_ATmega328P__)
#undef __SERIAL2_SUPPORT__
#endif
#if defined(__SERIAL2_SUPPORT__)
Serial2 serial2;

Serial2::Serial2(): Serial(){}

void Serial2::begin(HW_UART baud)
{
    UCSRxA = (volatile u8t*)&UCSR2A;
    init(baud);
}

#endif
