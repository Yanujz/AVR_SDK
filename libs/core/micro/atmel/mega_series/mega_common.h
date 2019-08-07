#pragma once
#include <avr/pgmspace.h>
#include <avr/eeprom.h>
#include <macros.h>
#include <avr/io.h>
#include <util/delay.h>

///@file

#define __SERIAL0_SUPPORT__
#define __SPI0_SUPPORT__


//---- TIMER SECTION ----//

/**
 * @brief This define is used by timer's offset
*/
#define TCCRxA TCCRxA


#define TCCRxB_8BIT_OFFSET(x)   (x + 1)
#define TCNTx_8BIT_OFFSET(x)	(x + 2)
#define OCRxA_8BIT_OFFSET(x)	(x + 3)
#define OCRxB_8BIT_OFFSET(x)	(x + 4)


#define TCCRxB_16BIT_OFFSET(x)	(x + 1)
#define TCCRxC_16BIT_OFFSET(x)	(x + 2)
#define TCNTx_16BIT_OFFSET(x)	(&_SFR_MEM16(x + 4))
#define ICRx_16BIT_OFFSET(x)	(&_SFR_MEM16(x + 6))
#define OCRxA_16BIT_OFFSET(x)	(&_SFR_MEM16(x + 8))
#define OCRxB_16BIT_OFFSET(x)	(&_SFR_MEM16(x + 10))
#define OCRxC_16BIT_OFFSET(x)	(&_SFR_MEM16(x + 12))

/**
  * @brief To work this define you must decleare volatile u8t* TCCRxA variable.
  * use TCCRxB_8BIT_OFFSET(x) instead.
  */
#define TCCRxB_8BIT TCCRxB_8BIT_OFFSET(TCCRxA) // To work this define you must decleare volatile u8t* TCCRxA variable. Use TCCRxB_8BIT_OFFSET(x) instead.
#define TCNTx_8BIT  TCNTx_8BIT_OFFSET(TCCRxA)  // To work this define you must decleare volatile u8t* TCCRxA variable. Use TCNTx_8BIT_OFFSET(x) instead.
#define OCRxA_8BIT  OCRxA_8BIT_OFFSET(TCCRxA)  // To work this define you must decleare volatile u8t* TCCRxA variable. Use OCRxA_8BIT_OFFSET(x) instead.
#define OCRxB_8BIT  OCRxB_8BIT_OFFSET(TCCRxA)  // To work this define you must decleare volatile u8t* TCCRxA variable. Use OCRxB_8BIT_OFFSET(x) instead.


#define TCCRxB_16BIT	TCCRxB_16BIT_OFFSET(TCCRxA)
#define TCCRxC_16BIT	TCCRxC_16BIT_OFFSET(TCCRxA)
#define TCNTx_16BIT	TCNTx_16BIT_OFFSET(TCCRxA)
#define ICRx_16BIT	ICRx_16BIT_OFFSET(TCCRxA)
#define OCRxA_16BIT	OCRxA_16BIT_OFFSET(TCCRxA)
#define OCRxB_16BIT	OCRxB_16BIT_OFFSET(TCCRxA)
#define OCRxC_16BIT	OCRxC_16BIT_OFFSET(TCCRxA)

//---- END TIMER SECTION ----//


//---- UART SECTION ----//

#define UCSRxA UCSRxA

#define UART_UCSRxB_REG_OFFSET(x) (x  + 1)
#define UART_UCSRxC_REG_OFFSET(x) (x  + 2)
#define UART_UBRRxL_REG_OFFSET(x) (x  + 4)
#define UART_UBRRxH_REG_OFFSET(x) (x  + 5)
#define UART_UDRx_REG_OFFSET(x)   (x  + 6)


#define UCSRxB_REG  UART_UCSRxB_REG_OFFSET(UCSRxA)
#define UCSRxC_REG  UART_UCSRxC_REG_OFFSET(UCSRxA)
#define UBRRxL_REG  UART_UBRRxL_REG_OFFSET(UCSRxA)
#define UBRRxH_REG  UART_UBRRxH_REG_OFFSET(UCSRxA)
#define UDRx_REG    UART_UDRx_REG_OFFSET(UCSRxA)

