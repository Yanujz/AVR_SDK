#ifndef SPIMASTER_H
#define SPIMASTER_H
#include <spi.h>


class MasterSPI
{
public:
	virtual void begin(SPI_MODE mode = MODE_0,
																				SPI_CLKSEL clock = FOSC_BY_128,
																				SPI_DORD dataOrder = MSB_FIRST) = 0;
	void end();
	u8t transfer(u8t data);
	void transfer(u8t *src, int size);
	void transfer(u8t* dst, u8t *src, int size);
	void enableSlave(PIN slave, bool enable = true);
	MasterSPI();
protected:
	void init(u16t cfg);

	volatile u8t* SPIx_CFG_REG;
};


#endif // SPI_H






