#include <usart_async_stream_in.h>

UsartAsyncStreamIn::UsartAsyncStreamIn()
{

}

void UsartAsyncStreamIn::setOnRxCallback(SystemEventHandler *context)
{
  asyncUsart->setOnRxCallback (context);
}

u8 UsartAsyncStreamIn::pop_rx_fifo()
{
  return  asyncUsart->pop_rx_fifo();
}

void UsartAsyncStreamIn::reset_rx_fifo()
{
  asyncUsart->reset_rx_fifo ();
}

int UsartAsyncStreamIn::get_rx_fifo_unread_element()
{
  return asyncUsart->get_rx_fifo_unread_element ();
}

bool UsartAsyncStreamIn::is_rx_fifo_empty()
{
  return  asyncUsart->is_rx_fifo_empty ();
}
