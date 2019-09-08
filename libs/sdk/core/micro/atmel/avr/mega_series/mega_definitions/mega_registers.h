#pragma once
#include <core.h>
#include <avr/io.h>
#define ATmega48PA_88PA_168PA_328P defined(__ATMEGA48PA__) || defined(__ATMEGA88PA__) || \
    defined(__ATMEGA168PA__) || defined(__ATMEGA328P__)

#define ATmega640_1280_1281_2560_2561 defined(__ATMEGA640__) || defined(__ATMEGA1280__) || \
    defined(__ATMEGA2560__) || defined(__ATMEGA1281__) || defined(__ATMEGA2561__)

#define ATmega328PB defined(__ATMEGA328PB__)

#if ATmega640_1280_1281_2560_2561

#define PINA    _SFR_IO8(0X00)
#define DDRA    _SFR_IO8(0X01)
#define PORTA   _SFR_IO8(0X02)

#endif

#if ATmega48PA_88PA_168PA_328P || ATmega328PB || ATmega640_1280_1281_2560_2561

#define PINB    _SFR_IO8(0X03)
#define DDRB    _SFR_IO8(0x04)
#define PORTB   _SFR_IO8(0x05)

#define PINC    _SFR_IO8(0x06)
#define DDRC    _SFR_IO8(0x07)
#define PORTC   _SFR_IO8(0x08)

#define PIND    _SFR_IO8(0x09)
#define DDRD    _SFR_IO8(0x0A)
#define PORTD   _SFR_IO8(0x0B)
#endif

#if ATmega328PB || ATmega640_1280_1281_2560_2561

#define PINE    _SFR_IO8(0x0C)
#define DDRE    _SFR_IO8(0x0D)
#define PORTE   _SFR_IO8(0x0E)

#endif

#if ATmega640_1280_1281_2560_2561

#define PINF    _SFR_IO8(0x0F)
#define DDRF    _SFR_IO8(0x10)
#define PORTF   _SFR_IO8(0x11)

#define PING    _SFR_IO8(0x12)
#define DDRG    _SFR_IO8(0x13)
#define PORTG   _SFR_IO8(0x14)


# define PINH   _SFR_MEM8(0x100)
# define DDRH   _SFR_MEM8(0x101)
# define PORTH  _SFR_MEM8(0x102)

# define PINJ   _SFR_MEM8(0x103)
# define DDRJ   _SFR_MEM8(0x104)
# define PORTJ  _SFR_MEM8(0x105)

# define PINK   _SFR_MEM8(0x106)
# define DDRK   _SFR_MEM8(0x107)
# define PORTK  _SFR_MEM8(0x108)

# define PINL   _SFR_MEM8(0x109)
# define DDRL   _SFR_MEM8(0x10A)
# define PORTL  _SFR_MEM8(0x10B)

#endif
enum GPIO_BIT {
    BIT0,
    BIT1,
    BIT2,
    BIT3,
    BIT4,
    BIT5,
    BIT6,
    BIT7
};


#if ATmega48PA_88PA_168PA_328P || ATmega328PB || ATmega640_1280_1281_2560_2561
#define TIFR0   _SFR_IO8(0x15)
#define TIFR1   _SFR_IO8(0x16)
#define TIFR2   _SFR_IO8(0x17)
#endif
#if ATmega328PB || ATmega640_1280_1281_2560_2561
#define TIFR3   _SFR_IO8(0x18)
#define TIFR4   _SFR_IO8(0x19)
#endif
#if ATmega640_1280_1281_2560_2561
#define TIFR5   _SFR_IO8(0x1A)
#endif


enum TIFRx {
    ICFx    = 5,
    OCFxC   = 3,
    OCFxB   = 2,
    OCFxA   = 1,
    TOVx    = 0
};


// Pin Change Interrupt Control Register
#define PCIFR   _SFR_IO8(0x1B)
#undef PCIF2
#undef PCIF1
#undef PCIF0
enum PCIFR_BIT {
    PCIF2 = 2, // Pin Change Interrupt Enable 2
    PCIF1 = 1, // Pin Change Interrupt Enable 1
    PCIF0 = 0  // Pin Change Interrupt Enable 0
};

#if ATmega48PA_88PA_168PA_328P || ATmega328PB || ATmega640_1280_1281_2560_2561
// External Interrupt Flag Register
#define EIFR   _SFR_IO8(0x1C)
#undef INTF7
#undef INTF6
#undef INTF5
#undef INTF4
#undef INTF3
#undef INTF2
#undef INTF1
#undef INTF0
enum EIFR_BIT {
#if ATmega640_1280_1281_2560_2561
    INTF7 = 7, // External Interrupt Flags 7
    INTF6 = 6, // External Interrupt Flags 6
    INTF5 = 5, // External Interrupt Flags 5
    INTF4 = 4, // External Interrupt Flags 4
    INTF3 = 3, // External Interrupt Flags 3
    INTF2 = 2, // External Interrupt Flags 2
#endif
#if ATmega48PA_88PA_168PA_328P || ATmega328PB || ATmega640_1280_1281_2560_2561
    INTF1 = 1, // External Interrupt Flags 1
    INTF0 = 0  // External Interrupt Flags 0
#endif
};
#endif

