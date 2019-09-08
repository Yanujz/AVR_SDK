#pragma once
#include <core.h>
#if defined (__USART3_SUPPORT__)
#include <usart_async_stream_out.h>
#include <hardware_usart.h>

class USART3_AsyncStreamOut : public UsartAsyncStreamOut
{
public:
  USART3_AsyncStreamOut();
  using UsartAsyncStreamOut::setOnTxCallback;
};

extern USART3_AsyncStreamOut usart3_asyncStreamOut;
#endif
