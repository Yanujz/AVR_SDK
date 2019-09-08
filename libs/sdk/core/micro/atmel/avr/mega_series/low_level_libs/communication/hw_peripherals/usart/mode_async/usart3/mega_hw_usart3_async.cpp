#include <core.h>
#if defined (__MEGA_SERIES_USART3_SUPPORT__)
#include <mega_hw_usart3_async.h>
AsyncUsart3 asyncUsart3;
static AsyncUsart::HW_UART_INT __hw_uart3_int;
AsyncUsart3::AsyncUsart3()
{

}

void AsyncUsart3::begin(HW_UART baud)
{
    cbContainer = &__hw_uart3_int;
    UCSRxA = &UCSR3A;
    AsyncUsart::init(baud);
}

ISR(USART3_RX_vect)
{
    char temp = UDR3;
    asyncUsart3.push_rx_fifo(temp);
    if(__hw_uart3_int.rx_user_cb){
	__hw_uart3_int.rx_user_cb(temp);
    }
    else if(__hw_uart3_int.rx_context) {
	SystemEventHandler::call_int_callback(__hw_uart3_int.rx_context, temp);
    }
}

ISR(USART3_TX_vect)
{
    if(false == asyncUsart3.is_tx_fifo_empty()){
	UDR3 = asyncUsart3.pop_tx_fifo();
    }
    else {
	if(__hw_uart3_int.tx_user_cb){
	    __hw_uart3_int.tx_user_cb(0);
	}
	else if(__hw_uart3_int.tx_context) {
	    SystemEventHandler::call_int_callback(__hw_uart3_int.tx_context, 0);
	}
    }
}


#endif
