#include <core.h>
#if defined (__MEGA_SERIES_USART0_SUPPORT__)
#include <mega_hw_usart0_async_low_size.h>
#include <mega_hw_usart_sync_low_size.h>

Fifo<u8t, ASYNC_USART_FIFO_SIZE> async_usart0_rx_fifo;
Fifo<u8t, ASYNC_USART_FIFO_SIZE> async_usart0_tx_fifo;
HW_UART_INT __hw_uart0_int;

#if defined(USART0_RX_vect)
ISR(USART0_RX_vect)
#elif defined(USART_RX_vect)
ISR(USART_RX_vect)
#endif
{

    char temp = UDR0;
    async_usart0_rx_fifo.push(temp);
    if(__hw_uart0_int.rx_user_cb){
	__hw_uart0_int.rx_user_cb(temp);
    }
    else if(__hw_uart0_int.rx_context) {
	SystemEventHandler::call_int_callback(__hw_uart0_int.rx_context, temp);
    }
}

#if defined(USART0_TX_vect)
ISR(USART0_TX_vect)
#elif defined(USART_TX_vect)
ISR(USART_TX_vect)
#endif
{
    if(false == async_usart0_tx_fifo.isEmpty()) {
	UDR0 = async_usart0_tx_fifo.pop();
    }
    else {
	async_usart0_tx_fifo.reset();
	if(__hw_uart0_int.tx_user_cb){
	    __hw_uart0_int.tx_user_cb(0);
	}
	else if(__hw_uart0_int.tx_context) {
	    SystemEventHandler::call_int_callback(__hw_uart0_int.tx_context, 0);
	}
    }
}



#endif

