#pragma once
#include <mega_common.h>
#include <atmega2560_common.h>
#include <atmega2560_common_define.h>

/*
╔════╦════╦════╦════╦═══════════╦════╦═══╦═══╦════╦════╦═══════╦═══╦═══╦═══╦═══╦═══╗
║ 15 ║ 14 ║ 13 ║ 12 ║     11    ║ 10 ║ 9 ║ 8 ║  7 ║  6 ║   5   ║ 4 ║ 3 ║ 2 ║ 1 ║ 0 ║
╠════╬════╩════╩════╬═══════════╬════╩═══╩═══╬════╩════╬═══════╬═══╩═══╩═══╩═══╩═══╣
║    ║    TIMERx    ║ PWM GROUP ║   REG BIT  ║ LETTERx ║ OR100 ║        PINx       ║
╚════╩══════════════╩═══════════╩════════════╩═════════╩═══════╩═══════════════════╝
*/
enum class PIN : int
{
	IO_PA0 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD0) |  PINx(_PINA), //22		| AD0
	IO_PA1 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD1) |  PINx(_PINA), //23		| AD1
	IO_PA2 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD2) |  PINx(_PINA), //24		| AD2
	IO_PA3 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD3) |  PINx(_PINA), //25		| AD3
	IO_PA4 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD4) |  PINx(_PINA), //26		| AD4
	IO_PA5 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD5) |  PINx(_PINA), //27		| AD5
	IO_PA6 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD6) |  PINx(_PINA), //28		| AD6
	IO_PA7 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD7) |  PINx(_PINA), //29		| AD7

	IO_PB0 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD0) |  PINx(_PINB), //53	SS	| SS/PCINT0
	IO_PB1 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD1) |  PINx(_PINB), //52	SCK	| SCK/PCINT1
	IO_PB2 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD2) |  PINx(_PINB), //51	MOSI| MOSI/PCINT2
	IO_PB3 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD3) |  PINx(_PINB), //50	MISO| MISO/PCINT3
	IO_PB4 = LETTERx(LETTER_A)  | TIMERx(TIMER_2)  | PWM_GROUP(PWM8BIT)  | BIT(DD4) |  PINx(_PINB), //10		| OC2A/PCINT4
	IO_PB5 = LETTERx(LETTER_A)  | TIMERx(TIMER_1)  | PWM_GROUP(PWM16BIT) | BIT(DD5) |  PINx(_PINB), //11		| OC1A/PCINT5
	IO_PB6 = LETTERx(LETTER_B)  | TIMERx(TIMER_1)  | PWM_GROUP(PWM16BIT) | BIT(DD6) |  PINx(_PINB), //12		| OC1B/PCINT6
	IO_PB7 = LETTERx(LETTER_C)  | TIMERx(TIMER_1)  | PWM_GROUP(PWM16BIT) | BIT(DD7) |  PINx(_PINB), //13		| OC0A/OC1C/PCINT7

	IO_PC0 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD0) |  PINx(_PINC), //37		| A8
	IO_PC1 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD1) |  PINx(_PINC), //36		| A9
	IO_PC2 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD2) |  PINx(_PINC), //35		| A10
	IO_PC3 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD3) |  PINx(_PINC), //34		| A11
	IO_PC4 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD4) |  PINx(_PINC), //33		| A12
	IO_PC5 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD5) |  PINx(_PINC), //32		| A13
	IO_PC6 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD6) |  PINx(_PINC), //31		| A14
	IO_PC7 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD7) |  PINx(_PINC), //30		| A15

	IO_PD0 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD0) |  PINx(_PIND), //21	SCL	| SCL/INT0
	IO_PD1 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD1) |  PINx(_PIND), //20	SDA	| SDA/INT1
	IO_PD2 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD2) |  PINx(_PIND), //19	RX1	| RXD1/INT2
	IO_PD3 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD3) |  PINx(_PIND), //18	TX1	| TXD1/INT3
	/*
	IO_PD4
	IO_PD5
	IO_PD6
*/
	IO_PD7 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD7) |  PINx(_PIND), //38		| T0


	IO_PE0 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD0) |  PINx(_PINE), //0 RX0 - RXD0/PCINT8
	IO_PE1 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD1) |  PINx(_PINE), //1 TX0 - TXD0
	IO_PE3 = LETTERx(LETTER_A)  | TIMERx(TIMER_3)  | PWM_GROUP(PWM16BIT) | BIT(DD3) |  PINx(_PINE), //5			| OC3A/AIN1
	IO_PE4 = LETTERx(LETTER_B)  | TIMERx(TIMER_3)  | PWM_GROUP(PWM16BIT) | BIT(DD4) |  PINx(_PINE), //2 - 0C3B/INT4
	IO_PE5 = LETTERx(LETTER_C)  | TIMERx(TIMER_3)  | PWM_GROUP(PWM16BIT) | BIT(DD5) |  PINx(_PINE), //3	- OC3C/INT5

	IO_PF0 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD0) |  PINx(_PINF), //A00	54	| ADC0
	IO_PF1 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD1) |  PINx(_PINF), //A01	55	| ADC1
	IO_PF2 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD2) |  PINx(_PINF), //A02	56	| ADC2
	IO_PF3 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD3) |  PINx(_PINF), //A03	57	| ADC3
	IO_PF4 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD4) |  PINx(_PINF), //A04	58	| ADC4/TMK
	IO_PF5 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD5) |  PINx(_PINF), //A05	59	| ADC5/TMS
	IO_PF6 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD6) |  PINx(_PINF), //A06	60	| ADC6
	IO_PF7 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD7) |  PINx(_PINF), //A07	61	| ADC7

	IO_PG0 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD0) |  PINx(_PING), //41		| WR
	IO_PG1 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD1) |  PINx(_PING), //40		| RD
	IO_PG2 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD2) |  PINx(_PING), //39		| ALE
	IO_PG5 = LETTERx(LETTER_B)  | TIMERx(TIMER_0)  | PWM_GROUP(PWM8BIT)  | BIT(DD5) |  PINx(_PING), //4			| OC0B

	IO_PH0 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD0) |  PINx(_PINH), //17	RX2	| RXD2
	IO_PH1 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD1) |  PINx(_PINH), //16	TX2	| TXD2
	IO_PH3 = LETTERx(LETTER_A)  | TIMERx(TIMER_4)  | PWM_GROUP(PWM16BIT) | BIT(DD3) |  PINx(_PINH), //6			| OC4A
	IO_PH4 = LETTERx(LETTER_B)  | TIMERx(TIMER_4)  | PWM_GROUP(PWM16BIT) | BIT(DD4) |  PINx(_PINH), //7			| OC4B
	IO_PH5 = LETTERx(LETTER_C)  | TIMERx(TIMER_4)  | PWM_GROUP(PWM16BIT) | BIT(DD5) |  PINx(_PINH), //8			| OC4C
	IO_PH6 = LETTERx(LETTER_B)  | TIMERx(TIMER_2)  | PWM_GROUP(PWM8BIT)  | BIT(DD6) |  PINx(_PINH), //9			| OC2B

	IO_PJ0 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD0) |  PINx(_PINJ), //15	RX3	| RXD3/PCINT9
	IO_PJ1 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD1) |  PINx(_PINJ), //14	TX3	| TXD3/PCINT10

	IO_PK0 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD0) |  PINx(_PINK), //A08	62	| ADC8/PCINT16
	IO_PK1 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD1) |  PINx(_PINK), //A09	63	| ADC9/PCINT17
	IO_PK2 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD2) |  PINx(_PINK), //A10	64	| ADC10/PCINT18
	IO_PK3 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD3) |  PINx(_PINK), //A11	65	| ADC11/PCINT19
	IO_PK4 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD4) |  PINx(_PINK), //A12	66	| ADC12/PCINT20
	IO_PK5 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD5) |  PINx(_PINK), //A13	67	| ADC13/PCINT21
	IO_PK6 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD6) |  PINx(_PINK), //A14	68	| ADC14/PCINT22
	IO_PK7 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD7) |  PINx(_PINK), //A15	69	| ADC15/PCINT23

	IO_PL0 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD0) |  PINx(_PINL), //49		| ICP4
	IO_PL1 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD1) |  PINx(_PINL), //48		| ICP5
	IO_PL2 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD2) |  PINx(_PINL), //47		| T5
	IO_PL3 = LETTERx(LETTER_A)  | TIMERx(TIMER_5)  | PWM_GROUP(PWM16BIT) | BIT(DD3) |  PINx(_PINL), //46		| OC5A
	IO_PL4 = LETTERx(LETTER_B)  | TIMERx(TIMER_5)  | PWM_GROUP(PWM16BIT) | BIT(DD4) |  PINx(_PINL), //45		| OC5B
	IO_PL5 = LETTERx(LETTER_C)  | TIMERx(TIMER_5)  | PWM_GROUP(PWM16BIT) | BIT(DD5) |  PINx(_PINL), //44		| OC5C
	IO_PL6 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD6) |  PINx(_PINL), //43		|
	IO_PL7 = LETTERx(NO_LETTER) | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD7) |  PINx(_PINL), //42		|
};
enum PWM {
    IO_PB4 = LETTERx(LETTER_A)  | TIMERx(TIMER_2)  | PWM_GROUP(PWM8BIT)  | BIT(DD4) |  PINx(_PINB), //10		| OC2A/PCINT4
    IO_PB5 = LETTERx(LETTER_A)  | TIMERx(TIMER_1)  | PWM_GROUP(PWM16BIT) | BIT(DD5) |  PINx(_PINB), //11		| OC1A/PCINT5
    IO_PB6 = LETTERx(LETTER_B)  | TIMERx(TIMER_1)  | PWM_GROUP(PWM16BIT) | BIT(DD6) |  PINx(_PINB), //12		| OC1B/PCINT6
    IO_PB7 = LETTERx(LETTER_C)  | TIMERx(TIMER_1)  | PWM_GROUP(PWM16BIT) | BIT(DD7) |  PINx(_PINB), //13		| OC0A/OC1C/PCINT7

