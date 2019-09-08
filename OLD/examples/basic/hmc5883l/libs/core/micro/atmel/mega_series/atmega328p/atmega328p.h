#pragma once
#include <mega_common.h>
#include <atmega328p_common.h>
#include <atmega328p_common_define.h>


/*
╔════╦════╦════╦════╦════╦═════════╦════╦═══╦═══════════╦═══╦═══╦═══╦═══╦═══╦═══╦═══╗
║ 15 ║ 14 ║ 13 ║ 12 ║ 11 ║    10   ║  9 ║ 8 ║     7     ║ 6 ║ 5 ║ 4 ║ 3 ║ 2 ║ 1 ║ 0 ║
╠════╬════╬════╬════╬════╬═════════╬════╩═══╬═══════════╬═══╩═══╩═══╬═══╩═══╩═══╩═══╣
║    ║    ║    ║    ║    ║ LETTERx ║ TIMERx ║ PWM GROUP ║  REG BIT  ║      PINx     ║
╚════╩════╩════╩════╩════╩═════════╩════════╩═══════════╩═══════════╩═══════════════╝
*/

enum class PIN : int
{
	IO_PB0  =	LETTERx(0)        | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD0) |  PINx(_PINB), //8 CLKO - PCINT0 - ICP1
	IO_PB1  =	LETTERx(LETTER_A) | TIMERx(TIMER_1)  | PWM_GROUP(PWM16BIT) | BIT(DD1) |  PINx(_PINB), //9 PCINT1
	IO_PB2  =	LETTERx(LETTER_B) | TIMERx(TIMER_1)  | PWM_GROUP(PWM16BIT) | BIT(DD2) |  PINx(_PINB), //10 PCINT2 - SS
	IO_PB3  =	LETTERx(LETTER_A) | TIMERx(TIMER_2)  | PWM_GROUP(PWM8BIT)  | BIT(DD3) |  PINx(_PINB), //11 PCINT3 - MOSI
	IO_PB4  =	LETTERx(0)        | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD4) |  PINx(_PINB), //12 PCINT4 - MISO
	IO_PB5  =	LETTERx(0)        | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD5) |  PINx(_PINB), //13 PCINT5 - SCK

	IO_PC0		=	LETTERx(0)        | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD0) |  PINx(_PINC), //14 PCINT8 - SCK
	IO_PC1  = LETTERx(0)        | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD1) |  PINx(_PINC), //15 PCINT9 - SCK
	IO_PC2  = LETTERx(0)        | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD2) |  PINx(_PINC), //16 PCINT10 - SCK
	IO_PC3	 = LETTERx(0)        | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD3) |  PINx(_PINC), //17 PCINT11 - SCK
	IO_PC4	 = LETTERx(0)        | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD4) |  PINx(_PINC), //18 PCINT12 - SCK
	IO_PC5 	= LETTERx(0)        | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD5) |  PINx(_PINC), //19 PCINT13 - SCK

	IO_PD0  =	LETTERx(0)        | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD0) |  PINx(_PIND), //0	RX - PCINT16
	IO_PD1  =	LETTERx(0)        | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD1) |  PINx(_PIND), //1 TX- PCINT17
	IO_PD2  =	LETTERx(0)        | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD2) |  PINx(_PIND), //2 INT0 - PCINT18
	IO_PD3  =	LETTERx(LETTER_B) | TIMERx(TIMER_2)  | PWM_GROUP(PWM8BIT)  | BIT(DD3) |  PINx(_PIND), //3 INT1 - PCINT19
	IO_PD4  =	LETTERx(0)        | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD4) |  PINx(_PIND), //4 T0 - PCINT20 - XCK
	IO_PD5  =	LETTERx(LETTER_B) | TIMERx(TIMER_0)  | PWM_GROUP(PWM8BIT)  | BIT(DD5) |  PINx(_PIND), //5 T1 - PCINT21
	IO_PD6  =	LETTERx(LETTER_A) | TIMERx(TIMER_0)  | PWM_GROUP(PWM8BIT)  | BIT(DD6) |  PINx(_PIND), //6 AIN0 - PCINT22
	IO_PD7  =	LETTERx(0)        | TIMERx(NO_TIMER) | PWM_GROUP(0)        | BIT(DD7) |  PINx(_PIND), //7 AIN1 - PCINT23
};

#define SPI0_DEFAULT_SS PIN::IO_PB2
#define SPI0_DEFAULT_MOSI PIN::IO_PB3
#define SPI0_DEFAULT_MISO PIN::IO_PB4
#define SPI0_DEFAULT_SCK PIN::IO_PB5

//constexpr u16t __hw_timer_addr[] = {0x24, 0x80, 0xB0};
constexpr u8t PROGMEM __hw_int_mappedPin[] = {2, 3};



