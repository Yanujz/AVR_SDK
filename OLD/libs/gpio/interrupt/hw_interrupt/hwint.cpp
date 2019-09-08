#include "hwint.h"


bool HwInt::attachInterrupt(uint8_t pin, INT_EDGE edge, int_cb_t *func)
{
	u8t index = _pinToInterrupt(pin);
	if(index == 255){
		return false;
	}
	__hw_event_isr[index].user_cb_vect = func;
	u8t _edge = 0;
	if(index > 3){
		_edge =  (edge << ((2*index) - 8));
	}
	else {
		_edge = edge << (2*index);
	}
#if defined(__AVR_ATmega640__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
	if(pin == 2 || pin == 3){
		EICRB |= _edge;
	}
	else {
		EICRA |= _edge;
	}
#endif
#if defined(__AVR_ATmega48p__) ||  defined(__AVR_ATmega88P__) || defined(__AVR_ATmega328P__)
	EICRA |= _edge;
#endif
	EIMSK |=  bitValue(index);

	sei();
	return true;
}

bool HwInt::attachInterrupt(uint8_t pin, INT_EDGE edge, SystemEventHandler *func)
{
	u8t index = _pinToInterrupt(pin);
	if(index == 255){
		return false;
	}
	__hw_event_isr[index].sys_cb_vect = func;
	u8t _edge = 0;
	if(index > 3){
		_edge =  (edge << ((2*index) - 8));
	}
	else {
		_edge = edge << (2*index);
	}
#if defined(__AVR_ATmega640__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
	if(pin == 2 || pin == 3){
		EICRB |= _edge;
	}
	else {
		EICRA |= _edge;
	}
	EIMSK |=  bitValue(index);
#endif

	sei();
	return true;
}

void HwInt::deatchInterrupt(u8t pin)
{
	EIMSK  &= ~bitValue(_pinToInterrupt(pin));
}

u8t HwInt::_pinToInterrupt(u8t &  pin)
{
	u8t index = 0;
	for( ; index < SIZE_OF_ARRAY(__hw_int_mappedPin); ++index){
		if(pin == pgm_read_byte(&__hw_int_mappedPin[index])){
			break;
		}
		if(pgm_read_byte(&__hw_int_mappedPin[index]) == 255){
			return 255;
		}
	}
	return index;
}


//-----------HW INTERRUPT------------//
#ifdef INT0_vect
ISR(INT0_vect){
	cli();
	if(__hw_event_isr[0].user_cb_vect != nullptr){
		((void(*)(u8t))__hw_event_isr[0].user_cb_vect)(__hw_int_mappedPin[0]);
	}
	else if(__hw_event_isr[0].sys_cb_vect != nullptr) {
		SystemEventHandler::call_int_callback(__hw_event_isr[0].sys_cb_vect, __hw_int_mappedPin[0]);
	}
	sei();
}
#endif
#ifdef INT1_vect
ISR(INT1_vect){
	cli();
	if(__hw_event_isr[1].user_cb_vect != nullptr){
		((void(*)(u8t))__hw_event_isr[1].user_cb_vect)(__hw_int_mappedPin[1]);
	}
	else if(__hw_event_isr[1].sys_cb_vect != nullptr) {
		SystemEventHandler::call_int_callback(__hw_event_isr[1].sys_cb_vect, __hw_int_mappedPin[1]);
	}
	sei();
}
#endif
#ifdef INT2_vect
ISR(INT2_vect){
	cli();
	if(__hw_event_isr[2].user_cb_vect != nullptr){
		((void(*)(u8t))__hw_event_isr[2].user_cb_vect)(__hw_int_mappedPin[2]);
	}
	else if(__hw_event_isr[2].sys_cb_vect != nullptr) {
		SystemEventHandler::call_int_callback(__hw_event_isr[2].sys_cb_vect, __hw_int_mappedPin[2]);
	}
	sei();
}
#endif
#ifdef INT3_vect
ISR(INT3_vect){
	cli();
	if(__hw_event_isr[3].user_cb_vect != nullptr){
		((void(*)(u8t))__hw_event_isr[3].user_cb_vect)(__hw_int_mappedPin[3]);
	}
	else if(__hw_event_isr[3].sys_cb_vect != nullptr) {
		SystemEventHandler::call_int_callback(__hw_event_isr[3].sys_cb_vect, __hw_int_mappedPin[3]);
	}
	sei();
}
#endif
#ifdef INT4_vect
ISR(INT4_vect){
	cli();
	if(__hw_event_isr[4].user_cb_vect != nullptr){
		((void(*)(u8t))__hw_event_isr[4].user_cb_vect)(__hw_int_mappedPin[4]);
	}
	else if(__hw_event_isr[4].sys_cb_vect != nullptr) {
		SystemEventHandler::call_int_callback(__hw_event_isr[4].sys_cb_vect, __hw_int_mappedPin[4]);
	}
	sei();
}
#endif
#ifdef INT5_vect
ISR(INT5_vect){
	cli();
	if(__hw_event_isr[5].user_cb_vect != nullptr){
		((void(*)(u8t))__hw_event_isr[5].user_cb_vect)(__hw_int_mappedPin[5]);
	}
	else if(__hw_event_isr[5].sys_cb_vect != nullptr) {
		SystemEventHandler::call_int_callback(__hw_event_isr[5].sys_cb_vect, __hw_int_mappedPin[5]);
	}
	sei();
}
#endif
#ifdef INT6_vect
ISR(INT6_vect){
	cli();
	if(__hw_event_isr[6].user_cb_vect != nullptr){
		((void(*)(u8t))__hw_event_isr[6].user_cb_vect)(__hw_int_mappedPin[6]);
	}
	else if(__hw_event_isr[6].sys_cb_vect != nullptr) {
		SystemEventHandler::call_int_callback(__hw_event_isr[6].sys_cb_vect, __hw_int_mappedPin[6]);
	}
	sei();
}
#endif
#ifdef INT7_vect
ISR(INT7_vect){
	cli();
	if(__hw_event_isr[7].user_cb_vect != nullptr){
		((void(*)(u8t))__hw_event_isr[7].user_cb_vect)(__hw_int_mappedPin[7]);
	}
	else if(__hw_event_isr[7].sys_cb_vect != nullptr) {
		SystemEventHandler::call_int_callback(__hw_event_isr[7].sys_cb_vect, __hw_int_mappedPin[7]);
	}
	sei();
}
#endif
