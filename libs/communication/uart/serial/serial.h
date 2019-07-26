#ifndef SERIAL_H
#define SERIAL_H
#include <macros.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/setbaud.h>
#include <stdio.h>
#include <systemevent.h>
#include <printf.h>
#if defined(__AVR_ATmega640__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
#include <atmega2560.h>
#elif defined(__AVR_ATmega48p__) ||  defined(__AVR_ATmega88P__) || defined(__AVR_ATmega328P__)
#include <atmega328p.h>
#else
#include <gpiodef.h>
#endif


///@file



class Serial
{
public:
	//-----------------METHODS-----------------//
	virtual void begin(HW_UART baud) = 0;
	void printf(const char *fmt, ...);
	void print(const char* str);
	void print(char c);
	void write(const char* buff, int size);
	void readUntil(char *buffer, char chr);
	void flush();
	bool isAvailable();
	char receive();
	void clear();
	//-----------------VARIABLES---------------//

protected:
	//-----------------METHODS-----------------//
	Serial(){}
	void init(HW_UART baud);


	//-----------------VARIABLES---------------//
	volatile u8t* UCSRxA;

};



#endif // SERIAL_H
