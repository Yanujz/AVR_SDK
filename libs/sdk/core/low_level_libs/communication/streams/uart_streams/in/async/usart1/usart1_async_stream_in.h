#pragma once
#include <core.h>
#if defined (__USART1_SUPPORT__)
#include <usart_async_stream_in.h>
#include <hardware_usart.h>

class USART1_AsyncStreamIn : public UsartAsyncStreamIn
{
public:
  USART1_AsyncStreamIn();
  using UsartAsyncStreamIn::setOnRxCallback;
};

extern USART1_AsyncStreamIn usart1_asyncStreamIn;
#endif
