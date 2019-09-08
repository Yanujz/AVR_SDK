#pragma once
#include <core.h>
#if defined (__MEGA_SERIES_USART1_SUPPORT__)
#include <mega_hw_usart_async.h>
#include <mega_hw_usart1_sync.h>

class AsyncUsart1 : public AsyncUsart
{
public:
    AsyncUsart1();
    using AsyncUsart::begin;
private:
    void begin(HW_UART baud) override;
};
extern AsyncUsart1 asyncUsart1;
#endif
