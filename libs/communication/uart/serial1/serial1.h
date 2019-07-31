#pragma once
#include <serial.h>
#if defined(__SERIAL1_SUPPORT__)
class Serial1 : public virtual Serial {
public:
	Serial1();
	virtual void begin(HW_UART baud) override;

};
extern Serial1 serial1;
#endif //__SERIAL1_SUPPORT__
