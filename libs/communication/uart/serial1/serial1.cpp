#include "serial1.h"

Serial1 serial1;

void Serial1::begin(HW_UART baud)
{
    UCSRxA = (volatile u8t*)&UCSR1A;
    init(baud);
}
