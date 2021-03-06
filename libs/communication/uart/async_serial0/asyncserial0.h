#pragma once
#include <asyncserial.h>
#include <serial0.h>
#if defined(__SERIAL0_SUPPORT__)
class AsyncSerial0 : public Serial0, public AsyncSerial
{
public:
	AsyncSerial0();
	virtual void begin(HW_UART baud) override;
	virtual void registerCallback(ser_cb_t* cb = nullptr) override;
	virtual void registerCallback(SystemEventHandler* context = nullptr) override;
};
extern AsyncSerial0 asyncSerial0;
#endif // __SERIAL0_SUPPORT__

