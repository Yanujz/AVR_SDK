#include "spislave0.h"
#if defined(__SPI0_SUPPORT__)
SlaveSPI0 slaveSPI0;

SlaveSPI0::SlaveSPI0() : SlaveSPI(){

}

void SlaveSPI0::begin()
{
	SPI0_SLAVE_INIT;

	SPIx_CFG_REG = SPI0_CFG_REG;
}

bool SlaveSPI0::isAvailable()
{
	return !digitalRead(SPI0_DEFAULT_SS);
}

#endif
