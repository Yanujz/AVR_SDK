//#include "portmanager.h"

//#define _DDRx(x) (*(x  + 1))
//#define _PORTx(x) (*(x  + 2))
/*
Pin::Pin(uint8_t portNo, DDRx direction)
{
	if(portNo > ELEMENT_IN_ARRAY(__flashMappedPort)){
		return;
	}

	_pinx	       = (volatile u8t*)pgm_read_word(&__flashMappedPort[portNo].pinx);
	//_ddrx	       = (volatile u8t*)(_pinx + 1);
	//_portx       = (volatile u8t*)(_pinx + 2);
	_registerBit = pgm_read_byte(&__flashMappedPort[portNo].registerBit);
	_controlBits = pgm_read_word(&__flashMappedPort[portNo].controlBits);
	_pinNumber	  = portNo;
	if(IS_PWM_MASK(_controlBits)){
		u8t temp = OUT_CMP_SEL_MASK(_controlBits);

		//WARNING  Timer 2 will be used into scheduler
		if(temp == 2){
			//_local_ctrl_bits = _PWM_8BIT;
			_pwm_8BIT.TCCRxA = (volatile u8t*)pgm_read_word(&__hw_timer_addr[temp]);
			_pwm_8BIT.TCCRxB = (volatile u8t*)_pwm_8BIT.TCCRxA + 1;
			_pwm_8BIT.TCNTx	 = (volatile u8t*)_pwm_8BIT.TCCRxB + 1;
		}
		else if(temp){
			//_local_ctrl_bits  = _PWM_16BIT;
			_pwm_16BIT.TCCRxA = (volatile u8t*)pgm_read_word(&__hw_timer_addr[temp]);
			_pwm_16BIT.TCCRxB = (volatile u8t*)_pwm_16BIT.TCCRxA + 1;
			_pwm_16BIT.TCCRxC = (volatile u8t*)_pwm_16BIT.TCCRxB + 1;
			_pwm_16BIT.TCNTx  = (volatile u8t*)_pwm_16BIT.TCCRxC + 2;
			_pwm_16BIT.ICRx   = (volatile u8t*)_pwm_16BIT.TCNTx  + 2;


		}
		//}
	}
	else if(IS_ADC_MASK(_controlBits)){
		//_local_ctrl_bits = _ADC; //setting ADC flag
		channel = pgm_read_word(&__adc_channels[ADC_CH_MASK(_controlBits)]);
	}
	setDirection(direction);
}
*/
/*
Pin::Pin(uint8_t portNo, DDRx direction)
{
	if(portNo > ELEMENT_IN_ARRAY(__flashMappedPort)){
		return;
	}

	_pinx	       = (volatile u8t*)pgm_read_word(&__flashMappedPort[portNo].pinx);
	//_ddrx	       = (volatile u8t*)(_pinx + 1);
	//_portx       = (volatile u8t*)(_pinx + 2);
	_registerBit = pgm_read_byte(&__flashMappedPort[portNo].registerBit);
	_controlBits = pgm_read_word(&__flashMappedPort[portNo].controlBits);
	_pinNumber	  = portNo;
	if(IS_PWM_MASK(_controlBits)){
		//u8t temp =  OUT_CMP_SEL_MASK(_controlBits);
		if(OUT_CMP_SEL_MASK(_controlBits)){
			//_TCCRxA = (volatile u8t*)__hw_timer_addr[OUT_CMP_SEL_MASK(_controlBits)];
			_TCCRxA = (volatile u8t*)pgm_read_word(&__hw_timer_addr[OUT_CMP_SEL_MASK(_controlBits)]);
		}
		////WARNING  Timer 2 will be used into scheduler
		//if(temp == 2){
		//				//_local_ctrl_bits = _PWM_8BIT;
		//				//_pwm_8BIT.TCCRxA = (volatile u8t*)*(__hw_timer_addr+temp);
		//				//_pwm_8BIT.TCCRxB = (volatile u8t*)_pwm_8KBIT.TCCRxA + 1;
		//				//_pwm_8BI                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   T.TCNTx	 = (volatile u8t*)_pwm_8BIT.TCCRxB + 1;
		//}
		//else if(temp){
		//				//_local_ctrl_bits  = _PWM_16BIT;
		//				//_pwm_16BIT.TCCRxA = (volatile u8t*)*(__hw_timer_addr+temp);
		//				//_pwm_16BIT.TCCRxB = (volatile u8t*)_pwm_16BIT.TCCRxA + 1;
		//				//_pwm_16BIT.TCCRxC = (volatile u8t*)_pwm_16BIT.TCCRxB + 1;
		//				//_pwm_16BIT.TCNTx  = (volatile u8t*)_pwm_16BIT.TCCRxC + 2;
		//				//_pwm_16BIT.ICRx   = (volatile u8t*)_pwm_16BIT.TCNTx  + 2;
		//}

	}
#if defined(__AVR_ATmega640__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
	else if(IS_ADC_MASK(_controlBits)){
		//_local_ctrl_bits = _ADC; //setting ADC flag
		channel = __adc_channels[ADC_CH_MASK(_controlBits)];
	}
#endif
	setDirection(direction);
}

Pin::~Pin()
{

}

void Pin::on()
{
	//*_portx |= bitValue(_registerBit);
	_PORTx(_pinx) |= bitValue(_registerBit);
}

void Pin::setState(bool stat)
{
	if(stat == HIGH){
		//*_portx |= bitValue(_registerBit);
		_PORTx(_pinx) |= bitValue(_registerBit);
		return;
	}
	//*_portx &= ~bitValue(_registerBit);
	_PORTx(_pinx) &= ~bitValue(_registerBit);


}

void Pin::off()
{

	//*_portx &= ~bitValue(_registerBit);
	_PORTx(_pinx) &= ~bitValue(_registerBit);
}

void Pin::toggle()
{
	//*_portx ^= bitValue(_registerBit);
	_PORTx(_pinx)  ^= bitValue(_registerBit);
}

void Pin::setDirection(DDRx direction)
{

	if(direction == OUTPUT){
		//*_ddrx |= (1 << _registerBit);
		_DDRx(_pinx) |= (1 << _registerBit);
		return;
	}
	//*_ddrx &= ~(1 <<_registerBit);
	_DDRx(_pinx)  &= ~(1 <<_registerBit);
	if(direction == INPUT_PULLUP){
		on();
	}


}
bool Pin::setPWM(uint32_t freq, uint8_t duty)
{
	//	if(_pwm_8BIT.TCCRxA == nullptr &&  _pwm_16BIT.TCCRxA == nullptr){
	//		return false;
	//	}
	//	switch (PWM_BITS_MASK(_controlBits)) {
	//	case _PWM_8BIT:
	//		_duty_pwm=(-2.55*duty) + 255;
	//		switch (PWM_LETTER_MASK(_controlBits)) {
	//		case 0:
	//			_pwm_8BIT.OCRx = (volatile u8t*)_pwm_8BIT.TCNTx + 1;
	//			*_pwm_8BIT.TCCRxA |= (1 << 7) | (1 << 6);
	//			break;
	//		case 1:
	//			_pwm_8BIT.OCRx = (volatile u8t*) _pwm_8BIT.TCNTx + 2;
	//			*_pwm_8BIT.TCCRxA |= (1 << 5) | (1 << 4);
	//			break;
	//		}
	//		*((volatile u8t*) _pwm_8BIT.TCNTx + 2) = 10;
	//		*((volatile u8t*)_pwm_8BIT.OCRx)=_duty_pwm;
	//		*_pwm_8BIT.TCCRxA |= (0 << WGM11) | (1 << WGM10);													// Setting PWM, Phase Correct
	//		*_pwm_8BIT.TCCRxB |= (0 << WGM22);																												// TOP = OCRnA TOVx Flag = BOTTOM
	//		*_pwm_8BIT.TCCRxB |= (0 << CS12) | (1 << CS11) | (0 << CS10);	// Setting prescaler to 1, so F_CPU
	//		return true;
	//
	//	case _PWM_16BIT:
	//		_freq_pwm = calculateTicks(freq);
	//		_duty_pwm = _freq_pwm-(_freq_pwm*((float)duty/100));
	//		*((volatile u16t*)_pwm_16BIT.ICRx) = _freq_pwm;
	//		switch(PWM_LETTER_MASK(_controlBits)){
	//		case 0:
	//			_pwm_16BIT.OCRx = (volatile u8t*)_pwm_16BIT.ICRx + 2;
	//			*_pwm_16BIT.TCCRxA |= (1 << 7 ) | (1 << 6) ;
	//			break;
	//		case 1:
	//			_pwm_16BIT.OCRx = (volatile u8t*)_pwm_16BIT.ICRx + 4;
	//			*_pwm_16BIT.TCCRxA |= (1 << 5) | (1 << 4) ;
	//			break;
	//		case 2:
	//			_pwm_16BIT.OCRx = (volatile u8t*)_pwm_16BIT.ICRx + 6;
	//			*_pwm_16BIT.TCCRxA |= (1 << 3) | (1 << 2) ;
	//			break;
	//		};
	//
	//		*((volatile u16t*)_pwm_16BIT.OCRx) = _duty_pwm;
	//		*_pwm_16BIT.TCCRxA  |= (1 << WGM11) | (0 << WGM10);// Setting PWM, Phase Correct
	//		*_pwm_16BIT.TCCRxB  |= (1 << WGM13) | (1 << WGM12);// TOP = OCRnA TOVx Flag = BOTTOM
	//		*_pwm_16BIT.TCCRxB  |= (0 << CS12) | (0 << CS11) | (1 << CS10); //Setting prescaler to 1, so F_CPU
	//		return true;
	//	default:
	//		return false;
	//	}
	if(_TCCRxA == nullptr){
		return false;
	}
	switch (PWM_BITS_MASK(_controlBits)) {
	case _PWM_8BIT:
		switch (PWM_LETTER_MASK(_controlBits)) {
		case 0:
			break;
		case 1:
			break;
		}


		break;
	default:
		break;
	}
}

bool Pin::setDuty(uint8_t duty)
{
	//	if(_pwm_8BIT.TCCRxA == nullptr && _pwm_16BIT.TCCRxA == nullptr){
	//		return false;
	//	}
	//
	//	switch (PWM_BITS_MASK(_controlBits)) {
	//	case _PWM_8BIT:
	//		_duty_pwm=(-2.55*duty)+255;
	//		*((volatile u8t*)_pwm_8BIT.OCRx)=_duty_pwm;
	//		break;
	//	case _PWM_16BIT:
	//		_duty_pwm=_freq_pwm-(_freq_pwm*((float)duty/100));
	//		*((volatile u16t*)_pwm_16BIT.OCRx)=_duty_pwm;
	//		break;
	//	default:
	//		return false;
	//
	//	}
}

bool Pin::setFreq(uint16_t freq)
{
	//if(_pwm_16BIT.TCCRxA == nullptr){
	//	return false;
	//}
	//float ratio =_freq_pwm/_duty_pwm;
	//_freq_pwm = calculateTicks(freq);
	//_duty_pwm = (float)_freq_pwm/(float)ratio;
	//*((volatile u16t*)_pwm_16BIT.ICRx) = _freq_pwm;
	//*((volatile u16t*)_pwm_16BIT.OCRx) = _duty_pwm;
	//return true;
}

bool Pin::stopPWM()
{
	//switch (PWM_BITS_MASK(_controlBits)) {
	//case 0:
	//	_pwm_8BIT.TCCRxB = 0;
	//	break;
	//case 1:
	//	_pwm_16BIT.TCCRxB = 0;
	//	break;
	//default:
	//	return false;
	//}
}

bool Pin::digitalRead()
{
	if(*_pinx & (1<<_registerBit)){
		return true;
	}
	return false;
}


uint16_t Pin::analogRead(_ADMUX vRef, _ADCSRA_PRESCALER prescaler, _ADCSRB_AUTOTRIGGER autoTrigger)
{
	if(IS_ADC_MASK(_controlBits) == 0){
		return 65535;
	}

	/*
	╔════════╦═══════╦═══════╦═══════╦══════╦══════╦═══════╦═══════╦═══════╗
	║        ║   7   ║   6   ║   5   ║   4  ║   3  ║   2   ║   1   ║   0   ║
	╠════════╬═══════╬═══════╬═══════╬══════╬══════╬═══════╬═══════╬═══════╣
	║ ADCSRB ║   -   ║  ACME ║   -   ║   -  ║ MUX5 ║ ADTS2 ║ ADTS1 ║ ADTS0 ║
	╠════════╬═══════╬═══════╬═══════╬══════╬══════╬═══════╬═══════╬═══════╣
	║  ADMUX ║ REFS1 ║ REFS0 ║ ADLAR ║ MUX4 ║ MUX3 ║  MUX2 ║  MUX1 ║  MUX0 ║
	╚════════╩═══════╩═══════╩═══════╩══════╩══════╩═══════╩═══════╩═══════╝
	*/
