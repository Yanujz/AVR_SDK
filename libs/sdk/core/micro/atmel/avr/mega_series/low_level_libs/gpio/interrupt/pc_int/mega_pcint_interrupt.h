#pragma once
#include <core.h>
#if defined (__MEGA_SERIES__)
#include <common_typedef.h>
#include <avr/interrupt.h>
#include <sys_event_handler.h>

using namespace core::IO;

struct PC_INT_ISR : public SystemEventHandler::SYS_EVENT
{
    int_cb_t* user_cb;
    INT_EDGE edge;
};

void attachInterrupt(PC_INT pin, INT_EDGE edge, int_cb_t* func);
void attachInterrupt(PC_INT pin, INT_EDGE edge, SystemEventHandler *context);
void deatchInterrupt(PC_INT pin);
#endif
