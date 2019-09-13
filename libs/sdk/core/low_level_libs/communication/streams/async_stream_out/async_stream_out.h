#pragma once
#include <core.h>
#include <stream_out.h>
#include <sys_event_handler.h>

class AsyncStreamOut
{
public:
	virtual void setOnTxCallback(SystemEventHandler* context) = 0;
	virtual void push_tx_fifo(u8t *value, int size, bool startOnFinish = false) = 0;
	virtual void reset_tx_fifo() = 0;
	virtual int get_tx_fifo_unread_element() = 0;
	virtual bool is_tx_fifo_empty() = 0;
	virtual void startAsyncSend() = 0;
	virtual void sendSync(u8 byte) = 0;
	virtual void sendSync(u8* byte, int size) = 0;

};