#if ATmega48PA_88PA_168PA_328P || ATmega328PB || ATmega640_1280_1281_2560_2561
// External Interrupt Mask Register
#define EIMSK   _SFR_IO8(0x1D)
#undef INT7
#undef INT6
#undef INT5
#undef INT4
#undef INT3
#undef INT2
#undef INT1
#undef INT0
enum EIMSK_BIT {
#if ATmega640_1280_1281_2560_2561
    INT7 = 7, // External Interrupt Request 7 Enable
    INT6 = 6, // External Interrupt Request 6 Enable
    INT5 = 5, // External Interrupt Request 5 Enable
    INT4 = 4, // External Interrupt Request 4 Enable
    INT3 = 3, // External Interrupt Request 3 Enable
    INT2 = 2, // External Interrupt Request 2 Enable
#endif
#if ATmega48PA_88PA_168PA_328P || ATmega328PB || ATmega640_1280_1281_2560_2561
    INT1 = 1, // External Interrupt Request 1 Enable
    INT0 = 0  // External Interrupt Request 0 Enable
#endif
};
#endif

#if ATmega48PA_88PA_168PA_328P || ATmega328PB || ATmega640_1280_1281_2560_2561
// General Purpose I/O Register 0
#define GPIOR0  _SFR_IO8(0x1E)
#endif

#if ATmega48PA_88PA_168PA_328P || ATmega328PB || ATmega640_1280_1281_2560_2561
// General Purpose I/O Register 1
#define GPIOR1  _SFR_IO8(0x2A)

// General Purpose I/O Register 1
#define GPIOR2  _SFR_IO8(0x2B)
#endif

// EEPROM Control Register
#define EECR    _SFR_IO8(0x1F)
#undef EEPM1
#undef EEPM0
#undef EERIE
#undef EEMPE
#undef EEPE
#undef EERE
enum EECR_BIT{
    EEPM1 = 5, // EEPROM Programming Mode Bits
    EEPM0 = 4, // EEPROM Programming Mode Bits
    EERIE = 3, // EEPROM Ready Interrupt Enable
    EEMPE = 2, // EEPROM Master Programming Enable
    EEPE  = 1, // EEPROM Programming Enable
    EERE  = 0  // EEPROM Read Enable
};

// EEPROM Data Register
#define EEDR    _SFR_IO8(0X20)

// EEPROM Read Enable
/* Combine EEARL and EEARH */
#define EEAR    _SFR_IO16(0x21)
#define EEARL   _SFR_IO8(0x21)
#define EEARH   _SFR_IO8(0X22)

/* 6-char sequence denoting where to find the EEPROM registers in memory space.
   Adresses denoted in hex syntax with uppercase letters. Used by the EEPROM
   subroutines.
   First two letters:  EECR address.
   Second two letters: EEDR address.
   Last two letters:   EEAR address.  */
#define __EEPROM_REG_LOCATIONS__ 1F2021

// General Timer/Counter Control Register
#define GTCCR   _SFR_IO8(0x23)
#undef TSM
#undef PSRASY
#undef PSRSYNC
enum GTCCR_BIT {
    TSM     = 7, // Timer/Counter Synchronization Mode
    PSRASY  = 1, // PSRASY: Prescaler Reset Timer/Counter2. Not sure if correct!
    PSRSYNC = 0  // Prescaler Reset for Synchronous Timer/Counters
};



#if ATmega48PA_88PA_168PA_328P || ATmega328PB || ATmega640_1280_1281_2560_2561
// SPI Control Register 0
#define SPCR0	_SFR_IO8(0x2C)

// SPI Status Register 0
#define SPSR0 _SFR_IO8(0x2D)

// SPI Data Register 0
#define SPDR0 _SFR_IO8(0x2E)
#endif


#if ATmega328PB
// SPI Control Register 1
#define SPCR1	_SFR_IO8(0xAC)

// SPI Status Register 0
#define SPSR1 _SFR_IO8(0xAD)

// SPI Data Register 0
#define SPDR1 _SFR_IO8(0xAE)
#endif

#undef SPIE
#undef SPE
#undef DORD
#undef MSTR
#undef CPOL
#undef CPHA
#undef SPR1
#undef SPR0
enum SPCRx_BIT {
    SPIE = 7, // SPIx Interrupt Enable
    SPE  = 6, // SPIx Enable
    DORD = 5, // Datax Order
    MSTR = 4, // Master/Slave1 Select
    CPOL = 3, // Clockx Polarity
    CPHA = 2, // Clockx Phase
    SPR1 = 1, // SPIx Clock Rate Select
    SPR0 = 0  // SPIx Clock Rate Select
};

#undef SPIF
#undef WCOL
#undef SPI2X
enum SPSRx_BIT {
    SPIF  = 7, // SPI Interrupt Flag
    WCOL  = 6, // Write Collision Flag
    SPI2X = 0  // Double SPI Speed Bit
};




// Analog Comparator Control and Status Register
#define ACSR _SFR_IO8(0x30)
#undef ACD
#undef ACBG
#undef ACO
#undef ACI
#undef ACIE
#undef ACIC
#undef ACIS1
#undef ACIS0
enum ACSR_BIT
{
    ACD   = 7, // Analog Comparator Disable
    ACBG  = 6, // Analog Comparator Bandgap Select
    ACO   = 5, // Analog Comparator Output
    ACI   = 4, // Analog Comparator Interrupt Flag
    ACIE  = 3, // Analog Comparator Interrupt Enable
    ACIC  = 2, // Analog Comparator Input Capture Enable
    ACIS1 = 1, // Analog Comparator Interrupt Mode Select
    ACIS0 = 0  // Analog Comparator Interrupt Mode Select
};


