#ifndef PINS_H
#define PINS_H
#include <core.h>
///@file

// Must pass PINx_REG
#define DDRx_OFFSET(x) (x  + 1)

// Must pass PINx_REG
#define PORTx_OFFSET(x) (x  + 2)

#define PINx_REG (varToPinx(pin))
#define DDRx_REG DDRx_OFFSET(PINx_REG)
#define PORTx_REG PORTx_OFFSET(PINx_REG)




using namespace core;
using namespace core::IO;
using namespace core::mega;
using namespace core::mega::timer;
using namespace core::mega::adc;


/**
 * @brief pinMode Set direction of a pin
 * @param pin
 * @param dir
 */
inline void pinMode(PIN pin, IO::DDRx dir)  {
    if (dir == OUTPUT) {
	*DDRx_REG |= bitToValue[varToRegBit(pin)];
	return;
    } else {
	*DDRx_REG &= ~bitToValue[varToRegBit(pin)];
    }
    if(dir == INPUT_PULLUP){
	*PORTx_REG |= bitToValue[varToRegBit(pin)];
    }
}

/**
 * @brief digitalToggle Toggles pin's state
 * @param pin
 */
inline void digitalToggle(PIN pin) {
    *PINx_REG = bitToValue[varToRegBit(pin)];
}

/**
 * @brief digitalSet Set pin to high level
 * @param pin
 */
inline void digitalSet(PIN pin) {
    *PORTx_REG |= bitToValue[varToRegBit(pin)];
}

/**
 * @brief digitalClr
 * @param pin
 */
inline void digitalClr(PIN pin) {
    *PORTx_REG &= ~bitToValue[varToRegBit(pin)];
}

/**
 * @brief digitalRead
 * @param pin
 * @return
 */
inline bool digitalRead(PIN pin) {
    return *PORTx_REG & bitToValue[varToRegBit(pin)];
}

/**
 * @brief digitalWrite
 * @param pin
 * @param level
 */
inline void digitalWrite(PIN pin, LOGIC_STATE level = LOW) {
    level ? digitalSet(pin) : digitalClr(pin);
}


/**
 * @brief setPWM
 * @param pin
 * @param freq
 * @param duty
 */
inline void setPWM(PWM pin, size_t freq, u8t duty){
    u8t timer = varToTimer((PIN)pin);
    u8t pwmGroup = varToPWMGroup((PIN)pin);
    u8t letter = varToLetter((PIN)pin);

    u8t _valueTCCRxa = 0;
    volatile u8t* TCCRxA = (volatile u8t*)hw_timer_addr[timer];

    if(pwmGroup == PWM8BIT){
	u8t _duty8 = calcDuty8bit(duty);
	switch (letter) {
	case LETTER_A:
	    _valueTCCRxa |= FREQ_PHASE_CORRECT_OCxA_MODE_SET;
	    *OCRxA_8BIT = _duty8;
	    break;
	case LETTER_B:
	    _valueTCCRxa |= FREQ_PHASE_CORRECT_OCxB_MODE_SET;
	    *OCRxB_8BIT = _duty8;
	    break;
	default:
	    break;
	}
	_valueTCCRxa |= LO8(WAVEFORM_PH_CORRECT_TOP_0XFF);
	*TCCRxB_8BIT |= HI8(WAVEFORM_PH_CORRECT_TOP_0XFF) | TIMERn_xBIT_PRESCALER_8;
    }
    else {
	u16t _freq = calcPwmTicks(freq);
	u16t _duty16 = calcDuty16bit(_freq, duty);
	*ICRx_16BIT = _freq;
	switch (letter) {
	case LETTER_A:
	    _valueTCCRxa |= FAST_PWM_OCxA_MODE_SET;
	    *OCRxA_16BIT = _duty16;
	    break;
	case LETTER_B:
	    _valueTCCRxa |= FAST_PWM_OCxB_MODE_SET;
	    *OCRxB_16BIT = _duty16;
	    break;
#if defined(LETTER_C)
	case LETTER_C:
	    _valueTCCRxa |= FAST_PWM_OCxC_MODE_SET;
	    *OCRxC_16BIT = _duty16;
	    break;
#endif
	default:
	    break;
	}
	_valueTCCRxa |= LO8(WAVEFORM_FAST_PWM_TOP_ICRx);
	*TCCRxB_16BIT |= HI8(WAVEFORM_FAST_PWM_TOP_ICRx) | TIMERn_xBIT_PRESCALER_1;
    }
    *TCCRxA |= _valueTCCRxa;
}



