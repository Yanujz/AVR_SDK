#ifndef PORTMANAGER_H
#define PORTMANAGER_H

///@file
#include <stdlib.h>
#include <math.h>
#include <util/delay.h>
#include <stdio.h>
#include "macros.h"


#include <pins.h>

//
///**
//								* @brief The DDRx enum
//								*/
//enum DDRx:uint8_t{
//	INPUT,
//	OUTPUT,
//	INPUT_PULLUP
//};
//
/**
								* @brief The LogicStates enum
								*/
//enum LogicStates:uint8_t{
//	LOW, HIGH
//};





/**
								* @brief The PWM_8BIT struct
								*/
struct PWM_8BIT {
	volatile uint8_t *TCCRxA = nullptr;
	volatile uint8_t *TCCRxB = nullptr;
	volatile uint8_t *TCNTx  = nullptr;
	volatile uint8_t *OCRx   = nullptr;
};

/**
								* @brief The PWM_16BIT struct
								*/
struct PWM_16BIT : PWM_8BIT {
	volatile uint8_t *TCCRxC = nullptr;
	volatile uint8_t *ICRx   = nullptr;
};

/**
	* @brief The _LOCAL_CTRL_BITS enum
	*/
/*
enum _LOCAL_CTRL_BITS:uint8_t{
								_PWM_8BIT = 0x2, _PWM_16BIT = 0x3, _ADC = 0x4
};*/


enum _PWM_BITS : u8t {
	_PWM_8BIT, _PWM_16BIT
};



/**
	* @brief The Pin class
	*/

class Pin{
public:

	Pin(){}

	/**
	* @brief Pin Constructor
	* @param[in] portNo Is the physical pin of the board
	* @param[in] direction Check DDRx enum
	*/
	Pin(uint8_t portNo, DDRx direction);

	~Pin();

	/**
	* @brief Sets state on of a pin
	*/
	void on();

	/**
	* @brief Set state of a pin
	* @param[in] stat  True = on, False = off
	*/
	void setState(bool stat = true);

	/**
	* @brief Sets state off of a pin
	*/
	void off();

	/**
	* @brief Toggle a pin state
	*/
	void toggle();

	/**
	* @brief setDirection
	* @param[in] direction
	*/
	void setDirection(DDRx direction);

	/**
	* @brief Set hardware PWM
	* @param[in] freq In hertz
	* @param[in] duty In range 0 - 100
	* @return True if pin has hardware PWM, else  false
	*/
	bool setPWM(uint32_t freq, uint8_t duty = 50);

	/**
	* @brief Set duty of hardware PWM
	* @param[in] duty Range 0 - 100
	* @return True if pin has hardware PWM, else  false
	*/
	bool setDuty(uint8_t duty);

	/**
	* @brief Set Frequency of hardware PWM
	* @param[in] freq In hertz
	* @return True if pin has hardware PWM, else  false
	*/
	bool setFreq(uint16_t freq);

	/**
	* @brief Stop PWM
	* @return True if pin has hardware PWM, else  false
	*/
	bool stopPWM();

	/**
	* @brief digitalRead
	* @return True if pin TTL high, else False
	*/
	bool digitalRead();

	/**
	* @brief analogRead
	* @param[in] vRef Check _ADMUX enum
	* @param[in] prescaler Check _ADCSRA_PRESCALER enum
	* @param[in] autoTrigger Check _ADCSRB_AUTOTRIGGER enum
	* @return
																																								*/
	uint16_t analogRead(_ADMUX vRef = AVCC, _ADCSRA_PRESCALER prescaler = F_CPU_BY_128, _ADCSRB_AUTOTRIGGER autoTrigger = FREE_RUNNING_MODE);

	/**
	* @brief getPinNumber
	* @return Number of mapped pin into the board
	*/
	uint8_t getPinNumber();

	/**
	* @brief Get PWM Duty Cycle
	* @return Percentage of duty cycle. Range : 0% - 100%
	*/
	uint8_t getPWM();

	/**
	* @brief Get register bit
	* @return Bits into own register
	*/
	uint8_t getRegisterBit();

	/**
	* @brief getPINxAddr
	* @return Mapped address of PINx
	*/
	volatile uint8_t *getPINxAddr();

private:
	//---- Methods ----//
	inline uint16_t calculateTicks(uint32_t freq);

	//---- Variables ----//
	volatile uint8_t *_pinx;
	volatile u8t* _TCCRxA;
	//volatile uint8_t *_ddrx;
	//volatile uint8_t *_portx;
#if defined(__AVR_ATmega640__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
	uint16_t channel = 65535;
#endif
	uint8_t _registerBit;
	//uint8_t _local_ctrl_bits;

	//PWM_16BIT _pwm_16BIT;
	//PWM_8BIT _pwm_8BIT;

	uint16_t _freq_pwm;
	uint16_t _duty_pwm;
	uint16_t _controlBits;

	uint8_t _pinNumber;
};










/*
inline void setPWM(u8t pin, size_t _freq, u8t _duty){
	u16t freq = getFreq(_freq);
	u16t duty = getDuty(freq, _duty);

	switch (pwm[pin].pwmGroup) {
	case PWM16BIT:
		ICRx_16BIT(pwm[pin].TCCRxA) = freq;
		switch (pwm[pin].letter) {
		case LETTER_A:
			*pwm[pin].TCCRxA |= bitValue(7) | bitValue(6);
			//OCRxA_16BIT(TCCRxA) = CALCULATE_DUTY_16BIT(freq, duty);
			break;
		case LETTER_B:
			*pwm[pin].TCCRxA	|= bitValue(5) | bitValue(4);

			break;
#if defined(LETTER_C)
		case LETTER_C:
			*pwm[pin].TCCRxA	|= bitValue(3) | bitValue(2);
			//*(pwm[pin].TCCRxA+12)	 = duty;
			OCRxC_16BIT(pwm[pin].TCCRxA) = duty;
			break;
#endif
		}
		//OCRxB_16BIT(TCCRxA) = CALCULATE_DUTY_16BIT(freq, duty);
		*pwm[pin].TCCRxA   |= (1 << WGM11) | (0 << WGM10);// Setting PWM, Phase Correct
		*(pwm[pin].TCCRxA+1)  |= (1 << WGM13) | (1 << WGM12);// TOP = OCRnA TOVx Flag = BOTTOM
		*(pwm[pin].TCCRxA+1)  |= (0 << CS12) | (0 << CS11) | (1 << CS10); //Setting prescaler to 1, so F_CPU
	default:
		break;
	}


}*/




#endif // PORTMANAGER_H
