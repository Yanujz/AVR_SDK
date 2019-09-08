#include "interrupt.h"
/*
INT_REG_CALLBACK Interrupt::interruptCallback;//(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
bool Interrupt::attachInterrupt(uint8_t pin, INT_EDGE edge, int_cb_t *func)
{


	PCINT_PIN _pin;
	HW_INT_PIN _pinHW;
	uint8_t _hw_edge;
	switch (Interrupt::searchPin(pin,&_pin,&_pinHW)) {
	case INT_PIN_RES::NOT_FOUND:
		break;
	case INT_PIN_RES::_PCINT:

		switch (_pin.PCINTx_vect) {
		case _PCINT0_vect:
			//PCICR  |= _BV(PCIE0);+
			//PCMSK0 |= _BV(_pin.PCINTx);
			bitSet(PCICR, PCIE0);
			bitSet(PCMSK0, _pin.PCINTx);
			break;
		case _PCINT1_vect:
			//PCICR  |= _BV(PCIE1);
			//PCMSK1 |= _BV(_pin.PCINTx);
			bitSet(PCICR, PCIE1);
			bitSet(PCMSK1, _pin.PCINTx);
			break;
		case _PCINT2_vect:
			//PCICR  |= _BV(PCIE2);
			//PCMSK2 |= _BV(_pin.PCINTx);
			bitSet(PCICR, PCIE2);
			bitSet(PCMSK2, _pin.PCINTx);
			break;
		}
		*_pin.interruptCallback = func;
		*_pin.px_edge = edge;
		sei();
		return true;

	case INT_PIN_RES::_INT:
		cli();
		switch (edge) {
		case INT_EDGE::LOW_LEVEL:
			_hw_edge = (uint8_t)_pinHW.lowLevel;
			break;
		case INT_EDGE::ANYEDGE:
			_hw_edge = (uint8_t)_pinHW.anyEdge;
			break;
		case INT_EDGE::FALLING:
			_hw_edge = (uint8_t)_pinHW.falling;
			break;
		case INT_EDGE::RISING:
			_hw_edge = (uint8_t)_pinHW.rising;
			break;
		}
		switch (_pinHW.EICRx) {
#if defined (__AVR_ATmega328P__) || defined(__AVR_ATmega640__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
		case 0:
			EICRA |= _hw_edge;
			break;
#endif
#if defined(__AVR_ATmega640__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
		case 1:
			EICRB |= _hw_edge;
			break;
#endif
		}
		EIMSK |= (1<<_pinHW.bitField);
		*_pinHW.interruptCallback = func;
		*_pinHW.px_edge = (INT_EDGE)_hw_edge;
		sei();
		return true;

	}
	if( edge == NEGATIVE_EDGE){
		*((volatile uint8_t*)pgm_read_word(&__flashMappedPort[pin].pinx) + 2 ) |=
				(1 << (pgm_read_byte( &__flashMappedPort[pin].registerBit)));
	}

	return false;
}

bool Interrupt::attachInterrupt(uint8_t pin, INT_EDGE edge, SystemEventHandler* ptr)
{

}

bool Interrupt::deatchInterrupt(uint8_t pin)
{
	PCINT_PIN _pin;
	HW_INT_PIN _pinHW;
	bool result = false;
	switch (Interrupt::searchPin(pin, &_pin, &_pinHW)) {

	case INT_PIN_RES::_PCINT:
		switch (_pin.PCINTx_vect) {
		case _PCINT0_vect:
			PCMSK0 &=  ~_BV(_pin.PCINTx);
			result = ((PCMSK0 & _BV(_pin.PCINTx))& 0xFF) == 0;
			break;
		case _PCINT1_vect:
			PCMSK1 &=  ~_BV(_pin.PCINTx);
			result = ((PCMSK1 & _BV(_pin.PCINTx))& 0xFF) == 0;
			break;
		case _PCINT2_vect:
			PCMSK2 &=  ~_BV(_pin.PCINTx);
			result = ((PCMSK2 & _BV(_pin.PCINTx) )& 0xFF) == 0;
			break;
		}
	case INT_PIN_RES::_INT:
		EIMSK &= ~(1<<_pinHW.bitField);
		result = ((EIMSK & _BV(_pinHW.bitField) )& 0xFF) == 0;
		break;

	case INT_PIN_RES::NOT_FOUND:
		break;
	}
	return result;

}
*/
////---------PCINT DATABASE---------//
//PCINT_PIN pcint_vect[]{
//	/*00*/{ 0, 1,  PCINT8, &Interrupt::interruptCallback.pe0, &Interrupt::interruptCallback.pe0_edge},// Not working
//	/*01*/{ 1, 0,  PCINT3, &Interrupt::interruptCallback.pe1, &Interrupt::interruptCallback.pe1_edge},// Not working
//	/*02*/{ 6, 1,  PCINT8, &Interrupt::interruptCallback.ph3, &Interrupt::interruptCallback.ph3_edge},// Not working
//	/*03*/{10, 0,  PCINT4, &Interrupt::interruptCallback.pb4, &Interrupt::interruptCallback.pb4_edge},
//	/*04*/{11, 0,  PCINT5, &Interrupt::interruptCallback.pb5, &Interrupt::interruptCallback.pb5_edge},
//	/*05*/{12, 0,  PCINT6, &Interrupt::interruptCallback.pb6, &Interrupt::interruptCallback.pb6_edge},
//	/*06*/{13, 0,  PCINT7, &Interrupt::interruptCallback.pb7, &Interrupt::interruptCallback.pb7_edge},
//	/*07*/{14, 1, PCINT10, &Interrupt::interruptCallback.pj1, &Interrupt::interruptCallback.pj1_edge},
//	/*08*/{15, 1,  PCINT9, &Interrupt::interruptCallback.pj0, &Interrupt::interruptCallback.pj0_edge},
//	/*09*/{50, 0,  PCINT3, &Interrupt::interruptCallback.pb3, &Interrupt::interruptCallback.pb3_edge},
//	/*10*/{51, 0,  PCINT2, &Interrupt::interruptCallback.pb2, &Interrupt::interruptCallback.pb2_edge},
//	/*11*/{52, 0,  PCINT1, &Interrupt::interruptCallback.pb1, &Interrupt::interruptCallback.pb1_edge},
//	/*12*/{53, 0,  PCINT0, &Interrupt::interruptCallback.pb0, &Interrupt::interruptCallback.pb0_edge},
//	/*13*/{62, 2, PCINT16, &Interrupt::interruptCallback.pk0, &Interrupt::interruptCallback.pk0_edge},
//	/*14*/{63, 2, PCINT17, &Interrupt::interruptCallback.pk1, &Interrupt::interruptCallback.pk1_edge},
//	/*15*/{64, 2, PCINT18, &Interrupt::interruptCallback.pk2, &Interrupt::interruptCallback.pk2_edge},
//	/*16*/{65, 2, PCINT19, &Interrupt::interruptCallback.pk3, &Interrupt::interruptCallback.pk3_edge},
//	/*17*/{66, 2, PCINT20, &Interrupt::interruptCallback.pk4, &Interrupt::interruptCallback.pk4_edge},
//	/*18*/{67, 2, PCINT21, &Interrupt::interruptCallback.pk5, &Interrupt::interruptCallback.pk5_edge},
//	/*19*/{68, 2, PCINT22, &Interrupt::interruptCallback.pk6, &Interrupt::interruptCallback.pk6_edge},
//	/*20*/{69, 2, PCINT23, &Interrupt::interruptCallback.pk7, &Interrupt::interruptCallback.pk7_edge}
//
//};
//PCINT_PIN vectB[] = {pcint_vect[12], pcint_vect[11], pcint_vect[10], pcint_vect[9], pcint_vect[3], pcint_vect[4], pcint_vect[5], pcint_vect[6]};
//PCINT_PIN vectK[] = {pcint_vect[13], pcint_vect[14], pcint_vect[15], pcint_vect[16], pcint_vect[17], pcint_vect[18], pcint_vect[19], pcint_vect[20]};
//PCINT_PIN vectJ[] = {pcint_vect[8], pcint_vect[7]};
//---------END PCINT DATABASE---------//

