#pragma once
#include <core.h>
#include <stdarg.h>
class StreamOut {
public:
    virtual void send(char c) = 0;
    virtual void send(const char* str) = 0;
    virtual void printf(const char* fmt, va_list arg) = 0;

};
