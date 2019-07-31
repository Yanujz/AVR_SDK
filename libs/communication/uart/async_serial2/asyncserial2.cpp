#include "asyncserial2.h"

#if defined(__SERIAL2_SUPPORT__)
AsyncSerial2 asyncSerial2;
AsyncSerial::HW_UART_INT __hw_uart2_int;


AsyncSerial2::AsyncSerial2() : AsyncSerial(), Serial2(){

}

void AsyncSerial2::begin(HW_UART baud)
{
	Serial2::begin(baud);
	AsyncSerial::init();
}

void AsyncSerial2::registerCallback(ser_cb_t *cb){
	__hw_uart2_int.user_cb_vect = cb;
}

void AsyncSerial2::registerCallback(SystemEventHandler *cb){
	__hw_uart2_int.contex = cb;
}



ISR(USART2_RX_vect){
	char temp = UDR2;
	asyncSerial2.push_rx_fifo(temp);
	if(asyncSerial2.echoIsEnabled()){
		UDR2 = temp;
	}
	if(__hw_uart2_int.user_cb_vect != nullptr){
		__hw_uart2_int.user_cb_vect();
	}
	else if(__hw_uart2_int.contex != nullptr) {
		SystemEventHandler::call_int_callback(__hw_uart2_int.contex, temp);
	}
}
ISR(USART2_TX_vect){
	if(asyncSerial2.is_tx_fifo_empty() == false) {
		UDR2 = asyncSerial2.pop_tx_fifo();
	}
}

#endif