//HW_INT_PIN int_vect[] = {
//	{ 2, 1, &Interrupt::interruptCallback.pe4, &Interrupt::interruptCallback.pe4_edge, INT4_LOW_LEVEL, INT4_ANY_EDGE, INT4_FALLING_EDGE, INT4_RISING_EDGE, 4},
//	{ 3, 1, &Interrupt::interruptCallback.pe5, &Interrupt::interruptCallback.pe5_edge, INT5_LOW_LEVEL, INT5_ANY_EDGE, INT5_FALLING_EDGE, INT5_RISING_EDGE, 5},
//	{18, 0, &Interrupt::interruptCallback.pd3, &Interrupt::interruptCallback.pd3_edge, INT3_LOW_LEVEL, INT3_ANY_EDGE, INT3_FALLING_EDGE, INT3_RISING_EDGE, 3},
//	{19, 0, &Interrupt::interruptCallback.pd2, &Interrupt::interruptCallback.pd2_edge, INT2_LOW_LEVEL, INT2_ANY_EDGE, INT2_FALLING_EDGE, INT2_RISING_EDGE, 2},
//	{20, 0, &Interrupt::interruptCallback.pd1, &Interrupt::interruptCallback.pd1_edge, INT1_LOW_LEVEL, INT1_ANY_EDGE, INT1_FALLING_EDGE, INT1_RISING_EDGE, 1},
//	{21, 0, &Interrupt::interruptCallback.pd0, &Interrupt::interruptCallback.pd0_edge, INT0_LOW_LEVEL, INT0_ANY_EDGE, INT0_FALLING_EDGE, INT0_RISING_EDGE, 0}
//};



