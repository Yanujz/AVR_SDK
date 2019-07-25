#include "serial2.h"
Serial2 serial2;

void Serial2::begin(HW_UART baud)
{
    UCSRxA = (volatile u8t*)&UCSR2A;
    init(baud);
}
