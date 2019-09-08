#include <core.h>
#if defined (__USART1_SUPPORT__)
#include <usart1_stream_in.h>

USART1_StreamIn usart1_streamIn;

USART1_StreamIn::USART1_StreamIn(){
    ptr = &usart1;
}

u8t USART1_StreamIn::receive() {
    return  ptr->receive();
}

#endif