#if ATmega640_1280_1281_2560_2561
#define MONDR   _SFR_IO8(0x31)
#define OCDR    _SFR_IO8(0x31)
#define IDRD    7
#define OCDR7   7
#define OCDR6   6
#define OCDR5   5
#define OCDR4   4
#define OCDR3   3
#define OCDR2   2
#define OCDR1   1
#define OCDR0   0
#endif

#if ATmega48PA_88PA_168PA_328P || ATmega328PB || ATmega640_1280_1281_2560_2561
// Sleep Mode Control Register
#define SMCR _SFR_IO8(0x33)
#undef SM2
#undef SM1
#undef SM0
#undef SE
enum SMCR_BIT {
    SM2 = 3,// Sleep Mode Select Bits
    SM1 = 2,// Sleep Mode Select Bits
    SM0 = 1,// Sleep Mode Select Bits
    SE  = 0 // Sleep Enable
};
#endif

#if ATmega48PA_88PA_168PA_328P || ATmega328PB || ATmega640_1280_1281_2560_2561
// MCU Status Register
#define MCUSR   _SFR_IO8(0x34)
#undef JTRF
#undef WDRF
#undef BORF
#undef EXTRF
#undef PORF
enum MCUSR_BIT{
    JTRF  = 4, // JTAG Reset Flag
    WDRF  = 3, // Watchdog System Reset Flag
    BORF  = 2, // Brown-out Reset Flag
    EXTRF = 1, // External Reset Flag
    PORF  = 0  // Power-on Reset Flag
};
#endif

#if ATmega48PA_88PA_168PA_328P || ATmega328PB || ATmega640_1280_1281_2560_2561
// MCU Control Register
#define MCUCR   _SFR_IO8(0X35)
#undef JTD
#undef PUD
#undef IVSEL
#undef IVCE
enum MCUCR_BIT {
    JTD   = 7, //
    PUD   = 4, // Pull-up Disable
    IVSEL = 1, // Interrupt Vector Select
    IVCE  = 0  //  Interrupt Vector Change Enable
};
#endif

#if ATmega48PA_88PA_168PA_328P || ATmega328PB || ATmega640_1280_1281_2560_2561
// Store Program Memory Control and Status Register
#define SPMCSR  _SFR_IO8(0x37)
#undef SPMIE
#undef RWWSB
#undef SIGRD
#undef RWWSRE
#undef BLBSET
#undef PGWRT
#undef PGERS
#undef SPMEN
enum SPMCSR_BIT {
    SPMIE  = 7, // SPM Interrupt Enable
    RWWSB  = 6, // Read-While-Write Section Busy
    SIGRD  = 5, // Signature Row Read
    RWWSRE = 4, // Read-While-Write Section Read Enable
    BLBSET = 3, // Boot Lock Bit Set
    PGWRT  = 2, // Page Write
    PGERS  = 1, // Page Erase
    SPMEN  = 0  // Store Program Memory
};
#endif

#ifdef ATmega640_1280_1281_2560_2561
#define RAMPZ   _SFR_IO8(0X3B)
#define RAMPZ0  0

#define EIND    _SFR_IO8(0X3C)
#define EIND0   0
#endif

/* SP [0x3D..0x3E] */
/* SREG [0x3F] */


#if ATmega48PA_88PA_168PA_328P || ATmega328PB || ATmega640_1280_1281_2560_2561
// Watchdog Timer Control Register
#define WDTCSR  _SFR_MEM8(0x60)
#undef WDIF
#undef WDIE
#undef WDP3
#undef WDCE
#undef WDE
#undef WDP2
#undef WDP1
#undef WDP0
enum WDTCSR_BIT {
    WDIF = 7, // Watchdog Interrupt Flag
    WDIE = 6, // Watchdog Interrupt Enable
    WDP3 = 5, // Watchdog Timer Prescaler 3
    WDCE = 4, // Watchdog Change Enable
    WDE  = 3, // Watchdog System Reset Enable
    WDP2 = 2, // Watchdog Timer Prescaler 2
    WDP1 = 1, // Watchdog Timer Prescaler 1
    WDP0 = 0  // Watchdog Timer Prescaler 0
};
#endif


#if ATmega48PA_88PA_168PA_328P || ATmega328PB || ATmega640_1280_1281_2560_2561
// Clock Prescale Register
#define CLKPR   _SFR_MEM8(0x61)
#undef CLKPCE
#undef CLKPS3
#undef CLKPS2
#undef CLKPS1
#undef CLKPS0
enum CLPR_BIT {
    CLKPCE = 7, // Clock Prescaler Change Enable
    CLKPS3 = 3, // Clock Prescaler Select 3
    CLKPS2 = 2, // Clock Prescaler Select 2
    CLKPS1 = 1, // Clock Prescaler Select 1
    CLKPS0 = 0  // Clock Prescaler Select 0
};
#endif


