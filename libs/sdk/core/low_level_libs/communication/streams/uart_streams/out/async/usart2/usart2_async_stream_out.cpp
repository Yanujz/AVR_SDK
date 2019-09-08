#include <core.h>
#if defined (__USART2_SUPPORT__)
#include <usart2_async_stream_out.h>
USART2_AsyncStreamOut usart2_asyncStreamOut;

USART2_AsyncStreamOut::USART2_AsyncStreamOut()
{
  UsartAsyncStreamOut::asyncUsart = &asyncUsart2;
}

#endif
