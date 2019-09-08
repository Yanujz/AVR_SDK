#pragma once
#include <core.h>
#if defined (__MEGA_SERIES_USART2_SUPPORT__)
#include <mega_hw_usart_sync.h>

class Usart2 : public Usart {
public:
    Usart2();
    void begin(HW_UART baud) override;
};
extern Usart2 usart2;
#endif
