#pragma once
#include <macros.h>
#include <avr/io.h>
#if defined(__COMPILE__)
#else
#include <avr/iom328p.h>
#endif


const static u16t __hw_timer_addr[] = {0x24, 0x80, 0xB0};


enum class PIN_ADC : u8t {
	A0,
	A1,
	A2,
	A3,
	A4,
	A5
};
