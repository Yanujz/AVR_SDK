#include <core.h>
#if defined (__USART3_SUPPORT__)
#include <usart3_stream_out.h>
USART3_StreamOut usart3_streamOut;

USART3_StreamOut::USART3_StreamOut(){
  UsartStreamOut::usart = &usart3;
}

USART3_StreamOut::USART3_StreamOut(HW_UART baud)
{
  usart3.begin (baud);
  UsartStreamOut::usart = &usart3;
}

#endif
