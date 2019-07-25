#ifndef SERIAL3_H
#define SERIAL3_H
#include <serial.h>

class Serial3 : public Serial {
public:
    Serial3(): Serial(){}
    virtual void begin(HW_UART baud) override;

};
extern Serial3 serial3;
#endif // SERIAL3_H
