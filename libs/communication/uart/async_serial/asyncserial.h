#ifndef ASYNCSERIAL_H
#define ASYNCSERIAL_H
#include <macros.h>
#include <serial.h>

class AsyncSerial : public Serial
{
public:
	AsyncSerial();
	virtual void begin(HW_UART baud, bool setRxIrq = false, bool setEcho = false) = 0;
	virtual void registerCallback(ser_cb_t* cb = nullptr) = 0;
	virtual void registerCallback(SystemEventHandler* cb = nullptr) = 0;
	void setRxISRCallBack (bool state);
	void setEchoServer(bool state = false);
	void insertData(u8t data);
	bool bufferIsReadable();
	bool echoIsEnabled();
	u8t readData();
protected:
	void init(bool setRxIrq, bool setEcho, u8t index);
	bool _echoServer;
	bool _bufferReadable;
	u8t *_read;
	u8t *_write;
	u8t *USART_BUFF;
};
extern AsyncSerial* __hw_serial[4];

#endif // ASYNCSERIAL_H
