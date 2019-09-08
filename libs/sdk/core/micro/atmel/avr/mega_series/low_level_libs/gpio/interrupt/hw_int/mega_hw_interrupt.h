#pragma once
#include <core.h>
#if defined (__MEGA_SERIES__)
#include <common_typedef.h>
#include <avr/interrupt.h>
#include <sys_event_handler.h>

using namespace core::IO;

struct HW_INT_ISR : public SystemEventHandler::SYS_EVENT
{
    int_cb_t* user_cb;
};


void hw_int_common_attach(HW_INT pin, INT_EDGE & edge);

void attachInterrupt(HW_INT pin, INT_EDGE edge, int_cb_t *func);
void attachInterrupt(HW_INT pin, INT_EDGE edge, SystemEventHandler *context);
void attachInterruptMulti(u8t hw_int, u16t sense, int_cb_t *func);

void deatchInterrupt(HW_INT pin);





#endif
