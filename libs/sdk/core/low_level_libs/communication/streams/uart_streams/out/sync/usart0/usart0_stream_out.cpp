#include <core.h>
#if defined (__USART0_SUPPORT__)
#include <usart0_stream_out.h>
USART0_StreamOut usart0_streamOut;

USART0_StreamOut::USART0_StreamOut(){
  UsartStreamOut::usart = &usart0;
}

USART0_StreamOut::USART0_StreamOut(HW_UART baud)
{
  usart0.begin (baud);
  UsartStreamOut::usart = &usart0;
}

#endif