#if ATmega48PA_88PA_168PA_328P || ATmega328PB || ATmega640_1280_1281_2560_2561
// Power Reduction Register 0
#define PRR0    _SFR_MEM8(0x64)
#undef PRTWI
#undef PRTIM2
#undef PRTIM0
#undef PRTIM1
#undef PRSPI
#undef PRUSART0
#undef PRADC
enum PPR0_BIT{
    PRTWI0   = 7, // Power Reduction TWI0
    PRTIM2   = 6, // Power Reduction Timer/Counter2
    PRTIM0   = 5, // Power Reduction Timer/Counter0
#if ATmega328PB
    PRUSART1 = 4, // Power Reduction USART1
#endif
    PRTIM1   = 3, // Power Reduction Timer/Counter1
    PRSPI0   = 2, // Power Reduction Serial Peripheral Interface 0
    PRUSART0 = 1, // Power Reduction USART0
    PRADC    = 0  // Power Reduction ADC
};
#endif

#if ATmega640_1280_1281_2560_2561
#define PRR1    _SFR_MEM8(0x65)
#undef PRTIM5
#undef PRTIM4
#undef PRTIM3
#undef PRUSART3
#undef PRUSART2
#undef PRUSART1
enum PRR1_BIT{
    PRTIM5   = 5, // Power Reduction Timer/Counter5
    PRTIM4   = 4, // Power Reduction Timer/Counter4
    PRTIM3   = 3, // Power Reduction Timer/Counter3
    PRUSART3 = 2, // Power Reduction USART3
    PRUSART2 = 1, // Power Reduction USART2
    PRUSART1 = 0  // Power Reduction USART1
};
#endif

#if ATmega48PA_88PA_168PA_328P || ATmega328PB || ATmega640_1280_1281_2560_2561
#define OSCCAL  _SFR_MEM8(0x66)
#endif

#if ATmega48PA_88PA_168PA_328P || ATmega328PB || ATmega640_1280_1281_2560_2561
// Pin Change Interrupt Control Register
#define PCICR   _SFR_MEM8(0x68)
#undef PCIE2
#undef PCIE1
#undef PCIE0
enum PCICR_BIT {
    PCIE2 = 2,
    PCIE1 = 1,
    PCIE0 = 0
};
#endif

#if ATmega48PA_88PA_168PA_328P || ATmega328PB || ATmega640_1280_1281_2560_2561
//External Interrupt Control Register A
#define EICRA _SFR_MEM8(0x69)
#if ATmega640_1280_1281_2560_2561
#undef ISC31
#undef ISC30
#undef ISC21
#undef ISC20
#endif

#undef ISC11
#undef ISC10
#undef ISC01
#undef ISC00
enum EICRA_BIT {
#if ATmega640_1280_1281_2560_2561
    ISC31 = 7, // Interrupt Sense Control 3
    ISC30 = 6, // Interrupt Sense Control 3
    ISC21 = 5, // Interrupt Sense Control 2
    ISC20 = 4, // Interrupt Sense Control 2
#endif
    ISC11 = 3, // Interrupt Sense Control 1
    ISC10 = 2, // Interrupt Sense Control 1
    ISC01 = 1, // Interrupt Sense Control 0
    ISC00 = 0  // Interrupt Sense Control 0
};
#endif

#if ATmega640_1280_1281_2560_2561
#define EICRB   _SFR_MEM8(0x6A)
#undef ISC71
#undef ISC70
#undef ISC61
#undef ISC60
#undef ISC51
#undef ISC50
#undef ISC41
#undef ISC40
enum EICRB_BIT {
    ISC71 = 7, // Interrupt Sense Control 7
    ISC70 = 6, // Interrupt Sense Control 7
    ISC61 = 5, // Interrupt Sense Control 6
    ISC60 = 4, // Interrupt Sense Control 6
    ISC51 = 3, // Interrupt Sense Control 5
    ISC50 = 2, // Interrupt Sense Control 5
    ISC41 = 1, // Interrupt Sense Control 4
    ISC40 = 0  // Interrupt Sense Control 4
};
#endif

#if ATmega48PA_88PA_168PA_328P || ATmega328PB || ATmega640_1280_1281_2560_2561
// Pin Change Mask Register 0
#define PCMSK0  _SFR_MEM8(0x6B)
#undef PCINT7
#undef PCINT6
#undef PCINT5
#undef PCINT4
#undef PCINT3
#undef PCINT2
#undef PCINT1
#undef PCINT0
enum PCMSK0_BIT {
    PCINT7 = 7, // Pin Change Enable Mask
    PCINT6 = 6,	// Pin Change Enable Mask
    PCINT5 = 5,	// Pin Change Enable Mask
    PCINT4 = 4,	// Pin Change Enable Mask
    PCINT3 = 3,	// Pin Change Enable Mask
    PCINT2 = 2,	// Pin Change Enable Mask
    PCINT1 = 1,	// Pin Change Enable Mask
    PCINT0 = 0	// Pin Change Enable Mask
};
#endif

#if ATmega48PA_88PA_168PA_328P || ATmega328PB || ATmega640_1280_1281_2560_2561
// Pin Change Mask Register 1
#define PCMSK1  _SFR_MEM8(0x6C)
#if ATmega640_1280_1281_2560_2561
#undef PCINT15
#endif
#undef PCINT14
#undef PCINT13
#undef PCINT12
#undef PCINT11
#undef PCINT10
#undef PCINT9
#undef PCINT8
enum PCMSK1_BIT {
#if ATmega640_1280_1281_2560_2561
    PCINT15 = 7, // Pin Change Enable Mask
#endif
    PCINT14 = 6, // Pin Change Enable Mask
    PCINT13 = 5, // Pin Change Enable Mask
    PCINT12 = 4, // Pin Change Enable Mask
    PCINT11 = 3, // Pin Change Enable Mask
    PCINT10 = 2, // Pin Change Enable Mask
    PCINT9  = 1, // Pin Change Enable Mask
    PCINT8  = 0  // Pin Change Enable Mask
};
#endif

