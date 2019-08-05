#include "spislave.h"

void SlaveSPI::end()
{
	bitClear(*SPIx_CFG_REG, SPI_CFG_BIT_SPE);
}

u8t SlaveSPI::receive()
{
	loop_until_bit_is_set(*SPIx_STAT_REG, SPI_STAT_BIT_SPIF);
	// Return Data Register
	return *SPIx_DATA_REG;
}

//void SlaveSPI::init()
//{
//	//bitSet(*SPIx_CFG_REG, SPE);
//}
