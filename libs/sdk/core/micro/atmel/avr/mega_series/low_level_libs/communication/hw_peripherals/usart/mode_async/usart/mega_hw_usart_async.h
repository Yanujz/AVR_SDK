#pragma once
#include <core.h>
#if defined (__MEGA_SERIES__)
#include <mega_hw_usart_sync.h>
#include <mega_hw_usart_async_low_size.h>
#include <fifo.hpp>
#include <sys_event_handler.h>
#include <avr/interrupt.h>
using namespace yanujz;
class AsyncUsart
{
public:
    struct HW_UART_INT
    {
	HW_UART_INT(){
	    rx_user_cb = nullptr;
	    tx_user_cb = nullptr;
	    rx_context = nullptr;
	    tx_context = nullptr;
	}
	SystemEventHandler* rx_context;
	SystemEventHandler* tx_context;
	ser_cb_t* rx_user_cb;
	ser_cb_t* tx_user_cb;
    };
    void begin(HW_UART baud, ser_cb_t* rxCallback, ser_cb_t* txCallback);
    void begin(HW_UART baud, SystemEventHandler* rxCallback, SystemEventHandler* txCallback);
    void begin(HW_UART baud, ser_cb_t* rxCallback, SystemEventHandler* txCallback);
    void begin(HW_UART baud, SystemEventHandler* rxCallback, ser_cb_t* txCallback);

    void setOnRxCallback(ser_cb_t* cb = nullptr);
    void setOnRxCallback(SystemEventHandler* context = nullptr);
    void clearRxCallback();

    void setOnTxCompleteCallback(ser_cb_t* cb = nullptr);
    void setOnTxCompleteCallback(SystemEventHandler* context = nullptr);
    void clearTxCompleteCallback();

    void startAsyncSend();

    void push_rx_fifo(u8t value);
    u8t pop_rx_fifo();
    void reset_rx_fifo();
    int get_rx_fifo_unread_element();
    bool is_rx_fifo_empty();

    void push_tx_fifo(u8t *value, int size, bool startOnFinish = false);
    u8t pop_tx_fifo();
    int get_tx_fifo_unread_element();
    void reset_tx_fifo();
    bool is_tx_fifo_empty();

    void sendSync(u8 byte);
    void sendSync(u8* byte, int size);

protected:
    AsyncUsart();
    void init(HW_UART baud);
    Fifo<u8t, ASYNC_USART_FIFO_SIZE> rx_fifo;
    Fifo<u8t, ASYNC_USART_FIFO_SIZE> tx_fifo;
    HW_UART_INT* cbContainer;
    volatile u8t* UCSRxA;

    virtual void begin(HW_UART baud) = 0;

};
#endif
