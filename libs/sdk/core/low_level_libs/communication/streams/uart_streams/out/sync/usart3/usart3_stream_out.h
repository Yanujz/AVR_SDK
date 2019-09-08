#pragma once
#include <core.h>
#if defined (__USART3_SUPPORT__)
#include <usart_stream_out.h>
#include <mega_hw_usart3_sync.h>
class USART3_StreamOut : public UsartStreamOut
{
public:
	USART3_StreamOut();
	USART3_StreamOut(HW_UART baud);

};
extern USART3_StreamOut usart3_streamOut;
#endif
