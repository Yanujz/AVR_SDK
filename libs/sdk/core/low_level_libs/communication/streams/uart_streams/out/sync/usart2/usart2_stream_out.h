#pragma once
#include <core.h>
#if defined (__USART2_SUPPORT__)
#include <usart_stream_out.h>
#include <mega_hw_usart2_sync.h>
class USART2_StreamOut : public UsartStreamOut
{
public:
	USART2_StreamOut();
	USART2_StreamOut(HW_UART baud);

};
extern USART2_StreamOut usart2_streamOut;
#endif