#if defined (LETTER_C)
/**
 * @brief setMultiPWM16
 * @param timer
 * @param commonFreq
 * @param outA_duty
 * @param outB_duty
 * @param outC_duty
 */
inline void setMultiPWM16(TIMER16 timer,
			  size_t commonFreq,
			  u8t outA_duty = 0,
			  u8t outB_duty = 0,
			  u8t outC_duty = 0)
#else
/**
 * @brief setMultiPWM16
 * @param timer
 * @param commonFreq
 * @param outA_duty
 * @param outB_duty
 */
inline void setMultiPWM16(TIMER16 timer, size_t commonFreq, u8t outA_duty = 0,
			  u8t outB_duty = 0)
#endif

{

    volatile u8t* TCCRxA = (volatile u8t*)timer;
    u16t _freq = calcPwmTicks(commonFreq);
    u16t dutyA = calcDuty16bit(_freq, outA_duty);
    u16t dutyB = calcDuty16bit(_freq, outB_duty);
#if defined(LETTER_C)
    u16t dutyC = calcDuty16bit(_freq, outC_duty);
#endif
    *ICRx_16BIT = _freq;
    *OCRxA_16BIT = dutyA;
    *OCRxB_16BIT = dutyB;
#if defined(LETTER_C)
    *OCRxC_16BIT = dutyC;
#endif
    *TCCRxA |= FAST_PWM_OCxA_MODE_SET | FAST_PWM_OCxB_MODE_SET |
	#if defined(LETTER_C)
	    FAST_PWM_OCxC_MODE_SET |
	#endif
	    LO8(WAVEFORM_FAST_PWM_TOP_ICRx)
    ;
    *TCCRxB_16BIT |= HI8(WAVEFORM_FAST_PWM_TOP_ICRx) | TIMERn_xBIT_PRESCALER_1;

}



/**
 * @brief analogRead
 * @param pin
 * @param vRef
 * @param prescaler
 * @param autoTrigger
 * @return
 */
inline u16t analogRead(PIN_ADC pin, ADC_VREF vRef = ADC_VREF::AVCC,
		       ADCSRA_PRESCALER prescaler = ADCSRA_PRESCALER::F_CPU_BY_128,
		       ADCSRB_AUTOTRIGGER autoTrigger = ADCSRB_AUTOTRIGGER::FREE_RUNNING_MODE)
{
#if defined(__AVR_ATmega640__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
    u16t _adcsrb_adxmux_reg = (toU8(autoTrigger) << 8) | toU8(vRef) | (toU8(pin) > 7 ? (bitValue(11) | toU8(pin)) : toU8(pin));
#elif defined(__AVR_ATmega328P__)
    u16t _adcsrb_adxmux_reg = (toU8(autoTrigger) << 8) | toU8(vRef) | toU8(pin);
#else
    u16t _adcsrb_adxmux_reg;
#endif
    if(ADCSRA == 0){
	ADCSRA |= (1 << ADEN) | (0 << ADIE) | toU8(prescaler);
    }

    while(ADCSRA & bitValue(ADIF) == 0);

    ADCSRB = HI(_adcsrb_adxmux_reg);

    ADMUX = LO(_adcsrb_adxmux_reg);

    ADCSRA |= bitValue(ADSC);

    while(ADCSRA & bitValue(ADSC));

    return ADC;//*0.004882813;
}


#endif
