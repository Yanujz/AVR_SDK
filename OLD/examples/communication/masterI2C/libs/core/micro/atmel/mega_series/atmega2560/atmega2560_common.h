#pragma once
//#include <macros.h>
//#include <avr/io.h>
#include <core.h>


enum class PIN_ADC : u8t {
    A0,
    A1,
    A2,
    A3,
    A4,
    A5,
    A6,
    A7,
    A8,
    A9,
    A10,
    A11,
    A12,
    A13,
    A14,
    A15
};



inline volatile u8t* varToPinx(PIN pin){
    volatile u8t* pinx = (volatile u8t*)(toU8(pin) & 0x3F);
    if(toU16(pin) & OR100){
	pinx += 0x100;
    }
    return  pinx;
}

inline volatile u8t* varToTCCRxA(PWM16 pin){
    volatile u8t* TCCRxA = (volatile u8t*)(toU8(pin) & 0xFF);
    if(toU16(pin) & (1 << 8)){
	TCCRxA += 0x100;
    }
    return TCCRxA;
}
