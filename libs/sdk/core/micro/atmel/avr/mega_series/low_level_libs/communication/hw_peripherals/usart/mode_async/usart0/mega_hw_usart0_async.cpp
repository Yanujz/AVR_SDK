#include <core.h>
#if defined (__MEGA_SERIES_USART0_SUPPORT__)
#include <mega_hw_usart0_async.h>
AsyncUsart0 asyncUsart0;
static AsyncUsart::HW_UART_INT __hw_uart0_int;
AsyncUsart0::AsyncUsart0()
{

}
/*
void AsyncUsart0::begin(HW_UART baud)
{
    cbContainer = &__hw_uart0_int;
    UCSRxA = &UCSR0A;
    AsyncUsart::init(baud);
}
*/
void AsyncUsart0::begin(HW_UART baud)
{
    cbContainer = &__hw_uart0_int;
    UCSRxA = &UCSR0A;
    AsyncUsart::init(baud);
}



#if defined(USART0_RX_vect)
ISR(USART0_RX_vect)
#elif defined(USART_RX_vect)
ISR(USART_RX_vect)
#endif
{
    char temp = UDR0;
    asyncUsart0.push_rx_fifo(temp);
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
    if(false == asyncUsart0.is_tx_fifo_empty()){
	UDR0 = asyncUsart0.pop_tx_fifo();
    }
    else {
	if(__hw_uart0_int.tx_user_cb){
	    __hw_uart0_int.tx_user_cb(0);
	}
	else if(__hw_uart0_int.tx_context) {
	    SystemEventHandler::call_int_callback(__hw_uart0_int.tx_context, 0);
	}
    }
}


#endif
