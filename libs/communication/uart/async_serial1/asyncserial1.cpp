#include "asyncserial1.h"
#if defined(__SERIAL1_SUPPORT__)
AsyncSerial1 asyncSerial1;
AsyncSerial::HW_UART_INT __hw_uart1_int;

AsyncSerial1::AsyncSerial1() : AsyncSerial(), Serial1()
{
}

void AsyncSerial1::begin(HW_UART baud)
{
	Serial1::begin(baud);
	AsyncSerial::init();
}

void AsyncSerial1::registerCallback(ser_cb_t *cb)
{
	__hw_uart1_int.user_cb_vect = cb;
}

void AsyncSerial1::registerCallback(SystemEventHandler *cb)
{
	__hw_uart1_int.contex = cb;
}



ISR(USART1_RX_vect){
	char temp = UDR1;
	asyncSerial1.push_rx_fifo(temp);
	if(asyncSerial1.echoIsEnabled()){
		UDR1 = temp;
	}
	if(__hw_uart1_int.user_cb_vect != nullptr){
		__hw_uart1_int.user_cb_vect();
	}
	else if(__hw_uart1_int.contex != nullptr) {
		SystemEventHandler::call_int_callback(__hw_uart1_int.contex, temp);
	}
}
ISR(USART1_TX_vect){
	if(asyncSerial1.is_tx_fifo_empty() == false) {
		UDR1 = asyncSerial1.pop_tx_fifo();
	}
}

#endif // __SERIAL1_SUPPORT__
