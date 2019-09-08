#include <core.h>
#if defined (__MEGA_SERIES__)
#include <mega_hw_usart_sync.h>

void Usart::end()
{
    flush();
    *UART_UCSRxB_REG_OFFSET(UCSRxA) &= ~(bitValue(RXENx) | bitValue(TXENx) | bitValue(RXCIEx) |	bitValue(TXCIEx));
}

void Usart::printf(const char *fmt, ...)
{
    va_list arg;
    va_start(arg,fmt);
    yanujz::vfprintf(UCSRxA, fmt, arg);
    va_end(arg);
}

void Usart::printf(const char *fmt, va_list arg)
{
    yanujz::vfprintf(UCSRxA, fmt, arg);
}

void Usart::print(const char *str)
{
    yanujz::puts(str, UCSRxA);
}

void Usart::print(char c)
{
    yanujz::putc(c, UCSRxA);
}

void Usart::write(const char *buff, int size)
{
    //while (size--) {
	//yanujz::putc(*buff++, UCSRxA);
    //}
    usart_write((USART)((int)UCSRxA), buff, size);
}

void Usart::readUntil(char *buffer, char chr)
{
    //u8t i = 0;
    //while (1) {
	//char temp = receive();
	//if(temp == chr){
	//    buffer[++i] ='\0';
	//    break;
	//}
	//buffer[i++] = temp;
    //}
    usart_readUntil((USART)((int)UCSRxA), buffer, chr);
}

void Usart::flush()
{
    //u8t dummy;
    //while(*UCSRxA & bitValue(RXCx)){
	//dummy = *UART_UDRx_REG_OFFSET(UCSRxA);
    //}
    usart_flush((USART)((int)UCSRxA));
}

bool Usart::isAvailable()
{
    return *UCSRxA & bitValue(RXCx); // Return true means is available

}

char Usart::receive()
{
    return yanujz::getc(UCSRxA);
    //return usart_receive((USART)((int)UCSRxA));
}

Usart::Usart(){}

void Usart::init(HW_UART baud)
{
   // *UART_UBRRxL_REG_OFFSET(UCSRxA) = HI8(toU16(baud));
   // *UART_UBRRxH_REG_OFFSET(UCSRxA) = LO8(toU16(baud));
   // // Enable receiver and transmitter
   // *UART_UCSRxB_REG_OFFSET(UCSRxA) = setBitValue(1, RXENx) | setBitValue(1, TXENx);
   // // Set format: 8data, 1stop bit
   // *UART_UCSRxC_REG_OFFSET(UCSRxA) = ASYNC_MODE | PARITY_DISABLED | EIGHT_BIT | ONE_STOP_BIT;
    usart_init((USART)((int)UCSRxA), baud);
}



#endif
