#include <core.h>
#if defined (__USART3_SUPPORT__)
#include <usart3_async_stream_out.h>
USART3_AsyncStreamOut usart3_asyncStreamOut;

USART3_AsyncStreamOut::USART3_AsyncStreamOut()
{
  UsartAsyncStreamOut::asyncUsart = &asyncUsart3;
}

#endif
