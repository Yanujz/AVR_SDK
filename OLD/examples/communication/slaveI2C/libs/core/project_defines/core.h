#pragma once
#include <project.h>


#if PROJECT_MCU_BOARD == BOARD_ARDUINO_MEGA2560_R3

#include <arduino_mega2560_r3.h>
#include <mega_common.h>
#include <common_typedef.h>
#include <atmega2560_common.h>
#include <atmega2560_common_constexpr.h>

#ifndef __AVR_ATmega2560__
#error Mismatch project compiling. Please set correct mcu/board define into "project.h" file
#endif // __AVR_ATmega2560__

#elif PROJECT_MCU_BOARD == MCU_ATMEGA2560
#include <atmega2560.h>
#include <atmega2560_common_constexpr.h>
#ifndef __AVR_ATmega2560__
#error Mismatch project compiling. Please set correct mcu/board define into "project.h" file
#endif // __AVR_ATmega2560__

#elif PROJECT_MCU_BOARD == BOARD_ARDUINO_UNO_R3
#include <arduino_uno_r3.h>
#include <atmega328p_common_constexpr.h>
#ifndef __AVR_ATmega328P__
#error Mismatch project compiling. Please set correct mcu/board define into "project.h" file
#endif // __AVR_ATmega328P__

#elif PROJECT_MCU_BOARD == MCU_ATMEGA328P
#include <atmega328p.h>
#include <atmega328p_common_constexpr.h>
#ifndef __AVR_ATmega328P__
#error Mismatch project compiling. Please set correct mcu/board define into "project.h" file
#endif // __AVR_ATmega328P__







#endif
