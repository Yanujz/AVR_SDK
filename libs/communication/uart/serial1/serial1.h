#ifndef SERIAL1_H
#define SERIAL1_H
#include <serial.h>
#define __SERIAL1_SUPPORT__
#if defined(__AVR_ATmega48p__) ||  defined(__AVR_ATmega88P__) || defined(__AVR_ATmega328P__)
#undef __SERIAL1_SUPPORT__
#endif
#if defined(__SERIAL1_SUPPORT__)
class Serial1 : public virtual Serial {
public:
	Serial1();
	virtual void begin(HW_UART baud) override;

};
extern Serial1 serial1;
#endif //__SERIAL1_SUPPORT__
#endif // SERIAL1_H
