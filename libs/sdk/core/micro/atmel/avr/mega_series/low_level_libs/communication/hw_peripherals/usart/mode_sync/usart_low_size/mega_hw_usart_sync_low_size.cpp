#include <core.h>
#if defined (__MEGA_SERIES__)
#include <mega_hw_usart_sync_low_size.h>

void usart_init(USART usart, HW_UART baud){
				*UART_UBRRxL_REG_OFFSET((volatile u8t*)usart) = LO8(toU16(baud));
				*UART_UBRRxH_REG_OFFSET((volatile u8t*)usart) = HI8(toU16(baud));
    // Enable receiver and transmitter
				*UART_UCSRxB_REG_OFFSET((volatile u8t*)usart) = setBitValue(1, RXENx) | setBitValue(1, TXENx);
				//*UART_UCSRxB_REG_OFFSET((volatile u8t*)usart) = (1 << RXENx) | (1 << TXENx);
    // Set format: 8data, 1stop bit
    *UART_UCSRxC_REG_OFFSET((volatile u8t*)usart) = ASYNC_MODE | PARITY_DISABLED | EIGHT_BIT | ONE_STOP_BIT;
}

char usart_receive(USART usart)
{
    return yanujz::getc((volatile u8t*)usart);
}


bool usart_isAvailable(USART usart)
{
    return *(volatile u8t*)usart & bitValue(RXCx); // Return true means is available

}

void usart_flush(USART usart)
{
    u8t dummy;
    while(*(volatile u8t*)usart & bitValue(RXCx)){
	dummy = *UART_UDRx_REG_OFFSET((volatile u8t*)usart);
    }
}

void usart_readUntil(USART usart, char *buffer, char chr)
{
    u8t i = 0;
    while (1) {
	char temp = usart_receive(usart);
	if(temp == chr){
	    buffer[++i] ='\0';
	    break;
	}
	buffer[i++] = temp;
    }
}

void usart_write(USART usart, const char *buff, int size)
{
    while (size--) {
	yanujz::putc(*buff++, (volatile u8t*)usart);
    }
}

void usart_print(USART usart, char c)
{
    yanujz::putc(c, (volatile u8t*)usart);
}

void usart_print(USART usart, const char *str)
{
    yanujz::puts(str, (volatile u8t*)usart);
}

void usart_printf(USART usart, const char *fmt, ...)
{
    va_list arg;
    va_start(arg,fmt);
    yanujz::vfprintf((volatile u8t*)usart, fmt, arg);
    va_end(arg);
}

void usart_end(USART usart)
{
    usart_flush(usart);
    *UART_UCSRxB_REG_OFFSET((volatile u8t*)usart) &= ~(bitValue(RXENx) | bitValue(TXENx) | bitValue(RXCIEx) |	bitValue(TXCIEx));
}
#endif
