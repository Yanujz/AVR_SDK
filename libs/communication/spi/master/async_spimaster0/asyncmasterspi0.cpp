#include "asyncmasterspi0.h"
AsyncMasterSPI0 asyncMasterSPI0;
__HW_SPI_INT __spi0_hw_int;

AsyncMasterSPI0::AsyncMasterSPI0() : AsyncMasterSPI(){

}

void AsyncMasterSPI0::begin(SPI_MODE mode, SPI_CLKSEL clock, SPI_DORD dataOrder)
{
	MasterSPI0::begin(mode, clock, dataOrder);
}

void AsyncMasterSPI0::registerCallback(spi_cb_t *cb)
{

}

void AsyncMasterSPI0::registerCallback(SystemEventHandler *cb)
{

}

ISR(SPI_STC_vect){
	if(asyncMasterSPI0.is_tx_fifo_empty() != false){
		asyncMasterSPI0.push_rx_fifo(asyncMasterSPI0.pop_tx_fifo());
	}
	if(nullptr != __spi0_hw_int.user_cb_t){
		__spi0_hw_int.user_cb_t();
	}
	else if(nullptr != __spi0_hw_int.contex){
		SystemEventHandler::call_int_callback(__spi0_hw_int.contex);
	}
}