//---- END UART SECTION ----//

//---- SPI SECTION ----//

#define SPIx_CFG_REG SPIx_CFG_REG

#define SPIx_STAT_REG_OFFSET(x) (x  + 1)
#define SPIx_DATA_REG_OFFSET(x) (x  + 2)

#define SPIx_STAT_REG SPIx_STAT_REG_OFFSET(SPIx_CFG_REG)
#define SPIx_DATA_REG SPIx_DATA_REG_OFFSET(SPIx_CFG_REG)


//---- END SPI SECTION ----//

namespace core {

    namespace mega {

	constexpr u8t bitToValue[] = {1, 2, 4, 8, 16, 32, 64, 128};

	namespace timer {

	    constexpr u16t hw_timer_addr[] = {0x24 + __SFR_OFFSET, 0x80, 0xB0, 0x90, 0xA0, 0x120};

	    /**
	     * @brief The TIMER16 enum Contains the address of 16Bit timers
	     */
	    enum class TIMER16 : int
	    {
		TIMER1 = core::mega::timer::hw_timer_addr[1],
		TIMER3 = core::mega::timer::hw_timer_addr[3],
		TIMER4 = core::mega::timer::hw_timer_addr[4],
		TIMER5 = core::mega::timer::hw_timer_addr[5]

	    };

	    /**
	     * @brief The TIMER8 enum Contains the address of 8Bit timers
	     */
	    enum class TIMER8 : int {
		TIMER0 = core::mega::timer::hw_timer_addr[0],
		TIMER2 = core::mega::timer::hw_timer_addr[2]
	    };

	    /**
	     * @brief The OUTPUT_COMP_BIT enum
	     */
	    enum OUTPUT_COMP_BIT {
		COMxA1 = 7,
		COMxA0 = 6,
		COMxB1 = 5,
		COMxB0 = 4,
		COMxC1 = 3,
		COMxC0 = 2
	    };

	    enum CLOCK_SEL_BIT {
		CSx0  = 0,
		CSx1  = 1,
		CSx2  = 2
	    };

	    enum WAVEFORM_GEN_BIT {
		WGMx0 = 0,
		WGMx1 = 1,
		WGMx2 = 3,
		WGMx3 = 4
	    };

	    enum OUT_COMP_NON_PWM : u8t
	    {
		NON_PWM_OCxA_MODE_DISCONNECTED  = (setBitValue(0, COMxA1) | setBitValue(0, COMxA0)),
		NON_PWM_OCxB_MODE_DISCONNECTED  = (setBitValue(0, COMxB1) | setBitValue(0, COMxB0)),
		NON_PWM_OCxC_MODE_DISCONNECTED  = (setBitValue(0, COMxC1) | setBitValue(0, COMxC0)),

		NON_PWM_OCxA_MODE_TOGGLE  = (setBitValue(0, COMxA1) | setBitValue(1, COMxA0)),
		NON_PWM_OCxB_MODE_TOGGLE  = (setBitValue(0, COMxB1) | setBitValue(1, COMxB0)),
		NON_PWM_OCxC_MODE_TOGGLE  = (setBitValue(0, COMxC1) | setBitValue(1, COMxC0)),

		NON_PWM_OCxA_MODE_CLEAR = (setBitValue(1, COMxA1) | setBitValue(0, COMxA0)),
		NON_PWM_OCxB_MODE_CLEAR = (setBitValue(1, COMxB1) | setBitValue(0, COMxB0)),
		NON_PWM_OCxC_MODE_CLEAR = (setBitValue(1, COMxC1) | setBitValue(0, COMxC0)),

