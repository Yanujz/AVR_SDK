#include "asyncspislave0.h"
AsyncSlaveSPI0 asyncSlaveSPI0;
AsyncSPI::HW_SPI_INT __hw_spi0_int;
AsyncSlaveSPI0::AsyncSlaveSPI0(): AsyncSlaveSPI(), SlaveSPI0(){}

void AsyncSlaveSPI0::begin()
{
	SlaveSPI0::begin();
	AsyncSlaveSPI::init();
}

void AsyncSlaveSPI0::registerCallback(spi_cb_t *cb)
{
	__hw_spi0_int.user_cb = cb;
}

void AsyncSlaveSPI0::registerCallback(SystemEventHandler *context)
{
	__hw_spi0_int.context = context;
}


ISR(SPI_STC_vect){
	u8t temp = SPDR;
	UDR3 = temp;
}

