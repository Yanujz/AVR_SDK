#include <sys_event_handler.h>

SystemEventHandler::SystemEventHandler()
{

}

void SystemEventHandler::call_int_callback(SystemEventHandler *context, u8t byte)
{
    context->callback(byte);
}
