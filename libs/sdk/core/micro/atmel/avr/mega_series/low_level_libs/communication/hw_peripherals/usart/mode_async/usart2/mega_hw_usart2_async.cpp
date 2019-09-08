#include <core.h>
#if defined (__MEGA_SERIES_USART2_SUPPORT__)
#include <mega_hw_usart2_async.h>
AsyncUsart2 asyncUsart2;
static AsyncUsart::HW_UART_INT __hw_uart2_int;
AsyncUsart2::AsyncUsart2()
{

}

void AsyncUsart2::begin(HW_UART baud)
{
    cbContainer = &__hw_uart2_int;
    UCSRxA = &UCSR2A;
    AsyncUsart::init(baud);
}

ISR(USART2_RX_vect)
{
    char temp = UDR2;
    asyncUsart2.push_rx_fifo(temp);
    if(__hw_uart2_int.rx_user_cb){
	__hw_uart2_int.rx_user_cb(temp);
    }
    else if(__hw_uart2_int.rx_context) {
	SystemEventHandler::call_int_callback(__hw_uart2_int.rx_context, temp);
    }
}


ISR(USART2_TX_vect)
{
    if(false == asyncUsart2.is_tx_fifo_empty()){
	UDR2 = asyncUsart2.pop_tx_fifo();
    }
    else {
	if(__hw_uart2_int.tx_user_cb){
	    __hw_uart2_int.tx_user_cb(0);
	}
	else if(__hw_uart2_int.tx_context) {
	    SystemEventHandler::call_int_callback(__hw_uart2_int.tx_context, 0);
	}
    }
}


#endif
