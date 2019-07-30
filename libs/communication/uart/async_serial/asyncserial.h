#ifndef ASYNCSERIAL_H
#define ASYNCSERIAL_H
#include <serial.h>
#include <fifo.hpp>

typedef void ser_cb_t();



class AsyncSerial : public virtual Serial
{
public:

	struct HW_UART_INT : SystemEventHandler::SYS_EVENT
	{
		HW_UART_INT(){
			user_cb_vect = nullptr;
			contex = nullptr;
		}
		ser_cb_t* user_cb_vect;
	};

	AsyncSerial();
	virtual void begin(HW_UART baud) = 0;
	virtual void registerCallback(ser_cb_t* cb = nullptr) = 0;
	virtual void registerCallback(SystemEventHandler* cb = nullptr) = 0;

	void startAsyncSend();

	void push_rx_fifo(u8t value);
	u8t pop_rx_fifo();
	void reset_rx_fifo();
	int get_rx_fifo_unread_element();
	bool is_rx_fifo_empty();

	void push_tx_fifo(u8t *value, int size, bool startOnFinish = false);
	u8t pop_tx_fifo();
	void reset_tx_fifo();
	bool is_tx_fifo_empty();

	void enable_tx_rx_isr();
	void setEchoServer(bool state = false);
	bool echoIsEnabled();

protected:
	void init();
	bool _echoServer = false;
	Fifo<u8t, 32> rx_fifo;
	Fifo<u8t, 32> tx_fifo;
};

//extern __HW_INT_ISR __hw_serial_cb[4];
#endif // ASYNCSERIAL_H
