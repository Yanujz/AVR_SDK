#pragma once

#define __SERIAL1_SUPPORT__
#define __SERIAL2_SUPPORT__
#define __SERIAL3_SUPPORT__


#define PINx(x) (x << 0)
#define OR100 (1 << 5)
#define LETTERx(x) (x << 6)
#define BIT(x) (x << 8)
#define PWM_GROUP(x) (x << 11)
#define TIMERx(x) (x << 12)

#define TIMER_0 0x00
#define TIMER_1 0x01
#define TIMER_2 0x02
#define TIMER_3 0x03
#define TIMER_4 0x04
#define TIMER_5 0x05
#define NO_TIMER 0x07

#define LETTER_A 0x00
#define LETTER_B 0x01
#define LETTER_C 0x02
#define NO_LETTER 0x03

#define PWM8BIT 0
#define PWM16BIT 1

#define _PINA 0x00
#define _PINB 0x03
#define _PINC 0x06
#define _PIND 0x09
#define _PINE 0x0C
#define _PINF 0x0F
#define _PING 0x12
#define _PINH (OR100 | 0x00)
#define _PINJ (OR100 | 0x03)
#define _PINK (OR100 | 0x06)
#define _PINL (OR100 | 0x09)
