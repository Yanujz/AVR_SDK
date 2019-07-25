#include "hardwareserial.h"

UART::UART(volatile u8t *UCSRxA, HW_UART baud){
	_UBRRxH(UCSRxA) = HI(toU16(baud));
	_UBRRxL(UCSRxA) = LO(toU16(baud));

	// Enable receiver and transmitter //
	_UCSRxB(UCSRxA) = (1<<RXEN0)|(1<<TXEN0);

	// Set frame format: 8data, 1stop bit //
	_UCSRxC(UCSRxA) = (1<<UCSZ01)|(1<<UCSZ00);
}

void UART::printf(const char *fmt, ...){
	va_list arg;
	va_start(arg,fmt);
	yanujz::vfprintf(UCSRxA, fmt, arg);
	va_end(arg);
}

void UART0::registerCallback(ser_cb_t *cb){
	//__hw_serial_cb[0].user_cb_vect = cb;
}

void UART0::registerCallback(SystemEventHandler *cb) {
	//	__hw_serial_cb[0].sys_cb_vect = cb;
}

void UART1::registerCallback(ser_cb_t *cb) {
	//__hw_serial_cb[0].user_cb_vect = cb;
}

void UART1::registerCallback(SystemEventHandler *cb) {
	//__hw_serial_cb[0].sys_cb_vect = cb;
}

