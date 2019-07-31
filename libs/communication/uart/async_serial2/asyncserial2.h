#pragma once
#include <asyncserial.h>
#include <serial2.h>

#if defined(__SERIAL2_SUPPORT__)
class AsyncSerial2 : public Serial2, public AsyncSerial
{
public:
    AsyncSerial2();
    virtual void begin(HW_UART baud) override;
    virtual void registerCallback(ser_cb_t* cb = nullptr) override;
    virtual void registerCallback(SystemEventHandler* cb = nullptr) override;
};
extern AsyncSerial2 asyncSerial2;
#endif // __SERIAL2_SUPPORT__
