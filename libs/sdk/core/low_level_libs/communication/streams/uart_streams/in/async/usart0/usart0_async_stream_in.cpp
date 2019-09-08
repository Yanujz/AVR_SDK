#include <core.h>
#if defined (__USART0_SUPPORT__)
#include <usart0_async_stream_in.h>
USART0_AsyncStreamIn usart0_asyncStreamIn;

USART0_AsyncStreamIn::USART0_AsyncStreamIn()
{
  UsartAsyncStreamIn::asyncUsart = &asyncUsart0;
}

#endif
