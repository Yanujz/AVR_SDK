#include <core.h>
#if defined(__MEGA_SERIES__)
#include <mega_hw_usart_async_low_size.h>
void usart_init(ASYNC_USART usart, HW_UART baud)
{
    usart_init((USART)usart, baud);
	*UART_UCSRxB_REG_OFFSET((volatile u8t*)usart) |= bitValue(RXCIEx) | bitValue(TXCIEx);
    sei();
}


void usart_asyncSend(ASYNC_USART usart)
{
    *UART_UDRx_REG_OFFSET((volatile u8t*)usart) = 0;
}


void usart_push_tx_fifo(Fifo<u8t, ASYNC_USART_FIFO_SIZE> *fifo, char byte)
{
    fifo->push(byte);
}

void usart_push_tx_fifo(Fifo<u8t, ASYNC_USART_FIFO_SIZE> *fifo, const char *str)
{
    while (*str) {
	fifo->push(*str++);
    }
}

void usart_push_tx_fifo(Fifo<u8t, ASYNC_USART_FIFO_SIZE> *fifo, u8t *buf, int size)
{
    while (size--) {
	fifo->push(*buf++);
    }
}

void usart_setOnRxCallback(HW_UART_INT *cbContainer, ser_cb_t* user_cb)
{
    cbContainer->rx_user_cb = user_cb;
}

void usart_setOnRxCallback(HW_UART_INT *cbContainer, SystemEventHandler* context)
{
    cbContainer->rx_context = context;
}

void usart_setOnTxCompleteCallback(HW_UART_INT *cbContainer, ser_cb_t* user_cb)
{
    cbContainer->tx_user_cb = user_cb;
}

void usart_setOnTxCompleteCallback(HW_UART_INT *cbContainer, SystemEventHandler* context)
{
    cbContainer->tx_context = context;
}

void usart_clearRxCallback(HW_UART_INT *cbContainer)
{
    cbContainer->rx_context =  nullptr;
    cbContainer->rx_user_cb =  nullptr;
}

void usart_clearTxCompleteCallback(HW_UART_INT *cbContainer)
{
    cbContainer->tx_context =  nullptr;
    cbContainer->tx_user_cb =  nullptr;
}

#endif
