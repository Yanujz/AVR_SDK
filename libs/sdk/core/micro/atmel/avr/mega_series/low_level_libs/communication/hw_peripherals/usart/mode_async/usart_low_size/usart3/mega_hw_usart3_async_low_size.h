#pragma once
#include <core.h>
#if defined (__MEGA_SERIES_USART3_SUPPORT__)
#include <mega_hw_usart_async_low_size.h>

using namespace yanujz;

extern Fifo<u8t, ASYNC_USART_FIFO_SIZE> async_usart3_rx_fifo;
extern Fifo<u8t, ASYNC_USART_FIFO_SIZE> async_usart3_tx_fifo;
extern HW_UART_INT __hw_uart3_int;
#define ASYNC_USART3_TX_FIFO (&async_usart3_tx_fifo)
#define ASYNC_USART3_CB_STRUCT (&__hw_uart3_int)

#endif
