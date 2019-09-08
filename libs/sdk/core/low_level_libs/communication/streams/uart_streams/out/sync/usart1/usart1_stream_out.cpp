#include <core.h>
#if defined (__USART1_SUPPORT__)
#include <usart1_stream_out.h>
USART1_StreamOut usart1_streamOut;

USART1_StreamOut::USART1_StreamOut(){
  UsartStreamOut::usart = &usart1;
}

USART1_StreamOut::USART1_StreamOut(HW_UART baud)
{
  usart1.begin (baud);
  UsartStreamOut::usart = &usart1;
}

#endif
