#pragma once
#include <core.h>
#if defined (__MEGA_SERIES__)
#include <sys_event_handler.h>
#include <fifo.hpp>
#include <avr/interrupt.h>
#include <mega_hw_usart_sync_low_size.h>

#define ASYNC_USART_FIFO_SIZE 8
using namespace yanujz;
using namespace core::mega::uart;
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

void usart_init(ASYNC_USART usart, HW_UART baud);

void usart_asyncSend(ASYNC_USART usart);

void usart_push_tx_fifo(Fifo<u8t, ASYNC_USART_FIFO_SIZE>* fifo, char byte);

void usart_push_tx_fifo(Fifo<u8t, ASYNC_USART_FIFO_SIZE>* fifo, const char *str);

void usart_push_tx_fifo(Fifo<u8t, ASYNC_USART_FIFO_SIZE>* fifo, u8t *buf, int size);

void usart_setOnRxCallback(HW_UART_INT* cbContainer, ser_cb_t* user_cb);
void usart_setOnRxCallback(HW_UART_INT* cbContainer, SystemEventHandler* context);
void usart_clearRxCallback(HW_UART_INT* cbContainer);

void usart_setOnTxCompleteCallback(HW_UART_INT* cbContainer, ser_cb_t* user_cb);
void usart_setOnTxCompleteCallback(HW_UART_INT* cbContainer, SystemEventHandler* context);
void usart_clearTxCompleteCallback(HW_UART_INT* cbContainer);

#endif
