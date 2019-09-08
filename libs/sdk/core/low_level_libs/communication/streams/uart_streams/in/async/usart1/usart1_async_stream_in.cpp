#include <core.h>
#if defined (__USART1_SUPPORT__)
#include <usart1_async_stream_in.h>
USART1_AsyncStreamIn usart1_asyncStreamIn;

USART1_AsyncStreamIn::USART1_AsyncStreamIn()
{
  UsartAsyncStreamIn::asyncUsart = &asyncUsart1;
}

#endif
