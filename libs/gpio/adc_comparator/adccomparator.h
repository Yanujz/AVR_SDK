#ifndef ADCCOMPARATOR_H
#define ADCCOMPARATOR_H
//#include <macros.h>
//#include <portmanager.h>
#include <pins.h>


/**
 * @brief The ADC_COMPARE enum
 * @note The semantic is in format: POS_NEG_GAIN
 * @example A0_A0_GAIN10 = GAIN10(A0) - GAIN10(A0)
 */
enum class ADC_COMPARE
{
    A0_A0_GAIN10    = 0x08,
    A1_A0_GAIN10    = 0x09,
    A0_A0_GAIN200   = 0x0A,
    A1_A0_GAIN200   = 0x0B,
    A2_A2_GAIN10    = 0x0C,
    A3_A2_GAIN10    = 0x0D,
    A2_A2_GAIN200   = 0x0E,
    A3_A2_GAIN200   = 0x0F,
    A0_A1_GAIN1     = 0x10,
    A1_A1_GAIN1     = 0x11,

    A2_A1_GAIN1     = 0x12,
    A3_A1_GAIN1     = 0x13,
    A4_A1_GAIN1     = 0x14,
    A5_A1_GAIN1     = 0x15,
    A6_A1_GAIN1     = 0x16,
    A7_A1_GAIN1     = 0x17,
    A0_A2_GAIN1     = 0x18,
    A1_A2_GAIN1     = 0x19,
    A2_A2_GAIN1     = 0x1A,
    A3_A2_GAIN1     = 0x1B,

    A4_A2_GAIN1     = 0x1C,
    A5_A2_GAIN1     = 0x1D,
    A8_A8_GAIN10    = 0x28,
    A9_A8_GAIN10    = 0x29,
    A8_A8_GAIN200   = 0x2A,
    A9_A8_GAIN200   = 0x2B,
    A10_A10_GAIN10  = 0x2C,
    A11_A10_GAIN10  = 0x2D,
    A10_A10_GAIN200 = 0x2E,
    A11_A10_GAIN200 = 0x2F,

    A8_A9_GAIN1     = 0x30,
    A9_A9_GAIN1     = 0x31,
    A10_A9_GAIN1    = 0x32,
    A11_A9_GAIN1    = 0x33,
    A12_A9_GAIN1    = 0x34,
    A13_A9_GAIN1    = 0x35,
    A14_A9_GAIN1    = 0x36,
    A15_A9_GAIN1    = 0x37,
    A8_A10_GAIN1    = 0x38,
    A9_A10_GAIN1    = 0x39,

    A10_A10_GAIN1   = 0x3A,
    A11_A10_GAIN1   = 0x3B,
    A12_A10_GAIN1   = 0x3C,
    A13_A10_GAIN1   = 0x3D,

};

const PROGMEM u8t adc_gain_vect[] = {
    0x0A, 0x0A, 0xC8, 0xC8, 0x0A, 0x0A, 0xC8, 0xC8,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x0A, 0x0A,
    0xC8, 0xC8, 0x0A, 0x0A, 0xC8, 0xC8, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01
};

/**
 * @brief adc_compare
 * @param[in] compare Check ADC_COMPARE enum
 * @param[in] vRef Check _ADMUX enum
 * @param[in] prescaler Check _ADCSRA_PRESCALER enum
 * @param[in] autoTrigger Check _ADCSRB_AUTOTRIGGER enum
 * @return Value in millivolt
 */
int32_t adc_compare(ADC_COMPARE compare, _ADMUX vRef = AVCC, _ADCSRA_PRESCALER prescaler = F_CPU_BY_16,
                    _ADCSRB_AUTOTRIGGER autoTrigger = _ADCSRB_AUTOTRIGGER::ANALOG_COMPARATOR);

#endif
