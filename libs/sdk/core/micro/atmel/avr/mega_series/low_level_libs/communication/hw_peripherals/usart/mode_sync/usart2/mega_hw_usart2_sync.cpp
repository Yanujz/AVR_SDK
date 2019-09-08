#include <core.h>
#if defined (__MEGA_SERIES_USART2_SUPPORT__)
#include <mega_hw_usart2_sync.h>
Usart2 usart2;

Usart2::Usart2(): Usart(){}

void Usart2::begin(HW_UART baud)
{
    UCSRxA = (volatile u8t*)&UCSR2A;
    Usart::init(baud);
}
#endif
