#pragma once
#include <stream_in.h>
#include <hardware_usart.h>
class UsartStreamIn : public StreamIn
{
public:
  u8t receive() override;


protected:
  Usart* usart;
  UsartStreamIn();
};
