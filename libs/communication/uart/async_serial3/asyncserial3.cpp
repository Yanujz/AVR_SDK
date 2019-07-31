#include "asyncserial3.h"
#if defined(__SERIAL3_SUPPORT__)
AsyncSerial3 asyncSerial3;
AsyncSerial::HW_UART_INT __hw_uart3_int;


AsyncSerial3::AsyncSerial3() : AsyncSerial(), Serial3(){

}

void AsyncSerial3::begin(HW_UART baud)
{
	Serial3::begin(baud);
	AsyncSerial::init();
}

void AsyncSerial3::registerCallback(ser_cb_t *cb){
	__hw_uart3_int.user_cb_vect = cb;
}

void AsyncSerial3::registerCallback(SystemEventHandler *cb){
	__hw_uart3_int.contex = cb;
}



ISR(USART3_RX_vect){
	char temp = UDR3;
	asyncSerial3.push_rx_fifo(temp);
	if(asyncSerial3.echoIsEnabled()){
		UDR3 = temp;
	}
	if(__hw_uart3_int.user_cb_vect != nullptr){
		__hw_uart3_int.user_cb_vect();
	}
	else if(__hw_uart3_int.contex != nullptr) {
		SystemEventHandler::call_int_callback(__hw_uart3_int.contex, temp);
	}
}
ISR(USART3_TX_vect){
	if(asyncSerial3.is_tx_fifo_empty() == false) {
		UDR3 = asyncSerial3.pop_tx_fifo();
	}
}
#endif
