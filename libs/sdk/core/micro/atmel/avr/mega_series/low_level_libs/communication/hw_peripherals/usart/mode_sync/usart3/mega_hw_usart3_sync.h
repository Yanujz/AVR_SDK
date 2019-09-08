#pragma once
#include <core.h>
#if defined (__MEGA_SERIES_USART3_SUPPORT__)
#include <mega_hw_usart_sync.h>

class Usart3 : public Usart {
public:
    Usart3();
    void begin(HW_UART baud) override;
};
extern Usart3 usart3;
#endif
