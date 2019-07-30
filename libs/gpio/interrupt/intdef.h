#ifndef INTDEF_H
#define INTDEF_H
#include <macros.h>
#include <systemevent.h>
#include <avr/interrupt.h>
#include <core.h>

typedef void int_cb_t(u8t pin);

enum INT_EDGE: u8t{
	LOW_LEVEL,
	ANY_EDGE,
	FALLING,
	RISING
};


#endif // INTDEF_H
