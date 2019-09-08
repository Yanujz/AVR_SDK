#pragma once
#include <core.h>
#include <streams.h>
#include <sys_event_handler.h>
class ConsoleIn
{
public:
    ConsoleIn();
    u8t receive();
    void setStreamIn(StreamIn* streamIn);
private:
    StreamIn* streamIn;
};

class ConsoleOut
{
public:
    ConsoleOut();
    void send(char c);
    void send(const char *str);
    void send(u8t *buff, int size);
    void printf(const char* fmt, ...);
    void setStreamOut(StreamOut* streamOut);
private:
    StreamOut* streamOut;
};

class Console : public SystemEventHandler {
public:
    Console(StreamIn *in, StreamOut *out);
    void setEcho(bool value);
    void setTerminatorChar(u8t chr);
    ConsoleOut* out;
    ConsoleIn* in;

private:
    u8t endRowChar = 0;
	bool echoServer = false;
    void callback(u8t byte) override;
};

