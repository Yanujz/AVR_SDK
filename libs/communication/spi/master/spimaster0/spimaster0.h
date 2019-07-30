#pragma once
#include <spimaster.h>


class MasterSPI0 : public virtual MasterSPI
{
public:
	MasterSPI0();
	virtual void begin(SPI_MODE mode = MODE_0,
																				SPI_CLKSEL clock = FOSC_BY_128,
																				SPI_DORD dataOrder = MSB_FIRST) override;
};

extern 	MasterSPI0 masterSPI0;
