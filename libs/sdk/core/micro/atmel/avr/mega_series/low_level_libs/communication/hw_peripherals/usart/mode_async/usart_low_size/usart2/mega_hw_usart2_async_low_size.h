#pragma once
#include <core.h>
#if defined (__MEGA_SERIES_USART2_SUPPORT__)
#include <mega_hw_usart_async_low_size.h>

using namespace yanujz;

extern Fifo<u8t, ASYNC_USART_FIFO_SIZE> async_usart2_rx_fifo;
extern Fifo<u8t, ASYNC_USART_FIFO_SIZE> async_usart2_tx_fifo;
extern HW_UART_INT __hw_uart2_int;
#define ASYNC_USART2_TX_FIFO (&async_usart2_tx_fifo)
#define ASYNC_USART2_CB_STRUCT (&__hw_uart2_int)

#endif
