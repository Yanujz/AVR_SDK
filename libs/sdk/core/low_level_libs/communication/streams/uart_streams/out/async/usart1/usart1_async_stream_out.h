#pragma once
#include <core.h>
#if defined (__USART1_SUPPORT__)
#include <usart_async_stream_out.h>
#include <hardware_usart.h>

class USART1_AsyncStreamOut : public UsartAsyncStreamOut
{
public:
  USART1_AsyncStreamOut();
  using UsartAsyncStreamOut::setOnTxCallback;
};

extern USART1_AsyncStreamOut usart1_asyncStreamOut;
#endif
