#pragma once
#include <core.h>
#if defined (__MEGA_SERIES_USART2_SUPPORT__)
#include <mega_hw_usart_async.h>
#include <mega_hw_usart2_sync.h>

class AsyncUsart2 : public AsyncUsart
{
public:
    AsyncUsart2();
    using AsyncUsart::begin;
private:
    void begin(HW_UART baud) override;
};
extern AsyncUsart2 asyncUsart2;
#endif
