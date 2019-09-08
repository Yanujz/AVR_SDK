#pragma once

#define PINx(x) (x << 0)
#define BIT(x) (x << 4)
#define PWM_GROUP(x) (x << 7)
#define TIMERx(x) (x << 8)
#define LETTERx(x) (x << 10)

#define TIMER_0 0x00
#define TIMER_1 0x01
#define TIMER_2 0x02
#define NO_TIMER 0x03

#define LETTER_A 0x00
#define LETTER_B 0x01

#define PWM8BIT 0
#define PWM16BIT 1

#define _PINB 0x03
#define _PINC 0x06
#define _PIND 0x09
#define NO_PINX 0xF
