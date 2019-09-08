#pragma once
#include <core.h>
#if defined (__USART0_SUPPORT__)
#include <usart_async_stream_out.h>
#include <hardware_usart.h>

class USART0_AsyncStreamOut : public UsartAsyncStreamOut
{
public:
  USART0_AsyncStreamOut();
  using UsartAsyncStreamOut::setOnTxCallback;
};

extern USART0_AsyncStreamOut usart0_asyncStreamOut;
#endif
