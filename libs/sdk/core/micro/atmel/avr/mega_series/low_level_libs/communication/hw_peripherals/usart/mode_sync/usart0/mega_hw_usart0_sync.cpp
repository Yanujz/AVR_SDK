#include <core.h>
#if defined (__MEGA_SERIES_USART0_SUPPORT__)
#include <mega_hw_usart0_sync.h>
Usart0 usart0;

Usart0::Usart0(): Usart(){}

void Usart0::begin(HW_UART baud)
{
    UCSRxA = (volatile u8t*)&UCSR0A;
    Usart::init(baud);
}
#endif
