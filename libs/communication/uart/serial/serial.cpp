#include "serial.h"
void Serial::init(HW_UART baud)
{
	_UBRRxH(UCSRxA) = HI(toU16(baud));
	_UBRRxL(UCSRxA) = LO(toU16(baud));

	// Enable receiver and transmitter //
	_UCSRxB(UCSRxA) = (1<<RXEN0)|(1<<TXEN0);

	// Set frame format: 8data, 1stop bit //
	_UCSRxC(UCSRxA) = (1<<UCSZ01)|(1<<UCSZ00);
	//UCSR0A = (1<<U2X0); // Clock multiplier


}

void Serial::printf(const char *fmt, ...)
{
	va_list arg;
	va_start(arg,fmt);
	yanujz::vfprintf(UCSRxA, fmt, arg);
	va_end(arg);
}

void Serial::readUntil(char *buffer, char chr)
{
	u8t i = 0;
	while (1) {
		char temp = receive();
		if(temp == chr){
			buffer[++i] ='\0';
			break;
		}
		buffer[i++] = temp;
	}
}

void Serial::flush()
{

	u8t dummy;
	while(*UCSRxA & (1<<RXC0)){
		dummy = _UDRx(UCSRxA);
	}
}





//////
bool Serial::isAvailable()
{
	return ((*UCSRxA & (1 << RXC0)) >> RXC0); // Return true means is available
}

uint8_t Serial::receive()
{
	return yanujz::getc(UCSRxA);
}
void Serial::clear()
{
	yanujz::puts("\e[1;1H\e[2J", UCSRxA);
}


/*

void Serial1::begin(HW_UART baud, bool setRxIrq, bool setEcho)
{
	UCSRxA = (volatile u8t*)&UCSR1A;
	init(baud, setRxIrq, setEcho, 1);
	__hw_serial[1] = this;
}

void Serial1::registerCallback(ser_cb_t *cb) {
	__hw_serial_cb[1].user_cb_vect = cb;
}

void Serial1::registerCallback(SystemEventHandler *cb) {
	__hw_serial_cb[1].sys_cb_vect = cb;
}


void Serial2::begin(HW_UART baud, bool setRxIrq, bool setEcho)
{
	UCSRxA = (volatile u8t*)&UCSR2A;
	init(baud, setRxIrq, setEcho, 2);
	__hw_serial[2] = this;
}

void Serial2::registerCallback(ser_cb_t *cb)
{
	__hw_serial_cb[2].user_cb_vect = cb;
}

void Serial2::registerCallback(SystemEventHandler *cb)
{
	__hw_serial_cb[2].sys_cb_vect = cb;
}


void Serial3::begin(HW_UART baud, bool setRxIrq, bool setEcho)
{
	UCSRxA = (volatile u8t*)&UCSR3A;
	init(baud, setRxIrq, setEcho, 3);
	__hw_serial[3] = this;
}

void Serial3::registerCallback(ser_cb_t *cb)
{
	__hw_serial_cb[3].user_cb_vect = cb;
}

void Serial3::registerCallback(SystemEventHandler *cb)
{
__hw_serial_cb[3].sys_cb_vect = cb;
}
*/






//Serial1 serial1;
//Serial2 serial2;
//Serial3 serial3;

__HW_INT_ISR __hw_serial_cb[4] = {nullptr, nullptr, nullptr, nullptr};


/*

#if defined(__AVR_ATmega640__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
#endif


ISR(USART1_RX_vect){
	char temp = UDR1;
	//__hw_serial[0]->insertData(temp);
	if(__hw_serial[1]->echoIsEnabled()){
		UDR1 = temp;
	}
	if(__hw_serial_cb[0].user_cb_vect != nullptr){
		((void(*)())__hw_serial_cb[0].user_cb_vect)();
	}
	else if(__hw_serial_cb[0].sys_cb_vect != nullptr) {
		SystemEventHandler::call_int_callback(__hw_serial_cb[0].sys_cb_vect);
	}
}

ISR(USART2_RX_vect){
	char temp = UDR2;
	//__hw_serial[0]->insertData(temp);
	if(__hw_serial[2]->echoIsEnabled()){
		UDR2 = temp;
	}
	if(__hw_serial_cb[2].user_cb_vect != nullptr){
		((void(*)())__hw_serial_cb[2].user_cb_vect)();
	}
	else if(__hw_serial_cb[2].sys_cb_vect != nullptr) {
		SystemEventHandler::call_int_callback(__hw_serial_cb[2].sys_cb_vect);
	}
}
ISR(USART3_RX_vect){
	char temp = UDR3;
	//__hw_serial[0]->insertData(temp);
	if(__hw_serial[3]->echoIsEnabled()){
		UDR3 = temp;
	}
	if(__hw_serial_cb[3].user_cb_vect != nullptr){
		((void(*)())__hw_serial_cb[3].user_cb_vect)();
	}
	else if(__hw_serial_cb[3].sys_cb_vect != nullptr) {
		SystemEventHandler::call_int_callback(__hw_serial_cb[3].sys_cb_vect);
	}
}
*/
/*


#if defined(__AVR_ATmega328P__)
ISR(USART_RX_vect){
	char temp = UDR0;
	__hw_serial[0]->insertData(temp);
	if(__hw_serial[0]->echoIsEnabled()){
		UDR0 = temp;
	}
	//if(__hw_serial_cb[0] != nullptr){
	//	__hw_serial_cb[0]();
	//}

	if(__hw_serial_cb[0].user_cb_vect != nullptr){
		((void(*)())__hw_serial_cb[0].user_cb_vect)();
	}
	else if(__hw_serial_cb[0].sys_cb_vect != nullptr) {
		SystemEventHandler::call_int_callback(__hw_serial_cb[0].sys_cb_vect);
	}
}
#endif
*/
/*
#elif defined(__AVR_ATmega640__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)


//ISR(USART0_RX_vect){
//				//Serial *serial0 = SerialManager::getInstance(SERIAL0);
//				Serial *serial = __hw_serial[0];
//				char temp = UDR0;
//				serial->printf("Dentro isr %p %p\r\n", __hw_serial[0], &serial);
//				//serial0.insertData(temp);
//				//if(serial0->echoIsEnabled()){
//				//				UDR0 = temp;
//				//}
//				//serial0->rxCallBack();
//}
ISR(USART1_RX_vect){
				Serial *serial1 = SerialManager::getInstance(SERIAL1);
				char temp = UDR1;
				serial1->insertData(temp);
				if(serial1->echoIsEnabled()){
								UDR1 = temp;
				}
				serial1->rxCallBack();

}
ISR(USART2_RX_vect){
				Serial *serial2 = SerialManager::getInstance(SERIAL2);
				char temp = UDR2;
				serial2->insertData(temp);
				if(serial2->echoIsEnabled()){
								UDR2 = temp;
				}
				serial2->rxCallBack();

}
ISR(USART3_RX_vect){
				Serial *serial3 = SerialManager::getInstance(SERIAL3);
				uint8_t temp = UDR3;
				serial3->insertData(temp);
				if(serial3->echoIsEnabled()){
								UDR3 = temp;
				}
				serial3->rxCallBack();
}
#endif
*/
