#pragma once
//#ifdef __cplusplus
//extern "C" {
//#endif

#include <gpiodef.h>

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


//#define pinToPinx(x) (pgm_read_word(&__flashMappedPort[x]) & OR100 ? &_SFR_MEM8(0x100 | pgm_read_word(&__flashMappedPort[x]) & 0x1F) :  &_SFR_IO8(pgm_read_word(&__flashMappedPort[x]) & 0x1F))

#define varToPinx(x) (toU16(x) & OR100 ? &_SFR_MEM8(0x100 | (toU16(x) & 0x1F)) :  &_SFR_IO8(toU16(x) & 0x1F))
#define varToLetter(x) (((toU16(x) >> 6) & 0x03))
#define varToRegBit(x) ((toU16(x) >> 8) & 0x07)
#define varToPWMGroup(x) ((toU16(x) >> 11) & 0x01)
#define varToTimer(x) (((toU16(x) >> 12) & 0x07))


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

/*
╔════╦════╦════╦════╦═══════════╦════╦═══╦═══╦════╦════╦═══════╦═══╦═══╦═══╦═══╦═══╗
║ 15 ║ 14 ║ 13 ║ 12 ║     11    ║ 10 ║ 9 ║ 8 ║  7 ║  6 ║   5   ║ 4 ║ 3 ║ 2 ║ 1 ║ 0 ║
╠════╬════╩════╩════╬═══════════╬════╩═══╩═══╬════╩════╬═══════╬═══╩═══╩═══╩═══╩═══╣
║    ║    TIMERx    ║ PWM GROUP ║   REG BIT  ║ LETTERx ║ OR100 ║        PINx       ║
╚════╩══════════════╩═══════════╩════════════╩═════════╩═══════╩═══════════════════╝
*/
enum class PIN :  int {
	IO0  = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD0) |  PINx(_PINE), //0 RX0 - RXD0/PCINT8
	IO1  = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD1) |  PINx(_PINE), //1 TX0 - TXD0
	IO2  = LETTERx(LETTER_B)  | TIMERx(TIMER_3)  | PWM_GROUP(PWM16BIT) | BIT(DD4) |  PINx(_PINE), //2 - 0C3B/INT4
	IO3  = LETTERx(LETTER_C)  | TIMERx(TIMER_3)  | PWM_GROUP(PWM16BIT) | BIT(DD5) |  PINx(_PINE), //3	- OC3C/INT5
	IO4  = LETTERx(LETTER_B)  | TIMERx(TIMER_0)  | PWM_GROUP(PWM8BIT)  | BIT(DD5) |  PINx(_PING), //4			| OC0B
	IO5  = LETTERx(LETTER_A)  | TIMERx(TIMER_3)  | PWM_GROUP(PWM16BIT) | BIT(DD3) |  PINx(_PINE), //5			| OC3A/AIN1
	IO6  = LETTERx(LETTER_A)  | TIMERx(TIMER_4)  | PWM_GROUP(PWM16BIT) | BIT(DD3) |  PINx(_PINH), //6			| OC4A
	IO7  = LETTERx(LETTER_B)  | TIMERx(TIMER_4)  | PWM_GROUP(PWM16BIT) | BIT(DD4) |  PINx(_PINH), //7			| OC4B
	IO8  = LETTERx(LETTER_C)  | TIMERx(TIMER_4)  | PWM_GROUP(PWM16BIT) | BIT(DD5) |  PINx(_PINH), //8			| OC4C
	IO9  = LETTERx(LETTER_B)  | TIMERx(TIMER_2)  | PWM_GROUP(PWM8BIT)  | BIT(DD6) |  PINx(_PINH), //9			| OC2B
	IO10 = LETTERx(LETTER_A)  | TIMERx(TIMER_2)  | PWM_GROUP(PWM8BIT)  | BIT(DD4) |  PINx(_PINB), //10		| OC2A/PCINT4
	IO11 = LETTERx(LETTER_A)  | TIMERx(TIMER_1)  | PWM_GROUP(PWM16BIT) | BIT(DD5) |  PINx(_PINB), //11		| OC1A/PCINT5
	IO12 = LETTERx(LETTER_B)  | TIMERx(TIMER_1)  | PWM_GROUP(PWM16BIT) | BIT(DD6) |  PINx(_PINB), //12		| OC1B/PCINT6
	IO13 = LETTERx(LETTER_C)  | TIMERx(TIMER_1)  | PWM_GROUP(PWM16BIT) | BIT(DD7) |  PINx(_PINB), //13		| OC0A/OC1C/PCINT7
	IO14 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD1) |  PINx(_PINJ), //14	TX3	| TXD3/PCINT10
	IO15 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD0) |  PINx(_PINJ), //15	RX3	| RXD3/PCINT9
	IO16 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD1) |  PINx(_PINH), //16	TX2	| TXD2
	IO17 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD0) |  PINx(_PINH), //17	RX2	| RXD2
	IO18 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD3) |  PINx(_PIND), //18	TX1	| TXD1/INT3
	IO19 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD2) |  PINx(_PIND), //19	RX1	| RXD1/INT2
	IO20 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD1) |  PINx(_PIND), //20	SDA	| SDA/INT1
	IO21 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD0) |  PINx(_PIND), //21	SCL	| SCL/INT0
	IO22 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD0) |  PINx(_PINA), //22		| AD0
	IO23 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD1) |  PINx(_PINA), //23		| AD1
	IO24 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD2) |  PINx(_PINA), //24		| AD2
	IO25 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD3) |  PINx(_PINA), //25		| AD3
	IO26 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD4) |  PINx(_PINA), //26		| AD4
	IO27 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD5) |  PINx(_PINA), //27		| AD5
	IO28 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD6) |  PINx(_PINA), //28		| AD6
	IO29 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD7) |  PINx(_PINA), //29		| AD7
	IO30 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD7) |  PINx(_PINC), //30		| A15
	IO31 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD6) |  PINx(_PINC), //31		| A14
	IO32 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD5) |  PINx(_PINC), //32		| A13
	IO33 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD4) |  PINx(_PINC), //33		| A12
	IO34 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD3) |  PINx(_PINC), //34		| A11
	IO35 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD2) |  PINx(_PINC), //35		| A10
	IO36 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD1) |  PINx(_PINC), //36		| A9
	IO37 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD0) |  PINx(_PINC), //37		| A8
	IO38 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD7) |  PINx(_PIND), //38		| T0
	IO39 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD2) |  PINx(_PING), //39		| ALE
	IO40 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD1) |  PINx(_PING), //40		| RD
	IO41 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD0) |  PINx(_PING), //41		| WR
	IO42 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD7) |  PINx(_PINL), //42		|
	IO43 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD6) |  PINx(_PINL), //43		|
	IO44 = LETTERx(LETTER_C)  | TIMERx(TIMER_5)  | PWM_GROUP(PWM16BIT) | BIT(DD5) |  PINx(_PINL), //44		| OC5C
	IO45 = LETTERx(LETTER_B)  | TIMERx(TIMER_5)  | PWM_GROUP(PWM16BIT) | BIT(DD4) |  PINx(_PINL), //45		| OC5B
	IO46 = LETTERx(LETTER_A)  | TIMERx(TIMER_5)  | PWM_GROUP(PWM16BIT) | BIT(DD3) |  PINx(_PINL), //46		| OC5A
	IO47 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD2) |  PINx(_PINL), //47		| T5
	IO48 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD1) |  PINx(_PINL), //48		| ICP5
	IO49 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD0) |  PINx(_PINL), //49		| ICP4
	IO50 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD3) |  PINx(_PINB), //50	MISO| MISO/PCINT3
	IO51 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD2) |  PINx(_PINB), //51	MOSI| MOSI/PCINT2
	IO52 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD1) |  PINx(_PINB), //52	SCK	| SCK/PCINT1
	IO53 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD0) |  PINx(_PINB), //53	SS	| SS/PCINT0

	A0   = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD0) |  PINx(_PINF), //A00	54	| ADC0
	A1   = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD1) |  PINx(_PINF), //A01	55	| ADC1
	A2   = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD2) |  PINx(_PINF), //A02	56	| ADC2
	A3   = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD3) |  PINx(_PINF), //A03	57	| ADC3
	A4   = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD4) |  PINx(_PINF), //A04	58	| ADC4/TMK
	A5   = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD5) |  PINx(_PINF), //A05	59	| ADC5/TMS
	A6   = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD6) |  PINx(_PINF), //A06	60	| ADC6
	A7   = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD7) |  PINx(_PINF), //A07	61	| ADC7
	A8   = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD0) |  PINx(_PINK), //A08	62	| ADC8/PCINT16
	A9   = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD1) |  PINx(_PINK), //A09	63	| ADC9/PCINT17
	A10  = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD2) |  PINx(_PINK), //A10	64	| ADC10/PCINT18
	A11  = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD3) |  PINx(_PINK), //A11	65	| ADC11/PCINT19
	A12  = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD4) |  PINx(_PINK), //A12	66	| ADC12/PCINT20
	A13  = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD5) |  PINx(_PINK), //A13	67	| ADC13/PCINT21
	A14  = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD6) |  PINx(_PINK), //A14	68	| ADC14/PCINT22
	A15  = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD7) |  PINx(_PINK) //A15	69	| ADC15/PCINT23
};

