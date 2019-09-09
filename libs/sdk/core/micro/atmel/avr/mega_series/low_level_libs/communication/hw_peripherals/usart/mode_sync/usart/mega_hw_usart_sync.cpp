#include <core.h>
#if defined (__MEGA_SERIES__)
#include <mega_hw_usart_sync.h>

void Usart::end()
{
  flush();
  usart_end((USART)((int)UCSRxA));
}

void Usart::printf(const char *fmt, ...)
{
  va_list arg;
  va_start(arg,fmt);
  yanujz::vfprintf((USART)((int)UCSRxA), fmt, arg);
  va_end(arg);
}

void Usart::printf(const char *fmt, va_list arg)
{
  yanujz::vfprintf((USART)((int)UCSRxA), fmt, arg);
}

void Usart::print(const char *str)
{
  yanujz::puts((USART)((int)UCSRxA), str);
}

void Usart::print(char c)
{
  yanujz::putc((USART)((int)UCSRxA), c);
}

void Usart::write(const char *buff, int size)
{
  usart_write((USART)((int)UCSRxA), buff, size);
}

void Usart::readUntil(char *buff, int size, char chr)
{
  usart_readUntil((USART)((int)UCSRxA), buff, size, chr);
}

void Usart::flush()
{
  usart_flush((USART)((int)UCSRxA));
}

bool Usart::isAvailable()
{
  return ((USART_TypeDef*)UCSRxA)->UCSRA & bitValue(RXCx); // Return true means is available

}

char Usart::receive()
{
  return yanujz::getc((USART)((int)UCSRxA));
}

Usart::Usart(){}

void Usart::init(HW_UART baud)
{
  usart_init((USART)((int)UCSRxA), baud);
}



#endif
