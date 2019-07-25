#ifndef HARDWARESERIAL_H
#define HARDWARESERIAL_H
#include <macros.h>
#include <serial.h>
#include <avr/io.h>
//#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <printf.h>


class UART
{
public:
	void printf(const char* fmt, ...);
	virtual void registerCallback(ser_cb_t *cb = nullptr) = 0;
	virtual void registerCallback(SystemEventHandler *cb = nullptr) = 0;

protected:
	UART(volatile u8t* UCSRxA, HW_UART baud);
	volatile u8t* UCSRxA;

};

class UART0 : public UART
{
public:
	UART0(HW_UART baud) : UART((volatile u8t*)&UCSR1A, baud){
		UCSRxA = (volatile u8t*)&UCSR1A;
	}
	virtual void registerCallback(ser_cb_t* cb = nullptr) override;
	virtual void registerCallback(SystemEventHandler* cb = nullptr) override;

private:
};

class UART1 : public UART
{
public:
	UART1(HW_UART baud) : UART((volatile u8t*)&UCSR0A, baud){
		UCSRxA = (volatile u8t*)&UCSR0A;
	}
	virtual void registerCallback(ser_cb_t* cb = nullptr) override;
	virtual void registerCallback(SystemEventHandler* cb = nullptr) override;

private:
};




#endif // HARDWARESERIAL_H
