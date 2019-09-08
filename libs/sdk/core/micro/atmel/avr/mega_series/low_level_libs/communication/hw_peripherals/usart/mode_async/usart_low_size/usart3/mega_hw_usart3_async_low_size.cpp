#include <core.h>
#if defined (__MEGA_SERIES_USART3_SUPPORT__)
#include <mega_hw_usart3_async_low_size.h>
#include <mega_hw_usart_sync_low_size.h>
Fifo<u8t, ASYNC_USART_FIFO_SIZE> async_usart3_rx_fifo;
Fifo<u8t, ASYNC_USART_FIFO_SIZE> async_usart3_tx_fifo;
HW_UART_INT __hw_uart3_int;

ISR(USART3_RX_vect){
    char temp = UDR3;
    async_usart3_rx_fifo.push(temp);
    if( __hw_uart3_int.rx_user_cb){
	__hw_uart3_int.rx_user_cb(temp);
    }
    else if(__hw_uart3_int.rx_context) {
	SystemEventHandler::call_int_callback(__hw_uart3_int.rx_context, temp);
    }
}

ISR(USART3_TX_vect)
{
    if(false == async_usart3_tx_fifo.isEmpty()) {
	UDR3 = async_usart3_tx_fifo.pop();
    }
    else {
	async_usart3_tx_fifo.reset();
	if(__hw_uart3_int.tx_user_cb){
	    __hw_uart3_int.tx_user_cb(0);
	}
	else if(__hw_uart3_int.tx_context) {
	    SystemEventHandler::call_int_callback(__hw_uart3_int.tx_context, 0);
	}
    }
}

#endif

