#include <core.h>
#if defined (__MEGA_SERIES__)
#include <mega_hw_interrupt.h>

static HW_INT_ISR __hw_event_isr[N_HW_INT];

void attachInterruptMulti(u8t hw_int, u16t sense, int_cb_t *func)
{
  EIMSK |= hw_int;
  EICRA |= LO8(sense);
#ifdef EICRB
  EICRB |= HI8(sense);
#endif
  for ( u8t i = 0; i < sizeof(hw_int)*8; ++i) {
	if(is_bit_on(hw_int,i)){
	  __hw_event_isr[i].user_cb = func;
	}
  }
}

void hw_int_common_attach(HW_INT pin, INT_EDGE &edge)
{
  sei();
  u8t intNumber = pinToIntNumber(pin);

  EIMSK |=  bitValue(intNumber);
  // Check page 110 of atmega2560's datasheet
  if(intNumber >= 4){
	intNumber -= 4;
  }
  if(edge == LOW_LEVEL){
	*pinToEICRx(pin) &= ~(edge << (2*intNumber));
  }
  else {
	*pinToEICRx(pin) |= (edge << (2*intNumber));
  }
}

void attachInterrupt(HW_INT pin, INT_EDGE edge, int_cb_t *func)
{
  __hw_event_isr[toU8(pin)].user_cb = func;
  hw_int_common_attach(pin, edge);
}

void attachInterrupt(HW_INT pin, INT_EDGE edge, SystemEventHandler *context)
{
  __hw_event_isr[toU8(pin)].context = context;
  hw_int_common_attach(pin, edge);
}

void deatchInterrupt(HW_INT pin)
{
  EIMSK  &= ~bitValue(toU8(pin));
}


inline void hw_int_isr_func(HW_INT_ISR *ptr, u8t pin)
{
  //u8t oldSREG = SREG;
  //cli();
  if(ptr->user_cb){
	ptr->user_cb(pin);
  }
  else if(ptr->context) {
	SystemEventHandler::call_int_callback(ptr->context, pin);
  }
  //SREG = oldSREG;
}

//-----------HW INTERRUPT------------//


#ifdef __MEGA_SERIES_INT0_SUPPORT__
ISR(INT0_vect)
{
  hw_int_isr_func(&__hw_event_isr[0], HW_INT0_MAPPED_PIN);
}
#endif

#ifdef __MEGA_SERIES_INT1_SUPPORT__
ISR(INT1_vect)
{
  hw_int_isr_func(&__hw_event_isr[1], HW_INT1_MAPPED_PIN);
}
#endif

#ifdef __MEGA_SERIES_INT2_SUPPORT__
ISR(INT2_vect)
{
  hw_int_isr_func(&__hw_event_isr[2], HW_INT2_MAPPED_PIN);
}
#endif

#ifdef __MEGA_SERIES_INT3_SUPPORT__
ISR(INT3_vect)
{
  hw_int_isr_func(&__hw_event_isr[3], HW_INT3_MAPPED_PIN);
}
#endif

#ifdef __MEGA_SERIES_INT4_SUPPORT__
ISR(INT4_vect)
{
  hw_int_isr_func(&__hw_event_isr[4], HW_INT4_MAPPED_PIN);
}
#endif

#ifdef __MEGA_SERIES_INT5_SUPPORT__
ISR(INT5_vect)
{
  hw_int_isr_func(&__hw_event_isr[5], HW_INT5_MAPPED_PIN);
}
#endif

#ifdef __MEGA_SERIES_INT6_SUPPORT__
ISR(INT6_vect)
{
  hw_int_isr_func(&__hw_event_isr[6], HW_INT6_MAPPED_PIN);
}
#endif

#ifdef __MEGA_SERIES_INT7_SUPPORT__
ISR(INT7_vect)
{
  hw_int_isr_func(&__hw_event_isr[7], HW_INT7_MAPPED_PIN);
}
#endif


#endif
