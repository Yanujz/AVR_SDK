#pragma once
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <macros.h>
#include <atmega2560_common_define.h>



/*
╔════╦════╦════╦════╦════╦════╦═══╦═══╦═══╦═══════╦═══╦═══╦═══╦═══╦═══╦═══╗
║ 15 ║ 14 ║ 13 ║ 12 ║ 11 ║ 10 ║ 9 ║ 8 ║ 7 ║   6   ║ 5 ║ 4 ║ 3 ║ 2 ║ 1 ║ 0 ║
╠════╩════╩════╩════╩════╩════╩═══╩═══╬═══╬═══════╬═══╩═══╩═══╩═══╩═══╩═══╣
║            REG BIT VALUE            ║   ║ OR100 ║          PINx         ║
╚═════════════════════════════════════╩═══╩═══════╩═══════════════════════╝
*/

enum class PIN : u16t
{
    IO0  = toWord(bitValue(DD0),  REG_PINE), //0 RX0 - RXD0/PCINT8
    IO1  = toWord(bitValue(DD1),  REG_PINE), //1 TX0 - TXD0
    IO2  = toWord(bitValue(DD4),  REG_PINE), //2 - 0C3B/INT4
    IO3  = toWord(bitValue(DD5),  REG_PINE), //3	- OC3C/INT5
    IO4  = toWord(bitValue(DD5),  REG_PING), //4			| OC0B
    IO5  = toWord(bitValue(DD3),  REG_PINE), //5			| OC3A/AIN1
    IO6  = toWord(bitValue(DD3),  REG_PINH), //6			| OC4A
    IO7  = toWord(bitValue(DD4),  REG_PINH), //7			| OC4B
    IO8  = toWord(bitValue(DD5),  REG_PINH), //8			| OC4C
    IO9  = toWord(bitValue(DD6),  REG_PINH), //9			| OC2B
    IO10 = toWord(bitValue(DD4),  REG_PINB), //10		| OC2A/PCINT4
    IO11 = toWord(bitValue(DD5),  REG_PINB), //11		| OC1A/PCINT5
    IO12 = toWord(bitValue(DD6),  REG_PINB), //12		| OC1B/PCINT6
    IO13 = toWord(bitValue(DD7),  REG_PINB), //13		| OC0A/OC1C/PCINT7
    IO14 = toWord(bitValue(DD1),  REG_PINJ), //14	TX3	| TXD3/PCINT10
    IO15 = toWord(bitValue(DD0),  REG_PINJ), //15	RX3	| RXD3/PCINT9
    IO16 = toWord(bitValue(DD1),  REG_PINH), //16	TX2	| TXD2
    IO17 = toWord(bitValue(DD0),  REG_PINH), //17	RX2	| RXD2
    IO18 = toWord(bitValue(DD3),  REG_PIND), //18	TX1	| TXD1/INT3
    IO19 = toWord(bitValue(DD2),  REG_PIND), //19	RX1	| RXD1/INT2
    IO20 = toWord(bitValue(DD1),  REG_PIND), //20	SDA	| SDA/INT1
    IO21 = toWord(bitValue(DD0),  REG_PIND), //21	SCL	| SCL/INT0
    IO22 = toWord(bitValue(DD0),  REG_PINA), //22		| AD0
    IO23 = toWord(bitValue(DD1),  REG_PINA), //23		| AD1
    IO24 = toWord(bitValue(DD2),  REG_PINA), //24		| AD2
    IO25 = toWord(bitValue(DD3),  REG_PINA), //25		| AD3
    IO26 = toWord(bitValue(DD4),  REG_PINA), //26		| AD4
    IO27 = toWord(bitValue(DD5),  REG_PINA), //27		| AD5
    IO28 = toWord(bitValue(DD6),  REG_PINA), //28		| AD6
    IO29 = toWord(bitValue(DD7),  REG_PINA), //29		| AD7
    IO30 = toWord(bitValue(DD7),  REG_PINC), //30		| A15
    IO31 = toWord(bitValue(DD6),  REG_PINC), //31		| A14
    IO32 = toWord(bitValue(DD5),  REG_PINC), //32		| A13
    IO33 = toWord(bitValue(DD4),  REG_PINC), //33		| A12
    IO34 = toWord(bitValue(DD3),  REG_PINC), //34		| A11
    IO35 = toWord(bitValue(DD2),  REG_PINC), //35		| A10
    IO36 = toWord(bitValue(DD1),  REG_PINC), //36		| A9
    IO37 = toWord(bitValue(DD0),  REG_PINC), //37		| A8
    IO38 = toWord(bitValue(DD7),  REG_PIND), //38		| T0
    IO39 = toWord(bitValue(DD2),  REG_PING), //39		| ALE
    IO40 = toWord(bitValue(DD1),  REG_PING), //40		| RD
    IO41 = toWord(bitValue(DD0),  REG_PING), //41		| WR
    IO42 = toWord(bitValue(DD7),  REG_PINL), //42		|
    IO43 = toWord(bitValue(DD6),  REG_PINL), //43		|
    IO44 = toWord(bitValue(DD5),  REG_PINL), //44		| OC5C
    IO45 = toWord(bitValue(DD4),  REG_PINL), //45		| OC5B
    IO46 = toWord(bitValue(DD3),  REG_PINL), //46		| OC5A
    IO47 = toWord(bitValue(DD2),  REG_PINL), //47		| T5
    IO48 = toWord(bitValue(DD1),  REG_PINL), //48		| ICP5
    IO49 = toWord(bitValue(DD0),  REG_PINL), //49		| ICP4
    IO50 = toWord(bitValue(DD3),  REG_PINB), //50	MISO| MISO/PCINT3
    IO51 = toWord(bitValue(DD2),  REG_PINB), //51	MOSI| MOSI/PCINT2
    IO52 = toWord(bitValue(DD1),  REG_PINB), //52	SCK	| SCK/PCINT1
    IO53 = toWord(bitValue(DD0),  REG_PINB), //53	SS	| SS/PCINT0

