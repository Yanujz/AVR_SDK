#pragma once
#include <core.h>
#if defined (__MEGA_SERIES_USART0_SUPPORT__)
#include <mega_hw_usart_async_low_size.h>
#include <avr/interrupt.h>
#include <fifo.hpp>
using namespace yanujz;
using namespace core::mega::uart;

extern Fifo<u8t, ASYNC_USART_FIFO_SIZE> async_usart0_rx_fifo;
extern Fifo<u8t, ASYNC_USART_FIFO_SIZE> async_usart0_tx_fifo;
extern HW_UART_INT __hw_uart0_int;
#define ASYNC_USART0_TX_FIFO (&async_usart0_tx_fifo)
#define ASYNC_USART0_CB_STRUCT (&__hw_uart0_int)

#endif
