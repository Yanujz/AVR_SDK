#include "serial.h"

void Serial::init(HW_UART baud)
{
	_UBRRxH(UCSRxA) = HI(toU16(baud));
	_UBRRxL(UCSRxA) = LO(toU16(baud));

	// Enable receiver and transmitter //
	_UCSRxB(UCSRxA) = (1<<RXEN0)|(1<<TXEN0);

	// Set frame format: 8data, 1stop bit //
	_UCSRxC(UCSRxA) = (1<<UCSZ01)|(1<<UCSZ00);
	//UCSR0A = (1<<U2X0); // Clock multiplier
}

void Serial::printf(const char *fmt, ...)
{
	va_list arg;
	va_start(arg,fmt);
	yanujz::vfprintf(UCSRxA, fmt, arg);
	va_end(arg);
}

void Serial::print(const char *str)
{
	yanujz::puts(str, UCSRxA);
}
void Serial::print(char c)
{
	yanujz::putc(c, UCSRxA);
}

void Serial::write(const char *buff, int size)
{
	while (size--) {
		yanujz::putc(*buff++, UCSRxA);
	}
}

void Serial::readUntil(char *buffer, char chr)
{
	u8t i = 0;
	while (1) {
		char temp = receive();
		if(temp == chr){
			buffer[++i] ='\0';
			break;
		}
		buffer[i++] = temp;
	}
}

void Serial::flush()
{

	u8t dummy;
	while(*UCSRxA & (1<<RXC0)){
		dummy = _UDRx(UCSRxA);
	}
}

bool Serial::isAvailable()
{
	return ((*UCSRxA & (1 << RXC0)) >> RXC0); // Return true means is available
}

char Serial::receive()
{
	return yanujz::getc(UCSRxA);
}
void Serial::clear()
{
	yanujz::puts("\e[1;1H\e[2J", UCSRxA);
}

