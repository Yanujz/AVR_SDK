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
using namespace core::mega::common_typef;
using namespace core::mega::timer;
using namespace core::mega::adc;



inline void pinMode(PIN pin, IO::DDRx dir){
  volatile u8t* pinx = varToPinx(pin);

  if (dir == OUTPUT) {
	*DDRx_OFFSET(pinx) |= varToBitValue(pin);
	return;
  } else {
	*DDRx_OFFSET(pinx) &= ~varToBitValue(pin);
  }
  if(dir == INPUT_PULLUP){
	*PORTx_OFFSET(pinx) |= varToBitValue(pin);
  }
}


inline void digitalToggle(PIN pin) {
  *PINx_REG = varToBitValue(pin);
}

inline void digitalSet(PIN pin) {
  *PORTx_REG |= varToBitValue(pin);
}

inline void digitalClr(PIN pin) {
  *PORTx_REG &= ~varToBitValue(pin);
}

inline bool digitalRead(PIN pin) {
  return *PINx_REG & varToBitValue(pin);
}

inline void digitalWrite(PIN pin, LOGIC_STATE level = LOW) {
  level ? digitalSet(pin) : digitalClr(pin);
}






// PWM 8 bits
inline void setPWM(PWM8 pin, u16 /*freq*/, u8 duty){
  auto* timer = castTo(TIMER8_TypeDef*, (int*)pinToTCCRxA_8BIT (pin));

  u8t _duty8 = calcDuty8bit(duty);

  *pinToOCRx_8BIT(pin) = _duty8; //Getting OCRnX

  timer->TCCRA |= LO8(WAVEFORM_PH_CORRECT_TOP_0XFF) |  pinToPWMComOutput(pin);
  timer->TCCRB |= HI8(WAVEFORM_PH_CORRECT_TOP_0XFF) | TIMERn_xBIT_PRESCALER_8;
}

// PWM 16 bits
inline void setPWM(PWM16 pin, u16 freq, u8 duty){
  auto* timer = castTo(TIMER16_TypeDef*, (int*)varToTCCRxA(pin));
  u16 _freq = calcPwmTicks(freq);
  u16 _duty16 = calcDuty16bit(_freq, duty);

  timer->ICR = _freq;

  *pinToOCRx_16BIT(timer->TCCRA, pin) = _duty16; //Getting OCRnX

  timer->TCCRA |= LO8(WAVEFORM_FAST_PWM_TOP_ICRx) | pinToPWMComOutput(pin); // SHIFT_3_BY_X (PWM mode set)
  timer->TCCRB |= HI8(WAVEFORM_FAST_PWM_TOP_ICRx) | TIMERn_xBIT_PRESCALER_1;
}



enum class DATA_ORDER {
  LSB, MSB
};
enum class CLOCK_EDGE {
  RISING, FALLING
};

inline void shiftOut(PIN clock, PIN data, DATA_ORDER dOrd, CLOCK_EDGE clockEdge, u8t byte){
  volatile u8t* pinxClock = varToPinx(clock);
  volatile u8t* pinxData = varToPinx(data);
  volatile u8t* portxData = PORTx_OFFSET(pinxData);
  u8t cycles = sizeof(byte)*8;
  u8t clockBitValue = varToBitValue(clock);
  u8t dataBitValue = varToBitValue(data);

  digitalWrite(clock, (LOGIC_STATE)toU8(clockEdge));
  *portxData &= ~dataBitValue;
  if(dOrd == DATA_ORDER::LSB){
	while (cycles--) {
	  if(byte & 1){
		*portxData |= dataBitValue;
	  }
	  else {
		*portxData &= ~dataBitValue;
	  }
	  *pinxClock = clockBitValue;
	  *pinxClock = clockBitValue;
	  byte >>=1;
	}
  }
  else {
	while (cycles--) {
	  if(byte & 0x80){
		*portxData |= dataBitValue;
	  }
	  else {
		*portxData &= ~dataBitValue;
	  }
	  *pinxClock = clockBitValue;
	  *pinxClock = clockBitValue;
	  byte <<=1;
	}
  }
  *portxData &= ~dataBitValue;
  digitalWrite (clock, (LOGIC_STATE)toU8(clockEdge));
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





#endif
