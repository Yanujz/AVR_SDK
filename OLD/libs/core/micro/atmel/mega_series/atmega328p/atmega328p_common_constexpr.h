#pragma once
#include <project.h>
#if PROJECT_MCU_BOARD == BOARD_ARDUINO_UNO_R3
#include <arduino_uno_r3.h>
#elif PROJECT_MCU_BOARD == MCU_ATMEGA328P
#include <atmega328p.h>
#endif

constexpr volatile u8t* varToPinx(PIN x){
	return (&_SFR_IO8(toU16(x) & 0xF));
}
constexpr u8t varToRegBit(PIN x){
	return ((toU16(x) >> 4) & 0x07);
}
constexpr u8t varToPWMGroup(PIN x){
	return ((toU16(x) >> 7) & 0x01);
}
constexpr u8t varToTimer(PIN x){
	return ((toU16(x) >> 8) & 0x07);
}
constexpr u8t varToLetter(PIN x){
	return 	(((toU16(x) >> 10) & 0x03));
}

