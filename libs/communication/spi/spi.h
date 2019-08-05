#ifndef SPI_H
#define SPI_H
#include <avr/interrupt.h>
#include <pins.h>
#include <macros.h>
#include <common_structures.h>

#define SPIx_STAT_REG SPIx_STAT_REG_OFFSET(SPIx_CFG_REG)
#define SPIx_DATA_REG SPIx_DATA_REG_OFFSET(SPIx_CFG_REG)
///@file

/**
	* @brief The SPI Data Order enum
	*/
enum SPI_DORD: u8t {
	MSB_FIRST = setBitValue(0, SPI_CFG_BIT_DORD),
	LSB_FIRST = setBitValue(1, SPI_CFG_BIT_DORD)
};

/**
	* @brief The SPI Clock Rate Select enum
	* @verbatim
╔═══════╦══════╦══════╦═══════════════╗
║ SPI2X ║ SPR1 ║ SPR0 ║ SCK Frequency ║
╠═══════╬══════╬══════╬═══════════════╣
║   0   ║   0  ║   0  ║     fosc/4    ║
╠═══════╬══════╬══════╬═══════════════╣
║   0   ║   0  ║   1  ║    fosc/16    ║
╠═══════╬══════╬══════╬═══════════════╣
║   0   ║   1  ║   0  ║    fosc/64    ║
╠═══════╬══════╬══════╬═══════════════╣
║   0   ║   1  ║   1  ║    fosc/128   ║
╠═══════╬══════╬══════╬═══════════════╣
║   1   ║   0  ║   0  ║     fosc/2    ║
╠═══════╬══════╬══════╬═══════════════╣
║   1   ║   0  ║   1  ║     fosc/8    ║
╠═══════╬══════╬══════╬═══════════════╣
║   1   ║   1  ║   0  ║    fosc/32    ║
╠═══════╬══════╬══════╬═══════════════╣
║   1   ║   1  ║   1  ║    fosc/64    ║
╚═══════╩══════╩══════╩═══════════════╝
@endverbatim
	*/
enum SPI_CLKSEL: u16t {
	FOSC_BY_4		 = toWord(setBitValue(0, SPI_STAT_BIT_SPI2X), setBitValue(0, SPI_CFG_BIT_SPR1) | setBitValue(0, SPI_CFG_BIT_SPR0)),
	FOSC_BY_16	 = toWord(setBitValue(0, SPI_STAT_BIT_SPI2X), setBitValue(0, SPI_CFG_BIT_SPR1) | setBitValue(1, SPI_CFG_BIT_SPR0)),
	FOSC_BY_64	 = toWord(setBitValue(0, SPI_STAT_BIT_SPI2X), setBitValue(1, SPI_CFG_BIT_SPR1) | setBitValue(0, SPI_CFG_BIT_SPR0)),
	FOSC_BY_128 = toWord(setBitValue(0, SPI_STAT_BIT_SPI2X), setBitValue(1, SPI_CFG_BIT_SPR1) | setBitValue(1, SPI_CFG_BIT_SPR0)),
	FOSC_BY_2	  = toWord(setBitValue(1, SPI_STAT_BIT_SPI2X), setBitValue(0, SPI_CFG_BIT_SPR1) | setBitValue(0, SPI_CFG_BIT_SPR0)),
	FOSC_BY_8	  = toWord(setBitValue(1, SPI_STAT_BIT_SPI2X), setBitValue(0, SPI_CFG_BIT_SPR1) | setBitValue(1, SPI_CFG_BIT_SPR0)),
	FOSC_BY_32  = toWord(setBitValue(1, SPI_STAT_BIT_SPI2X), setBitValue(1, SPI_CFG_BIT_SPR1) | setBitValue(0, SPI_CFG_BIT_SPR0))
};

enum SPI_MODE : u8t {
	MODE_0 = setBitValue(0, SPI_CFG_BIT_CPOL) | setBitValue(0, SPI_CFG_BIT_CPHA),
	MODE_1 = setBitValue(0, SPI_CFG_BIT_CPOL) | setBitValue(1, SPI_CFG_BIT_CPHA),
	MODE_2 = setBitValue(1, SPI_CFG_BIT_CPOL) | setBitValue(0, SPI_CFG_BIT_CPHA),
	MODE_3 = setBitValue(1, SPI_CFG_BIT_CPOL) | setBitValue(1, SPI_CFG_BIT_CPHA)
};












#endif // SPI_H

