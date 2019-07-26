#include "asyncserial0.h"
#include <avr/iom2560.h>
AsyncSerial0 asyncSerial0;



AsyncSerial0::AsyncSerial0() : AsyncSerial(), Serial0(){

}

void AsyncSerial0::begin(HW_UART baud)
{

}

void AsyncSerial0::begin(HW_UART baud, bool setRxIrq, bool setEcho){
	Serial0::begin(baud);
	AsyncSerial::init(setRxIrq, setEcho, 0);
}

void AsyncSerial0::registerCallback(ser_cb_t *cb){
	__hw_serial_cb[0].user_cb_vect = cb;
}

void AsyncSerial0::registerCallback(SystemEventHandler *cb){
	__hw_serial_cb[0].sys_cb_vect = cb;
}



ISR(USART0_RX_vect){
	char temp = UDR0;
	asyncSerial0.push_rx_fifo(temp);
	if(asyncSerial0.echoIsEnabled()){
		UDR0 = temp;
	}
	if(__hw_serial_cb[0].user_cb_vect != nullptr){
		((void(*)())__hw_serial_cb[0].user_cb_vect)();
	}
	else if(__hw_serial_cb[0].sys_cb_vect != nullptr) {
		SystemEventHandler::call_int_callback(__hw_serial_cb[0].sys_cb_vect);
	}
}

ISR(USART0_TX_vect){
	if(asyncSerial0.is_tx_fifo_empty() == false) {
		UDR0 = asyncSerial0.pop_tx_fifo();
	}
}
