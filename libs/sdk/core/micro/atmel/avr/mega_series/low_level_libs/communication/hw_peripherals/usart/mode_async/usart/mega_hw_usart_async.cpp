#include <core.h>
#if defined (__MEGA_SERIES__)
#include <mega_hw_usart_async.h>

void AsyncUsart::begin(HW_UART baud, ser_cb_t *rxCallback, ser_cb_t *txCallback)
{
    begin(baud);
    cbContainer->rx_user_cb = rxCallback;
    cbContainer->tx_user_cb = txCallback;
}

void AsyncUsart::begin(HW_UART baud, SystemEventHandler *rxCallback, SystemEventHandler *txCallback)
{
    begin(baud);
    cbContainer->rx_context = rxCallback;
    cbContainer->tx_context = txCallback;
}

void AsyncUsart::begin(HW_UART baud, ser_cb_t *rxCallback, SystemEventHandler *txCallback)
{
    begin(baud);
    cbContainer->rx_user_cb = rxCallback;
    cbContainer->tx_context = txCallback;
}

void AsyncUsart::begin(HW_UART baud, SystemEventHandler *rxCallback, ser_cb_t *txCallback)
{
    begin(baud);
    cbContainer->rx_context = rxCallback;
    cbContainer->tx_user_cb = txCallback;
}

void AsyncUsart::setOnRxCallback(ser_cb_t *cb)
{
    cbContainer->rx_user_cb = cb;
}

void AsyncUsart::setOnRxCallback(SystemEventHandler *context)
{
    cbContainer->rx_context = context;
}

void AsyncUsart::clearRxCallback()
{
    cbContainer->rx_context =  nullptr;
    cbContainer->rx_user_cb =  nullptr;
}

void AsyncUsart::setOnTxCompleteCallback(ser_cb_t *cb)
{
    cbContainer->tx_user_cb = cb;
}

void AsyncUsart::setOnTxCompleteCallback(SystemEventHandler *context)
{
    cbContainer->tx_context = context;
}

void AsyncUsart::clearTxCompleteCallback()
{
    cbContainer->tx_context =  nullptr;
    cbContainer->tx_user_cb =  nullptr;
}

void AsyncUsart::startAsyncSend()
{
    if(false == is_tx_fifo_empty()){
	*UART_UDRx_REG_OFFSET(UCSRxA) = tx_fifo.pop();
    }
}

void AsyncUsart::push_rx_fifo(u8t value)
{
    rx_fifo.push(value);
}

u8t AsyncUsart::pop_rx_fifo()
{
    return rx_fifo.pop();
}

void AsyncUsart::reset_rx_fifo()
{
    rx_fifo.reset();
}

int AsyncUsart::get_rx_fifo_unread_element()
{
    return rx_fifo.getUnreadElement();
}

bool AsyncUsart::is_rx_fifo_empty()
{
    return rx_fifo.isEmpty();
}

void AsyncUsart::push_tx_fifo(u8t *value, int size, bool startOnFinish)
{
    while (size--) {
	tx_fifo.push(*value++);
    }
    if(startOnFinish){
	*UART_UDRx_REG_OFFSET(UCSRxA) = tx_fifo.pop();
    }
}

u8t AsyncUsart::pop_tx_fifo()
{
    return tx_fifo.pop();
}

int AsyncUsart::get_tx_fifo_unread_element()
{
    return tx_fifo.getUnreadElement();
}

void AsyncUsart::reset_tx_fifo()
{
    tx_fifo.reset();
}

bool AsyncUsart::is_tx_fifo_empty()
{
    return tx_fifo.isEmpty();
}

AsyncUsart::AsyncUsart()
{

}

void AsyncUsart::init(HW_UART baud)
{
    usart_init((ASYNC_USART)(int)UCSRxA, baud);
}
#endif
