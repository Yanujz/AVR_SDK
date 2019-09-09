#include <core.h>
#if defined (__MEGA_SERIES__)
#include <mega_hw_usart_sync_low_size.h>

void usart_init(USART usart, HW_UART baud){

  ((USART_TypeDef*)usart)->UBRRL = LO8(toU16(baud));
  ((USART_TypeDef*)usart)->UBRRH = HI8(toU16(baud));

  // Enable receiver and transmitter
  ((USART_TypeDef*)usart)->UCSRB = setBitValue(1, RXENx) | setBitValue(1, TXENx);

  // Set format: 8data, 1stop bit
  ((USART_TypeDef*)usart)->UCSRC = ASYNC_MODE | PARITY_DISABLED | EIGHT_BIT | ONE_STOP_BIT;
}

char usart_receive(USART usart)
{
  return yanujz::getc(usart);
}


bool usart_isAvailable(USART usart)
{
  return ((USART_TypeDef*)usart)->UCSRA & bitValue(RXCx); // Return true means is available
}

void usart_flush(USART usart)
{
  u8 dummy;
  while(((USART_TypeDef*)usart)->UCSRA & bitValue(RXCx)){
	dummy = ((USART_TypeDef*)usart)->UDR;
  }
}

void usart_readUntil(USART usart, char *buff, int size, char chr)
{
  u8 i = 0;
  while (size--) {
	char temp = usart_receive(usart);
	if(temp == chr){
	  *buff ='\0';
	  return;
	}
	*buff++ = temp;
  }
  *buff ='\0';
}

void usart_write(USART usart, const char *buff, int size)
{
  while (size--) {
	yanujz::putc(usart, *buff++);
  }
}

void usart_print(USART usart, char c)
{
  yanujz::putc(usart, c);
}

void usart_print(USART usart, const char *str)
{
  yanujz::puts(usart, str);
}

void usart_printf(USART usart, const char *fmt, ...)
{
  va_list arg;
  va_start(arg,fmt);
  yanujz::vfprintf(usart, fmt, arg);
  va_end(arg);
}

void usart_end(USART usart)
{
  usart_flush(usart);
  ((USART_TypeDef*)usart)->UCSRB &= ~(bitValue(RXENx) | bitValue(TXENx) | bitValue(RXCIEx) |	bitValue(TXCIEx));
}
#endif
