#pragma once
#include <core.h>
#if defined (__USART2_SUPPORT__)
#include <usart_stream_in.h>
#include <mega_hw_usart2_sync.h>
class USART2_StreamIn : public UsartStreamIn
{
public:
	USART2_StreamIn();
	USART2_StreamIn(HW_UART baud);
};

extern USART2_StreamIn usart2_streamIn;
#endif