    A0   = toWord(bitValue(DD0), REG_PINF), //A00	54	| ADC0
    A1   = toWord(bitValue(DD1), REG_PINF), //A01	55	| ADC1
    A2   = toWord(bitValue(DD2), REG_PINF), //A02	56	| ADC2
    A3   = toWord(bitValue(DD3), REG_PINF), //A03	57	| ADC3
    A4   = toWord(bitValue(DD4), REG_PINF), //A04	58	| ADC4/TMK
    A5   = toWord(bitValue(DD5), REG_PINF), //A05	59	| ADC5/TMS
    A6   = toWord(bitValue(DD6), REG_PINF), //A06	60	| ADC6
    A7   = toWord(bitValue(DD7), REG_PINF), //A07	61	| ADC7
    A8   = toWord(bitValue(DD0), REG_PINK), //A08	62	| ADC8/PCINT16
    A9   = toWord(bitValue(DD1), REG_PINK), //A09	63	| ADC9/PCINT17
    A10  = toWord(bitValue(DD2), REG_PINK), //A10	64	| ADC10/PCINT18
    A11  = toWord(bitValue(DD3), REG_PINK), //A11	65	| ADC11/PCINT19
    A12  = toWord(bitValue(DD4), REG_PINK), //A12	66	| ADC12/PCINT20
    A13  = toWord(bitValue(DD5), REG_PINK), //A13	67	| ADC13/PCINT21
    A14  = toWord(bitValue(DD6), REG_PINK), //A14	68	| ADC14/PCINT22
    A15  = toWord(bitValue(DD7), REG_PINK) //A15	69	| ADC15/PCINT23
};
#define SPI0_DEFAULT_MISO PIN::IO50
#define SPI0_DEFAULT_MOSI PIN::IO51
#define SPI0_DEFAULT_SCK PIN::IO52
#define SPI0_DEFAULT_SS PIN::IO53




/*
╔════╦════╦════╦════╦════╦════╦═══╦═══════╦═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╗
║ 15 ║ 14 ║ 13 ║ 12 ║ 11 ║ 10 ║ 9 ║ 8     ║ 7 ║ 6 ║ 5 ║ 4 ║ 3 ║ 2 ║ 1 ║ 0 ║
╠════╩════╩════╩════╬════╩════╩═══╬═══════╬═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╣
║  SUM TO GET OCRnX ║ SHIFT 3 BY  ║ OR100 ║             TCCRxA            ║
╚═══════════════════╩═════════════╩═══════╩═══════════════════════════════╝
*/
#define TIMER0_ADDR 0x24 + __SFR_OFFSET
#define TIMER1_ADDR 0x80
#define TIMER2_ADDR 0xB0
#define TIMER3_ADDR 0x90
#define TIMER4_ADDR 0xA0
#define TIMER5_ADDR 0x120