		NON_PWM_OCxA_MODE_SET	= (setBitValue(1, COMxA1) | setBitValue(1, COMxA0)),
		NON_PWM_OCxB_MODE_SET	= (setBitValue(1, COMxB1) | setBitValue(1, COMxB0)),
		NON_PWM_OCxC_MODE_SET	= (setBitValue(1, COMxC1) | setBitValue(1, COMxC0))
	    };

	    enum OUT_COMP_FAST_PWM : u8t
	    {
		FAST_PWM_OCxA_MODE_DISCONNECTED  = (setBitValue(0, COMxA1) | setBitValue(0, COMxA0)),
		FAST_PWM_OCxB_MODE_DISCONNECTED  = (setBitValue(0, COMxB1) | setBitValue(0, COMxB0)),
		FAST_PWM_OCxC_MODE_DISCONNECTED  = (setBitValue(0, COMxC1) | setBitValue(0, COMxC0)),

		FAST_PWM_OCxA_MODE_CLEAR = (setBitValue(1, COMxA1) | setBitValue(0, COMxA0)),
		FAST_PWM_OCxB_MODE_CLEAR = (setBitValue(1, COMxB1) | setBitValue(0, COMxB0)),
		FAST_PWM_OCxC_MODE_CLEAR = (setBitValue(1, COMxC1) | setBitValue(0, COMxC0)),

		FAST_PWM_OCxA_MODE_SET	= (setBitValue(1, COMxA1) | setBitValue(1, COMxA0)),
		FAST_PWM_OCxB_MODE_SET	= (setBitValue(1, COMxB1) | setBitValue(1, COMxB0)),
		FAST_PWM_OCxC_MODE_SET	= (setBitValue(1, COMxC1) | setBitValue(1, COMxC0))
	    };

	    enum OUT_COMP_PHASE_CORRECT_PHASE_FREQUENCY_CORRECT : u8t
	    {
		FREQ_PHASE_CORRECT_OCxA_MODE_DISCONNECTED  = (setBitValue(0, COMxA1) | setBitValue(0, COMxA0)),
		FREQ_PHASE_CORRECT_OCxB_MODE_DISCONNECTED  = (setBitValue(0, COMxB1) | setBitValue(0, COMxB0)),
		FREQ_PHASE_CORRECT_OCxC_MODE_DISCONNECTED  = (setBitValue(0, COMxC1) | setBitValue(0, COMxC0)),

		FREQ_PHASE_CORRECT_OCxA_MODE_CLEAR  = (setBitValue(1, COMxA1) | setBitValue(0, COMxA0)),
		FREQ_PHASE_CORRECT_OCxB_MODE_CLEAR  = (setBitValue(1, COMxB1) | setBitValue(0, COMxB0)),
		FREQ_PHASE_CORRECT_OCxC_MODE_CLEAR  = (setBitValue(1, COMxC1) | setBitValue(0, COMxC0)),

		FREQ_PHASE_CORRECT_OCxA_MODE_SET    = (setBitValue(1, COMxA1) | setBitValue(1, COMxA0)),
		FREQ_PHASE_CORRECT_OCxB_MODE_SET    = (setBitValue(1, COMxB1) | setBitValue(1, COMxB0)),
		FREQ_PHASE_CORRECT_OCxC_MODE_SET    = (setBitValue(1, COMxC1) | setBitValue(1, COMxC0))
	    };

	    enum COMMON_PESCALER : u8t
	    {
		TIMERn_xBIT_NO_CLOCK	    = setBitValue(0, CSx2) | setBitValue(0, CSx1) | setBitValue(0, CSx0),
		TIMERn_xBIT_PRESCALER_1	    = setBitValue(0, CSx2) | setBitValue(0, CSx1) | setBitValue(1, CSx0),
		TIMERn_xBIT_PRESCALER_8	    = setBitValue(0, CSx2) | setBitValue(1, CSx1) | setBitValue(0, CSx0),
		TIMERn_xBIT_PRESCALER_64    = setBitValue(0, CSx2) | setBitValue(1, CSx1) | setBitValue(1, CSx0),
		TIMERn_xBIT_PRESCALER_256   = setBitValue(1, CSx2) | setBitValue(0, CSx1) | setBitValue(0, CSx0),
		TIMERn_xBIT_PRESCALER_1024  = setBitValue(1, CSx2) | setBitValue(0, CSx1) | setBitValue(1, CSx0),
		TIMERn_xBIT_Tn_FALLING_EDGE = setBitValue(1, CSx2) | setBitValue(1, CSx1) | setBitValue(0, CSx0),
		TIMERn_xBIT_Tn_RISING_EDGE  = setBitValue(1, CSx2) | setBitValue(1, CSx1) | setBitValue(1, CSx0)
	    };

