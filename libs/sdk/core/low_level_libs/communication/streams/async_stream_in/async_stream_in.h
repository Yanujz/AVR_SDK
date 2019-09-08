#pragma once
#include <core.h>
#include <stream_in.h>
#include <sys_event_handler.h>

class AsyncStreamIn
{
public:
  virtual void setOnRxCallback(SystemEventHandler* context) = 0;
  virtual u8 pop_rx_fifo() = 0;
  virtual void reset_rx_fifo() = 0;
  virtual int get_rx_fifo_unread_element() = 0;
  virtual bool is_rx_fifo_empty() = 0;
};