#define NO_OR100 (0 << 0)
#define YES_OR100 (1 << 0)
#define SHIFT_MODE_SET_C (2 << 9)
#define SHIFT_MODE_SET_B (4 << 9)
#define SHIFT_MODE_SET_A (6 << 9)

#define PWM_8_BIT_OCRxA_OFFSET (3 << 12)
#define PWM_8_BIT_OCRxB_OFFSET (4 << 12)

#define PWM_16_BIT_OCRxA_OFFSET (8 << 12)
#define PWM_16_BIT_OCRxB_OFFSET (10 << 12)
#define PWM_16_BIT_OCRxC_OFFSET (12 << 12)


enum class PWM8 : int
{
    IO4	 = (PWM_8_BIT_OCRxB_OFFSET | SHIFT_MODE_SET_B | TIMER0_ADDR),
    IO9	 = (PWM_8_BIT_OCRxB_OFFSET | SHIFT_MODE_SET_B | TIMER2_ADDR),
    IO10 = (PWM_8_BIT_OCRxA_OFFSET | SHIFT_MODE_SET_A | TIMER2_ADDR)
};
enum class PWM16 : int
{
    IO2  = (PWM_16_BIT_OCRxB_OFFSET | SHIFT_MODE_SET_B | TIMER3_ADDR),
    IO3  = (PWM_16_BIT_OCRxC_OFFSET | SHIFT_MODE_SET_C | TIMER3_ADDR),
    IO5  = (PWM_16_BIT_OCRxA_OFFSET | SHIFT_MODE_SET_A | TIMER3_ADDR),
    IO6  = (PWM_16_BIT_OCRxA_OFFSET | SHIFT_MODE_SET_A | TIMER4_ADDR),
    IO7  = (PWM_16_BIT_OCRxB_OFFSET | SHIFT_MODE_SET_B | TIMER4_ADDR),
    IO8  = (PWM_16_BIT_OCRxC_OFFSET | SHIFT_MODE_SET_C | TIMER4_ADDR),
    IO11 = (PWM_16_BIT_OCRxA_OFFSET | SHIFT_MODE_SET_A | TIMER1_ADDR),
    IO12 = (PWM_16_BIT_OCRxB_OFFSET | SHIFT_MODE_SET_B | TIMER1_ADDR),
    IO13 = (PWM_16_BIT_OCRxC_OFFSET | SHIFT_MODE_SET_C | TIMER1_ADDR),
    IO44 = (PWM_16_BIT_OCRxC_OFFSET | SHIFT_MODE_SET_C | TIMER5_ADDR),
    IO45 = (PWM_16_BIT_OCRxB_OFFSET | SHIFT_MODE_SET_B | TIMER5_ADDR),
    IO46 = (PWM_16_BIT_OCRxA_OFFSET | SHIFT_MODE_SET_A | TIMER5_ADDR)
};

#define PWM_IO4 PWM8::IO4
#define PWM_IO9 PWM8::IO9
#define PWM_IO10 PWM8::IO10

#define PWM_IO2  PWM16::IO2
#define PWM_IO3  PWM16::IO3
#define PWM_IO5  PWM16::IO5
#define PWM_IO6  PWM16::IO6
#define PWM_IO7  PWM16::IO7
#define PWM_IO8  PWM16::IO8
#define PWM_IO11 PWM16::IO11
#define PWM_IO12 PWM16::IO12
#define PWM_IO13 PWM16::IO13
#define PWM_IO44 PWM16::IO44
#define PWM_IO45 PWM16::IO45
#define PWM_IO46 PWM16::IO46




//constexpr u16t __hw_timer_addr[] = {0x24, 0x80, 0xB0, 0x90, 0xA0, 0x120};
//TODO convert to u16t and put correct PIN
namespace core {
namespace irq {
constexpr u8t PROGMEM hw_int_mappedPin[8] = {21, 20, 19, 18, 2, 3, 255, 255};
}
}
constexpr u8t PROGMEM __hw_int_mappedPin[8] = {21, 20, 19, 18, 2, 3, 255, 255};



