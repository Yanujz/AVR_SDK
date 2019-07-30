#ifndef SERIAL2_H
#define SERIAL2_H
#include <serial.h>
#define __SERIAL2_SUPPORT__
#if defined(__AVR_ATmega48p__) ||  defined(__AVR_ATmega88P__) || defined(__AVR_ATmega328P__)
#undef __SERIAL2_SUPPORT__
#endif
#if defined(__SERIAL2_SUPPORT__)
class Serial2 : public virtual Serial {
public:
	Serial2();
	virtual void begin(HW_UART baud) override;

};
extern Serial2 serial2;
#endif // __SERIAL2_SUPPORT__
#endif // SERIAL2_H
