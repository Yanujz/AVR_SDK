#pragma once
#include <core.h>
#include <async_stream_in.h>
#include <hardware_usart.h>
class UsartAsyncStreamIn : public AsyncStreamIn
{
public:
  void setOnRxCallback(SystemEventHandler* context) override;
  u8 pop_rx_fifo() override;
  void reset_rx_fifo() override;
  int get_rx_fifo_unread_element() override;
  bool is_rx_fifo_empty() override;

protected:
  UsartAsyncStreamIn();
  AsyncUsart* asyncUsart;
};