/*
INT_PIN_RES Interrupt::searchPin(uint8_t pin,PCINT_PIN *_pin,HW_INT_PIN *_pinHW)
{

	uint8_t middleOfVector_pc = ELEMENT_IN_ARRAY(pcint_vect)/2;
	uint8_t middleOfVector_hw = ELEMENT_IN_ARRAY(int_vect)/2;

	uint8_t hw_indexFound = 255;
	uint8_t pc_indexFound = 255;


	if(int_vect[middleOfVector_hw].mappedPin == pin){
		hw_indexFound = middleOfVector_hw;
	}
	else if(int_vect[middleOfVector_hw].mappedPin > pin){
		while (1) {
			--middleOfVector_hw;
			if(int_vect[middleOfVector_hw].mappedPin == pin){
				hw_indexFound = middleOfVector_hw;
			}
			if(middleOfVector_hw==0){
				break;
			}
		}

	}
	else {
		while (++middleOfVector_hw != ELEMENT_IN_ARRAY(int_vect)) {
			if(int_vect[middleOfVector_hw].mappedPin == pin){
				hw_indexFound = middleOfVector_hw;
			}
		}
	}

	if (hw_indexFound != 255){
		_pinHW->EICRx    = int_vect[hw_indexFound].EICRx;
		_pinHW->px_edge	 = int_vect[hw_indexFound].px_edge;
		_pinHW->lowLevel = int_vect[hw_indexFound].lowLevel;
		_pinHW->anyEdge	 = int_vect[hw_indexFound].anyEdge;
		_pinHW->falling	 = int_vect[hw_indexFound].falling;
		_pinHW->rising   = int_vect[hw_indexFound].rising;
		_pinHW->bitField = int_vect[hw_indexFound].bitField;
		_pinHW->interruptCallback = int_vect[hw_indexFound].interruptCallback;
		return INT_PIN_RES::_INT;
	}


	if(pcint_vect[middleOfVector_pc].mappedPin == pin){
		pc_indexFound = middleOfVector_pc;
	}
	else if(pcint_vect[middleOfVector_pc].mappedPin > pin){
		while (1) {
			--middleOfVector_pc;
			if(pcint_vect[middleOfVector_pc].mappedPin == pin){
				pc_indexFound = middleOfVector_pc;
			}
			if(middleOfVector_pc==0){break;}
		}

	}
	else {
		while (++middleOfVector_pc != ELEMENT_IN_ARRAY(pcint_vect)) {
			if(pcint_vect[middleOfVector_pc].mappedPin == pin){
				pc_indexFound = middleOfVector_pc;

			}
		}
	}

	if(pc_indexFound != 255){
		_pin->PCINTx_vect       = pcint_vect[pc_indexFound].PCINTx_vect;
		_pin->PCINTx            = pcint_vect[pc_indexFound].PCINTx;
		_pin->px_edge           = pcint_vect[pc_indexFound].px_edge;
		_pin->interruptCallback = pcint_vect[pc_indexFound].interruptCallback;
		return INT_PIN_RES::_PCINT;
	}



	return INT_PIN_RES::NOT_FOUND;
}
*/
/*
inline void call_int_callback(int_cb_t *f,INT_EDGE  edgeMode, volatile uint8_t *PINx,uint8_t registerBit,
																							uint8_t pin,volatile uint8_t port_x_history){
	switch (edgeMode) {
	case RISING:
		if (*PINx & (1<<registerBit)) {
			f(pin);
		}
		break;
	case FALLING:
		if ((*PINx & (1<<registerBit)) >> registerBit== 0 ) {
			f(pin);
		}
		break;
	case POSITIVE_EDGE:
		if( (*PINx  & (1<<registerBit))  && (port_x_history & (1<<registerBit)) >> registerBit == 1 ){
			f(pin);
		}
		else{
			f(pin);
		}
		break;
	case NEGATIVE_EDGE:
		if( (*PINx  & (1<<registerBit)) >> registerBit == 0 && (port_x_history & (1<<registerBit)) >> registerBit == 0){
			f(pin);
		}
		else {
			f(pin);
		}
		break;
	case ANYEDGE:
		f(pin);
		break;
	default:
		break;

	}

}

volatile uint8_t port_b_history = PINB; // start whith pulled-up pins ;
ISR(PCINT0_vect){
	volatile uint8_t changed_bits = PINB ^ port_b_history;
	port_b_history = PINB;
	uint8_t pin	= 255;
	uint8_t registerBit	= 255;
	int_cb_t *f	= nullptr;
	volatile uint8_t* PINx= nullptr;
	INT_EDGE edgeMode;

	uint8_t i;
	for(i=0; i<sizeof(changed_bits)*8; i++){
		if(is_bit_on(changed_bits,i)){
			f	 	  = *vectB[i].interruptCallback;
			pin	 	= pcint_vect[ vectB[i].interruptCallback-pcint_vect[0].interruptCallback ].mappedPin;
			PINx 	= (volatile uint8_t*)pgm_read_word(&__flashMappedPort[pin].pinx);
			edgeMode		= *vectB[i].px_edge;
			registerBit = i;
			break;
		}
	}
	if(f != nullptr){
		call_int_callback(f,edgeMode,PINx,registerBit,pin,port_b_history);
	}
}




//----------DA VERIFICARE PINH----------//
#if defined(__AVR_ATmega640__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
volatile uint8_t port_j_history = PINJ;
ISR(PCINT1_vect){
	volatile uint8_t changed_bits_j = PINJ ^ port_j_history;
	port_j_history = PINJ;
	uint8_t pin = 255;
	uint8_t registerBit = 255;
	int_cb_t *f = nullptr;
	volatile uint8_t* PINx = nullptr;
	INT_EDGE edgeMode;

	uint8_t i;
	for(i=0; i<2; i++){ //Only 2 because we're using only j0 & j1
		if(is_bit_on(changed_bits_j,i)){
			f			= *vectJ[i].interruptCallback;
			pin			= pcint_vect[ vectJ[i].interruptCallback-pcint_vect[0].interruptCallback ].mappedPin;
			PINx		= (volatile uint8_t*)pgm_read_word(&__flashMappedPort[pin].pinx);
			edgeMode		= *vectJ[i].px_edge;
			registerBit = i;
			break;
		}
	}
	if(f!=nullptr){
		call_int_callback(f,edgeMode,PINx,registerBit,pin,port_j_history);
	}
}





volatile uint8_t port_k_history = PINK; // start whith pulled-up pins ;
ISR (PCINT2_vect) {
	volatile uint8_t changed_bits  = PINK ^ port_k_history;
	port_k_history                 = PINK;
	uint8_t pin                    = 255;
	uint8_t edgeMode               = 255;
	uint8_t registerBit            = 255;
	int_cb_t *f                    = nullptr;
	volatile uint8_t* PINx         = nullptr;

	uint8_t i;
	for(i=0; i<sizeof(changed_bits)*8; i++){
		if(is_bit_on(changed_bits,i)){
			f           = *vectK[i].interruptCallback;
			pin         = pcint_vect[ vectK[i].interruptCallback-pcint_vect[0].interruptCallback ].mappedPin;
			PINx        = (volatile uint8_t*)pgm_read_word(&__flashMappedPort[pin].pinx);
			edgeMode    = *vectK[i].px_edge;
			registerBit = i;
			if(f!=nullptr){
				call_int_callback(f,(INT_EDGE)edgeMode,PINx,registerBit,pin,port_k_history);
			}
		}
	}
}
#endif












//---------END HW INTERRUPT----------//





*/
