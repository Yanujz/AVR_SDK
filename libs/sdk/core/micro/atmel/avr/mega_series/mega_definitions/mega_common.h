#pragma once
#include <avr/pgmspace.h>
#include <avr/eeprom.h>
#include <common_macros.h>
#include <avr/io.h>
#include <util/delay.h>
#include <mega_registers.h>

///@file




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

//#define UCSRxA UCSRxA

#define UART_UCSRxB_REG_OFFSET(x) (x  + 1)
#define UART_UCSRxC_REG_OFFSET(x) (x  + 2)
#define UART_UBRRxL_REG_OFFSET(x) (x  + 4)
#define UART_UBRRxH_REG_OFFSET(x) (x  + 5)
#define UART_UDRx_REG_OFFSET(x)   (x  + 6)


//#define UCSRxB_REG  UART_UCSRxB_REG_OFFSET(UCSRxA)
//#define UCSRxC_REG  UART_UCSRxC_REG_OFFSET(UCSRxA)
//#define UBRRxL_REG  UART_UBRRxL_REG_OFFSET(UCSRxA)
//#define UBRRxH_REG  UART_UBRRxH_REG_OFFSET(UCSRxA)
//#define UDRx_REG    UART_UDRx_REG_OFFSET(UCSRxA)

//---- END UART SECTION ----//

//---- SPI SECTION ----//

#define SPIx_CFG_REG SPIx_CFG_REG

#define SPIx_STAT_REG_OFFSET(x) (x  + 1)
#define SPIx_DATA_REG_OFFSET(x) (x  + 2)

#define SPIx_STAT_REG SPIx_STAT_REG_OFFSET(SPIx_CFG_REG)
#define SPIx_DATA_REG SPIx_DATA_REG_OFFSET(SPIx_CFG_REG)


//---- END SPI SECTION ----//

//---- I2C SECTION ----//

