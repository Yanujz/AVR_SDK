#pragma once
#include <project.h>


#if PROJECT_MCU_BOARD == BOARD_ARDUINO_MEGA2560_R3

#define __MEGA_SERIES__
#define __ATMEGA2560__

#define __SPI0_SUPPORT__
#define __MEGA_SERIES_SPI0_SUPPORT__

#define __USART0_SUPPORT__
#define __USART1_SUPPORT__
#define __USART2_SUPPORT__
#define __USART3_SUPPORT__
#define __MEGA_SERIES_USART0_SUPPORT__
#define __MEGA_SERIES_USART1_SUPPORT__
#define __MEGA_SERIES_USART2_SUPPORT__
#define __MEGA_SERIES_USART3_SUPPORT__

#define __MEGA_SERIES_INT0_SUPPORT__
#define __MEGA_SERIES_INT1_SUPPORT__
#define __MEGA_SERIES_INT2_SUPPORT__
#define __MEGA_SERIES_INT3_SUPPORT__
#define __MEGA_SERIES_INT4_SUPPORT__
#define __MEGA_SERIES_INT5_SUPPORT__

#define __I2C0_SUPPORT__
#define __MEGA_SERIES_I2C0_SUPPORT__

#include <arduino_mega2560_r3.h>
#include <atmega2560_common.h>
#include <mega_common.h>
#include <mega_registers.h>
#include <atmega2560_common_constexpr.h>
#include <atmega2560_common_define.h>
#ifndef __MCU_ATMEGA2560__
#error Mismatch project compiling. Please set correct mcu/board define into "project.h" file
#endif // __MCU_ATMEGA2560__

#elif PROJECT_MCU_BOARD == MCU_ATMEGA2560
#include <mcu_atmega2560.h>
//#include <atmega2560_common_constexpr.h>

#ifndef __MCU_ATMEGA2560__
#error Mismatch project compiling. Please set correct mcu/board define into "project.h" file
#endif // __MCU_ATMEGA2560__

#elif PROJECT_MCU_BOARD == BOARD_ARDUINO_UNO_R3
//#include <arduino_uno_r3.h>
//#include <atmega328p_common_constexpr.h>
#define __ATMEGA328P__
#ifndef __MCU_ATMEGA328P__
#error Mismatch project compiling. Please set correct mcu/board define into "project.h" file
#endif // __MCU_ATMEGA328P__

#elif PROJECT_MCU_BOARD == MCU_ATMEGA328P
#include <atmega328p.h>
#include <atmega328p_common_constexpr.h>
#ifndef __MCU_ATMEGA328P__
#error Mismatch project compiling. Please set correct mcu/board define into "project.h" file
#endif // __MCU_ATMEGA328P__

#elif PROJECT_MCU_BOARD == MCU_ATMEGA328PB
//#include <atmega328pb.h>
//#include <atmega328pb_common_constexpr.h>
#define __ATMEGA328PB__
#define __SPI1_SUPPORT__
#define __MEGA_SERIES_SPI0_SUPPORT__
#define __MEGA_SERIES_SPI1_SUPPORT__
#ifndef __MCU_ATMEGA328PB__
#error Mismatch project compiling. Please set correct mcu/board define into "project.h" file
#endif // __MCU_ATMEGA328PB__


#elif PROJECT_MCU_BOARD == MCU_ATSAMD21G18
//#include <atsamd21g18.h>
//#include <atsamd21g18_common_constexpr.h>
#define __ATSAMD21G18__
#define __SPI0_SUPPORT__
#define __SPI1_SUPPORT__
#define __SAMD21_SERIES_SPI0_SUPPORT__
#define __SAMD21_SERIES_SPI1_SUPPORT__
//#ifndef __MCU_ATSAMD21G18__
//#error Mismatch project compiling. Please set correct mcu/board define into "project.h" file
//#endif // __MCU_ATSAMD21G18__



#endif
