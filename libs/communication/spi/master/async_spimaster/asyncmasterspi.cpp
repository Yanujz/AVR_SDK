#include "asyncmasterspi.h"

AsyncMasterSPI::AsyncMasterSPI() : MasterSPI(){

}

void AsyncMasterSPI::startAsyncTransfer()
{
	u8t dummy = transfer(pop_tx_fifo());
}

void AsyncMasterSPI::push_rx_fifo(u8t value)
{
	rx_fifo.push(value);
}

u8t AsyncMasterSPI::pop_rx_fifo()
{
	return rx_fifo.pop();
}

bool AsyncMasterSPI::is_rx_fifo_empty()
{
	return rx_fifo.isEmpty();
}

void AsyncMasterSPI::push_tx_fifo(u8t *value, int size, bool startOnFinish)
{
	while (size--) {
		tx_fifo.push(*value++);
	}
	if(startOnFinish){
		push_rx_fifo(transfer(pop_tx_fifo()));
	}
}

u8t AsyncMasterSPI::pop_tx_fifo()
{
	return tx_fifo.pop();
}

bool AsyncMasterSPI::is_tx_fifo_empty()
{
	return tx_fifo.isEmpty();
}

void AsyncMasterSPI::init()
{
	*SPCRx |= bitValue(SPIE);
}