#if ATmega48PA_88PA_168PA_328P || ATmega328PB || ATmega640_1280_1281_2560_2561
// Pin Change Mask Register 2
#define PCMSK2 _SFR_MEM8(0x6D)
#undef PCINT23
#undef PCINT22
#undef PCINT21
#undef PCINT20
#undef PCINT19
#undef PCINT18
#undef PCINT17
#undef PCINT16
enum PCMSK2_BIT {
    PCINT23 = 7, // Pin Change Enable Mask
    PCINT22 = 6, // Pin Change Enable Mask
    PCINT21 = 5, // Pin Change Enable Mask
    PCINT20 = 4, // Pin Change Enable Mask
    PCINT19 = 3, // Pin Change Enable Mask
    PCINT18 = 2, // Pin Change Enable Mask
    PCINT17 = 1, // Pin Change Enable Mask
    PCINT16 = 0	 // Pin Change Enable Mask
};
#endif

#if ATmega48PA_88PA_168PA_328P || ATmega328PB || ATmega640_1280_1281_2560_2561
// Timer/Counter Interrupt Mask Register
#define TIMSK0  _SFR_MEM8(0x6E)

// Timer/Counter Interrupt Mask Register
#define TIMSK1  _SFR_MEM8(0x6F)

// Timer/Counter Interrupt Mask Register
#define TIMSK2  _SFR_MEM8(0x70)
#endif

#if ATmega328PB || ATmega640_1280_1281_2560_2561
// Timer/Counter Interrupt Mask Register
#define TIMSK3  _SFR_MEM8(0x71)

// Timer/Counter Interrupt Mask Register
#define TIMSK4  _SFR_MEM8(0x72)
#endif

#if ATmega640_1280_1281_2560_2561

// Timer/Counter Interrupt Mask Register
#define TIMSK5  _SFR_MEM8(0x73)
#endif

enum TIMSKx_BIT{
    ICIEx  = 5,
    OCIExC = 3,
    OCIExB = 2,
    OCIExA = 1,
    TOIEx  = 0
};

#if ATmega640_1280_1281_2560_2561
// External Memory Control Register A
#define XMCRA   _SFR_MEM8(0x74)
#undef SRE
#undef SRL2
#undef SRL1
#undef SRL0
#undef SRW11
#undef SRW10
#undef SRW01
#undef SRW00
enum XMCRA_BIT {
    SRE   = 7, // External SRAM/XMEM Enable
    SRL2  = 6, // Wait-state Sector Limit
    SRL1  = 5, // Wait-state Sector Limit
    SRL0  = 4, // Wait-state Sector Limit
    SRW11 = 3, // Wait-state Select Bits for Upper Sector
    SRW10 = 2, // Wait-state Select Bits for Upper Sector
    SRW01 = 1, // Wait-state Select Bits for Lower Sector
    SRW00 = 0  // Wait-state Select Bits for Lower Sector
};


// External Memory Control Register B
#define XMCRB   _SFR_MEM8(0x75)
#undef XMBK
#undef XMM2
#undef XMM1
#undef XMM0
enum XMCRB_BIT{
    XMBK = 7, // External Memory Bus-keeper Enable
    XMM2 = 2, // External Memory High Mask
    XMM1 = 1, // External Memory High Mask
    XMM0 = 0  // External Memory High Mask
};
#endif

/* Combine ADCL and ADCH */
#ifndef __ASSEMBLER__
#define ADC     _SFR_MEM16(0x78)
#endif
#define ADCW    _SFR_MEM16(0x78)

// ADC Data Register Low and High Byte
#define ADCL    _SFR_MEM8(0x78)
#define ADCH    _SFR_MEM8(0x79)


// ADC Control and Status Register A
#define ADCSRA  _SFR_MEM8(0x7A)
#undef ADEN
#undef ADSC
#undef ADATE
#undef ADIF
#undef ADIE
#undef ADPS2
#undef ADPS1
#undef ADPS0
enum ADCSRA_BIT {
    ADEN  = 7, // ADC Enable
    ADSC  = 6, // ADC Start Conversion
    ADATE = 5, // ADC Auto Trigger Enable
    ADIF  = 4, // ADC Interrupt Flag
    ADIE  = 3, // ADC Interrupt Enable
    ADPS2 = 2, // ADC Prescaler Select
    ADPS1 = 1, // ADC Prescaler Select
    ADPS0 = 0  // ADC Prescaler Select
};

// ADC Control and Status Register B
#define ADCSRB  _SFR_MEM8(0x7B)
#undef ACME
#undef MUX5
#undef ADTS2
#undef ADTS1
#undef ADTS0
enum ADCSRB_BIT {
    ACME = 6, // Analog Comparator Multiplexer Enable
#if ATmega640_1280_1281_2560_2561
    MUX5 = 3,
#endif
    ADTS2 = 2, // ADC Auto Trigger Source
    ADTS1 = 1, // ADC Auto Trigger Source
    ADTS0 = 0  // ADC Auto Trigger Source
};

