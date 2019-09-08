#include <core.h>
#if defined (__USART0_SUPPORT__)
#include <usart0_async_stream_out.h>
USART0_AsyncStreamOut usart0_asyncStreamOut;

USART0_AsyncStreamOut::USART0_AsyncStreamOut()
{
  UsartAsyncStreamOut::asyncUsart = &asyncUsart0;
}

#endif
