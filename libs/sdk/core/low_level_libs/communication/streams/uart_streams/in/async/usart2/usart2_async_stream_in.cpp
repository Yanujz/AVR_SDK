#include <core.h>
#if defined (__USART2_SUPPORT__)
#include <usart2_async_stream_in.h>
USART2_AsyncStreamIn usart2_asyncStreamIn;

USART2_AsyncStreamIn::USART2_AsyncStreamIn()
{
  UsartAsyncStreamIn::asyncUsart = &asyncUsart2;
}

#endif
