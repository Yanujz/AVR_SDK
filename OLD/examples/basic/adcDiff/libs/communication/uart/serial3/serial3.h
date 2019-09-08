#pragma once
#include <serial.h>

#if defined(__SERIAL3_SUPPORT__)
class Serial3 : public virtual Serial {
public:
	Serial3();
	virtual void begin(HW_UART baud) override;
};
extern Serial3 serial3;
#endif //__SERIAL3_SUPPORT__


