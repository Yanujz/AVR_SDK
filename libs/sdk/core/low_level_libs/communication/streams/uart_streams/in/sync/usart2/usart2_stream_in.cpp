#include <core.h>
#if defined (__USART2_SUPPORT__)
#include <usart2_stream_in.h>

USART2_StreamIn usart2_streamIn;

USART2_StreamIn::USART2_StreamIn()
{
  UsartStreamIn::usart = &usart2;
}

USART2_StreamIn::USART2_StreamIn(HW_UART baud){
	usart2.begin (baud);
	UsartStreamIn::usart = &usart2;
}
#endif
