#include <usart_stream_out.h>

void UsartStreamOut::send(char c)
{
  usart->print (c);
}

void UsartStreamOut::send(const char *str)
{
  usart->print (str);
}

void UsartStreamOut::printf(const char *fmt, va_list arg)
{
  usart->printf(fmt, arg);
}

UsartStreamOut::UsartStreamOut()
{

}
