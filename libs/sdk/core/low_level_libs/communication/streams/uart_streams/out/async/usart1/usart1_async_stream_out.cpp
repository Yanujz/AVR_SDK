#include <core.h>
#if defined (__USART1_SUPPORT__)
#include <usart1_async_stream_out.h>
USART1_AsyncStreamOut usart1_asyncStreamOut;

USART1_AsyncStreamOut::USART1_AsyncStreamOut()
{
  UsartAsyncStreamOut::asyncUsart = &asyncUsart1;
}

#endif
