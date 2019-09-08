#include <core.h>
#if defined (__USART3_SUPPORT__)
#include <usart3_async_stream_in.h>
USART3_AsyncStreamIn usart3_asyncStreamIn;

USART3_AsyncStreamIn::USART3_AsyncStreamIn()
{
  UsartAsyncStreamIn::asyncUsart = &asyncUsart3;
}

#endif
