#pragma once
#include <core.h>
#include <async_stream_out.h>
#include <hardware_usart.h>
class UsartAsyncStreamOut : public AsyncStreamOut
{
public:
  void setOnTxCallback(SystemEventHandler* context) override ;
  void push_tx_fifo(u8t *value, int size, bool startOnFinish = false) override;
  void reset_tx_fifo() override;
  int get_tx_fifo_unread_element() override;
  bool is_tx_fifo_empty() override;
  void startAsyncSend() override;
protected:
  UsartAsyncStreamOut();
  AsyncUsart* asyncUsart;
};

