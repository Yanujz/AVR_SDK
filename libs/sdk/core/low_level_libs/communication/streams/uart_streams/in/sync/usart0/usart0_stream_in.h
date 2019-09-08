#pragma once
#include <core.h>
#if defined (__USART0_SUPPORT__)
#include <usart_stream_in.h>
#include <mega_hw_usart0_sync.h>
class USART0_StreamIn : public UsartStreamIn
{
public:
	USART0_StreamIn();
	USART0_StreamIn(HW_UART baud);
};

extern USART0_StreamIn usart0_streamIn;
#endif
