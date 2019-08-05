#pragma once
#include <spislave.h>
#include <fifo.hpp>

class AsyncSlaveSPI : public virtual SlaveSPI
{
public:
	AsyncSlaveSPI();
	virtual void begin() = 0;
	virtual void registerCallback(spi_cb_t* cb = nullptr) = 0;
	virtual void registerCallback(SystemEventHandler* context = nullptr) = 0;

protected:
	void init();

	Fifo<u8t, 32> rx_fifo;
	Fifo<u8t, 32> tx_fifo;

};


