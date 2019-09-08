#include <console.h>

ConsoleOut::ConsoleOut(){
  this->streamOut = streamOut;
}

void ConsoleOut::send(char c)
{
  streamOut->send(c);
}

void ConsoleOut::send(const char *str){
  streamOut->send(str);
}

void ConsoleOut::send(u8t *buff, int size){
  while (size--) {
	streamOut->send(*buff++);
  }
}

void ConsoleOut::printf(const char *fmt, ...){
  va_list arg;
  va_start(arg, fmt);
  streamOut->printf(fmt, arg);
  va_end(arg);
}

void ConsoleOut::setStreamOut(StreamOut *streamOut){
  this->streamOut = streamOut;
}

ConsoleOut consoleOut;
ConsoleIn consoleIn;


Console::Console(StreamIn* in, StreamOut* out)
{
  this->in = &consoleIn;
  this->out = &consoleOut;
  this->in->setStreamIn(in);
  this->out->setStreamOut(out);
}

void Console::setEcho(bool value)
{
  echoServer = value;
}

void Console::setTerminatorChar(u8t chr)
{
  endRowChar = chr;
}

void Console::callback(u8t byte)
{
  if(echoServer){
	out->send(byte);
	if(byte == endRowChar){
	  out->send("\r\nFine riga\r\n");
	}
  }
}

ConsoleIn::ConsoleIn()
{
  this->streamIn = streamIn;
}

u8t ConsoleIn::receive()
{
  return streamIn->receive();
}

void ConsoleIn::setStreamIn(StreamIn *streamIn)
{
  this->streamIn = streamIn;
}
