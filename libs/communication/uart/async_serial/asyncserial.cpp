#include "asyncserial.h"
AsyncSerial* __hw_serial[4] = {nullptr, nullptr, nullptr, nullptr};

AsyncSerial::AsyncSerial() : Serial(){}

void AsyncSerial::setRxISRCallBack(bool state)
{
	if(state) {
		_UCSRxB(UCSRxA) |= (1 << RXCIE0);
		sei();
		return;
	}
	_UCSRxB(UCSRxA) &= ~(1 << RXCIE0);
}

void AsyncSerial::setEchoServer(bool state)
{
	_echoServer = state;
}

void AsyncSerial::insertData(u8t data)
{
	bool bufferIsWritable = true;
	if( ++_write > (uint8_t*)(&USART_BUFF+1)-1){
		_write = USART_BUFF;
	}
	if(_write == _read){

		bufferIsWritable = false;
		--_write;
		if(_write < USART_BUFF){
			_write = (uint8_t*)(&USART_BUFF+1)-1;
		}
	}
	if(bufferIsWritable){
		*_write = data;
	}
}

bool AsyncSerial::bufferIsReadable()
{
	if(_read == _write){
		return false;
	}

	return true;
}

bool AsyncSerial::echoIsEnabled()
{
	if(_echoServer){
		return true;
	}
	return false;
}

u8t AsyncSerial::readData()
{
	_bufferReadable = false;

	if( ++_read > (uint8_t*)(&USART_BUFF+1)-1){
		_read = USART_BUFF;
	}
	if(_read != _write){
		_bufferReadable = true;
	}
	uint8_t temp = *_read;
	return temp;
}

void AsyncSerial::init(bool setRxIrq, bool setEcho, u8t index){
	setRxISRCallBack(setRxIrq);
	setEchoServer(setEcho);

	__hw_serial_cb[index].user_cb_vect = nullptr;
	__hw_serial_cb[index].sys_cb_vect = nullptr;

	//memset(USART_BUFF,0xFF,MAX_SERIAL_BUFFER);
	_read  = USART_BUFF;
	_write = USART_BUFF;

}
