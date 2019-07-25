#ifndef ASYNCSERIAL0_H
#define ASYNCSERIAL0_H
#include <asyncserial.h>
#include <serial0.h>

class AsyncSerial0 : public Serial0, public AsyncSerial
{
public:
    AsyncSerial0();
				virtual void begin(HW_UART baud) override;
    virtual void begin(HW_UART baud, bool setRxIrq = false, bool setEcho = false) override;
    virtual void registerCallback(ser_cb_t* cb = nullptr) override;
    virtual void registerCallback(SystemEventHandler* cb = nullptr) override;
};
extern AsyncSerial0 asyncSerial0;
#endif // ASYNCSERIAL0_H

