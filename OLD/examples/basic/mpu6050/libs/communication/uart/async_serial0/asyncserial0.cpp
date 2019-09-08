#include "asyncserial0.h"
#if defined(__SERIAL0_SUPPORT__)
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
	__hw_uart0_int.user_cb = cb;
}

void AsyncSerial0::registerCallback(SystemEventHandler *context){
	__hw_uart0_int.context = context;
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
	if( nullptr != __hw_uart0_int.user_cb){
		__hw_uart0_int.user_cb();
		}
	else if(nullptr != __hw_uart0_int.context) {
		SystemEventHandler::call_int_callback(__hw_uart0_int.context, temp);
	}
}

#if defined(USART0_TX_vect)
ISR(USART0_TX_vect){
#elif defined(USART_TX_vect)
ISR(USART_TX_vect){
#endif
	if(false == asyncSerial0.is_tx_fifo_empty()) {
		UDR0 = asyncSerial0.pop_tx_fifo();
	}
}
#endif
