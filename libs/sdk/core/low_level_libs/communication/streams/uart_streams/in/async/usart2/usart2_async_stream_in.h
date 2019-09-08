#pragma once
#include <core.h>
#if defined (__USART2_SUPPORT__)
#include <usart_async_stream_in.h>
#include <hardware_usart.h>

class USART2_AsyncStreamIn : public UsartAsyncStreamIn
{
public:
  USART2_AsyncStreamIn();
  using UsartAsyncStreamIn::setOnRxCallback;
};

extern USART2_AsyncStreamIn usart2_asyncStreamIn;
#endif
