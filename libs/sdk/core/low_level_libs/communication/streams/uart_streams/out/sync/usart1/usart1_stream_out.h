#pragma once
#include <core.h>
#if defined (__USART1_SUPPORT__)
#include <usart_stream_out.h>
#include <mega_hw_usart1_sync.h>
class USART1_StreamOut : public UsartStreamOut
{
public:
	USART1_StreamOut();
	USART1_StreamOut(HW_UART baud);

};
extern USART1_StreamOut usart1_streamOut;
#endif
