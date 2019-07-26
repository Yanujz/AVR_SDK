#ifndef SERIAL2_H
#define SERIAL2_H
#include <serial.h>

class Serial2 : public virtual Serial {
public:
	Serial2();
	virtual void begin(HW_UART baud) override;

};
extern Serial2 serial2;
#endif // SERIAL2_H
