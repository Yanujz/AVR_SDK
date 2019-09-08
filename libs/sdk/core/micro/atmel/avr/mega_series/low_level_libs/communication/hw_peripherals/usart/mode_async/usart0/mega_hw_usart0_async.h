#pragma once
#include <core.h>
#if defined (__MEGA_SERIES_USART0_SUPPORT__)
#include <mega_hw_usart_async.h>
#include <mega_hw_usart0_sync.h>

class AsyncUsart0 : public AsyncUsart
{
public:
    AsyncUsart0();
    using AsyncUsart::begin;
private:
   void begin(HW_UART baud) override;

};
extern AsyncUsart0 asyncUsart0;
#endif
