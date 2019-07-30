#ifndef PINS_H
#define PINS_H
#include <core.h>

// Must pass PINx
#define _DDRx(x) (*(x  + 1))

// Must pass PINx
#define _PORTx(x) (*(x  + 2))


#ifdef __cplusplus
extern "C" {
#endif

/**
* @brief The DDRx enum
*/
typedef enum {
	INPUT,
	OUTPUT,
	INPUT_PULLUP
} DDRx;

/**
* @brief The LogicStates enum
*/
typedef enum  {
	LOW, HIGH
} LOGIC_STATE;


/**
* @brief The _ADMUX enum
*/
typedef enum {
	INTERNAL_VREF   = (0<<REFS1) | (0<<REFS0), // AREF,Internal VREF turned OFF
	AVCC            = (0<<REFS1) | (1<<REFS0), // AVCC at AREF Pin with external capacitor
	INTERNAL_1_1V   = (1<<REFS1) | (0<<REFS0), // Internal 1.1Voltage reference with external capacitor at AREF pin
	INTERNAL_2_56V  = (1<<REFS1) | (1<<REFS0), // Internal 2.56Voltage reference with external capacitor at AREF pin
} _ADMUX;

/**
* @brief The _ADCSRA_PRESCALER enum
*/
typedef enum {
	F_CPU_BY_2	  = (0<<ADPS2)|(0<<ADPS1)|(1<<ADPS0),
	F_CPU_BY_4	  = (0<<ADPS2)|(1<<ADPS1)|(0<<ADPS0),
	F_CPU_BY_8	  = (0<<ADPS2)|(1<<ADPS1)|(1<<ADPS0),
	F_CPU_BY_16	 = (1<<ADPS2)|(0<<ADPS1)|(0<<ADPS0),
	F_CPU_BY_32	 = (1<<ADPS2)|(0<<ADPS1)|(1<<ADPS0),
	F_CPU_BY_64	 = (1<<ADPS2)|(1<<ADPS1)|(0<<ADPS0),
	F_CPU_BY_128 = (1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0),
} _ADCSRA_PRESCALER;


/**
* @brief The _ADCSRB_AUTOTRIGGER enum
*/
typedef enum {
	FREE_RUNNING_MODE         = (0<<ADTS2) | (0<<ADTS1) |(0<<ADTS0),
	ANALOG_COMPARATOR         = (0<<ADTS2) | (0<<ADTS1) |(1<<ADTS0),
	EXTERNAL_INTERRUPT_REQ_0  = (0<<ADTS2) | (1<<ADTS1) |(0<<ADTS0),
	TNCT0_COMP_A              = (0<<ADTS2) | (1<<ADTS1) |(1<<ADTS0),
	TNCT0_OVERFLOW            = (1<<ADTS2) | (0<<ADTS1) |(0<<ADTS0),
	TNCT1_COMP_B              = (1<<ADTS2) | (0<<ADTS1) |(1<<ADTS0),
	TNCT1_OVERFLOW												= (1<<ADTS2) | (1<<ADTS1) |(0<<ADTS0),
	TNCT1_CAPTURE_EVENT	      = (1<<ADTS2) | (1<<ADTS1) |(1<<ADTS0),
} _ADCSRB_AUTOTRIGGER;



#ifdef __cplusplus
}
#endif

inline void pinMode(PIN pin, DDRx dir)  {
	if (dir == OUTPUT) {
		*(varToPinx(pin)+1) |= __bitToValue[varToRegBit(pin)];
		return;
	} else {
		*(varToPinx(pin)+1) &= ~__bitToValue[varToRegBit(pin)];

	}
	if(dir == INPUT_PULLUP){
		*(varToPinx(pin)+2) |= __bitToValue[varToRegBit(pin)];
	}
}

inline void digitalToggle(PIN pin) {
	*(varToPinx(pin)) = __bitToValue[varToRegBit(pin)];
}

inline void digitalSet(PIN pin) {
	*(varToPinx(pin)+2) = __bitToValue[varToRegBit(pin)];
}

inline void digitalClr(PIN pin) {
	*(varToPinx(pin)+2) &= __bitToValue_compl[varToRegBit(pin)];
}

inline bool digitalRead(PIN pin) {
	return *(varToPinx(pin)+2) & __bitToValue[varToRegBit(pin)];
}

inline void digitalWrite(PIN pin, LOGIC_STATE level = LOW) {
	level ? digitalSet(pin) : digitalClr(pin);
}

