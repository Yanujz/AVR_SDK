#include <core.h>
#if defined (__MEGA_SERIES_USART2_SUPPORT__)
#include <mega_hw_usart2_async_low_size.h>
#include <mega_hw_usart_sync_low_size.h>
Fifo<u8t, ASYNC_USART_FIFO_SIZE> async_usart2_rx_fifo;
Fifo<u8t, ASYNC_USART_FIFO_SIZE> async_usart2_tx_fifo;
HW_UART_INT __hw_uart2_int;

ISR(USART2_RX_vect){
    char temp = UDR2;
    async_usart2_rx_fifo.push(temp);
    if( __hw_uart2_int.rx_user_cb){
	__hw_uart2_int.rx_user_cb(temp);
    }
    else if(__hw_uart2_int.rx_context) {
	SystemEventHandler::call_int_callback(__hw_uart2_int.rx_context, temp);
    }
}

ISR(USART2_TX_vect)
{
    if(false == async_usart2_tx_fifo.isEmpty()) {
	UDR2 = async_usart2_tx_fifo.pop();
    }
    else {
	async_usart2_tx_fifo.reset();
	if(__hw_uart2_int.tx_user_cb){
	    __hw_uart2_int.tx_user_cb(0);
	}
	else if(__hw_uart2_int.tx_context) {
	    SystemEventHandler::call_int_callback(__hw_uart2_int.tx_context, 0);
	}
    }
}

#endif

