#ifndef ASYNCSERIAL3_H
#define ASYNCSERIAL3_H
#include <asyncserial.h>
#include <serial3.h>
#define __SERIAL3_SUPPORT__
#if defined(__AVR_ATmega48p__) ||  defined(__AVR_ATmega88P__) || defined(__AVR_ATmega328P__)
#undef __SERIAL3_SUPPORT__
#endif
#if defined(__SERIAL3_SUPPORT__)
class AsyncSerial3 : public Serial3, public AsyncSerial
{
public:
	AsyncSerial3();
	virtual void begin(HW_UART baud) override;
	virtual void registerCallback(ser_cb_t* cb = nullptr) override;
	virtual void registerCallback(SystemEventHandler* cb = nullptr) override;
};
extern AsyncSerial3 asyncSerial3;
#endif
#endif // ASYNCSERIAL3_H