// ADC Multiplexer Selection Register
#define ADMUX   _SFR_MEM8(0x7C)
#undef REFS1
#undef REFS0
#undef ADLAR
#undef MUX4
#undef MUX3
#undef MUX2
#undef MUX1
#undef MUX0
enum ADMUX_BIT {
    REFS1 = 7, // Reference Selection
    REFS0 = 6, // Reference Selection
    ADLAR = 5, // ADC Left Adjust Resul
    MUX4  = 4,
    MUX3  = 3,
    MUX2  = 2,
    MUX1  = 1,
    MUX0  = 0
};

#if ATmega640_1280_1281_2560_2561
// Digital Input Disable Register 2
#define DIDR2   _SFR_MEM8(0x7D)
#undef ADC15D
#undef ADC14D
#undef ADC13D
#undef ADC12D
#undef ADC11D
#undef ADC10D
#undef ADC9D
#undef ADC8D
enum DIDR2_BIT {
    ADC15D = 7, // ADC Digital Input Disable
    ADC14D = 6,	// ADC Digital Input Disable
    ADC13D = 5,	// ADC Digital Input Disable
    ADC12D = 4,	// ADC Digital Input Disable
    ADC11D = 3,	// ADC Digital Input Disable
    ADC10D = 2,	// ADC Digital Input Disable
    ADC9D  = 1,	// ADC Digital Input Disable
    ADC8D  = 0	// ADC Digital Input Disable
};
#endif

#if ATmega48PA_88PA_168PA_328P || ATmega328PB || ATmega640_1280_1281_2560_2561
// Digital Input Disable Register 0
#define DIDR0   _SFR_MEM8(0x7E)
#undef ADC7D
#undef ADC6D
#undef ADC5D
#undef ADC4D
#undef ADC3D
#undef ADC2D
#undef ADC1D
#undef ADC0D
enum DIDR0_BIT {
    ADC7D = 7, // ADC Digital Input Disable
    ADC6D = 6, // ADC Digital Input Disable
    ADC5D = 5, // ADC Digital Input Disable
    ADC4D = 4, // ADC Digital Input Disable
    ADC3D = 3, // ADC Digital Input Disable
    ADC2D = 2, // ADC Digital Input Disable
    ADC1D = 1, // ADC Digital Input Disable
    ADC0D = 0  // ADC Digital Input Disable
};

// Digital Input Disable Register 1
#define DIDR1   _SFR_MEM8(0x7F)
#undef AIN1D
#undef AIN0D
enum DIDR1_BIT {
    AIN1D = 1, // AIN Digital Input Disable
    AIN0D = 0  // AIN Digital Input Disable
};

// Asynchronous Status Register
#define ASSR    _SFR_MEM8(0xB6)
#undef EXCLK
#undef AS2
#undef TCN2UB
#undef OCR2AUB
#undef OCR2BUB
#undef TCR2AUB
#undef TCR2BUB
enum ASSR_BIT {
    EXCLK   = 6,
    AS2     = 5,
    TCN2UB  = 4,
    OCR2AUB = 3,
    OCR2BUB = 2,
    TCR2AUB = 1,
    TCR2BUB = 0
};
#endif

#if ATmega48PA_88PA_168PA_328P || ATmega328PB || ATmega640_1280_1281_2560_2561

// TWI Bit Rate Register
#define TWBR0    _SFR_MEM8(0xB8)

// TWI Status Register
#define TWSR0    _SFR_MEM8(0xB9)

// TWI (Slave) Address Register
#define TWAR0    _SFR_MEM8(0xBA)

// TWI Data Register
#define TWDR0    _SFR_MEM8(0xBB)

// TWI Control Register
#define TWCR0    _SFR_MEM8(0xBC)

// TWI (Slave) Address Mask Register
#define TWAMR0   _SFR_MEM8(0xBD)

#endif

#if ATmega328PB
// TWI Bit Rate Register
#define TWBR1 _SFR_MEM8(0xD8)

// TWI Status Register
#define TWSR1 _SFR_MEM8(0xD9)

// TWI (Slave) Address Register
#define TWAR1 _SFR_MEM8(0xDA)

// TWI Data Register
#define TWDR1 _SFR_MEM8(0xDB)

// TWI Control Register
#define TWCR1 _SFR_MEM8(0xDC)

// TWI (Slave) Address Mask Register
#define TWAMR1 _SFR_MEM8(0xDD)

#endif

enum TWSRx {
    TWSx7  =  7,
    TWSx6  =  6,
    TWSx5  =  5,
    TWSx4  =  4,
    TWSx3  =  3,
    TWPSx1 =  1,
    TWPSx0 =  0
};

enum TWARx {

    TWAx6  =  7,
    TWAx5  =  6,
    TWAx4  =  5,
    TWAx3  =  4,
    TWAx2  =  3,
    TWAx1  =  2,
    TWAx0  =  1,
    TWGCEx =  0
};

enum TWCRx {
    TWINTx =  7,
    TWEAx  =  6,
    TWSTAx =  5,
    TWSTOx =  4,
    TWWCx  =  3,
    TWENx  =  2,
    TWIEx  =  0
};

enum TWAMRx {
    TWAMx6 =  7,
    TWAMx5 =  6,
    TWAMx4 =  5,
    TWAMx3 =  4,
    TWAMx2 =  3,
    TWAMx1 =  2,
    TWAMx0 =  1
};





//---- Timer Section ----//
#if ATmega48PA_88PA_168PA_328P || ATmega328PB || ATmega640_1280_1281_2560_2561
//---- Timer 1 ----//

