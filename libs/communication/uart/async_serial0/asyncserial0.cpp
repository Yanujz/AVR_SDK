#include "asyncserial0.h"
AsyncSerial0 asyncSerial0;
AsyncSerial::HW_UART_INT __hw_uart0_int;


AsyncSerial0::AsyncSerial0() : AsyncSerial(), Serial0(){

}

void AsyncSerial0::begin(HW_UART baud)
{
	Serial0::begin(baud);
	AsyncSerial::init();
}

void AsyncSerial0::registerCallback(ser_cb_t *cb){
	__hw_uart0_int.user_cb_vect = cb;
}

void AsyncSerial0::registerCallback(SystemEventHandler *cb){
	__hw_uart0_int.contex = cb;
}

#if defined(USART0_RX_vect)
ISR(USART0_RX_vect){
#elif defined(USART_RX_vect)
ISR(USART_RX_vect){
#endif
	char temp = UDR0;
	asyncSerial0.push_rx_fifo(temp);
	if(asyncSerial0.echoIsEnabled()){
		UDR0 = temp;
	}
	if(__hw_uart0_int.user_cb_vect != nullptr){
		__hw_uart0_int.user_cb_vect();
		}
	else if(__hw_uart0_int.contex != nullptr) {
		SystemEventHandler::call_int_callback(__hw_uart0_int.contex, temp);
	}
}

#if defined(USART0_TX_vect)
ISR(USART0_TX_vect){
#elif defined(USART_TX_vect)
ISR(USART_TX_vect){
#endif
	if(asyncSerial0.is_tx_fifo_empty() == false) {
		UDR0 = asyncSerial0.pop_tx_fifo();
	}
}
