#pragma once
#include <core.h>
#if defined (__USART3_SUPPORT__)
#include <usart_stream_in.h>
#include <mega_hw_usart3_sync.h>
class USART3_StreamIn : public UsartStreamIn
{
public:
	USART3_StreamIn();
	USART3_StreamIn(HW_UART baud);
};

extern USART3_StreamIn usart3_streamIn;
#endif
