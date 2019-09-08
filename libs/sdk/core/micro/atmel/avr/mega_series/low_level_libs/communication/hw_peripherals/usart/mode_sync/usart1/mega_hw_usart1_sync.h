#pragma once
#include <core.h>
#if defined (__MEGA_SERIES_USART1_SUPPORT__)
#include <mega_hw_usart_sync.h>

class Usart1 : public Usart {
public:
    Usart1();
    void begin(HW_UART baud) override;
};
extern Usart1 usart1;
#endif
