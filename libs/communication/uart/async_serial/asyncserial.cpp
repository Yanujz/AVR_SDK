#include "asyncserial.h"

//__HW_INT_ISR __hw_serial_cb[4] = {nullptr, nullptr, nullptr, nullptr};

AsyncSerial::AsyncSerial() : Serial(){}

void AsyncSerial::startAsyncSend()
{
	_UDRx(UCSRxA) = tx_fifo.pop();
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
		_UDRx(UCSRxA) = tx_fifo.pop();
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

void AsyncSerial::enable_tx_rx_isr()
{
	_UCSRxB(UCSRxA) |= bitValue(RXCIE0);
	_UCSRxB(UCSRxA) |= bitValue(TXCIE0);
	sei();
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
	enable_tx_rx_isr();
}