/*
#if defined(__AVR_ATmega640__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
	if(channel == 65535){
		return 65535;
	}
	uint16_t _adcsrb_adxmux_reg = (autoTrigger << 8) | vRef | channel;
#elif defined(__AVR_ATmega328P__)
	uint16_t _adcsrb_adxmux_reg = (autoTrigger << 8) | vRef | (_pinNumber - A0);
#endif

	if(ADCSRA == 0){

		ADCSRA |= (1<<ADEN) | (0<<ADIE) | prescaler;//FIXME if set ADIE will not work and crash(it's necessary?)

	}

	while(ADCSRA & (1 << ADIF) == 0);

	ADCSRB = (_adcsrb_adxmux_reg >> 8);

	ADMUX = (_adcsrb_adxmux_reg & 0xFF);

	ADCSRA |= (1 << ADSC);

	while(ADCSRA & (1 << ADSC));

	return ADC;//*0.004882813;
}


uint8_t Pin::getPinNumber()
{
	return _pinNumber;
}

uint8_t Pin::getPWM()
{
	return (uint8_t)((((float)_freq_pwm - (float)_duty_pwm) * (float)100) / (float)_freq_pwm) & 0xFF;
}

uint8_t Pin::getRegisterBit()
{
	return _registerBit;
}

volatile uint8_t* Pin::getPINxAddr()
{
	return _pinx;
}

uint16_t Pin::calculateTicks(uint32_t freq)
{
	return (1.0/freq)/(1.0/F_CPU);
}

*/







