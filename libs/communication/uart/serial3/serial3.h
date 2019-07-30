#ifndef SERIAL3_H
#define SERIAL3_H
#include <serial.h>

#define __SERIAL3_SUPPORT__
#if defined(__AVR_ATmega48p__) ||  defined(__AVR_ATmega88P__) || defined(__AVR_ATmega328P__)
#undef __SERIAL3_SUPPORT__
#endif
#if defined(__SERIAL3_SUPPORT__)
class Serial3 : public virtual Serial {
public:
	Serial3();
	virtual void begin(HW_UART baud) override;
};
extern Serial3 serial3;
#endif

#endif // SERIAL3_H
