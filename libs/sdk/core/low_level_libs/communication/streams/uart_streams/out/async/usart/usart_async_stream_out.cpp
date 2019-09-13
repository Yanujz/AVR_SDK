#include <usart_async_stream_out.h>

void UsartAsyncStreamOut::setOnTxCallback(SystemEventHandler *context)
{
	asyncUsart->setOnTxCompleteCallback (context);
}

void UsartAsyncStreamOut::push_tx_fifo(u8t *value, int size, bool startOnFinish)
{
	asyncUsart->push_tx_fifo (value, size, startOnFinish);
}

void UsartAsyncStreamOut::reset_tx_fifo()
{
	asyncUsart->reset_tx_fifo ();
}

int UsartAsyncStreamOut::get_tx_fifo_unread_element()
{
	return  asyncUsart->get_tx_fifo_unread_element ();
}

bool UsartAsyncStreamOut::is_tx_fifo_empty()
{
	return asyncUsart->is_tx_fifo_empty ();
}

void UsartAsyncStreamOut::startAsyncSend()
{
	asyncUsart->startAsyncSend ();
}

UsartAsyncStreamOut::UsartAsyncStreamOut()
{

}

void UsartAsyncStreamOut::sendSync(core::u8 byte)
{
	asyncUsart->sendSync(byte);
}

void UsartAsyncStreamOut::sendSync(u8 *byte, int size)
{
	asyncUsart->sendSync(byte, size);
}
