#include <usart_stream_in.h>

UsartStreamIn::UsartStreamIn()
{

}

u8t UsartStreamIn::receive() {
	return  usart->receive();
}
