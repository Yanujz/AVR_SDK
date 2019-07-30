#include "spimaster0.h"
MasterSPI0 masterSPI0;

MasterSPI0::MasterSPI0(): MasterSPI() {

}

void MasterSPI0::begin(SPI_MODE mode, SPI_CLKSEL clock, SPI_DORD dataOrder)
{
	SPCRx = &SPCR;

	u16t cfg = mode | clock | dataOrder;

	MasterSPI::init(cfg, SPI0_DEFAULT_MISO, SPI0_DEFAULT_MOSI, SPI0_DEFAULT_SCK, SPI0_DEFAULT_SS);
}