	    enum TIMER2_PESCALER : u8t
	    {
		TIMER2_8BIT_PRESCALER_32   = setBitValue(0, CSx2) | setBitValue(1, CSx1) | setBitValue(1, CSx0),
		TIMER2_8BIT_PRESCALER_64   = setBitValue(1, CSx2) | setBitValue(0, CSx1) | setBitValue(0, CSx0),
		TIMER2_8BIT_PRESCALER_128  = setBitValue(1, CSx2) | setBitValue(0, CSx1) | setBitValue(1, CSx0),
		TIMER2_8BIT_PRESCALER_256  = setBitValue(1, CSx2) | setBitValue(1, CSx1) | setBitValue(0, CSx0),
		TIMER2_8BIT_PRESCALER_1024 = setBitValue(1, CSx2) | setBitValue(1, CSx1) | setBitValue(1, CSx0)
	    };

	    enum COMMON_8BIT_WAVEFORM : int
	    {
		WAVEFORM_NORMAL_TOP_0XFF	= toWord(setBitValue(0, WGMx2), setBitValue(0, WGMx1) | setBitValue(0, WGMx0)),
		WAVEFORM_PH_CORRECT_TOP_0XFF	= toWord(setBitValue(0, WGMx2), setBitValue(0, WGMx1) | setBitValue(1, WGMx0)),
		WAVEFORM_CTC_TOP_OCRA		= toWord(setBitValue(0, WGMx2), setBitValue(1, WGMx1) | setBitValue(0, WGMx0)),
		WAVEFORM_FAST_PWM_TOP_0XFF	= toWord(setBitValue(0, WGMx2), setBitValue(1, WGMx1) | setBitValue(1, WGMx0)),
		WAVEFORM_PH_CORRECT_TOP_OCRA	= toWord(setBitValue(1, WGMx2), setBitValue(0, WGMx1) | setBitValue(1, WGMx0)),
		WAVEFORM_FAST_PWM_TOP_OCRA	= toWord(setBitValue(1, WGMx2), setBitValue(1, WGMx1) | setBitValue(1, WGMx0))
	    };

