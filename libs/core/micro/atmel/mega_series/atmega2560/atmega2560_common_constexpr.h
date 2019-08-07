#pragma once
#include <project.h>
#if PROJECT_MCU_BOARD == BOARD_ARDUINO_MEGA2560_R3
#include <arduino_mega2560_r3.h>
#elif PROJECT_MCU_BOARD == MCU_ATMEGA2560
#include <atmega2560.h>
#endif

constexpr volatile u8t* varToPinx(PIN x){
    return (toU16(x) & OR100 ?
		&_SFR_MEM8(0x100 | (toU16(x) & 0x1F)) :  &_SFR_IO8(toU16(x) & 0x1F));
}
constexpr u8t varToLetter(PIN x){
    return (((toU16(x) >> 6) & 0x03));
}
constexpr u8t varToRegBit(PIN x){
    return ((toU16(x) >> 8) & 0x07);
}
constexpr u8t varToPWMGroup(PIN x){
    return ((toU16(x) >> 11) & 0x01);
}
constexpr u8t varToTimer(PIN x){
    return (((toU16(x) >> 12) & 0x07));
}