// Timer/Counter Control Register A
#define TCCR0A  _SFR_IO8(0x24)

// Timer/Counter Control Register B
#define TCCR0B  _SFR_IO8(0x25)

// Timer/Counter Register
#define TCNT0   _SFR_IO8(0X26)

// Output Compare Register A
#define OCR0A   _SFR_IO8(0X27)

// Output Compare Register B
#define OCR0B   _SFR_IO8(0X28)

#define TCCR1A  _SFR_MEM8(0x80)
#define TCCR1B  _SFR_MEM8(0x81)
#define TCCR1C  _SFR_MEM8(0x82)

/* Combine TCNT1L and TCNT1H */
#define TCNT1   _SFR_MEM16(0x84)
#define TCNT1L  _SFR_MEM8(0x84)
#define TCNT1H  _SFR_MEM8(0x85)

/* Combine ICR1L and ICR1H */
#define ICR1    _SFR_MEM16(0x86)
#define ICR1L   _SFR_MEM8(0x86)
#define ICR1H   _SFR_MEM8(0x87)

/* Combine OCR1AL and OCR1AH */
#define OCR1A   _SFR_MEM16(0x88)
#define OCR1AL  _SFR_MEM8(0x88)
#define OCR1AH  _SFR_MEM8(0x89)

/* Combine OCR1BL and OCR1BH */
#define OCR1B   _SFR_MEM16(0x8A)
#define OCR1BL  _SFR_MEM8(0x8A)
#define OCR1BH  _SFR_MEM8(0x8B)

/* Combine OCR1CL and OCR1CH */
#define OCR1C   _SFR_MEM16(0x8C)
#define OCR1CL  _SFR_MEM8(0x8C)
#define OCR1CH  _SFR_MEM8(0x8D)
//---- End Timer 1 ----//


//---- Timer 2 ----//
#define TCCR2A  _SFR_MEM8(0xB0)
#define TCCR2B  _SFR_MEM8(0xB1)
#define TCNT2   _SFR_MEM8(0xB2)
#define OCR2A   _SFR_MEM8(0xB3)
#define OCR2B   _SFR_MEM8(0xB4)
//---- End Timer 2 ----//
#endif

#if ATmega328PB || ATmega640_1280_1281_2560_2561
//---- Timer 3 ----//
#define TCCR3A  _SFR_MEM8(0x90)
#define TCCR3B  _SFR_MEM8(0x91)
#define TCCR3C  _SFR_MEM8(0x92)

/* Combine TCNT3L and TCNT3H */
#define TCNT3   _SFR_MEM16(0x94)
#define TCNT3L  _SFR_MEM8(0x94)
#define TCNT3H  _SFR_MEM8(0x95)

/* Combine ICR3L and ICR3H */
#define ICR3    _SFR_MEM16(0x96)
#define ICR3L   _SFR_MEM8(0x96)
#define ICR3H   _SFR_MEM8(0x97)

/* Combine OCR3AL and OCR3AH */
#define OCR3A   _SFR_MEM16(0x98)
#define OCR3AL  _SFR_MEM8(0x98)
#define OCR3AH  _SFR_MEM8(0x99)

/* Combine OCR3BL and OCR3BH */
#define OCR3B   _SFR_MEM16(0x9A)
#define OCR3BL  _SFR_MEM8(0x9A)
#define OCR3BH  _SFR_MEM8(0x9B)

/* Combine OCR3CL and OCR3CH */
#define OCR3C   _SFR_MEM16(0x9C)
#define OCR3CL  _SFR_MEM8(0x9C)
#define OCR3CH  _SFR_MEM8(0x9D)
//---- End Timer 3 ----//

//---- Timer 4 ----//
#define TCCR4A  _SFR_MEM8(0xA0)
#define TCCR4B  _SFR_MEM8(0xA1)
#define TCCR4C  _SFR_MEM8(0xA2)

/* Combine TCNT4L and TCNT4H */
#define TCNT4   _SFR_MEM16(0xA4)
#define TCNT4L  _SFR_MEM8(0xA4)
#define TCNT4H  _SFR_MEM8(0xA5)

/* Combine ICR4L and ICR4H */
#define ICR4    _SFR_MEM16(0xA6)
#define ICR4L   _SFR_MEM8(0xA6)
#define ICR4H   _SFR_MEM8(0xA7)

/* Combine OCR4AL and OCR4AH */
#define OCR4A   _SFR_MEM16(0xA8)
#define OCR4AL  _SFR_MEM8(0xA8)
#define OCR4AH  _SFR_MEM8(0xA9)

/* Combine OCR4BL and OCR4BH */
#define OCR4B   _SFR_MEM16(0xAA)
#define OCR4BL  _SFR_MEM8(0xAA)
#define OCR4BH  _SFR_MEM8(0xAB)

/* Combine OCR4CL and OCR4CH */
#define OCR4C   _SFR_MEM16(0xAC)
#define OCR4CL  _SFR_MEM8(0xAC)
#define OCR4CH  _SFR_MEM8(0xAD)
//---- End Timer 4 ----//
#endif

#if ATmega640_1280_1281_2560_2561
//---- Timer 5 ----//
#define TCCR5A  _SFR_MEM8(0x120)
#define TCCR5B  _SFR_MEM8(0x121)
#define TCCR5C  _SFR_MEM8(0x122)

