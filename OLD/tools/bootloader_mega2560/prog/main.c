#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>

void printChar(char ch)
{
	while ( !( UCSR0A & (1<<UDRE0)) );
	UDR0 = ch;
}
int main(){
DDRB=0X80;
	UBRR0H = 0;
	UBRR0L = 8;
	// Enable receiver and transmitter //
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	// Set frame format: 8data, 1stop bit //
	UCSR0C = (1<<UCSZ01)|(1<<UCSZ00);
while(1) {
PORTB^=0X80;
printChar('B');
_delay_ms(1000);
}
}
