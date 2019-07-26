#include "asyncserial2.h"

AsyncSerial2 asyncSerial2;


AsyncSerial2::AsyncSerial2() : AsyncSerial(), Serial2(){

}

void AsyncSerial2::begin(HW_UART baud)
{

}

void AsyncSerial2::begin(HW_UART baud, bool setRxIrq, bool setEcho){
	Serial2::begin(baud);
	AsyncSerial::init(setRxIrq, setEcho, 2);
}

void AsyncSerial2::registerCallback(ser_cb_t *cb){
	__hw_serial_cb[2].user_cb_vect = cb;
}

void AsyncSerial2::registerCallback(SystemEventHandler *cb){
	__hw_serial_cb[2].sys_cb_vect = cb;
}



ISR(USART2_RX_vect){
	char temp = UDR2;
	//__hw_serial[0]->insertData(temp);
	if(asyncSerial2.echoIsEnabled()){
		UDR2 = temp;
	}
	if(__hw_serial_cb[2].user_cb_vect != nullptr){
		((void(*)())__hw_serial_cb[2].user_cb_vect)();
	}
	else if(__hw_serial_cb[2].sys_cb_vect != nullptr) {
		SystemEventHandler::call_int_callback(__hw_serial_cb[2].sys_cb_vect);
	}
}

