#ifndef SERIAL1_H
#define SERIAL1_H
#include <serial.h>

class Serial1 : public Serial {
public:
    Serial1(): Serial(){}
    virtual void begin(HW_UART baud) override;

};
extern Serial1 serial1;
#endif // SERIAL1_H
