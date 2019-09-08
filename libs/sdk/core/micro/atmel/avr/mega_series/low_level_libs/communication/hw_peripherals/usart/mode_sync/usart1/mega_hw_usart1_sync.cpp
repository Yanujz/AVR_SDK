#include <core.h>
#if defined (__MEGA_SERIES_USART1_SUPPORT__)
#include <mega_hw_usart1_sync.h>
Usart1 usart1;

Usart1::Usart1(): Usart(){}

void Usart1::begin(HW_UART baud)
{
    UCSRxA = (volatile u8t*)&UCSR1A;
    Usart::init(baud);
}
#endif
