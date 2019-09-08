#include <core.h>
#if defined (__USART3_SUPPORT__)
#include <usart3_stream_in.h>

USART3_StreamIn usart3_streamIn;

USART3_StreamIn::USART3_StreamIn()
{
  UsartStreamIn::usart = &usart3;
}

USART3_StreamIn::USART3_StreamIn(HW_UART baud){
	usart3.begin (baud);
	UsartStreamIn::usart = &usart3;
}
#endif
