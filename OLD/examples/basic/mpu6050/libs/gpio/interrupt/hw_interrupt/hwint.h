#ifndef HWINT_H
#define HWINT_H
#include <avr/pgmspace.h>
#include <intdef.h>


struct __HW_INT_ISR
{
	int_cb_t* user_cb_vect;
	SystemEventHandler* sys_cb_vect;
}__hw_event_isr[8];


class HwInt
{
public:

	static bool attachInterrupt(u8t pin, INT_EDGE edge, int_cb_t* func);
	static bool attachInterrupt(u8t pin, INT_EDGE edge, SystemEventHandler* func);
	static void deatchInterrupt(u8t pin);
private:
	static inline u8t _pinToInterrupt(u8t &pin);

};

#endif // HWINT_H