/* Combine TCNT5L and TCNT5H */
#define TCNT5   _SFR_MEM16(0x124)
#define TCNT5L  _SFR_MEM8(0x124)
#define TCNT5H  _SFR_MEM8(0x125)

/* Combine ICR5L and ICR5H */
#define ICR5    _SFR_MEM16(0x126)
#define ICR5L   _SFR_MEM8(0x126)
#define ICR5H   _SFR_MEM8(0x127)

/* Combine OCR5AL and OCR5AH */
#define OCR5A   _SFR_MEM16(0x128)
#define OCR5AL  _SFR_MEM8(0x128)
#define OCR5AH  _SFR_MEM8(0x129)

/* Combine OCR5BL and OCR5BH */
#define OCR5B   _SFR_MEM16(0x12A)
#define OCR5BL  _SFR_MEM8(0x12A)
#define OCR5BH  _SFR_MEM8(0x12B)

/* Combine OCR5CL and OCR5CH */
#define OCR5C   _SFR_MEM16(0x12C)
#define OCR5CL  _SFR_MEM8(0x12C)
#define OCR5CH  _SFR_MEM8(0x12D)
//---- End Timer 5 ----//
#endif

enum TCCRxA_BIT {
    COMxA1 = 7,
    COMxA0 = 6,
    COMxB1 = 5,
    COMxB0 = 4,
    COMxC1 = 3,
    COMxC0 = 2,
    WGMx1  = 1,
    WGMx0  = 0
};

enum TCCRxB_BIT {
    ICNCx  = 7,
    ICESx  = 6,
    WGMx3  = 4,
    WGMx2  = 3,
    CSx2   = 2,
    CSx1   = 1,
    CSx0   = 0
};

enum TCCRxC_BIT {
    FOCxA =  7,
    FOCxB =  6,
    FOCxC =  5
};

//---- End Timer Section ----//



//---- Uart Section ----//
#if  ATmega48PA_88PA_168PA_328P || ATmega640_1280_1281_2560_2561 || ATmega328PB

#define UCSR0A  _SFR_MEM8(0xC0)
#define UCSR0B  _SFR_MEM8(0XC1)
#define UCSR0C  _SFR_MEM8(0xC2)
#define UBRR0   _SFR_MEM16(0xC4)
#define UBRR0L  _SFR_MEM8(0xC4)
#define UBRR0H  _SFR_MEM8(0xC5)
#define UDR0    _SFR_MEM8(0XC6)

#endif

#if ATmega640_1280_1281_2560_2561 || ATmega328PB

#undef UCSR1A
#undef UCSR1B
#undef UCSR1C
#undef UBRR1
#undef UBRR1L
#undef UBRR1H
#undef UDR1


#define UCSR1A  _SFR_MEM8(0xC8)
#define UCSR1B  _SFR_MEM8(0xC9)
#define UCSR1C  _SFR_MEM8(0xCA)
#define UBRR1   _SFR_MEM16(0xCC)
#define UBRR1L  _SFR_MEM8(0xCC)
#define UBRR1H  _SFR_MEM8(0xCD)
#define UDR1    _SFR_MEM8(0XCE)

#endif

#if ATmega640_1280_1281_2560_2561

#define UCSR2A _SFR_MEM8(0xD0)
#define UCSR2B _SFR_MEM8(0XD1)
#define UCSR2C _SFR_MEM8(0xD2)
#define UBRR2  _SFR_MEM16(0xD4)
#define UBRR2L _SFR_MEM8(0xD4)
#define UBRR2H _SFR_MEM8(0xD5)
#define UDR2   _SFR_MEM8(0XD6)


#define UCSR3A _SFR_MEM8(0x130)
#define UCSR3B _SFR_MEM8(0X131)
#define UCSR3C _SFR_MEM8(0x132)
#define UBRR3  _SFR_MEM16(0x134)
#define UBRR3L _SFR_MEM8(0x134)
#define UBRR3H _SFR_MEM8(0x135)
#define UDR3   _SFR_MEM8(0X136)

#endif

enum UCSRxA_BIT {
    RXCx  =  7, // USART Receive Complete
    TXCx  =  6, // USART Transmit Complete
    UDREx =  5, // USART Data Register Empty
    FEx   =  4, // Frame Error
    DORx  =  3, // Data OverRun
    UPEx  =  2, // USART Parity Error
    U2Xx  =  1, // Double the USART Transmission Speed
    MPCMx =  0  // Multi-processor Communication Mode
};
enum UCSRxB_BIT {
    RXCIEx = 7, // RX Complete Interrupt Enable
    TXCIEx = 6,	// TX Complete Interrupt Enable
    UDRIEx = 5,	// USART Data Register Empty Interrupt Enable
    RXENx  = 4,	// Receiver Enable
    TXENx  = 3,	// Transmitter Enable
    UCSZx2 = 2,	// Character Size 2
    RXB8x  = 1,	// Receive Data Bit 8
    TXB8x  = 0	// Transmit Data Bit 8
};

enum UCSRxC_BIT{
    UMSELx1 = 7, // USART Mode Select
    UMSELx0 = 6, // USART Mode Select
    UPMx1   = 5, // Parity Mode
    UPMx0   = 4, // Parity Mode
    USBSx   = 3, // Stop Bit Select
    UCSZx1  = 2, // Character Size 1
    UCSZx0  = 1, // Character Size 0
    UCPOLx  = 0	 // Clock Polarity
};

//---- End Uart Section ----//