	    enum COMMON_16BIT_WAVEFORM : int
	    {
		WAVEFORM_NORMAL_TOP_0XFFFF	    = toWord(setBitValue(0, WGMx3) | setBitValue(0, WGMx2), setBitValue(0, WGMx1) | setBitValue(0, WGMx0)),
		WAVEFORM_PH_CORRECT_TOP_0X00FF	    = toWord(setBitValue(0, WGMx3) | setBitValue(0, WGMx2), setBitValue(0, WGMx1) | setBitValue(1, WGMx0)),
		WAVEFORM_PH_CORRECT_TOP_0X01FF	    = toWord(setBitValue(0, WGMx3) | setBitValue(0, WGMx2), setBitValue(1, WGMx1) | setBitValue(0, WGMx0)),
		WAVEFORM_PH_CORRECT_TOP_0X03FF	    = toWord(setBitValue(0, WGMx3) | setBitValue(0, WGMx2), setBitValue(1, WGMx1) | setBitValue(1, WGMx0)),
		WAVEFORM_CTC_TOP_OCRxA		    = toWord(setBitValue(0, WGMx3) | setBitValue(1, WGMx2), setBitValue(0, WGMx1) | setBitValue(0, WGMx0)),
		WAVEFORM_FAST_PWM_TOP_0X00FF	    = toWord(setBitValue(0, WGMx3) | setBitValue(1, WGMx2), setBitValue(0, WGMx1) | setBitValue(1, WGMx0)),
		WAVEFORM_FAST_PWM_TOP_0X01FF	    = toWord(setBitValue(0, WGMx3) | setBitValue(1, WGMx2), setBitValue(1, WGMx1) | setBitValue(0, WGMx0)),
		WAVEFORM_FAST_PWM_TOP_0X03FF	    = toWord(setBitValue(0, WGMx3) | setBitValue(1, WGMx2), setBitValue(1, WGMx1) | setBitValue(1, WGMx0)),
		WAVEFORM_PH_CORRECT_FREQ_TOP_ICRx   = toWord(setBitValue(1, WGMx3) | setBitValue(0, WGMx2), setBitValue(0, WGMx1) | setBitValue(0, WGMx0)),
		WAVEFORM_PH_CORRECT_FREQ_TOP_OCRxA  = toWord(setBitValue(1, WGMx3) | setBitValue(0, WGMx2), setBitValue(0, WGMx1) | setBitValue(1, WGMx0)),
		WAVEFORM_PH_CORRECT_TOP_ICRx	    = toWord(setBitValue(1, WGMx3) | setBitValue(0, WGMx2), setBitValue(1, WGMx1) | setBitValue(0, WGMx0)),
		WAVEFORM_PH_CORRECT_TOP_OCRxA	    = toWord(setBitValue(1, WGMx3) | setBitValue(0, WGMx2), setBitValue(1, WGMx1) | setBitValue(1, WGMx0)),
		WAVEFORM_CTC_TOP_ICRx		    = toWord(setBitValue(1, WGMx3) | setBitValue(1, WGMx2), setBitValue(0, WGMx1) | setBitValue(0, WGMx0)),
		WAVEFORM_FAST_PWM_TOP_ICRx	    = toWord(setBitValue(1, WGMx3) | setBitValue(1, WGMx2), setBitValue(1, WGMx1) | setBitValue(0, WGMx0)),
		WAVEFORM_FAST_PWM_TOP_OCRxA	    = toWord(setBitValue(1, WGMx3) | setBitValue(1, WGMx2), setBitValue(1, WGMx1) | setBitValue(1, WGMx0))

	    };
	}

	namespace adc {

	    enum ADCSRA_REG_BITS : u8t
	    {
		BIT_ADEN  =  7,
		BIT_ADSC  =  6,
		BIT_ADATE =  5,
		BIT_ADIF  =  4,
		BIT_ADIE  =  3,
		BIT_ADPS2 =  2,
		BIT_ADPS1 =  1,
		BIT_ADPS0 =  0
	    };

	    enum ADCSRB_REG_BITS : u8t
	    {
		BIT_ACME   = 6,
		BIT_MUX5   = 3,
		BIT_ADTS2  = 2,
		BIT_ADTS1  = 1,
		BIT_ADTS0  = 0
	    };

	    enum ADMUX_REG_BITS : u8t
	    {
		BIT_REFS1  = 7,
		BIT_REFS0  = 6,
		BIT_ADLAR  = 5,
		BIT_MUX4   = 4,
		BIT_MUX3   = 3,
		BIT_MUX2   = 2,
		BIT_MUX1   = 1,
		BIT_MUX0   = 0
	    };

	    enum class ADC_VREF : u8t
	    {
		INTERNAL_VREF   = setBitValue(0, BIT_REFS1) | setBitValue(0, BIT_REFS0), // AREF,Internal VREF turned OFF
		AVCC            = setBitValue(0, BIT_REFS1) | setBitValue(1, BIT_REFS0), // AVCC at AREF Pin with external capacitor
		INTERNAL_1_1V   = setBitValue(1, BIT_REFS1) | setBitValue(0, BIT_REFS0), // Internal 1.1Voltage reference with external capacitor at AREF pin
		INTERNAL_2_56V  = setBitValue(1, BIT_REFS1) | setBitValue(1, BIT_REFS0), // Internal 2.56Voltage reference with external capacitor at AREF pin
	    };

