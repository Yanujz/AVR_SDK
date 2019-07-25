#ifndef SERIAL0_H
#define SERIAL0_H
#include <serial.h>

class Serial0 : public Serial {
public:
	Serial0(): Serial(){}
	virtual void begin(HW_UART baud) override;

};
extern Serial0 serial0;
#endif // SERIAL0_H
