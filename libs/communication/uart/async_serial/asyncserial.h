#ifndef ASYNCSERIAL_H
#define ASYNCSERIAL_H
#include <serial.h>
#include <fifo.h>

typedef void ser_cb_t();
struct __HW_INT_ISR
{
	ser_cb_t* user_cb_vect;
	SystemEventHandler* sys_cb_vect;
};


class AsyncSerial : public virtual Serial
{
public:
	AsyncSerial();
	virtual void begin(HW_UART baud, bool setRxIrq = false, bool setEcho = false) = 0;
	virtual void registerCallback(ser_cb_t* cb = nullptr) = 0;
	virtual void registerCallback(SystemEventHandler* cb = nullptr) = 0;

	void push_rx_fifo(u8t value);
	u8t pop_rx_fifo();
	bool is_rx_fifo_empty();

	void push_tx_fifo(u8t *value, int size);
	u8t pop_tx_fifo();
	bool is_tx_fifo_empty();

	void setRxISRCallBack (bool state);
	void setEchoServer(bool state = false);
	bool echoIsEnabled();
protected:
	void init(bool setRxIrq, bool setEcho, u8t index);
	bool _echoServer;
	Fifo<u8t, 32> rx_fifo;
	Fifo<u8t, 32> tx_fifo;
};

//extern AsyncSerial* __hw_serial[4];
extern __HW_INT_ISR __hw_serial_cb[4];
#endif // ASYNCSERIAL_H
