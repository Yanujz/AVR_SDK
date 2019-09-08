#pragma once
#include <core.h>
#if defined (__USART2_SUPPORT__)
#include <usart_async_stream_out.h>
#include <hardware_usart.h>

class USART2_AsyncStreamOut : public UsartAsyncStreamOut
{
public:
  USART2_AsyncStreamOut();
  using UsartAsyncStreamOut::setOnTxCallback;
};

extern USART2_AsyncStreamOut usart2_asyncStreamOut;
#endif
