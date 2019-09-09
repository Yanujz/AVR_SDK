#pragma once
#include <core.h>
#if defined (__MEGA_SERIES__)
#include <stdarg.h>
#include <mega_usart_vfprintf.h>
#include <mega_hw_usart_sync_low_size.h>
using namespace core::mega::uart;



class Usart
{
public:
    virtual void begin(HW_UART baud) = 0;
    void end();
    void printf(const char *fmt, ...);
    void printf(const char *fmt, va_list arg);
    void print(const char* str);
    void print(char c);
    void write(const char* buff, int size);
    void readUntil(char *buff, int size, char chr);
    void flush();
    bool isAvailable();
    char receive();
protected:
    Usart();
    void init(HW_UART baud);

    volatile u8t* UCSRxA;
};

#endif
