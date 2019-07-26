#ifndef ASYNCSERIAL2_H
#define ASYNCSERIAL2_H
#include <asyncserial.h>
#include <serial2.h>

class AsyncSerial2 : public Serial2, public AsyncSerial
{
public:
    AsyncSerial2();
    virtual void begin(HW_UART baud) override;
    virtual void begin(HW_UART baud, bool setRxIrq = false, bool setEcho = false) override;
    virtual void registerCallback(ser_cb_t* cb = nullptr) override;
    virtual void registerCallback(SystemEventHandler* cb = nullptr) override;
};
extern AsyncSerial2 asyncSerial2;

#endif // ASYNCSERIAL2_H
