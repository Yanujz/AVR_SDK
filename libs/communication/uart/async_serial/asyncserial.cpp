#include "asyncserial.h"
//AsyncSerial* __hw_serial[4] = {nullptr, nullptr, nullptr, nullptr};
__HW_INT_ISR __hw_serial_cb[4] = {nullptr, nullptr, nullptr, nullptr};

AsyncSerial::AsyncSerial() : Serial(){}

void AsyncSerial::push_rx_fifo(u8t value)
{
	rx_fifo.push(value);
}

u8t AsyncSerial::pop_rx_fifo()
{
	return rx_fifo.pop();
}

bool AsyncSerial::is_rx_fifo_empty()
{
	return rx_fifo.isEmpty();
}

void AsyncSerial::push_tx_fifo(u8t* value, int size)
{
	while (size--) {
		tx_fifo.push(*value++);
	}
	_UDRx(UCSRxA) = tx_fifo.pop();
}

u8t AsyncSerial::pop_tx_fifo()
{
	return tx_fifo.pop();
}

bool AsyncSerial::is_tx_fifo_empty()
{
	return tx_fifo.isEmpty();
}

void AsyncSerial::setRxISRCallBack(bool state)
{
	if(state) {
		_UCSRxB(UCSRxA) |= (1 << RXCIE0);
		_UCSRxB(UCSRxA) |= (1 << TXCIE0);
		sei();
		return;
	}
	_UCSRxB(UCSRxA) &= ~(1 << RXCIE0);
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


void AsyncSerial::init(bool setRxIrq, bool setEcho, u8t index){
	setRxISRCallBack(setRxIrq);
	setEchoServer(setEcho);

	__hw_serial_cb[index].user_cb_vect = nullptr;
	__hw_serial_cb[index].sys_cb_vect = nullptr;

}
