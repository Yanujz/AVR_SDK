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



inline void pinMode(PIN pin, IO::DDRx dir){
    volatile u8t* pinx = varToPinx(pin);

    if (dir == OUTPUT) {
	*DDRx_OFFSET(pinx) |= HI8(toU16(pin));
	return;
    } else {
	*DDRx_OFFSET(pinx) &= ~HI8(toU16(pin));
    }
    if(dir == INPUT_PULLUP){
	*PORTx_OFFSET(pinx) |= HI8(toU16(pin));
    }
}


inline void digitalToggle(PIN pin) {
    *PINx_REG = HI8(toU16(pin));
}

inline void digitalSet(PIN pin) {
    *PORTx_REG |= HI8(toU16(pin));
}

inline void digitalClr(PIN pin) {
    *PORTx_REG &= ~HI8(toU16(pin));
}

inline bool digitalRead(PIN pin) {
    return *PORTx_REG & HI8(toU16(pin));
}

inline void digitalWrite(PIN pin, LOGIC_STATE level = LOW) {
    level ? digitalSet(pin) : digitalClr(pin);
}






// PWM 8 bits
inline void setPWM(PWM8 pin, u16t freq, u8t duty){
    volatile u8t* TCCRxA = (volatile u8t*)(toU16(pin) & 0xFF);
    u8t _duty8 = calcDuty8bit(duty);
    _SFR_MEM8(TCCRxA + ((toU16(pin) >> 12) & 0xF)) = _duty8;
    *TCCRxA |= LO8(WAVEFORM_PH_CORRECT_TOP_0XFF) |  (3 << ((toU16(pin) >> 9) & 0x7));
    *TCCRxB_8BIT |= HI8(WAVEFORM_PH_CORRECT_TOP_0XFF) | TIMERn_xBIT_PRESCALER_8;
}

// PWM 16 bits
inline void setPWM(PWM16 pin, u16t freq, u8t duty){
    volatile u8t* TCCRxA = varToTCCRxA(pin);

    u16t _freq = calcPwmTicks(freq);
    u16t _duty16 = calcDuty16bit(_freq, duty);
    *ICRx_16BIT = _freq;

    _SFR_MEM16(TCCRxA + ((toU16(pin) >> 12) & 0xF)) = _duty16; //Getting OCRnX

    *TCCRxA |= LO8(WAVEFORM_FAST_PWM_TOP_ICRx) | (0x03 << ((toU16(pin) >> 9) & 0x7)); // SHIFT_3_BY_X (PWM mode set)
    *TCCRxB_16BIT |= HI8(WAVEFORM_FAST_PWM_TOP_ICRx) | TIMERn_xBIT_PRESCALER_1;
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
