#include "asyncspislave0.h"
AsyncSlaveSPI0 asyncSlaveSPI0;
AsyncSPI::HW_SPI_INT __hw_spi0_int;
AsyncSlaveSPI0::AsyncSlaveSPI0(): AsyncSlaveSPI(), SlaveSPI0(){}

void AsyncSlaveSPI0::begin(SPI_MODE mode, SPI_CLKSEL clock, SPI_DORD dataOrder)
{
	SlaveSPI0::begin(mode, clock, dataOrder);
	AsyncSlaveSPI::init();
}

void AsyncSlaveSPI0::registerCallback(spi_cb_t *cb)
{
	__hw_spi0_int.user_cb = cb;
}

void AsyncSlaveSPI0::registerCallback(SystemEventHandler *cb)
{
	__hw_spi0_int.contex = cb;
}


ISR(SPI_STC_vect){
	//TODO
}
