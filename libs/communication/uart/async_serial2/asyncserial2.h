#ifndef ASYNCSERIAL2_H
#define ASYNCSERIAL2_H
#include <asyncserial.h>
#include <serial2.h>
#define __SERIAL2_SUPPORT__
#if defined(__AVR_ATmega48p__) ||  defined(__AVR_ATmega88P__) || defined(__AVR_ATmega328P__)
#undef __SERIAL2_SUPPORT__
#endif
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
#endif // ASYNCSERIAL2_H
