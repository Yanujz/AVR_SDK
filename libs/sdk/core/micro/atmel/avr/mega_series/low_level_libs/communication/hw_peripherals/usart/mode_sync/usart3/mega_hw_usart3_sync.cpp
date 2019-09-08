#include <core.h>
#if defined (__MEGA_SERIES_USART3_SUPPORT__)
#include <mega_hw_usart3_sync.h>
Usart3 usart3;

Usart3::Usart3(): Usart(){}

void Usart3::begin(HW_UART baud)
{
    UCSRxA = (volatile u8t*)&UCSR3A;
    Usart::init(baud);
}
#endif
