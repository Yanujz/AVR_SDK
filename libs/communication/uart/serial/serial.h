#ifndef SERIAL_H
#define SERIAL_H
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/setbaud.h>
#include <stdio.h>
#include <systemevent.h>
#include <printf.h>
#include <core.h>




#define UCSRxB_REG UART_UCSRxB_REG_OFFSET(UCSRxA)
#define UCSRxC_REG UART_UCSRxC_REG_OFFSET(UCSRxA)
#define UBRRxL_REG UART_UBRRxL_REG_OFFSET(UCSRxA)
#define UBRRxH_REG UART_UBRRxH_REG_OFFSET(UCSRxA)
#define UDRx_REG			UART_UDRx_REG_OFFSET(UCSRxA)





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
