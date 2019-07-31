#include "spislave0.h"
#if defined(__SPI0_SUPPORT__)
SlaveSPI0 slaveSPI0;

SlaveSPI0::SlaveSPI0() : SlaveSPI(){

}

void SlaveSPI0::begin(SPI_MODE mode, SPI_CLKSEL clock, SPI_DORD dataOrder)
{
	SPCRx = &SPCR;

	u16t cfg = mode | clock | dataOrder;

	SlaveSPI::init(cfg, SPI0_DEFAULT_MISO, SPI0_DEFAULT_MOSI, SPI0_DEFAULT_SCK, SPI0_DEFAULT_SS);
}

bool SlaveSPI0::isAvailable()
{
	return digitalRead(SPI0_DEFAULT_SS);
}

#endif