#define I2Cx_STAT_REG_OFFSET(x) (x + 1)
#define I2Cx_SLAVE_REG_OFFSET(x) (x + 2)
#define I2Cx_DATA_REG_OFFSET(x) (x + 3)
#define I2Cx_CTRL_REG_OFFSET(x) (x + 4)
#define I2Cx_SLAVE_MSK_REG_OFFSET(x) (x + 5)
#define I2C_STAT_MASK 0xF8
//---- END I2C SECTION ----//
namespace core {

namespace mega {

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

enum class ADC_VREF : u8t
{
  INTERNAL_VREF   = setBitValue(0, REFS1) | setBitValue(0, REFS0), // AREF,Internal VREF turned OFF
  AVCC            = setBitValue(0, REFS1) | setBitValue(1, REFS0), // AVCC at AREF Pin with external capacitor
  INTERNAL_1_1V   = setBitValue(1, REFS1) | setBitValue(0, REFS0), // Internal 1.1Voltage reference with external capacitor at AREF pin
  INTERNAL_2_56V  = setBitValue(1, REFS1) | setBitValue(1, REFS0), // Internal 2.56Voltage reference with external capacitor at AREF pin
};

enum class ADCSRA_PRESCALER : u8t
{
  F_CPU_BY_2	= setBitValue(0, ADPS2) | setBitValue(0, ADPS1) | setBitValue(1, ADPS0),
  F_CPU_BY_4	= setBitValue(0, ADPS2) | setBitValue(1, ADPS1) | setBitValue(0, ADPS0),
  F_CPU_BY_8	= setBitValue(0, ADPS2) | setBitValue(1, ADPS1) | setBitValue(1, ADPS0),
  F_CPU_BY_16	= setBitValue(1, ADPS2) | setBitValue(0, ADPS1) | setBitValue(0, ADPS0),
  F_CPU_BY_32	= setBitValue(1, ADPS2) | setBitValue(0, ADPS1) | setBitValue(1, ADPS0),
  F_CPU_BY_64	= setBitValue(1, ADPS2) | setBitValue(1, ADPS1) | setBitValue(0, ADPS0),
  F_CPU_BY_128	= setBitValue(1, ADPS2) | setBitValue(1, ADPS1) | setBitValue(1, ADPS0)
};

enum class ADCSRB_AUTOTRIGGER : u8t
{
  FREE_RUNNING_MODE	    =  setBitValue(0, ADTS2) | setBitValue(0, ADTS1) | setBitValue(0, ADTS0),
  ANALOG_COMPARATOR	    =  setBitValue(0, ADTS2) | setBitValue(0, ADTS1) | setBitValue(1, ADTS0),
  EXTERNAL_INTERRUPT_REQ_0    =  setBitValue(0, ADTS2) | setBitValue(1, ADTS1) | setBitValue(0, ADTS0),
  TNCT0_COMP_A		    =  setBitValue(0, ADTS2) | setBitValue(1, ADTS1) | setBitValue(1, ADTS0),
  TNCT0_OVERFLOW		    =  setBitValue(1, ADTS2) | setBitValue(0, ADTS1) | setBitValue(0, ADTS0),
  TNCT1_COMP_B		    =  setBitValue(1, ADTS2) | setBitValue(0, ADTS1) | setBitValue(1, ADTS0),
  TNCT1_OVERFLOW		    =  setBitValue(1, ADTS2) | setBitValue(1, ADTS1) | setBitValue(0, ADTS0),
  TNCT1_CAPTURE_EVENT	    =  setBitValue(1, ADTS2) | setBitValue(1, ADTS1) | setBitValue(1, ADTS0)
};

}

namespace uart {

enum USART_MODE_SELECT : u8t
{
  ASYNC_MODE  = setBitValue(0, UCSRxC_BIT::UMSELx1) | setBitValue(0, UCSRxC_BIT::UMSELx0),
  SYNC_MODE   = setBitValue(0, UCSRxC_BIT::UMSELx1) | setBitValue(0, UCSRxC_BIT::UMSELx0),
  MASTER_SPI  = setBitValue(0, UCSRxC_BIT::UMSELx1) | setBitValue(0, UCSRxC_BIT::UMSELx0)
};
enum USART_PARITY_MODE : u8t
{
  PARITY_DISABLED = setBitValue(0, UCSRxC_BIT::UPMx1) | setBitValue(0, UCSRxC_BIT::UPMx1),
  EVEN_PARITY	= setBitValue(1, UCSRxC_BIT::UPMx1) | setBitValue(0, UCSRxC_BIT::UPMx1),
  ODD_PARITY	= setBitValue(1, UCSRxC_BIT::UPMx1) | setBitValue(1, UCSRxC_BIT::UPMx1)
};
enum USART_STOP_BIT_SELECT : u8t
{
  ONE_STOP_BIT = setBitValue(0, UCSRxC_BIT::USBSx),
  TWO_STOP_BIT = setBitValue(1, UCSRxC_BIT::USBSx)
};
enum USART_CHAR_SIZE : u8t
{
  FIVE_BIT    = setBitValue(0, UCSRxC_BIT::UCSZx1) | setBitValue(0, UCSRxC_BIT::UCSZx0),
  SIX_BIT	    = setBitValue(0, UCSRxC_BIT::UCSZx1) | setBitValue(1, UCSRxC_BIT::UCSZx0),
  SEVEN_BIT   = setBitValue(1, UCSRxC_BIT::UCSZx1) | setBitValue(0, UCSRxC_BIT::UCSZx0),
  EIGHT_BIT   = setBitValue(1, UCSRxC_BIT::UCSZx1) | setBitValue(1, UCSRxC_BIT::UCSZx0),
  //NINE_BIT    = toWord(setBitValue(1, UCSRxB_BIT::UCSZx2), setBitValue(1, UCSRxC_BIT::UCSZx1) | setBitValue(1, UCSRxC_BIT::UCSZx1))
};


#if defined(__COMPILE__)
#if F_CPU == 16000000
enum class HW_UART : u16{
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

}
namespace spi {

enum SPI_DORD: u8t
{
  MSB_FIRST = setBitValue(0, SPCRx_BIT::DORD),
  LSB_FIRST = setBitValue(1, SPCRx_BIT::DORD)
};

enum SPI_CLKSEL: u16t
{
  FOSC_BY_4   = toWord(setBitValue(0, SPSRx_BIT::SPI2X), setBitValue(0, SPCRx_BIT::SPR1) | setBitValue(0, SPCRx_BIT::SPR0)),
  FOSC_BY_16  = toWord(setBitValue(0, SPSRx_BIT::SPI2X), setBitValue(0, SPCRx_BIT::SPR1) | setBitValue(1, SPCRx_BIT::SPR0)),
  FOSC_BY_64  = toWord(setBitValue(0, SPSRx_BIT::SPI2X), setBitValue(1, SPCRx_BIT::SPR1) | setBitValue(0, SPCRx_BIT::SPR0)),
  FOSC_BY_128 = toWord(setBitValue(0, SPSRx_BIT::SPI2X), setBitValue(1, SPCRx_BIT::SPR1) | setBitValue(1, SPCRx_BIT::SPR0)),
  FOSC_BY_2   = toWord(setBitValue(1, SPSRx_BIT::SPI2X), setBitValue(0, SPCRx_BIT::SPR1) | setBitValue(0, SPCRx_BIT::SPR0)),
  FOSC_BY_8   = toWord(setBitValue(1, SPSRx_BIT::SPI2X), setBitValue(0, SPCRx_BIT::SPR1) | setBitValue(1, SPCRx_BIT::SPR0)),
  FOSC_BY_32  = toWord(setBitValue(1, SPSRx_BIT::SPI2X), setBitValue(1, SPCRx_BIT::SPR1) | setBitValue(0, SPCRx_BIT::SPR0))
};

enum SPI_MODE : u8t {
  MODE_0 = setBitValue(0, SPCRx_BIT::CPOL) | setBitValue(0, SPCRx_BIT::CPHA),
  MODE_1 = setBitValue(0, SPCRx_BIT::CPOL) | setBitValue(1, SPCRx_BIT::CPHA),
  MODE_2 = setBitValue(1, SPCRx_BIT::CPOL) | setBitValue(0, SPCRx_BIT::CPHA),
  MODE_3 = setBitValue(1, SPCRx_BIT::CPOL) | setBitValue(1, SPCRx_BIT::CPHA)
};
}
namespace i2c {
#if defined(__COMPILE__)
#if F_CPU == 16000000
/*
		The below numbers are calculated with the formula:
		((((F_CPU / x) / Prescaler) - 16 ) / 2)
		*/
enum class F_SCL: u8t {
  SCL_500KHZ = 8,
  SCL_400KHZ = 12,
  SCL_320KHZ = 17,
  SCL_250KHZ = 24,
  SCL_200KHZ = 32,
  SCL_160KHZ = 42,
  SCL_125KHZ = 56,
  SCL_100KHZ = 72,
  SCL_80KHZ  = 92,
  SCL_64KHZ  = 117,
  SCL_50KHZ  = 152,
  SCL_40KHZ  = 192,
  SCL_32KHZ  = 242,
  SCL_31250HZ  = 248
};
#endif
#else
enum class F_SCL: u8t {
  SCL_500KHZ,
  SCL_400KHZ,
  SCL_320KHZ,
  SCL_250KHZ,
  SCL_200KHZ,
  SCL_160KHZ,
  SCL_125KHZ,
  SCL_100KHZ,
  SCL_80KHZ,
  SCL_64KHZ,
  SCL_50KHZ,
  SCL_40KHZ,
  SCL_32KHZ,
  SCL_31250HZ
};
#endif

}
namespace common_typef {
typedef struct{
  u8 PIN;
  u8 DDR;
  u8 PORT;
} GPIO_Typedef;

typedef struct {
  u8t TCCRA;
  u8t TCCRB;
  u8t TCNT;
  u8t OCRA;
  u8t OCRB;
} TIMER8_TypeDef;
typedef struct {
  u8 TCCRA;
  u8 TCCRB;
  u8 TCCRC;
  const u8/*Padding*/ :8;
  u16 TCNT;
  u16 ICR;
  u16 OCRA;
  u16 OCRB;
  u16 OCRC;
} TIMER16_TypeDef;
}
}
}


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




