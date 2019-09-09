#pragma once
#include <core.h>
#if defined (__MEGA_SERIES__)
#include <stdarg.h>
#include <mega_usart_vfprintf.h>

using namespace core::mega::uart;
using namespace core::mega::common_typef;
void usart_init(USART usart, HW_UART baud);

void usart_end(USART usart);

void usart_printf(USART usart, const char *fmt, ...);

void usart_print(USART usart, const char *str);

void usart_print(USART usart, char c);

void usart_write(USART usart, const char *buff, int size);

void usart_readUntil(USART usart, char *buff, int size, char chr);

void usart_flush(USART usart);

bool usart_isAvailable(USART usart);

char usart_receive(USART usart);


#endif