    IO_PG5 = LETTERx(LETTER_B)  | TIMERx(TIMER_0)  | PWM_GROUP(PWM8BIT)  | BIT(DD5) |  PINx(_PING), //4			| OC0B

    IO_PE3 = LETTERx(LETTER_A)  | TIMERx(TIMER_3)  | PWM_GROUP(PWM16BIT) | BIT(DD3) |  PINx(_PINE), //5			| OC3A/AIN1
    IO_PE4 = LETTERx(LETTER_B)  | TIMERx(TIMER_3)  | PWM_GROUP(PWM16BIT) | BIT(DD4) |  PINx(_PINE), //2 - 0C3B/INT4
    IO_PE5 = LETTERx(LETTER_C)  | TIMERx(TIMER_3)  | PWM_GROUP(PWM16BIT) | BIT(DD5) |  PINx(_PINE), //3	- OC3C/INT5

    IO_PH3 = LETTERx(LETTER_A)  | TIMERx(TIMER_4)  | PWM_GROUP(PWM16BIT) | BIT(DD3) |  PINx(_PINH), //6			| OC4A
    IO_PH4 = LETTERx(LETTER_B)  | TIMERx(TIMER_4)  | PWM_GROUP(PWM16BIT) | BIT(DD4) |  PINx(_PINH), //7			| OC4B
    IO_PH5 = LETTERx(LETTER_C)  | TIMERx(TIMER_4)  | PWM_GROUP(PWM16BIT) | BIT(DD5) |  PINx(_PINH), //8			| OC4C
    IO_PH6 = LETTERx(LETTER_B)  | TIMERx(TIMER_2)  | PWM_GROUP(PWM8BIT)  | BIT(DD6) |  PINx(_PINH), //9			| OC2B

    IO_PL3 = LETTERx(LETTER_A)  | TIMERx(TIMER_5)  | PWM_GROUP(PWM16BIT) | BIT(DD3) |  PINx(_PINL), //46		| OC5A
    IO_PL4 = LETTERx(LETTER_B)  | TIMERx(TIMER_5)  | PWM_GROUP(PWM16BIT) | BIT(DD4) |  PINx(_PINL), //45		| OC5B
    IO_PL5 = LETTERx(LETTER_C)  | TIMERx(TIMER_5)  | PWM_GROUP(PWM16BIT) | BIT(DD5) |  PINx(_PINL), //44		| OC5C
};

#define SPI0_DEFAULT_SS PIN::IO_PB0
#define SPI0_DEFAULT_SCK PIN::IO_PB1
#define SPI0_DEFAULT_MOSI PIN::IO_PB2
#define SPI0_DEFAULT_MISO PIN::IO_PB3


//constexpr u16t __hw_timer_addr[] = {0x24, 0x80, 0xB0, 0x90, 0xA0, 0x120};
//TODO convert to u16t and put correct IO
constexpr u8t PROGMEM __hw_int_mappedPin[8] = {21, 20, 19, 18, 2, 3, 255, 255};