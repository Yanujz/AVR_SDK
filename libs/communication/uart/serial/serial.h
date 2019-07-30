#ifndef SERIAL_H
#define SERIAL_H
//#include <macros.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/setbaud.h>
#include <stdio.h>
#include <systemevent.h>
#include <printf.h>
#include <core.h>



///@file



class Serial
{
public:
	virtual void begin(HW_UART baud) = 0;
	void end();
	void printf(const char *fmt, ...);
	void print(const char* str);
	void print(char c);
	void write(const char* buff, int size);
	void readUntil(char *buffer, char chr);
	void flush();
	bool isAvailable();
	char receive();

protected:
	Serial(){}
	void init(HW_UART baud);

	volatile u8t* UCSRxA;

};



#endif // SERIAL_H