//extern const u16t __flashMappedPort[] PROGMEM;


constexpr u16t __hw_timer_addr[] = {0x24, 0x80, 0xB0, 0x90, 0xA0, 0x120};
constexpr u8t PROGMEM __hw_int_mappedPin[8] = {21, 20, 19, 18, 2, 3, 255, 255};
/*
constexpr pin_setting _mappedPort[] {
	{&PINE, _BV(DD0), nullptr, 0, NO_LETTER}, //0 RX0 - RXD0/PCINT8
	{&PINE, _BV(DD1), nullptr, 0, NO_LETTER}, //1 TX0 - TXD0
	{&PINE, _BV(DD4), &TCCR3A, PWM16BIT, LETTER_B}, //2 - 0C3B/INT4
	{&PINE, _BV(DD5), &TCCR3A, PWM16BIT, LETTER_C}, //3	- OC3C/INT5
	{&PING, _BV(DD5), nullptr, 0, NO_LETTER}, //4			| OC0B
	{&PINE, _BV(DD3), &TCCR3A, PWM16BIT, LETTER_A}, //5			| OC3A/AIN1
	{&PINH, _BV(DD3), &TCCR4A, PWM16BIT, LETTER_A}, //6			| OC4A
	{&PINH, _BV(DD4), &TCCR4A, PWM16BIT, LETTER_B}, //7			| OC4B
	{&PINH, _BV(DD5), &TCCR4A, PWM16BIT, LETTER_C}, //8			| OC4C
	{&PINH, _BV(DD6), &TCCR2A, PWM8BIT,  LETTER_B}, //9			| OC2B
	{&PINB, _BV(DD4), &TCCR2A, PWM8BIT,  LETTER_A}, //10		| OC2A/PCINT4
	{&PINB, _BV(DD5), &TCCR1A, PWM16BIT, LETTER_A}, //11		| OC1A/PCINT5
	{&PINB, _BV(DD6), &TCCR1A, PWM16BIT, LETTER_B}, //12		| OC1B/PCINT6
	{&PINB, _BV(DD7), &TCCR1A, PWM16BIT, LETTER_C}, //13		| OC0A/OC1C/PCINT7
	{&PINJ, _BV(DD1), nullptr, 0, NO_LETTER}, //14	TX3	| TXD3/PCINT10
	{&PINJ, _BV(DD0), nullptr, 0, NO_LETTER}, //15	RX3	| RXD3/PCINT9
	{&PINH, _BV(DD1), nullptr, 0, NO_LETTER}, //16	TX2	| TXD2
	{&PINH, _BV(DD0), nullptr, 0, NO_LETTER}, //17	RX2	| RXD2
	{&PIND, _BV(DD3), nullptr, 0, NO_LETTER}, //18	TX1	| TXD1/INT3
	{&PIND, _BV(DD2), nullptr, 0, NO_LETTER}, //19	RX1	| RXD1/INT2
	{&PIND, _BV(DD1), nullptr, 0, NO_LETTER}, //20	SDA	| SDA/INT1
	{&PIND, _BV(DD0), nullptr, 0, NO_LETTER}, //21	SCL	| SCL/INT0
	{&PINA, _BV(DD0), nullptr, 0, NO_LETTER}, //22		| AD0
	{&PINA, _BV(DD1), nullptr, 0, NO_LETTER}, //23		| AD1
	{&PINA, _BV(DD2), nullptr, 0, NO_LETTER}, //24		| AD2
	{&PINA, _BV(DD3), nullptr, 0, NO_LETTER}, //25		| AD3
	{&PINA, _BV(DD4), nullptr, 0, NO_LETTER}, //26		| AD4
	{&PINA, _BV(DD5), nullptr, 0, NO_LETTER}, //27		| AD5
	{&PINA, _BV(DD6), nullptr, 0, NO_LETTER}, //28		| AD6
	{&PINA, _BV(DD7), nullptr, 0, NO_LETTER}, //29		| AD7
	{&PINC, _BV(DD7), nullptr, 0, NO_LETTER}, //30		| A15
	{&PINC, _BV(DD6), nullptr, 0, NO_LETTER}, //31		| A14
	{&PINC, _BV(DD5), nullptr, 0, NO_LETTER}, //32		| A13
	{&PINC, _BV(DD4), nullptr, 0, NO_LETTER}, //33		| A12
	{&PINC, _BV(DD3), nullptr, 0, NO_LETTER}, //34		| A11
	{&PINC, _BV(DD2), nullptr, 0, NO_LETTER}, //35		| A10
	{&PINC, _BV(DD1), nullptr, 0, NO_LETTER}, //36		| A9
	{&PINC, _BV(DD0), nullptr, 0, NO_LETTER}, //37		| A8
	{&PIND, _BV(DD7), nullptr, 0, NO_LETTER}, //38		| T0
	{&PING, _BV(DD2), nullptr, 0, NO_LETTER}, //39		| ALE
	{&PING, _BV(DD1), nullptr, 0, NO_LETTER}, //40		| RD
	{&PING, _BV(DD0), nullptr, 0, NO_LETTER}, //41		| WR
	{&PINL, _BV(DD7), nullptr, 0, NO_LETTER}, //42		|
	{&PINL, _BV(DD6), nullptr, 0, NO_LETTER}, //43		|
	{&PINL, _BV(DD5), &TCCR5A, PWM16BIT, LETTER_C}, //44		| OC5C
	{&PINL, _BV(DD4), &TCCR5A, PWM16BIT, LETTER_B}, //45		| OC5B
	{&PINL, _BV(DD3), &TCCR5A, PWM16BIT, LETTER_A}, //46		| OC5A
	{&PINL, _BV(DD2), nullptr, 0, NO_LETTER}, //47		| T5
	{&PINL, _BV(DD1), nullptr, 0, NO_LETTER}, //48		| ICP5
	{&PINL, _BV(DD0), nullptr, 0, NO_LETTER}, //49		| ICP4
	{&PINB, _BV(DD3), nullptr, 0, NO_LETTER}, //50	MISO| MISO/PCINT3
	{&PINB, _BV(DD2), nullptr, 0, NO_LETTER}, //51	MOSI| MOSI/PCINT2
	{&PINB, _BV(DD1), nullptr, 0, NO_LETTER}, //52	SCK	| SCK/PCINT1
	{&PINB, _BV(DD0), nullptr, 0, NO_LETTER}, //53	SS	| SS/PCINT0

	{&PINF, _BV(DD0), nullptr, 0, NO_LETTER}, //A00	54	| ADC0
	{&PINF, _BV(DD1), nullptr, 0, NO_LETTER}, //A01	55	| ADC1
	{&PINF, _BV(DD2), nullptr, 0, NO_LETTER}, //A02	56	| ADC2
	{&PINF, _BV(DD3), nullptr, 0, NO_LETTER}, //A03	57	| ADC3
	{&PINF, _BV(DD4), nullptr, 0, NO_LETTER}, //A04	58	| ADC4/TMK
	{&PINF, _BV(DD5), nullptr, 0, NO_LETTER}, //A05	59	| ADC5/TMS
	{&PINF, _BV(DD6), nullptr, 0, NO_LETTER}, //A06	60	| ADC6
	{&PINF, _BV(DD7), nullptr, 0, NO_LETTER}, //A07	61	| ADC7
	{&PINK, _BV(DD0), nullptr, 0, NO_LETTER}, //A08	62	| ADC8/PCINT16
	{&PINK, _BV(DD1), nullptr, 0, NO_LETTER}, //A09	63	| ADC9/PCINT17
	{&PINK, _BV(DD2), nullptr, 0, NO_LETTER}, //A10	64	| ADC10/PCINT18
	{&PINK, _BV(DD3), nullptr, 0, NO_LETTER}, //A11	65	| ADC11/PCINT19
	{&PINK, _BV(DD4), nullptr, 0, NO_LETTER}, //A12	66	| ADC12/PCINT20
	{&PINK, _BV(DD5), nullptr, 0, NO_LETTER}, //A13	67	| ADC13/PCINT21
	{&PINK, _BV(DD6), nullptr, 0, NO_LETTER}, //A14	68	| ADC14/PCINT22
	{&PINK, _BV(DD7), nullptr, 0, NO_LETTER}	//A15	69	| ADC15/PCINT23
};
*/

/*
constexpr pwm_settings _mappedPwmPort[] {
	{&TCCR1A, PWM16BIT, LETTER_C}
};*/



//#ifdef __cplusplus
//}
//#endif

