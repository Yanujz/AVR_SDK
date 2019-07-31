#pragma once
#include <asyncserial.h>
#include <serial1.h>

#if defined(__SERIAL1_SUPPORT__)
class AsyncSerial1 : public Serial1, public AsyncSerial
{
public:
	AsyncSerial1();
	virtual void begin(HW_UART baud) override;
	virtual void registerCallback(ser_cb_t* cb = nullptr) override;
	virtual void registerCallback(SystemEventHandler* cb = nullptr) override;
private:
};
extern AsyncSerial1 asyncSerial1;
#endif // __SERIAL1_SUPPORT__
