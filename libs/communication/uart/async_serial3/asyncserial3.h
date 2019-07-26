#ifndef ASYNCSERIAL3_H
#define ASYNCSERIAL3_H
#include <asyncserial.h>
#include <serial3.h>

class AsyncSerial3 : public Serial3, public AsyncSerial
{
public:
    AsyncSerial3();
    virtual void begin(HW_UART baud) override;
    virtual void begin(HW_UART baud, bool setRxIrq = false, bool setEcho = false) override;
    virtual void registerCallback(ser_cb_t* cb = nullptr) override;
    virtual void registerCallback(SystemEventHandler* cb = nullptr) override;
};
extern AsyncSerial3 asyncSerial3;

#endif // ASYNCSERIAL3_H
