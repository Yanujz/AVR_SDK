#pragma once
#include <common_macros.h>

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

private:
};

