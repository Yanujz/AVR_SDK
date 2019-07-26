#include "asyncserial3.h"

AsyncSerial3 asyncSerial3;


AsyncSerial3::AsyncSerial3() : AsyncSerial(), Serial3(){

}

void AsyncSerial3::begin(HW_UART baud)
{

}

void AsyncSerial3::begin(HW_UART baud, bool setRxIrq, bool setEcho){
	Serial3::begin(baud);
	AsyncSerial::init(setRxIrq, setEcho, 3);
}

void AsyncSerial3::registerCallback(ser_cb_t *cb){
	__hw_serial_cb[3].user_cb_vect = cb;
}

void AsyncSerial3::registerCallback(SystemEventHandler *cb){
	__hw_serial_cb[3].sys_cb_vect = cb;
}



ISR(USART3_RX_vect){
	char temp = UDR3;
	//__hw_serial[0]->insertData(temp);
	if(asyncSerial3.echoIsEnabled()){
		UDR3 = temp;
	}
	if(__hw_serial_cb[3].user_cb_vect != nullptr){
		((void(*)())__hw_serial_cb[3].user_cb_vect)();
	}
	else if(__hw_serial_cb[3].sys_cb_vect != nullptr) {
		SystemEventHandler::call_int_callback(__hw_serial_cb[3].sys_cb_vect);
	}
}
