#pragma once
#include <core.h>
#if defined (__USART0_SUPPORT__)
#include <usart_async_stream_in.h>
#include <hardware_usart.h>

class USART0_AsyncStreamIn : public UsartAsyncStreamIn
{
public:
  USART0_AsyncStreamIn();
  using UsartAsyncStreamIn::setOnRxCallback;
};

extern USART0_AsyncStreamIn usart0_asyncStreamIn;
#endif
