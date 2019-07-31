#pragma once
#include <spislave.h>
#include <fifo.hpp>

class AsyncSlaveSPI : public virtual SlaveSPI
{
public:
	AsyncSlaveSPI();
	virtual void begin(SPI_MODE mode = MODE_0,
																				SPI_CLKSEL clock = FOSC_BY_128,
																				SPI_DORD dataOrder = MSB_FIRST) = 0;
	virtual void registerCallback(spi_cb_t* cb = nullptr) = 0;
	virtual void registerCallback(SystemEventHandler* cb = nullptr) = 0;

protected:
	void init();

	Fifo<u8t, 32> rx_fifo;
	Fifo<u8t, 32> tx_fifo;

};


