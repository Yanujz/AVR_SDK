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

/**
	* @brief Used to handle interrupts
	*/
typedef void ser_cb_t();
struct __HW_INT_ISR
{
	ser_cb_t* user_cb_vect;
	SystemEventHandler* sys_cb_vect;
};







class Serial
{
public:
	//-----------------METHODS-----------------//
	virtual void begin(HW_UART baud) = 0;
	//virtual void registerCallback(ser_cb_t *cb = nullptr)  = 0;
	//virtual void registerCallback(SystemEventHandler *cb = nullptr)  = 0;


	void printf(const char *fmt, ...);
	void readUntil(char *buffer, char chr);
	void flush();
	bool isAvailable();
	uint8_t receive();
	void clear();
	//-----------------VARIABLES---------------//

protected:
	//-----------------METHODS-----------------//
	Serial(){}
	void init(HW_UART baud);


	//-----------------VARIABLES---------------//
	
	//u8t USART_BUFF[32];
	volatile u8t* UCSRxA;

};

//extern Serial* __hw_serial[4];
extern __HW_INT_ISR __hw_serial_cb[4];





//class Serial1 : public Serial {
//public:
//	Serial1(): Serial(){}
//	virtual void begin(HW_UART baud, bool setRxIrq = false, bool setEcho = false) override;
//	virtual void registerCallback(ser_cb_t* cb = nullptr) override;
//	virtual void registerCallback(SystemEventHandler* cb = nullptr) override;
//};
//
//class Serial2 : public Serial {
//public:
//	Serial2(): Serial(){}
//	virtual void begin(HW_UART baud, bool setRxIrq = false, bool setEcho = false) override;
//	virtual void registerCallback(ser_cb_t* cb = nullptr) override;
//	virtual void registerCallback(SystemEventHandler* cb = nullptr) override;
//};
//
//class Serial3 : public Serial {
//public:
//	Serial3(): Serial(){}
//	virtual void begin(HW_UART baud, bool setRxIrq = false, bool setEcho = false) override;
//	virtual void registerCallback(ser_cb_t* cb = nullptr) override;
//	virtual void registerCallback(SystemEventHandler* cb = nullptr) override;
//};
//
//
//extern Serial1 serial1;
//extern Serial2 serial2;
//extern Serial3 serial3;




/*


#if defined(__AVR_ATmega328P__) || defined(__AVR_ATmega640__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
#endif
#if defined(__AVR_ATmega640__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
//class Serial1 : public Serial {
//	friend class SerialManager;
//private:
//	Serial1(): Serial() {
//		_self.UCSRxA = (volatile uint8_t*)&UCSR1A;
//		_self.UCSRxB = (volatile uint8_t*)&UCSR1B;
//		_self.UCSRxC = (volatile uint8_t*)&UCSR1C;
//		_self.UBRRxH = (volatile uint8_t*)&UBRR1H;
//		_self.UBRRxL = (volatile uint8_t*)&UBRR1L;
//		_self.UDRx   = (volatile uint8_t*)&UDR1;
//	}
//
//};


//class Serial2 : public Serial {
//	friend class SerialManager;
//private:
//	Serial2(): Serial() {
//		_self.UCSRxA = (volatile uint8_t*)&UCSR2A;
//		_self.UCSRxB = (volatile uint8_t*)&UCSR2B;
//		_self.UCSRxC = (volatile uint8_t*)&UCSR2C;
//		_self.UBRRxH = (volatile uint8_t*)&UBRR2H;
//		_self.UBRRxL = (volatile uint8_t*)&UBRR2L;
//		_self.UDRx   = (volatile uint8_t*)&UDR2;
//	}
//
//};

//class Serial3 : public Serial {
//	friend class SerialManager;
//private:
//	Serial3(): Serial() {
//		_self.UCSRxA = (volatile uint8_t*)&UCSR3A;
//		_self.UCSRxB = (volatile uint8_t*)&UCSR3B;
//		_self.UCSRxC = (volatile uint8_t*)&UCSR3C;
//		_self.UBRRxH = (volatile uint8_t*)&UBRR3H;
//		_self.UBRRxL = (volatile uint8_t*)&UBRR3L;
//		_self.UDRx   = (volatile uint8_t*)&UDR3;
//	}
//
//
//};
#endif
*/

/*
class SerialManager
{
public:
	static Serial* getInstance(u8t port,HW_UART baud, bool setRxIrq = false, bool setEcho = false);
private:
	static Serial* _getPtr(u8t port){
		return __hw_serial[port];
	}

};
*/



#endif // SERIAL_H
