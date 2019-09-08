#include <mega_system_clock.h>

//#ifdef __cplusplus
//extern "C" {
//#endif
volatile u32t timer0_overflow_count = 0;
volatile u32t timer0_millis = 0;
static u8t timer0_fract = 0;
void sys_clock_init()
{
    sei();

    TCCR0A |= setBitValue(1, WGMx1) | setBitValue(1, WGMx0);
    TCCR0B |= TIMERn_xBIT_PRESCALER_8;
    TIMSK0 |= setBitValue(1, TOIEx);
}


ISR(TIMER0_OVF_vect)
{
    // copy these to local variables so they can be stored in registers
    // (volatile variables must be read from memory on every access)
    unsigned long m = timer0_millis;
    unsigned char f = timer0_fract;
    m += MILLIS_INC;
    f += FRACT_INC;
    if (f >= FRACT_MAX) {
	f -= FRACT_MAX;
	m += 1;
    }
    timer0_fract = f;
    timer0_millis = m;
    timer0_overflow_count++;
}

unsigned long millis()
{
    unsigned long m;
    u8t oldSREG = SREG;

    // disable interrupts while we read timer0_millis or we might get an
    // inconsistent value (e.g. in the middle of a write to timer0_millis)
    cli();
    m = timer0_millis;
    SREG = oldSREG;

    return m;
}

unsigned long micros()
{
    unsigned long m;
    uint8_t oldSREG = SREG, t;

    cli();
    m = timer0_overflow_count;
#if defined(TCNT0)
    t = TCNT0;
#elif defined(TCNT0L)
    t = TCNT0L;
#else
#error TIMER 0 not defined
#endif

#ifdef TIFR0
    if ((TIFR0 & _BV(TOV0)) && (t < 255))
	m++;
#else
    if ((TIFR & _BV(TOV0)) && (t < 255))
	m++;
#endif
    SREG = oldSREG;

    return ((m << 8) + t)/2;//* (8 / clockCyclesPerMicrosecond());
}

//#ifdef __cplusplus
//}
//#endif
