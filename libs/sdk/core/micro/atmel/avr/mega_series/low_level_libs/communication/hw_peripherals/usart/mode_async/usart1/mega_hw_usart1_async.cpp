#include <core.h>
#if defined (__MEGA_SERIES_USART1_SUPPORT__)
#include <mega_hw_usart1_async.h>
AsyncUsart1 asyncUsart1;
static AsyncUsart::HW_UART_INT __hw_uart1_int;
AsyncUsart1::AsyncUsart1()
{

}

void AsyncUsart1::begin(HW_UART baud)
{
    cbContainer = &__hw_uart1_int;
    UCSRxA = &UCSR1A;
    AsyncUsart::init(baud);
}

ISR(USART1_RX_vect)
{
    char temp = UDR1;
    asyncUsart1.push_rx_fifo(temp);
    if(__hw_uart1_int.rx_user_cb){
	__hw_uart1_int.rx_user_cb(temp);
    }
    else if(__hw_uart1_int.rx_context) {
	SystemEventHandler::call_int_callback(__hw_uart1_int.rx_context, temp);
    }
}

ISR(USART1_TX_vect)
{
    if(false == asyncUsart1.is_tx_fifo_empty()){
	UDR1 = asyncUsart1.pop_tx_fifo();
    }
    else {
	if(__hw_uart1_int.tx_user_cb){
	    __hw_uart1_int.tx_user_cb(0);
	}
	else if(__hw_uart1_int.tx_context) {
	    SystemEventHandler::call_int_callback(__hw_uart1_int.tx_context, 0);
	}
    }
}


#endif
