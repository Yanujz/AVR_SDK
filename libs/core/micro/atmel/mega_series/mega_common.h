#pragma once
#include <avr/pgmspace.h>
#include <avr/eeprom.h>
#include <macros.h>
#include <avr/io.h>
#include <util/delay.h>

#define __SERIAL0_SUPPORT__
#define __SPI0_SUPPORT__




#define TCCRxB_8BIT(x)  (*(x + 1))
#define TCNTx_8BIT(x)	(*(x + 2))
#define OCRxA_8BIT(x)	(*(x + 3))
#define OCRxB_8BIT(x)	(*(x + 4))


#define TCCRxB_16BIT(x) (*(x + 1))
#define TCCRxC_16BIT(x) (*(x + 2))
#define TCNTx_16BIT(x)  (*(&_SFR_MEM16(x + 4)))
#define ICRx_16BIT(x)   (*(&_SFR_MEM16(x + 6)))
#define OCRxA_16BIT(x)	(*(&_SFR_MEM16(x + 8)))
#define OCRxB_16BIT(x)	(*(&_SFR_MEM16(x + 10)))
#define OCRxC_16BIT(x)	(*(&_SFR_MEM16(x + 12)))


static const u8t __bitToValue[] = {1,2,4,8,16,32,64,128};
static const u8t __bitToValue_compl[] = {0xFE, 0xFD, 0xFB, 0xF7, 0xEF, 0xDF, 0xBF, 0x7F};

#if defined(__COMPILE__)
#if F_CPU == 16000000
enum class HW_UART : int{
        BAUD2400    = 416,
        BAUD4800    = 207,
        BAUD9600    = 103,
        BAUD14400   =  68,
        BAUD19200   =  51,
        BAUD28800   =  34,
        BAUD38400   =  25,
        BAUD57600   =  16,
        BAUD76800   =  12,
        BAUD115200  =   8,
        BAUD250000  =   3,
        BAUD500000  =   1,
        BAUD1000000 =   0
};
#endif
#else
enum class HW_UART : int{
        BAUD2400,
        BAUD4800,
        BAUD9600,
        BAUD14400,
        BAUD19200,
        BAUD28800,
        BAUD38400,
        BAUD57600,
        BAUD76800,
        BAUD115200,
        BAUD250000,
        BAUD500000,
        BAUD1000000
};
#endif
