#include "asyncserial.h"

//__HW_INT_ISR __hw_serial_cb[4] = {nullptr, nullptr, nullptr, nullptr};

AsyncSerial::AsyncSerial() : Serial(){}

void AsyncSerial::startAsyncSend()
{
	*UART_UDRx_REG_OFFSET(UCSRxA) = tx_fifo.pop();
}

void AsyncSerial::push_rx_fifo(u8t value)
{
	rx_fifo.push(value);
}

u8t AsyncSerial::pop_rx_fifo()
{
	return rx_fifo.pop();
}

void AsyncSerial::reset_rx_fifo()
{
	rx_fifo.reset();
}

int AsyncSerial::get_rx_fifo_unread_element()
{
	return rx_fifo.getUnreadElement();
}

bool AsyncSerial::is_rx_fifo_empty()
{
	return rx_fifo.isEmpty();
}

void AsyncSerial::push_tx_fifo(u8t* value, int size, bool startOnFinish)
{
	while (size--) {
		tx_fifo.push(*value++);
	}
	if(startOnFinish){
		*UART_UDRx_REG_OFFSET(UCSRxA) = tx_fifo.pop();
	}

}

u8t AsyncSerial::pop_tx_fifo()
{
	return tx_fifo.pop();
}

void AsyncSerial::reset_tx_fifo()
{
	tx_fifo.reset();
}

bool AsyncSerial::is_tx_fifo_empty()
{
	return tx_fifo.isEmpty();
}

void AsyncSerial::setEchoServer(bool state)
{
	_echoServer = state;
}

bool AsyncSerial::echoIsEnabled()
{
	if(_echoServer){
		return true;
	}
	return false;
}


void AsyncSerial::init(){
	//Enabling TX/RX interrupts
	*UCSRxB_REG |= bitValue(RXCIE0) | bitValue(TXCIE0);

	//Enabling global interrupts
	sei();
}
