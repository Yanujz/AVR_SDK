#ifndef SPI_H
#define SPI_H
#include <core.h>

///@file

/**
	* @brief The SPI Data Order enum
	*/
//enum SPI_DORD: u8t {
//    MSB_FIRST = setBitValue(0, SPI_CFG_BIT_DORD),
//    LSB_FIRST = setBitValue(1, SPI_CFG_BIT_DORD)
//};





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








#endif // SPI_H

