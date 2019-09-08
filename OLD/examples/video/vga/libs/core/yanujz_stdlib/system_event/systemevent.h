#pragma once
#include <macros.h>

class SystemEventHandler
{
public:
	struct SYS_EVENT
	{
		SystemEventHandler* context;
	};

	SystemEventHandler();
	static void call_int_callback(SystemEventHandler *context, u8t byte = 0);
	virtual void callback(u8t byte) = 0;
protected:

};


//class NetworkEvent : public SystemEventHandler
//{
//public:
//	//NetworkEvent : public SystemEvent() {}
//};