	    enum class ADCSRA_PRESCALER : u8t
	    {
		F_CPU_BY_2	= setBitValue(0, BIT_ADPS2) | setBitValue(0, BIT_ADPS1) | setBitValue(1, BIT_ADPS0),
		F_CPU_BY_4	= setBitValue(0, BIT_ADPS2) | setBitValue(1, BIT_ADPS1) | setBitValue(0, BIT_ADPS0),
		F_CPU_BY_8	= setBitValue(0, BIT_ADPS2) | setBitValue(1, BIT_ADPS1) | setBitValue(1, BIT_ADPS0),
		F_CPU_BY_16	= setBitValue(1, BIT_ADPS2) | setBitValue(0, BIT_ADPS1) | setBitValue(0, BIT_ADPS0),
		F_CPU_BY_32	= setBitValue(1, BIT_ADPS2) | setBitValue(0, BIT_ADPS1) | setBitValue(1, BIT_ADPS0),
		F_CPU_BY_64	= setBitValue(1, BIT_ADPS2) | setBitValue(1, BIT_ADPS1) | setBitValue(0, BIT_ADPS0),
		F_CPU_BY_128	= setBitValue(1, BIT_ADPS2) | setBitValue(1, BIT_ADPS1) | setBitValue(1, BIT_ADPS0)
	    };

	    enum class ADCSRB_AUTOTRIGGER : u8t
	    {
		FREE_RUNNING_MODE	    =  setBitValue(0, BIT_ADTS2) | setBitValue(0, BIT_ADTS1) | setBitValue(0, BIT_ADTS0),
		ANALOG_COMPARATOR	    =  setBitValue(0, BIT_ADTS2) | setBitValue(0, BIT_ADTS1) | setBitValue(1, BIT_ADTS0),
		EXTERNAL_INTERRUPT_REQ_0    =  setBitValue(0, BIT_ADTS2) | setBitValue(1, BIT_ADTS1) | setBitValue(0, BIT_ADTS0),
		TNCT0_COMP_A		    =  setBitValue(0, BIT_ADTS2) | setBitValue(1, BIT_ADTS1) | setBitValue(1, BIT_ADTS0),
		TNCT0_OVERFLOW		    =  setBitValue(1, BIT_ADTS2) | setBitValue(0, BIT_ADTS1) | setBitValue(0, BIT_ADTS0),
		TNCT1_COMP_B		    =  setBitValue(1, BIT_ADTS2) | setBitValue(0, BIT_ADTS1) | setBitValue(1, BIT_ADTS0),
		TNCT1_OVERFLOW		    =  setBitValue(1, BIT_ADTS2) | setBitValue(1, BIT_ADTS1) | setBitValue(0, BIT_ADTS0),
		TNCT1_CAPTURE_EVENT	    =  setBitValue(1, BIT_ADTS2) | setBitValue(1, BIT_ADTS1) | setBitValue(1, BIT_ADTS0)
	    };

	}

	namespace uart {

	}
	namespace spi {

	    enum SPCR_REG_BITS : u8t
	    {
		BIT_SPIE    = 7,
		BIT_SPE     = 6,
		BIT_DORD    = 5,
		BIT_MSTR    = 4,
		BIT_CPOL    = 3,
		BIT_CPHA    = 2,
		BIT_SPR1    = 1,
		BIT_SPR0    = 0
	    };

	    enum SPSR_REG_BITS : u8t
	    {
		BIT_SPIF    = 7,
		BIT_WCOL    = 6,
		BIT_SPI2X   = 0
	    };

	    enum SPI_DORD: u8t {
		MSB_FIRST = setBitValue(0, BIT_DORD),
		LSB_FIRST = setBitValue(1, BIT_DORD)
	    };

