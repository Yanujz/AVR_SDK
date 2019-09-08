#pragma once
#include <core.h>
#include <stream_out.h>
#include <hardware_usart.h>
class UsartStreamOut : public StreamOut
{
public:
  void send(char c) override;
  void send(const char* str) override;
  void printf(const char* fmt, va_list arg) override;
protected:
  UsartStreamOut();
  Usart* usart;
};

