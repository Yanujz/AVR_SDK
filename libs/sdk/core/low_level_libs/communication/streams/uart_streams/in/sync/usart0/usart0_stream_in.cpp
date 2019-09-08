#include <core.h>
#if defined (__USART0_SUPPORT__)
#include <usart0_stream_in.h>

USART0_StreamIn usart0_streamIn;

USART0_StreamIn::USART0_StreamIn()
{
  UsartStreamIn::usart = &usart0;
}

USART0_StreamIn::USART0_StreamIn(HW_UART baud){
	usart0.begin (baud);
	UsartStreamIn::usart = &usart0;
}
#endif
