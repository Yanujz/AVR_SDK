#pragma once
#include <spislave.h>
#if defined(__SPI0_SUPPORT__)
class SlaveSPI0 : public virtual SlaveSPI
{
public:
	SlaveSPI0();
	virtual void begin(SPI_MODE mode = MODE_0,
																				SPI_CLKSEL clock = FOSC_BY_128,
																				SPI_DORD dataOrder = MSB_FIRST) override;
	virtual bool isAvailable() override;
};
extern SlaveSPI0 slaveSPI0;
#endif // __SPI0_SUPPORT__
