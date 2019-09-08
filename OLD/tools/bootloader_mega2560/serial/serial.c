#include "serial.h"
#include <avr/io.h>
#include <math.h>
#include <avr/interrupt.h>
#define MYUBRR(x) (F_CPU/16/(float)x-1)
void uartinit(int baud)
{
	UBRR0H = 0;
	UBRR0L = 0;
	// Enable receiver and transmitter //
	UCSR0B |= (1<<RXEN0)|(1<<TXEN0)| (1 << RXCIE0);
	// Set frame format: 8data, 1stop bit //
	UCSR0C = (1<<UCSZ01)|(1<<UCSZ00);

	sei();
}

void printStr(char *str)
{
	register uint8_t i = 0;
	while (str[i]) {
		printChar(str[i]);
		++i;
	}
}

void printChar(char ch)
{
	while ( !( UCSR0A & (1<<UDRE0)) );
	UDR0 = ch;
}

char uartReceive()
{
	while (!(UCSR0A & (1<<RXC0)));
	return UDR0;
}

char isAvailable()
{
	return (UCSR0A & (1<<RXC0))>>RXC0; // Return true means is available
}


