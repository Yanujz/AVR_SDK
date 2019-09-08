#pragma once
#include <core.h>
#if defined (__USART3_SUPPORT__)
#include <usart_async_stream_in.h>
#include <hardware_usart.h>

class USART3_AsyncStreamIn : public UsartAsyncStreamIn
{
public:
  USART3_AsyncStreamIn();
  using UsartAsyncStreamIn::setOnRxCallback;
  //using UsartAsyncStreamIn::pop_rx_fifo;
  //using UsartAsyncStreamIn::reset_rx_fifo;
  //using UsartAsyncStreamIn::get_rx_fifo_unread_element;
  //using UsartAsyncStreamIn::is_rx_fifo_empty;
};

extern USART3_AsyncStreamIn usart3_asyncStreamIn;
#endif
