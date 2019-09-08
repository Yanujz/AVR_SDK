#pragma once
#include <serial.h>

#if defined(__SERIAL2_SUPPORT__)
class Serial2 : public virtual Serial {
public:
	Serial2();
	virtual void begin(HW_UART baud) override;

};
extern Serial2 serial2;
#endif // __SERIAL2_SUPPORT__
