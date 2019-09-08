#include "spimaster0.h"
#if defined(__SPI0_SUPPORT__)
MasterSPI0 masterSPI0;

MasterSPI0::MasterSPI0(): MasterSPI() {

}

void MasterSPI0::begin(SPI_MODE mode, SPI_CLKSEL clock, SPI_DORD dataOrder)
{
	SPI0_MASTER_INIT;

	SPIx_CFG_REG = SPI0_CFG_REG;

	u16t cfg = mode | clock | dataOrder;

	MasterSPI::init(cfg);

}
#endif //__SPI0_SUPPORT__
