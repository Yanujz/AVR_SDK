#pragma once
#include <core.h>

#if defined (__MEGA_SERIES__)

#include <avr/interrupt.h>
#include <pins.h>
//#define clockCyclesPerMicrosecond() (F_CPU / 1000000L)
constexpr unsigned long clockCyclesPerMicrosecond(){
    return F_CPU / 1000000L;
}
constexpr unsigned long clockCyclesToMicroseconds(int x){
    return  (x * 1000L) / (F_CPU / 1000L);
}
//#define clockCyclesToMicroseconds(x) ((x * 1000L) / (F_CPU / 1000L) )
// the prescaler is set so that timer0 ticks every 64 clock cycles, and the
// the overflow handler is called every 256 ticks.
#define MICROSECONDS_PER_TIMER0_OVERFLOW (clockCyclesToMicroseconds(8 * 256))
// the whole number of milliseconds per timer0 overflow
#define MILLIS_INC (MICROSECONDS_PER_TIMER0_OVERFLOW / 1000)
// the fractional number of milliseconds per timer0 overflow. we shift right
// by three to fit these numbers into a byte. (for the clock speeds we care
// about - 8 and 16 MHz - this doesn't lose precision.)
#define FRACT_INC ((MICROSECONDS_PER_TIMER0_OVERFLOW % 1000) >> 3)
#define FRACT_MAX (1000 >> 3)


unsigned long millis();
unsigned long micros();
void sys_clock_init();

#endif
