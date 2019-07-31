#pragma once
#include <asyncserial.h>
#include <serial3.h>

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
