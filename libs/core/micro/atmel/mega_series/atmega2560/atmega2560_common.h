#pragma once
#include <macros.h>
#include <avr/io.h>

#if defined (__COMPILE__)
#else
#include <avr/iom2560.h>
#endif


constexpr u16t __hw_timer_addr[] = {0x24, 0x80, 0xB0, 0x90, 0xA0, 0x120};


enum class PIN_ADC : u8t {
	A0,
	A1,
	A2,
	A3,
	A4,
	A5,
	A6,
	A7,
	A8,
	A9,
	A10,
	A11,
	A12,
	A13,
	A14,
	A15
};
