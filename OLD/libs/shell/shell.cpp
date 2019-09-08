#include "shell.h"

Shell::Shell(AsyncSerial & serial, HW_UART baud)
{
	this->serial = &serial;
	this->serial->begin(baud);
	this->serial->setEchoServer(true);
	this->serial->registerCallback(this);
	clear();
	this->serial->print("> ");
}

void Shell::clear()
{
	serial->print("\e[1;1H\e[2J");
}

void Shell::callback(u8t byte){
	if(byte == '\r'){
		char str[32];
		u8t i = 0;
		serial->print('\n');
		int element = serial->get_rx_fifo_unread_element();
		while (element--) {
			str[i++] = serial->pop_rx_fifo();
		}
		str[i] = 0;
		serial->print(str);
		serial->reset_rx_fifo();
		serial->print("\r\n> ");
	}
}
