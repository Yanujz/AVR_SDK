#pragma once
#include <serial.h>
#if defined(__SERIAL0_SUPPORT__)
class Serial0 : public virtual Serial {
public:
	Serial0();
	virtual void begin(HW_UART baud) override;

};
extern Serial0 serial0;
#endif // __SERIAL0_SUPPORT__
