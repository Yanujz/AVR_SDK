#include "asyncserial1.h"

AsyncSerial1 asyncSerial1;


AsyncSerial1::AsyncSerial1() : AsyncSerial(), Serial1(){

}

void AsyncSerial1::begin(HW_UART baud)
{

}

void AsyncSerial1::begin(HW_UART baud, bool setRxIrq, bool setEcho){
	Serial1::begin(baud);
	AsyncSerial::init(setRxIrq, setEcho, 1);
}

void AsyncSerial1::registerCallback(ser_cb_t *cb){
	__hw_serial_cb[1].user_cb_vect = cb;
}

void AsyncSerial1::registerCallback(SystemEventHandler *cb){
	__hw_serial_cb[1].sys_cb_vect = cb;
}



ISR(USART1_RX_vect){
	char temp = UDR1;
	//__hw_serial[0]->insertData(temp);
	if(asyncSerial1.echoIsEnabled()){
		UDR1 = temp;
	}
	if(__hw_serial_cb[1].user_cb_vect != nullptr){
		((void(*)())__hw_serial_cb[1].user_cb_vect)();
	}
	else if(__hw_serial_cb[1].sys_cb_vect != nullptr) {
		SystemEventHandler::call_int_callback(__hw_serial_cb[1].sys_cb_vect);
	}
}

