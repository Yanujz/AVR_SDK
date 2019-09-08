#pragma once
#include <core.h>
#if defined (__USART0_SUPPORT__)
#include <usart_stream_out.h>
#include <mega_hw_usart0_sync.h>
class USART0_StreamOut : public UsartStreamOut
{
public:
	USART0_StreamOut();
	USART0_StreamOut(HW_UART baud);

};
extern USART0_StreamOut usart0_streamOut;
#endif
