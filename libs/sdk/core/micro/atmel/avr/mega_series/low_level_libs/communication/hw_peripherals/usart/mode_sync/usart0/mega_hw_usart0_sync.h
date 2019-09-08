#pragma once
#include <core.h>
#if defined (__MEGA_SERIES_USART0_SUPPORT__)
#include <mega_hw_usart_sync.h>

class Usart0 : public Usart {
public:
    Usart0();
    void begin(HW_UART baud) override;
};

extern Usart0 usart0;
#endif
