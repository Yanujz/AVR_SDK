#pragma once
#include <core.h>
#if defined (__MEGA_SERIES_USART1_SUPPORT__)
#include <mega_hw_usart_async_low_size.h>

using namespace yanujz;

extern Fifo<u8t, ASYNC_USART_FIFO_SIZE> async_usart1_rx_fifo;
extern Fifo<u8t, ASYNC_USART_FIFO_SIZE> async_usart1_tx_fifo;
extern HW_UART_INT __hw_uart1_int;
#define ASYNC_USART1_TX_FIFO (&async_usart1_tx_fifo)
#define ASYNC_USART1_CB_STRUCT (&__hw_uart1_int)

#endif