/*

if(temp == 2){
	//_local_ctrl_bits = _PWM_8BIT;
	_pwm_8BIT.TCCRxA = (volatile u8t*)pgm_read_word(&__hw_timer_addr[temp]);
	_pwm_8BIT.TCCRxB = (volatile u8t*)_pwm_8BIT.TCCRxA + 1;
	_pwm_8BIT.TCNTx	 = (volatile u8t*)_pwm_8BIT.TCCRxB + 1;
}
else if(temp){
	//_local_ctrl_bits  = _PWM_16BIT;
	_pwm_16BIT.TCCRxA = (volatile u8t*)pgm_read_word(&__hw_timer_addr[temp]);
	_pwm_16BIT.TCCRxB = (volatile u8t*)_pwm_16BIT.TCCRxA + 1;
	_pwm_16BIT.TCCRxC = (volatile u8t*)_pwm_16BIT.TCCRxB + 1;
	_pwm_16BIT.TCNTx  = (volatile u8t*)_pwm_16BIT.TCCRxC + 2;
	_pwm_16BIT.ICRx   = (volatile u8t*)_pwm_16BIT.TCNTx  + 2;


}

	switch (PWM_BITS_MASK(_controlBits)) {
	case _PWM_8BIT:
		_duty_pwm=(-2.55*duty) + 255;
		switch (PWM_LETTER_MASK(_controlBits)) {
		case 0:
			_pwm_8BIT.OCRx = (volatile u8t*)_pwm_8BIT.TCNTx + 1;
			*_pwm_8BIT.TCCRxA |= (1 << 7) | (1 << 6);
			break;
		case 1:
			_pwm_8BIT.OCRx = (volatile u8t*) _pwm_8BIT.TCNTx + 2;
			*_pwm_8BIT.TCCRxA |= (1 << 5) | (1 << 4);
			break;
		}
		*((volatile u8t*) _pwm_8BIT.TCNTx + 2) = 10;
		*((volatile u8t*)_pwm_8BIT.OCRx)=_duty_pwm;
		*_pwm_8BIT.TCCRxA |= (0 << WGM11) | (1 << WGM10);													// Setting PWM, Phase Correct
		*_pwm_8BIT.TCCRxB |= (0 << WGM22);																												// TOP = OCRnA TOVx Flag = BOTTOM
		*_pwm_8BIT.TCCRxB |= (0 << CS12) | (1 << CS11) | (0 << CS10);	// Setting prescaler to 1, so F_CPU
		return true;

	case _PWM_16BIT:
		_freq_pwm = calculateTicks(freq);
		_duty_pwm = _freq_pwm-(_freq_pwm*((float)duty/100));
		*((volatile u16t*)_pwm_16BIT.ICRx) = _freq_pwm;
		switch(PWM_LETTER_MASK(_controlBits)){
		case 0:
			_pwm_16BIT.OCRx = (volatile u8t*)_pwm_16BIT.ICRx + 2;
			*_pwm_16BIT.TCCRxA |= (1 << 7 ) | (1 << 6) ;
			break;
		case 1:
			_pwm_16BIT.OCRx = (volatile u8t*)_pwm_16BIT.ICRx + 4;
			*_pwm_16BIT.TCCRxA |= (1 << 5) | (1 << 4) ;
			break;
		case 2:
			_pwm_16BIT.OCRx = (volatile u8t*)_pwm_16BIT.ICRx + 6;
			*_pwm_16BIT.TCCRxA |= (1 << 3) | (1 << 2) ;
			break;
		};

		*((volatile u16t*)_pwm_16BIT.OCRx) = _duty_pwm;
		*_pwm_16BIT.TCCRxA  |= (1 << WGM11) | (0 << WGM10);// Setting PWM, Phase Correct
		*_pwm_16BIT.TCCRxB  |= (1 << WGM13) | (1 << WGM12);// TOP = OCRnA TOVx Flag = BOTTOM
		*_pwm_16BIT.TCCRxB  |= (0 << CS12) | (0 << CS11) | (1 << CS10); //Setting prescaler to 1, so F_CPU
		return true;

*/




