#include "serial3.h"

Serial3 serial3;
void Serial3::begin(HW_UART baud)
{
    UCSRxA = (volatile u8t*)&UCSR3A;
    Serial::init(baud);
}