inline void setPWM(PIN pin, size_t freq, u8t duty){
	u8t timer = varToTimer(pin);
	if( timer == NO_TIMER){
		return;
	}
	u8t pwmGroup = varToPWMGroup(pin);
	u8t letter = varToLetter(pin);
	u8t _valueTCCRxa = 0;
	volatile u8t* TCCRxA = (volatile u8t*)__hw_timer_addr[timer];
	if(pwmGroup == PWM8BIT){
		u8t _duty8 = calcDuty8bit(duty);
		switch (letter) {
		case LETTER_A:
			_valueTCCRxa	|= bitValue(7) | bitValue(6);
			OCRxA_8BIT(TCCRxA) = _duty8;
			break;
		case LETTER_B:
			_valueTCCRxa		|= bitValue(5) | bitValue(4);
			OCRxB_8BIT(TCCRxA) = _duty8;
			break;
		default:
			break;
		}
		_valueTCCRxa	 |= (0 << WGM11) | (1 << WGM10);
		TCCRxB_8BIT(TCCRxA) |= (0 << WGM22) |(0 << CS12) | (1 << CS11) | (0 << CS10);
	}
	else {
		u16t _freq = calcPwmTicks(freq);
		u16t _duty16 = calcDuty16bit(_freq, duty);
		ICRx_16BIT(TCCRxA) = _freq;
		switch (letter) {
		case LETTER_A:
			_valueTCCRxa	|= bitValue(7) | bitValue(6);
			OCRxA_16BIT(TCCRxA) = _duty16;
			break;
		case LETTER_B:
			_valueTCCRxa |= bitValue(5) | bitValue(4);
			OCRxB_16BIT(TCCRxA) = _duty16;
			break;
#if defined(LETTER_C)
		case LETTER_C:
			_valueTCCRxa |= bitValue(3) | bitValue(2);
			OCRxC_16BIT(TCCRxA) = _duty16;
			break;
#endif
		default:
			break;
		}
		_valueTCCRxa |= (1 << WGM11) | (0 << WGM10);// Setting PWM, Phase Correct
		TCCRxB_16BIT(TCCRxA)  |= (1 << WGM13) | (1 << WGM12) | (0 << CS12) | (0 << CS11) | (1 << CS10);
	}
	*TCCRxA |= _valueTCCRxa;
}

inline uint16_t analogRead(PIN_ADC pin, _ADMUX vRef = AVCC, _ADCSRA_PRESCALER prescaler = F_CPU_BY_128,
																											_ADCSRB_AUTOTRIGGER autoTrigger = FREE_RUNNING_MODE)
{
#if defined(__AVR_ATmega640__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
	uint16_t _adcsrb_adxmux_reg = (autoTrigger << 8) | vRef | (toU8(pin) > 7 ? (bitValue(11) | toU8(pin)) : toU8(pin));
#elif defined(__AVR_ATmega328P__)
	uint16_t _adcsrb_adxmux_reg = (autoTrigger << 8) | vRef | toU8(pin);
#endif
	if(ADCSRA == 0){
		ADCSRA |= (1<<ADEN) | (0<<ADIE) | prescaler;//FIXME if set ADIE will not work and crash(it's necessary?)
	}

	//while(ADCSRA & bitValue(ADIF) == 0);
	loop_until_bit_is_clear(ADCSRA , bitValue(ADIF));

	ADCSRB = HI(_adcsrb_adxmux_reg);

	ADMUX = LO(_adcsrb_adxmux_reg);

	ADCSRA |= bitValue(ADSC);

	while(ADCSRA & bitValue(ADSC));

	return ADC;//*0.004882813;

}

// ATTENTION not sure if needed
inline void changeDuty(PIN pin, u8t duty){
	u8t timer = varToTimer(pin);
	if( timer == NO_TIMER){
		return;
	}
	u8t pwmGroup = varToPWMGroup(pin);
	u8t letter = varToLetter(pin);
	volatile u8t* TCCRxA = (volatile u8t*)__hw_timer_addr[timer];
	if(pwmGroup == PWM8BIT){
		u8t duty8 = calcDuty8bit(duty);
		switch (letter) {
		case LETTER_A:
			OCRxA_8BIT(TCCRxA) = duty8;
			break;
		case LETTER_B:
			OCRxB_8BIT(TCCRxA) = duty8;
			break;
		default:
			break;
		}
	}
	else {
		u16t freq = ICRx_16BIT(TCCRxA);
		u16t duty16 = calcDuty16bit(freq, duty);
		switch (letter) {
		case LETTER_A:
			OCRxA_16BIT(TCCRxA) = duty16;
			break;
		case LETTER_B:
			OCRxB_16BIT(TCCRxA) = duty16;
			break;
#if defined(LETTER_C)
		case LETTER_C:
			OCRxC_16BIT(TCCRxA) = duty16;
			break;
#endif
		default:
			break;
		}
	}

}

#endif