	    enum SPI_CLKSEL: u16t {
		FOSC_BY_4   = toWord(setBitValue(0, BIT_SPI2X), setBitValue(0, BIT_SPR1) | setBitValue(0, BIT_SPR0)),
		FOSC_BY_16  = toWord(setBitValue(0, BIT_SPI2X), setBitValue(0, BIT_SPR1) | setBitValue(1, BIT_SPR0)),
		FOSC_BY_64  = toWord(setBitValue(0, BIT_SPI2X), setBitValue(1, BIT_SPR1) | setBitValue(0, BIT_SPR0)),
		FOSC_BY_128 = toWord(setBitValue(0, BIT_SPI2X), setBitValue(1, BIT_SPR1) | setBitValue(1, BIT_SPR0)),
		FOSC_BY_2   = toWord(setBitValue(1, BIT_SPI2X), setBitValue(0, BIT_SPR1) | setBitValue(0, BIT_SPR0)),
		FOSC_BY_8   = toWord(setBitValue(1, BIT_SPI2X), setBitValue(0, BIT_SPR1) | setBitValue(1, BIT_SPR0)),
		FOSC_BY_32  = toWord(setBitValue(1, BIT_SPI2X), setBitValue(1, BIT_SPR1) | setBitValue(0, BIT_SPR0))
	    };

	    enum SPI_MODE : u8t {
		MODE_0 = setBitValue(0, BIT_CPOL) | setBitValue(0, BIT_CPHA),
		MODE_1 = setBitValue(0, BIT_CPOL) | setBitValue(1, BIT_CPHA),
		MODE_2 = setBitValue(1, BIT_CPOL) | setBitValue(0, BIT_CPHA),
		MODE_3 = setBitValue(1, BIT_CPOL) | setBitValue(1, BIT_CPHA)
	    };
	}
    }
}

/*
#define SPI0_CFG_REG &SPCR
#define SPI0_CFG_BIT_SPIE    SPIE
#define SPI0_CFG_BIT_SPE     SPE
#define SPI0_CFG_BIT_DORD    DORD
#define SPI0_CFG_BIT_MSTR    MSTR
#define SPI0_CFG_BIT_CPOL    CPOL
#define SPI0_CFG_BIT_CPHA    CPHA
#define SPI0_CFG_BIT_SPR1    SPR1
#define SPI0_CFG_BIT_SPR0    SPR0

#define SPI0_STAT_REG SPSR
#define SPI0_STAT_BIT_SPIF    SPIF
#define SPI0_STAT_BIT_WCOL    WCOL
#define SPI0_STAT_BIT_SPI2X   SPI2X

#define SPI0_DATA_REG SPDR



#define SPI_CFG_BIT_SPIE    SPIE
#define SPI_CFG_BIT_SPE     SPE
#define SPI_CFG_BIT_DORD    DORD
#define SPI_CFG_BIT_MSTR    MSTR
#define SPI_CFG_BIT_CPOL    CPOL
#define SPI_CFG_BIT_CPHA    CPHA
#define SPI_CFG_BIT_SPR1    SPR1
#define SPI_CFG_BIT_SPR0    SPR0

#define SPI_STAT_BIT_SPIF    SPIF
#define SPI_STAT_BIT_WCOL    WCOL
#define SPI_STAT_BIT_SPI2X   SPI2X
*/


#define SPI0_MASTER_INIT do	{ \
    DDRB = setBitValue(1, PB0) | setBitValue(1, PB1) | \
    setBitValue(1, PB2) | setBitValue(0, PB3); \
    PORTB |= bitValue(PB0);	\
    } while(0);

#define SPI0_SLAVE_INIT do	{ \
    DDRB = setBitValue(0, PB0) | setBitValue(0, PB1) | \
    setBitValue(0, PB2) | setBitValue(1, PB3); \
    bitSet(SPCR, SPI_CFG_BIT_SPE); \
    } while(0);


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


