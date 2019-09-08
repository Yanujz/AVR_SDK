#include <core.h>
#if defined (__USART2_SUPPORT__)
#include <usart2_stream_out.h>
USART2_StreamOut usart2_streamOut;

USART2_StreamOut::USART2_StreamOut(){
  UsartStreamOut::usart = &usart2;
}

USART2_StreamOut::USART2_StreamOut(HW_UART baud)
{
  usart2.begin (baud);
  UsartStreamOut::usart = &usart2;
}

#endif
