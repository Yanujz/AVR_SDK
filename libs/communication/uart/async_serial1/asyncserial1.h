#ifndef ASYNCSERIAL1_H
#define ASYNCSERIAL1_H
#include <asyncserial.h>
#include <serial1.h>

class AsyncSerial1 : public Serial1, public AsyncSerial
{
public:
	AsyncSerial1();
	virtual void begin(HW_UART baud, bool setRxIrq = false, bool setEcho = false) override;
	virtual void registerCallback(ser_cb_t* cb = nullptr) override;
	virtual void registerCallback(SystemEventHandler* cb = nullptr) override;
private:
	virtual void begin(HW_UART baud) override;
};
extern AsyncSerial1 asyncSerial1;

#endif // ASYNCSERIAL1_H
