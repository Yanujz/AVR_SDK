#pragma once
#if defined(__COMPILE__)
#else
#include <avr/iom2560.h>
#endif
#define __SERIAL1_SUPPORT__
#define __SERIAL2_SUPPORT__
#define __SERIAL3_SUPPORT__



#define OR100 (1 << 6)


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

#define REG_PINA 0x00 + 0x20 // +0x20 = 0x20
#define REG_PINB 0x03 + 0x20 // +0x20 = 0x23
#define REG_PINC 0x06 + 0x20 // +0x20 = 0x26
#define REG_PIND 0x09 + 0x20 // +0x20 = 0x29
#define REG_PINE 0x0C + 0x20 // +0x20 = 0x2C
#define REG_PINF 0x0F + 0x20 // +0x20 = 0x2F
#define REG_PING 0x12 + 0x20 // +0x20 = 0x32
#define REG_PINH (OR100 | 0x00)
#define REG_PINJ (OR100 | 0x03)
#define REG_PINK (OR100 | 0x06)
#define REG_PINL (OR100 | 0x09)





#define SPI0_CFG_REG &SPCR
#define SPI0_CFG_BIT_SPIE    SPIE
#define SPI0_CFG_BIT_SPE     SPE
#define SPI0_CFG_BIT_DORD    DORD
#define SPI0_CFG_BIT_MSTR    MSTR
#define SPI0_CFG_BIT_CPOL    CPOL
#define SPI0_CFG_BIT_CPHA    CPHA
#define SPI0_CFG_BIT_SPR1    SPR1
#define SPI0_CFG_BIT_SPR0    SPR0

#define SPI0_STAT_REG SPSR
#define SPI0_STAT_BIT_SPIF    SPIF
#define SPI0_STAT_BIT_WCOL    WCOL
#define SPI0_STAT_BIT_SPI2X   SPI2X

#define SPI0_DATA_REG SPDR



#define SPI_CFG_BIT_SPIE    SPIE
#define SPI_CFG_BIT_SPE     SPE
#define SPI_CFG_BIT_DORD    DORD
#define SPI_CFG_BIT_MSTR    MSTR
#define SPI_CFG_BIT_CPOL    CPOL
#define SPI_CFG_BIT_CPHA    CPHA
#define SPI_CFG_BIT_SPR1    SPR1
#define SPI_CFG_BIT_SPR0    SPR0

#define SPI_STAT_BIT_SPIF    SPIF
#define SPI_STAT_BIT_WCOL    WCOL
#define SPI_STAT_BIT_SPI2X   SPI2X
