#pragma once
#include <core.h>

using namespace core;
using namespace core::IO;
using namespace core::mega;
using namespace core::mega::timer;
using namespace core::mega::adc;


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
