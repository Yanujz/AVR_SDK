#ifndef SERIAL1_H
#define SERIAL1_H
#include <serial.h>

class Serial1 : public virtual Serial {
public:
    Serial1();
    virtual void begin(HW_UART baud) override;

};
extern Serial1 serial1;
#endif // SERIAL1_H
