#include "adccomparator.h"

/*
int32_t adc_compare(ADC_COMPARE compare, _ADMUX vRef, _ADCSRA_PRESCALER prescaler, _ADCSRB_AUTOTRIGGER autoTrigger){

    uint16_t _adcsrb_adxmux_reg = (autoTrigger<<8) | vRef | toU8(compare);
    if(ADCSRA == 0){
        ADCSRA |= (1<<ADEN) | (0<<ADIE) | prescaler;//FIXME if set ADIE will not work and crash(it's necessary?)
    }

    while(ADCSRA & (1 << ADIF) == 0);

    ADCSRB = (_adcsrb_adxmux_reg >> 8);

    ADMUX = (_adcsrb_adxmux_reg & 0xFF);

    ADCSRA |= (1<<ADSC);

    while(ADCSRA & (1<<ADSC));

    int var = ADC;
    if(bitRead(var, 9)){
        var |= 0xFC00;
    }
    u8t index = 0;
    if(compare <= ADC_COMPARE::A5_A2_GAIN1){
        index = toU8(compare) - 0x08;
    }
    else{
        index =  toU8(compare) -0x12;
    }
    var =  round(var * 5000.0/(512.0 * pgm_read_byte(&adc_gain_vect[index])));
    return var;//*0.004882813; ADC*VREF(mV)/(512*GAIN) 4,874−3,326 = 1,548
}
*/
