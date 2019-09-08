#pragma once
#include <core.h>
#if defined (__MEGA_SERIES_USART3_SUPPORT__)
#include <mega_hw_usart_async.h>
#include <mega_hw_usart3_sync.h>

class AsyncUsart3 : public AsyncUsart
{
public:
    AsyncUsart3();
    using AsyncUsart::begin;
private:
    void begin(HW_UART baud) override;
};
extern AsyncUsart3 asyncUsart3;
#endif
