#include <mega_pcint_interrupt.h>

static PC_INT_ISR pc_int_isr_vect[24];
static u32t pcint_edges = 0;
void _attachInterrupt(PC_INT & pin, INT_EDGE & edge){
    // Getting PCICR VALUE
    bitSet(PCICR, pinToPCICRValue(pin));

    //Getting PCMSKx && PCMSKx VALUE
    bitSet(*pinToPCMSKx(pin), pinToPCMSKxValue(pin));
    pc_int_isr_vect[pinToPCINT_num(pin)].edge = edge;
    sei();
}


void attachInterrupt(PC_INT pin, INT_EDGE edge, int_cb_t *func)
{
    pc_int_isr_vect[pinToPCINT_num(pin)].user_cb = func;
    _attachInterrupt(pin, edge);
}
void attachInterrupt(PC_INT pin, INT_EDGE edge, SystemEventHandler *context)
{
    pc_int_isr_vect[pinToPCINT_num(pin)].context = context;
    _attachInterrupt(pin, edge);
}

void deatchInterrupt(PC_INT pin)
{
    bitClear(*pinToPCMSKx(pin), pinToPCMSKxValue(pin));
}


void pcint_isr_func(volatile u8t & pinx_value, u8t & changed_bits, u8t offset){
    u8t registerBit = 0;
    bool callable = false;
    for( ; registerBit < sizeof(changed_bits)*8; ++registerBit){
	if(is_bit_on(changed_bits, registerBit)){
	    break;
	}
    }
    u8t pcint_no = registerBit+offset;
    switch (pc_int_isr_vect[pcint_no].edge) {
    case ANY_EDGE:
	callable = true;
	break;
    case RISING:
	if (pinx_value &  bitValue(registerBit)) {
	    callable = true;
	}
	break;
    case LOW_LEVEL:
    case FALLING:
	if ((pinx_value & bitValue(registerBit)) == 0 ) {
	    callable = true;
	}
	break;
    default:
	return;
    }
    if(callable){
	if(nullptr !=  pc_int_isr_vect[pcint_no].user_cb){
	    pc_int_isr_vect[pcint_no].user_cb(registerBit+offset);
	}
	else if(nullptr != pc_int_isr_vect[pcint_no].context) {
	    SystemEventHandler::call_int_callback(pc_int_isr_vect[pcint_no].context, pcint_no);
	}
    }

}


volatile u8t port_b_history = PINB;
ISR(PCINT0_vect){
    u8t changed_bits = PINB ^ port_b_history;
    port_b_history = PINB;
    pcint_isr_func(port_b_history, changed_bits, 0);
}


volatile u8t port_j_history = PINJ;
ISR(PCINT1_vect){
    u8t changed_bits = PINJ ^ port_j_history;
    port_j_history  = PINJ;
    pcint_isr_func(port_j_history, changed_bits, 9);
}


volatile u8t port_k_history = PINK;
ISR (PCINT2_vect) {
    u8t changed_bits  = PINK ^ port_k_history;
    port_k_history  = PINK;
    pcint_isr_func(port_k_history, changed_bits, 16);
}
