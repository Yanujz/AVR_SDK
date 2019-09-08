#pragma once
#include <core.h>
#if defined (__USART1_SUPPORT__)
#include <stream_in.h>
#include <mega_hw_usart1_sync.h>
class USART1_StreamIn : public StreamIn
{
public:
    USART1_StreamIn();
    u8t receive() override;
private:
    Usart1 *ptr;
};

extern USART1_StreamIn usart1_streamIn;
#endif
