#ifndef ENC28J60_H
#define ENC28J60_H
#include <spimaster.h>
//#include <string>
#include <macros.h>
#include <net_utils.h>
//#include <serial.h>
//#include <interrupt.h>
//#include <functional>
#include <systemevent.h>
///@file


/**
	* @brief The ENC28J06_ECOCON_REG_BIT enum.
	* See <a href='datasheets/enc28j60_datasheet.pdf#page=8'>Enc28j60 Datasheet</a>
	*/
enum class ENC28J60_ECOCON_REG_BIT{
    COCON0, /*!< Read & Write | Default = 0 */
    COCON1, /*!< Read & Write | Default = 0 */
    COCON2  /*!< Read & Write | Default = 0 */
};

/**
	* @brief The ENC28J60_ECOCON_REG enum.
	* See <a href='datasheets/enc28j60_datasheet.pdf#page=8'>Enc28j60 Datasheet</a>
	*/
enum class ENC28J60_ECOCON_REG_CFG {
    CLKOUT_DISABLED,
    CLKOUT_DIVIDED_BY_1 = regBitToValue(ENC28J60_ECOCON_REG_BIT::COCON0),
    CLKOUT_DIVIDED_BY_2 = regBitToValue(ENC28J60_ECOCON_REG_BIT::COCON1),
    CLKOUT_DIVIDED_BY_3 = regBitToValue(ENC28J60_ECOCON_REG_BIT::COCON1) | regBitToValue(ENC28J60_ECOCON_REG_BIT::COCON0),
    CLKOUT_DIVIDED_BY_4 = regBitToValue(ENC28J60_ECOCON_REG_BIT::COCON2),
    CLKOUT_DIVIDED_BY_8 = regBitToValue(ENC28J60_ECOCON_REG_BIT::COCON2) | regBitToValue(ENC28J60_ECOCON_REG_BIT::COCON0)
};


/**
	* @brief The ENC28J60_PHLCON_REG_BIT enum.
	* See <a href='datasheets/enc28j60_datasheet.pdf#page=11'>Enc28j60 Datasheet</a>
	*/
enum class ENC28J60_PHLCON_REG_BIT {
    STRCH  =  1, /*!< Read & Write | Default = 1 */
    LFRQ0  =  2, /*!< Read & Write | Default = 0 */
    LFRQ1  =  3, /*!< Read & Write | Default = 0 */
    LBCFG0 =  4, /*!< Read & Write | Default = 0 */
    LBCFG1 =  5, /*!< Read & Write | Default = 1 */
    LBCFG2 =  6, /*!< Read & Write | Default = 0 */
    LBCFG3 =  7, /*!< Read & Write | Default = 0 */
    LACFG0 =  8, /*!< Read & Write | Default = 0 */
    LACFG1 =  9, /*!< Read & Write | Default = 0 */
    LACFG2 = 10, /*!< Read & Write | Default = 1 */
    LACFG3 = 11  /*!< Read & Write | Default = 0 */
};

/**
	* @brief The ENC28J60_PHLCON_REG_CFG enum
	* See <a href='datasheets/enc28j60_datasheet.pdf#page=11'>Enc28j60 Datasheet</a>
	*/
enum class ENC28J60_PHLCON_REG_CFG {
    STRETCH_LED_EVENTS_BY_TNSTRCH                       = (0x00 << 2),
    STRETCH_LED_EVENTS_BY_TMSTRCH                       = (0x01 << 2),
    STRETCH_LED_EVENTS_BY_TLSTRCH                       = (0x10 << 2),
    LEDB_DISPLAY_TRANSMIT_ACTIVITY                      = (0x01 << 4),
    LEDB_DISPLAY_RECEIVE_ACTIVITY                       = (0x02 << 4),
    LEDB_DISPLAY_COLLISION_ACTIVITY                     = (0x03 << 4),
    LEDB_DISPLAY_LINK_STATUS                            = (0x04 << 4),
    LEDB_DISPLAY_DUPLEX_STATUS                          = (0x05 << 4),
    LEDB_DISPLAY_TRANSMIT_RECEIVE_ACTIVITY              = (0x07 << 4),
    LEDB_ON                                             = (0x08 << 4),
    LEDB_OFF                                            = (0x09 << 4),
    LEDB_BLINK_FAST                                     = (0x0A << 4),
    LEDB_BLINK_SLOW                                     = (0x0B << 4),
    LEDB_DISPLAY_LINK_STATUS_RECEIVE_ACTIVITY           = (0x0C << 4),
    LEDB_DISPLAY_LINK_STATUS_TRANSMIT_RECEIVE_ACTIVITY  = (0x0D << 4),
    LEDB_DISPLAY_DUPLEX_STATUS_COLLISION_ACTIVITY       = (0x0E << 4),
    LEDA_DISPLAY_TRANSMIT_ACTIVITY                      = (0x01 << 8),
    LEDA_DISPLAY_RECEIVE_ACTIVITY                       = (0x02 << 8),
    LEDA_DISPLAY_COLLISION_ACTIVITY                     = (0x03 << 8),
    LEDA_DISPLAY_LINK_STATUS                            = (0x04 << 8),
    LEDA_DISPLAY_DUPLEX_STATUS                          = (0x05 << 8),
    LEDA_DISPLAY_TRANSMIT_RECEIVE_ACTIVITY              = (0x07 << 8),
    LEDA_ON                                             = (0x08 << 8),
    LEDA_OFF                                            = (0x09 << 8),
    LEDA_BLINK_FAST                                     = (0x0A << 8),
    LEDA_BLINK_SLOW                                     = (0x0B << 8),
    LEDA_DISPLAY_LINK_STATUS_RECEIVE_ACTIVITY           = (0x0C << 8),
    LEDA_DISPLAY_LINK_STATUS_TRANSMIT_RECEIVE_ACTIVITY  = (0x0D << 8),
    LEDA_DISPLAY_DUPLEX_STATUS_COLLISION_ACTIVITY       = (0x0E << 8)
};

/**
	* @brief The ENC28J60_ECON1_REG_BIT enum
	* See <a href='datasheets/enc28j60_datasheet.pdf#page=17'>Enc28j60 Datasheet</a>
	*/
enum class ENC28J60_ECON1_REG_BIT {
    BSEL0, /*!< Read & Write | Default  = 0 */
    BSEL1, /*!< Read & Write | Default  = 0 */
    RXEN,  /*!< Read & Write | Default  = 0 */
    TXRTS, /*!< Read & Write | Default  = 0 */
    CSUMEN,/*!< Read & Write | Default  = 0 */
    DMAST, /*!< Read & Write | Default  = 0 */
    RXRST, /*!< Read & Write | Default  = 0 */
    TXRST  /*!< Read & Write | Default  = 0 */
};
/**
	* @brief The ENC28J60_ECON1_REG enum
	* See <a href='datasheets/enc28j60_datasheet.pdf#page=17'>Enc28j60 Datasheet</a>
	*/
enum class ENC28J60_ECON1_REG_CFG {
    SPI_BANK0,
    SPI_BANK1,
    SPI_BANK2,
    SPI_BANK3,
    RXEN   = (1 << 2),
    TXRTS  = (1 << 3),
    CSUMEN = (1 << 4),
    DMAST  = (1 << 5),
    RXRST  = (1 << 6),
    TXRST  = (1 << 7)

};

/**
	* @brief The ENC28J60_ECON2_REG_BIT enum
	* See <a href='datasheets/enc28j60_datasheet.pdf#page=18'>Enc28j60 Datasheet</a>
	*/
enum class ENC28J60_ECON2_REG_BIT {
    VRPS    = 3, /*!< Read & Write | Default  = 0 */
    PWRSV   = 5, /*!< Read & Write | Default  = 0 */
    PKTDEC  = 6, /*!< Read & Write | Default  = 0 */
    AUTOINC = 7  /*!< Read & Write | Default  = 1 */
};

/**
	* @brief The ENC28J60_ECON2_REG enum
	* See <a href='datasheets/enc28j60_datasheet.pdf#page=18'>Enc28j60 Datasheet</a>
	*/
enum class ENC28J60_ECON2_REG_CFG {
    VRPS    = (1 << 3),
    PWRSV   = (1 << 5),
    PKTDEC  = (1 << 6),
    AUTOINC = (1 << 7)
};

/**
	* @brief The ENC28J60_MICMD_REG_BIT enum
	* See <a href='datasheets/enc28j60_datasheet.pdf#page=23'>Enc28j60 Datasheet</a>
	*/
enum class ENC28J60_MICMD_REG_BIT {
    MIIRD,   /*!< Read & Write | Default  = 0 */
    MIISCAN  /*!< Read & Write | Default  = 0 */
};


/**
	* @brief The ENC28J60_MISTAT_REG enum
	* See <a href='datasheets/enc28j60_datasheet.pdf#page=23'>Enc28j60 Datasheet</a>
	*/
enum class ENC28J60_MISTAT_REG_BIT {
    BUSY,  /*!< Read Only | Default  = 0 */
    SCAN,  /*!< Read Only | Default  = 0 */
    NVALID /*!< Read Only | Default  = 0 */
};


/**
	* @brief The ENC28J60_PHSTAT1_REG enum
	* See <a href='datasheets/enc28j60_datasheet.pdf#page=25'>Enc28j60 Datasheet</a>
	*/
enum class ENC28J60_PHSTAT1_REG_BIT {
    JBSTAT  = 1,  /*!< Read & Latches High  | Default  = 0 */
    LLSTAT  = 2,  /*!< Read & Latches Low   | Default  = 0 */
    PHDPX   = 11, /*!< Read Only            | Default  = 1 */
    PFDPX   = 12  /*!< Read Only            | Default  = 1 */
};


/**
	* @brief The ENC28J60_PHSTAT2_REG_BIT enum
	* See <a href='datasheets/enc28j60_datasheet.pdf#page=26'>Enc28j60 Datasheet</a>
	*/
enum class ENC28J60_PHSTAT2_REG_BIT {
    PLRITY  = 5,  /*!< Read Only | Default  = 0 */
    DPXSTAT = 9,  /*!< Read Only | Default  = Unknown */
    LSTAT   = 10, /*!< Read Only | Default  = 0 */
    COLSTAT = 11, /*!< Read Only | Default  = 0 */
    RXSTAT  = 12, /*!< Read Only | Default  = 0 */
    TXSTAT  = 13  /*!< Read Only | Default  = 0 */
};

/**
	* @brief The ENC28J60_SPI_OPCODE enum
	* See <a href='datasheets/enc28j60_datasheet.pdf#page=28'>Enc28j60 Datasheet</a>
	*/
enum ENC28J60_SPI_OPCODE {
    SPI_OPCODE_RCR = 0x00,    /*!< Read Control Register*/
    SPI_OPCODE_RBM = 0x3A,    /*!< Read Buffer Memory*/
    SPI_OPCODE_WCR = 0x40,    /*!< Write Control Register */
    SPI_OPCODE_WBM = 0x7A,    /*!< Write Buffer Memory */
    SPI_OPCODE_BFS = 0x80,    /*!< Bit Field Set */
    SPI_OPCODE_BFC = 0xA0,    /*!< Bit Field Clear */
    SPI_OPCODE_SRC = 0xFF     /*!< System Reset Command (Soft Reset) */
};


/**
	* @brief The ENC28J60_ISA struct
	* See <a href='datasheets/enc28j60_datasheet.pdf#page=28'>Enc28j60 Datasheet</a>
	*/
struct ENC28J60_ISA
{
    ENC28J60_ISA(uint16_t packet = 0) {
	this->packet = packet;
    }

    union {
	struct
	{
	    union {
		struct
		{
		    uint8_t opcode:3;
		    uint8_t argument:5;
		} fields;
		uint8_t data;
	    } byte0;

	    uint8_t payload;
	} cmd;

	uint16_t packet;

    };
};





/**
	* @brief The ENC28J60_COM_BANK_REG enum
	* See <a href='datasheets/enc28j60_datasheet.pdf#page=14'>Enc28j60 Datasheet</a>
	*/
enum class ENC28J60_COM_BANK_REG {
    EIE     = 0x1B,
    EIR     = 0x1C,
    ESTAT   = 0x1D,
    ECON2   = 0x1E,
    ECON1   = 0x1F
};


/**
	* @brief The ENC28J60_BANK0_REG enum
	* See <a href='datasheets/enc28j60_datasheet.pdf#page=14'>Enc28j60 Datasheet</a>
	*/
enum class ENC28J60_BANK0_REG {
    ERDPTL    = 0x00,
    ERDPTH    = 0x01,
    EWRPTL    = 0x02,
    EWRPTH    = 0x03,
    ETXSTL    = 0x04,
    ETXSTH    = 0x05,
    ETXNDL    = 0x06,
    ETXNDH    = 0x07,
    ERXSTL    = 0x08,
    ERXSTH    = 0x09,
    ERXNDL    = 0x0A,
    ERXNDH    = 0x0B,
    ERXRDPTL  = 0x0C,
    ERXRDPTH  = 0x0D,
    ERXWRPTL  = 0x0E,
    ERXWRPTH  = 0x0F,
    EDMASTL   = 0x10,
    EDMASTH   = 0x11,
    EDMANDL   = 0x12,
    EDMANDH   = 0x13,
    EDMADSTL  = 0x14,
    EDMADSTH  = 0x15,
    EDMACSL   = 0x16,
    EDMACSH   = 0x17
};

/**
	* @brief The ENC28J60_BANK1_REG enum
	* See <a href='datasheets/enc28j60_datasheet.pdf#page=14'>Enc28j60 Datasheet</a>
	*/
enum class ENC28J60_BANK1_REG {
    EHT0    = 0x00,
    EHT1    = 0x01,
    EHT2    = 0x02,
    EHT3    = 0x03,
    EHT4    = 0x04,
    EHT5    = 0x05,
    EHT6    = 0x06,
    EHT7    = 0x07,
    EPMM0   = 0x08,
    EPMM1   = 0x09,
    EPMM2   = 0x0A,
    EPMM3   = 0x0B,
    EPMM4   = 0x0C,
    EPMM5   = 0x0D,
    EPMM6   = 0x0E,
    EPMM7   = 0x0F,
    EPMCSL  = 0x10,
    EPMCSH  = 0x11,
    EPMOL   = 0x12,
    EPMOH   = 0x13,
    EWOLIE  = 0x14,
    EWOLIR  = 0x15,
    ERXFCON = 0x16,
    EPKTCNT = 0x17
};

/**
	* @brief The ENC28J60_BANK2_REG enum
	* See <a href='datasheets/enc28j60_datasheet.pdf#page=14'>Enc28j60 Datasheet</a>
	*/
enum class ENC28J60_BANK2_REG {
    MACON1     = 0x00,
    MACON3     = 0x02,
    MACON4     = 0x03,
    MABBIPG    = 0x04,
    MAIPGL     = 0x06,
    MAIPGH     = 0x07,
    MACLCON1   = 0x08,
    MACLCON2   = 0x09,
    MAMXFLL    = 0x0A,
    MAMXFLH    = 0x0B,
    MICMD      = 0x12,
    MIREGADR   = 0x14,
    MIWRL      = 0x16,
    MIWRH      = 0x17,
    MIRDL      = 0x18,
    MIRDH      = 0x19,
};


/**
	* @brief The ENC28J60_BANK3_REG enum
	* See <a href='datasheets/enc28j60_datasheet.pdf#page=14'>Enc28j60 Datasheet</a>
	*/
enum class ENC28J60_BANK3_REG {
    MAADR5  = 0x00,
    MAADR6  = 0x01,
    MAADR3  = 0x02,
    MAADR4  = 0x03,
    MAADR1  = 0x04,
    MAADR2  = 0x05,
    EBSTSD  = 0x06,
    EBSTCON = 0x07,
    EBSTCSL = 0x08,
    EBSTCSH = 0x09,
    MISTAT  = 0x0A,
    EREVID  = 0x12,
    ECOCON  = 0x15,
    EFLOCON = 0x17,
    EPAUSL  = 0x18,
    EPAUSH  = 0x19
};


/**
	* @brief The ENC28J60_PHY_REG enum
	* See <a href='datasheets/enc28j60_datasheet.pdf#page=22'>Enc28j60 Datasheet</a>
	*/
enum ENC28J60_PHY_REG {
    REG_PHCON1  = 0x00,
    REG_PHSTAT1 = 0x01,
    REG_PHID1   = 0x02,
    REG_PHID2   = 0x03,
    REG_PHCON2  = 0x10,
    REG_PHSTAT2 = 0x11,
    REG_PHIE    = 0x12,
    REG_PHIR    = 0x13,
    REG_PHLCON  = 0x14,
};

/**
	* @brief The ENC28J60_MACON1_REG enum
	* See <a href='datasheets/enc28j60_datasheet.pdf#page=36'>Enc28j60 Datasheet</a>
	*/
enum class ENC28J60_MACON1_REG_BIT {
    MARXEN , /*!< Read & Write | Default  = 0 */
    PASSALL, /*!< Read & Write | Default  = 0 */
    RXPAUS , /*!< Read & Write | Default  = 0 */
    TXPAUS   /*!< Read & Write | Default  = 0 */
};

/**
	* @brief The ENC28J60_MACON3_REG enum
	* See <a href='datasheets/enc28j60_datasheet.pdf#page=37'>Enc28j60 Datasheet</a>
	*/
enum class ENC28J60_MACON3_REG_BIT {
    FULDPX,  /*!< Read & Write | Default  = 0 */
    FRMLNEN, /*!< Read & Write | Default  = 0 */
    HFRMEN,  /*!< Read & Write | Default  = 0 */
    PHDREN,  /*!< Read & Write | Default  = 0 */
    TXCRCEN, /*!< Read & Write | Default  = 0 */
    PADCFG0, /*!< Read & Write | Default  = 0 */
    PADCFG1, /*!< Read & Write | Default  = 0 */
    PADCFG2  /*!< Read & Write | Default  = 0 */
};

/**
	* @brief The ENC28J60_MACON3_REG_CFG enum
	* See <a href='datasheets/enc28j60_datasheet.pdf#page=37'>Enc28j60 Datasheet</a>
	*/
enum class ENC28J60_MACON3_REG_CFG {
    PAD_FRAME_TO60B     = (1 << 5),
    NO_AUTOPAD          = (2 << 5),
    PAD_FRAME_TO64B     = (3 << 5),
    AUTO_DETECT_VLAN    = (5 << 5),
};

/**
	* @brief The ENC28J60_MACON4_REG enum
	* See <a href='datasheets/enc28j60_datasheet.pdf#page=38'>Enc28j60 Datasheet</a>
	*/
enum class ENC28J60_MACON4_REG_BIT {
    NOBKOFF = 4, /*!< Read & Write | Default  = 0 */
    BPEN    = 5, /*!< Read & Write | Default  = 0 */
    DEFER   = 6  /*!< Read & Write | Default  = 0 */
};

/**
	* @brief The ENC28J60_MBBIPG_REG enum
	* See <a href='datasheets/enc28j60_datasheet.pdf#page=38'>Enc28j60 Datasheet</a>
	*/
enum class ENC28J60_MBBIPG_REG_BIT {
    BBIPG0, /*!< Read & Write | Default  = 0 */
    BBIPG1, /*!< Read & Write | Default  = 0 */
    BBIPG2, /*!< Read & Write | Default  = 0 */
    BBIPG3, /*!< Read & Write | Default  = 0 */
    BBIPG4, /*!< Read & Write | Default  = 0 */
    BBIPG5, /*!< Read & Write | Default  = 0 */
    BBIPG6  /*!< Read & Write | Default  = 0 */
};

/**
	* @brief The ENC28J60_MBBIPG_REG_BIT enum
	* See <a href='datasheets/enc28j60_datasheet.pdf#page=38'>Enc28j60 Datasheet</a>
	*/
enum class ENC28J60_MBBIPG_REG_CFG {
    WITH_FULDX_OFF = 0x12,
    WITH_FULDX_ON = 0x15
};

/**
	* @brief The ENC28J60_PHCON2_REG_BIT enum
	* See <a href='datasheets/enc28j60_datasheet.pdf#page=39'>Enc28j60 Datasheet</a>
	*/
enum class ENC28J60_PHCON2_REG_BIT {
    HDLDIS  = 8,  /*!< Read & Write | Default  = 0 */
    JABBER  = 10, /*!< Read & Write | Default  = 0 */
    TXDIS   = 13, /*!< Read & Write | Default  = 0 */
    FRCLNK  = 14  /*!< Read & Write | Default  = 0 */
};

/**
	* @brief The ENC28J60_ERXFCON_REG enum
	* See <a href='datasheets/enc28j60_datasheet.pdf#page=50'>Enc28j60 Datasheet</a>
	*/
enum class ENC28J60_ERXFCON_REG_BIT {
    BCEN,  /*!< Read & Write | Default  = 1 */
    MCEN,  /*!< Read & Write | Default  = 0 */
    HTEN,  /*!< Read & Write | Default  = 0 */
    MPEN,  /*!< Read & Write | Default  = 0 */
    PMEN,  /*!< Read & Write | Default  = 0 */
    CRCEN, /*!< Read & Write | Default  = 1 */
    ANDOR, /*!< Read & Write | Default  = 0 */
    UCEN   /*!< Read & Write | Default  = 1 */
};

/**
	* @brief The ENC28J60_EFLOCON_REG enum
	* See <a href='datasheets/enc28j60_datasheet.pdf#page=58'>Enc28j60 Datasheet</a>
	*/
enum class ENC28J60_EFLOCON_REG_BIT {
    FCEN0,  /*!< Read & Write | Default  = 0 */
    FCEN1,  /*!< Read & Write | Default  = 0 */
    FULDPXS /*!< Read Only    | Default  = 0 */
};

/**
	* @brief The ENC28J60_PHCON1_REG enum
	* See <a href='datasheets/enc28j60_datasheet.pdf#page=63'>Enc28j60 Datasheet</a>
	*/
enum class ENC28J60_PHCON1_REG_BIT {
    PDPXMD  =   8, /*!< Read & Write | Default  = 0 */
    PPWRSV  =  11, /*!< Read & Write | Default  = 0 */
    PLOOPBK =  14, /*!< Read & Write | Default  = 0 */
    PRST    =  15  /*!< Read & Write | Default  = 0 */
};

/**
	* @brief The ENC28J60_ESTAT_REG_BIT enum
	* See <a href='datasheets/enc28j60_datasheet.pdf#page=66'>Enc28j60 Datasheet</a>
	*/
enum class ENC28J60_ESTAT_REG_BIT {
    CLKRDY  = 0,  /*!< Read & Write      | Default = 0 */
    TXABRT  = 1,  /*!< Read & Clearable  | Default = 0 */
    RXBUSY  = 2,  /*!< Read Only         | Default = 0 */
    LATECOL = 4,  /*!< Read & Clearable  | Default = 0 */
    BUFER   = 6,  /*!< Read & Clearable  | Default = 0 */
    INT     = 7   /*!< Read Only         | Default = 0 */
};

/**
	* @brief The ENC28J60_EIE_REG_BIT enum
	* See <a href='datasheets/enc28j60_datasheet.pdf#page=67'>Enc28j60 Datasheet</a>
	*/
enum class ENC28J60_EIE_REG_BIT {
    RXERIE  = 0, /*!< Read  & Write | Default = 0 */
    TXERIE  = 1, /*!< Read  & Write | Default = 0 */
    TXIE    = 3, /*!< Read  & Write | Default = 0 */
    LINKIE  = 4, /*!< Read  & Write | Default = 0 */
    DMAIE   = 5, /*!< Read  & Write | Default = 0 */
    PKTIE   = 6, /*!< Read  & Write | Default = 0 */
    INTIE   = 7  /*!< Read  & Write | Default = 0 */
};

/**
	* @brief The ENC28J60_EIR enum
	* See <a href='datasheets/enc28j60_datasheet.pdf#page=68'>Enc28j60 Datasheet</a>
	*/
enum class ENC28J60_EIR_REG_BIT {
    RXERIF  = 0, /*!< Read & Clearable  | Default = 0 */
    TXERIF  = 1, /*!< Read & Clearable  | Default = 0 */
    TXIF    = 3, /*!< Read & Clearable  | Default = 0 */
    LINKIF  = 4, /*!< Read Only         | Default = 0 */
    DMAIF   = 5, /*!< Read & Clearable  | Default = 0 */
    PKTIF   = 6, /*!< Read Only         | Default = 0 */
};

/**
	* @brief The ENC28J60_PHIE enum
	* See <a href='datasheets/enc28j60_datasheet.pdf#page=69'>Enc28j60 Datasheet</a>
	*/
enum class ENC28J60_PHIE_REG_BIT {
    PGEIE  = 1, /*!< Read & Write | Default = 0 */
    PLNKIE = 4  /*!< Read & Write | Default = 0 */
};

/**
	* @brief The ENC28J60_PHIR_REG_BIT enum
	* See <a href='datasheets/enc28j60_datasheet.pdf#page=69'>Enc28j60 Datasheet</a>
	*/
enum class ENC28J60_PHIR_REG_BIT {
    PGIF    =  2, /*!< Read & Self Clearing | Default = 0*/
    PLNKIF  =  4  /*!< Read & Self Clearing | Default = 0*/
};

/**
	* @brief The ENC28J60_EBSTCON_REG_BIT enum
	* See <a href='datasheets/enc28j60_datasheet.pdf#page=77'>Enc28j60 Datasheet</a>
	*/
enum class ENC28J60_EBSTCON_REG_BIT{
    BISTST,/*!< Read & Write | Default = 0 */
    TME,   /*!< Read & Write | Default = 0 */
    TMSEL0,/*!< Read & Write | Default = 0 */
    TMSEL1,/*!< Read & Write | Default = 0 */
    PSEL,  /*!< Read & Write | Default = 0 */
    PSV0,  /*!< Read & Write | Default = 0 */
    PSV1,  /*!< Read & Write | Default = 0 */
    PSV2,  /*!< Read & Write | Default = 0 */
};

/**
	* @brief The ENC28J60_EBSTCON enum
	* See <a href='datasheets/enc28j60_datasheet.pdf#page=77'>Enc28j60 Datasheet</a>
	*/
enum ENC28J60_EBSTCON_REG_CFG {
    /// \todo Some (optional) text

    //BISTST             = (1 << 0),
    //TME                = (1 << 1),
    //RANDOM_DATA_FILL   = (0 << 2),
    //ADDRESS_FILL       = (1 << 2),
    //PATTERN_SHIFT_FILL = (2 << 2),
    //PSEL               = (1 << 4)
};
#define ENC28J60_RX_BUFFER_START 0x0000
#define ENC28J60_RX_BUFFER_END 0x17FF
#define ENC28J60_TX_BUFFER_START 0x1800
#define ENC28J60_TX_BUFFER_END 0x1FFF
#define ENC28J60_MAX_FRAMELENGTH 1518


#if defined(__AVR_ATmega640__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
#define DEF_SPI_MISO 50
#define DEF_SPI_MOSI 51
#define DEF_SPI_SCK 52
#define DEF_SPI_SS 53

#elif (__AVR_ATmega328P__)
#define DEF_SPI_SS 10
#define DEF_SPI_MOSI 11
#define DEF_SPI_MISO 12
#define DEF_SPI_SCK 13
#endif
/**
	* @brief The ENC28J60_REGS enum
	*
	*
	* @verbatim
╔════╦════╦════╦════╦════╦════╦═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╗
║ 15 ║ 14 ║ 13 ║ 12 ║ 11 ║ 10 ║ 9 ║ 8 ║ 7 ║ 6 ║ 5 ║ 4 ║ 3 ║ 2 ║ 1 ║ 0 ║
╠════╩════╩════╩════╬════╩════╬═══╩═══╬═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╣
║       Unused      ║ KoR     ║ Bank  ║ Address                       ║
╚═══════════════════╩═════════╩═══════╩═══════════════════════════════╝
	@endverbatim
	@note
	KoR = Kind of Register

	0 = ETH group
	1 = MAC group
	2 = MII group

	*/
#define ETH 0
#define MAC 1
#define MII 2
#define ENC28J60_KoR_MASK (0x3 << 10)
#define ENC28J60_BANK_MASK (0x3 << 8)

#define ENC28J60_READ_KoR(x) ((x & ENC28J60_KoR_MASK) >> 10)
#define ENC28J60_READ_BANK(x) ((x & ENC28J60_BANK_MASK) >> 8)
#define ENC28J60_READ_ADDRESS(x) (x & 0xFF)

#define ENC28J60_BANK(x) (x << 8)
#define ENC28J60_KoR(x) (x << 10)
enum ENC28J60_REGS {

    //----------------------------- BANK0 -----------------------------//	 //------------------------- BANK1 -------------------------//
    /*00*/	REG_ERDPTL    = (ENC28J60_KoR(ETH) | ENC28J60_BANK(0) | 0x00),  REG_EHT0     = (ENC28J60_KoR(ETH) | ENC28J60_BANK(1) | 0x00),
    /*01*/ REG_ERDPTH    = (ENC28J60_KoR(ETH) | ENC28J60_BANK(0) | 0x01),  REG_EHT1     = (ENC28J60_KoR(ETH) | ENC28J60_BANK(1) | 0x01),
    /*02*/ REG_EWRPTL    = (ENC28J60_KoR(ETH) | ENC28J60_BANK(0) | 0x02),  REG_EHT2     = (ENC28J60_KoR(ETH) | ENC28J60_BANK(1) | 0x02),
    /*03*/ REG_EWRPTH    = (ENC28J60_KoR(ETH) | ENC28J60_BANK(0) | 0x03),  REG_EHT3     = (ENC28J60_KoR(ETH) | ENC28J60_BANK(1) | 0x03),
    /*04*/ REG_ETXSTL    = (ENC28J60_KoR(ETH) | ENC28J60_BANK(0) | 0x04),  REG_EHT4     = (ENC28J60_KoR(ETH) | ENC28J60_BANK(1) | 0x04),
    /*05*/ REG_ETXSTH    = (ENC28J60_KoR(ETH) | ENC28J60_BANK(0) | 0x05),  REG_EHT5     = (ENC28J60_KoR(ETH) | ENC28J60_BANK(1) | 0x05),
    /*06*/ REG_ETXNDL    = (ENC28J60_KoR(ETH) | ENC28J60_BANK(0) | 0x06),  REG_EHT6     = (ENC28J60_KoR(ETH) | ENC28J60_BANK(1) | 0x06),
    /*07*/ REG_ETXNDH    = (ENC28J60_KoR(ETH) | ENC28J60_BANK(0) | 0x07),  REG_EHT7     = (ENC28J60_KoR(ETH) | ENC28J60_BANK(1) | 0x07),
    /*08*/ REG_ERXSTL    = (ENC28J60_KoR(ETH) | ENC28J60_BANK(0) | 0x08),  REG_EPMM0    = (ENC28J60_KoR(ETH) | ENC28J60_BANK(1) | 0x08),
    /*09*/ REG_ERXSTH    = (ENC28J60_KoR(ETH) | ENC28J60_BANK(0) | 0x09),  REG_EPMM1    = (ENC28J60_KoR(ETH) | ENC28J60_BANK(1) | 0x09),
    /*0A*/ REG_ERXNDL    = (ENC28J60_KoR(ETH) | ENC28J60_BANK(0) | 0x0A),  REG_EPMM2    = (ENC28J60_KoR(ETH) | ENC28J60_BANK(1) | 0x0A),
    /*0B*/ REG_ERXNDH    = (ENC28J60_KoR(ETH) | ENC28J60_BANK(0) | 0x0B),  REG_EPMM3    = (ENC28J60_KoR(ETH) | ENC28J60_BANK(1) | 0x0B),
    /*0C*/ REG_ERXRDPTL  = (ENC28J60_KoR(ETH) | ENC28J60_BANK(0) | 0x0C),  REG_EPMM4    = (ENC28J60_KoR(ETH) | ENC28J60_BANK(1) | 0x0C),
    /*0D*/ REG_ERXRDPTH  = (ENC28J60_KoR(ETH) | ENC28J60_BANK(0) | 0x0D),  REG_EPMM5    = (ENC28J60_KoR(ETH) | ENC28J60_BANK(1) | 0x0D),
    /*0E*/ REG_ERXWRPTL  = (ENC28J60_KoR(ETH) | ENC28J60_BANK(0) | 0x0E),  REG_EPMM6    = (ENC28J60_KoR(ETH) | ENC28J60_BANK(1) | 0x0E),
    /*0F*/ REG_ERXWRPTH  = (ENC28J60_KoR(ETH) | ENC28J60_BANK(0) | 0x0F),  REG_EPMM7    = (ENC28J60_KoR(ETH) | ENC28J60_BANK(1) | 0x0F),
    /*10*/ REG_EDMASTL   = (ENC28J60_KoR(ETH) | ENC28J60_BANK(0) | 0x10),  REG_EPMCSL   = (ENC28J60_KoR(ETH) | ENC28J60_BANK(1) | 0x10),
    /*11*/ REG_EDMASTH   = (ENC28J60_KoR(ETH) | ENC28J60_BANK(0) | 0x11),  REG_EPMCSH   = (ENC28J60_KoR(ETH) | ENC28J60_BANK(1) | 0x11),
    /*12*/ REG_EDMANDL   = (ENC28J60_KoR(ETH) | ENC28J60_BANK(0) | 0x12),  /* ------------------------------------------------------- */
    /*13*/ REG_EDMANDH   = (ENC28J60_KoR(ETH) | ENC28J60_BANK(0) | 0x13),  /* ------------------------------------------------------- */
    /*14*/ REG_EDMADSTL  = (ENC28J60_KoR(ETH) | ENC28J60_BANK(0) | 0x14),  REG_EPMOL    = (ENC28J60_KoR(ETH) | ENC28J60_BANK(1) | 0x14),
    /*15*/ REG_EDMADSTH  = (ENC28J60_KoR(ETH) | ENC28J60_BANK(0) | 0x15),  REG_EPMOH    = (ENC28J60_KoR(ETH) | ENC28J60_BANK(1) | 0x15),
    /*16*/ REG_EDMACSL   = (ENC28J60_KoR(ETH) | ENC28J60_BANK(0) | 0x16),	 /*                         Reserved                        */
    /*17*/ REG_EDMACSH   = (ENC28J60_KoR(ETH) | ENC28J60_BANK(0) | 0x17),  /*                         Reserved                        */
    /*18*/ /* ------------------------------------------------------ */    REG_ERXFCON  = (ENC28J60_KoR(ETH) | ENC28J60_BANK(1) | 0x18),
    /*19*/ /* ------------------------------------------------------ */    REG_EPKTCNT  = (ENC28J60_KoR(ETH) | ENC28J60_BANK(1) | 0x19),
    /*1A*/ /*                         Reserved                       */    /*                         Reserved                        */
    /*1B*/ REG_EIE       = (ENC28J60_KoR(ETH) | ENC28J60_BANK(0) |  0x1B), /*                          Common                         */
    /*1C*/ REG_EIR       = (ENC28J60_KoR(ETH) | ENC28J60_BANK(0) |  0x1C), /*                          Common                         */
    /*1D*/ REG_ESTAT     = (ENC28J60_KoR(ETH) | ENC28J60_BANK(0) |  0x1D), /*                          Common                         */
    /*1E*/ REG_ECON2     = (ENC28J60_KoR(ETH) | ENC28J60_BANK(0) |  0x1E), /*                          Common                         */
    /*1F*/ REG_ECON1     = (ENC28J60_KoR(ETH) | ENC28J60_BANK(0) |  0x1F), /*                          Common                         */

    //----------------------------- BANK2 -----------------------------// //-------------------------- BANK3 -------------------------//
    /*00*/ REG_MACON1    = (ENC28J60_KoR(MAC) | ENC28J60_BANK(2) | 0x00), REG_MAADR5    = (ENC28J60_KoR(MAC) | ENC28J60_BANK(3) | 0x00),
    /*01*/ /*                         Reserved                        */ 	REG_MAADR6    = (ENC28J60_KoR(MAC) | ENC28J60_BANK(3) | 0x01),
    /*02*/ REG_MACON3    = (ENC28J60_KoR(MAC) | ENC28J60_BANK(2) | 0x02), REG_MAADR3    = (ENC28J60_KoR(MAC) | ENC28J60_BANK(3) | 0x02),
    /*03*/ REG_MACON4    = (ENC28J60_KoR(MAC) | ENC28J60_BANK(2) | 0x03), REG_MAADR4    = (ENC28J60_KoR(MAC) | ENC28J60_BANK(3) | 0x03),
    /*04*/ REG_MABBIPG   = (ENC28J60_KoR(MAC) | ENC28J60_BANK(2) | 0x04), REG_MAADR1    = (ENC28J60_KoR(MAC) | ENC28J60_BANK(3) | 0x04),
    /*05*/ /* ------------------------------------------------------ */ 	 REG_MAADR2    = (ENC28J60_KoR(MAC) | ENC28J60_BANK(3) | 0x05),
    /*06*/ REG_MAIPGL    = (ENC28J60_KoR(MAC) | ENC28J60_BANK(2) | 0x06), REG_EBSTSD    = (ENC28J60_KoR(ETH) | ENC28J60_BANK(3) | 0x06),
    /*07*/ REG_MAIPGH    = (ENC28J60_KoR(MAC) | ENC28J60_BANK(2) | 0x07), REG_EBSTCON   = (ENC28J60_KoR(ETH) | ENC28J60_BANK(3) | 0x07),
    /*08*/ REG_MACLCON1  = (ENC28J60_KoR(MAC) | ENC28J60_BANK(2) | 0x08), REG_EBSTCSL   = (ENC28J60_KoR(ETH) | ENC28J60_BANK(3) | 0x08),
    /*09*/	REG_MACLCON2  = (ENC28J60_KoR(MAC) | ENC28J60_BANK(2) | 0x09), REG_EBSTCSH   = (ENC28J60_KoR(ETH) | ENC28J60_BANK(3) | 0x09),
    /*0A*/ REG_MAMXFLL   = (ENC28J60_KoR(MAC) | ENC28J60_BANK(2) | 0x0A), REG_MISTAT    = (ENC28J60_KoR(MII) | ENC28J60_BANK(3) | 0x0A),
    /*0B*/ REG_MAMXFLH   = (ENC28J60_KoR(MAC) | ENC28J60_BANK(2) | 0x0B), /* ------------------------------------------------------ */
    /*0C*/ /*                         Reserved                        */		/* ------------------------------------------------------ */
    /*0D*/ /*                         Reserved                        */		/* ------------------------------------------------------ */
    /*0E*/ /*                         Reserved                        */		/* ------------------------------------------------------ */
    /*0F*/ /* ------------------------------------------------------ */			/* ------------------------------------------------------ */
    /*10*/ /*                         Reserved                        */		/* ------------------------------------------------------ */
    /*11*/ /*                         Reserved                        */		/* ------------------------------------------------------ */
    /*12*/ REG_MICMD     = (ENC28J60_KoR(MII) | ENC28J60_BANK(2) | 0x12), REG_EREVID    = (ENC28J60_KoR(ETH) | ENC28J60_BANK(3) | 0x12),
    /*13*/ /* ------------------------------------------------------ */   /* ------------------------------------------------------ */
    /*14*/ REG_MIREGADR  = (ENC28J60_KoR(MII) | ENC28J60_BANK(2) | 0x14),	/* ------------------------------------------------------ */
    /*15*/ /*                         Reserved                        */  REG_ECOCON    = (ENC28J60_KoR(ETH) | ENC28J60_BANK(3) | 0x15),
    /*16*/ REG_MIWRL     = (ENC28J60_KoR(MII) | ENC28J60_BANK(2) | 0x16), /*                         Reserved                        */
    /*17*/ REG_MIWRH     = (ENC28J60_KoR(MII) | ENC28J60_BANK(2) | 0x17), REG_EFLOCON   = (ENC28J60_KoR(ETH) | ENC28J60_BANK(3) | 0x17),
    /*18*/ REG_MIRDL     = (ENC28J60_KoR(MII) | ENC28J60_BANK(2) | 0x18), REG_EPAUSL    = (ENC28J60_KoR(ETH) | ENC28J60_BANK(3) | 0x18),
    /*19*/ REG_MIRDH     = (ENC28J60_KoR(MII) | ENC28J60_BANK(2) | 0x19), REG_EPAUSH    = (ENC28J60_KoR(ETH) | ENC28J60_BANK(3) | 0x19)
    /*1A*/ /*                         Reserved                        */  /*                         Reserved                        */
    /*1B*/ /*                          Common                         */	 /*                          Common                         */
    /*1C*/	/*                          Common                         */	 /*                          Common                         */
    /*1D*/	/*                          Common                         */	 /*                          Common                         */
    /*1E*/	/*                          Common                         */	 /*                          Common                         */
    /*1F*/	/*                          Common                         */  /*                          Common                         */
};

enum ENC28J60_INT: u8t{
    RXERIF,
    TXERIF,
    TXIF,
    LINKIF,
    DMAIF,
    PKTIF
};
/*
typedef void enc_cb_t(ENC28J60_INT type);
class Enc28j60 : public SystemEventHandler
{

public:

	Enc28j60(macaddr_t & mac);
	void setSPI(u8t miso = DEF_SPI_MISO, u8t mosi = DEF_SPI_MOSI, u8t sck = DEF_SPI_SCK, u8t ss = DEF_SPI_SS);

	void sendPacket(u8t* buff, u16t size);
	u16t receivePacket(u8t* buff, u16t size);
	bool isReceivingData();
	bool isLinkUp();
	u8t getUnreadPacket();

	void enableInterrupt(u8t value);
	void disableInterrupt();

	void registerCallback(enc_cb_t *cb = nullptr);



private:
	MasterSPI *_spi;

	struct enc28j60_t
	{
		enc28j60_t() {
			macAddress = macaddr_t (0xA0, 0xB1, 0xC2, 0xD3, 0xE4, 0xF5);
			revisionID = 0;
			fullDuplex = true;
			currentBank = 0;

			nextPacketPtr = ENC28J60_RX_BUFFER_START;
			rxBuffStart = ENC28J60_RX_BUFFER_START;
			rxBuffEnd   = ENC28J60_RX_BUFFER_END;
			txBuffStart = ENC28J60_TX_BUFFER_START;
			txBuffEnd   = ENC28J60_TX_BUFFER_END;

		}
		macaddr_t macAddress;
		u8t revisionID;
		bool fullDuplex;
		u8t currentBank;
		u16t nextPacketPtr;

		u16t rxBuffStart;
		u16t rxBuffEnd;
		u16t txBuffStart;
		u16t txBuffEnd;
	} _self;
	//bool _confirmRegisters = true;
	enc_cb_t *_cb;

	//---- Raw methods ----//
	u8t _spi_readControlReg(ENC28J60_REGS reg);
	void _spi_writeControlReg(ENC28J60_REGS reg, u8t data);

	void _spi_selectBank(u8t bank);

	void _spi_writeOpCode(u8t reg, u8t *buff, size_t size);
	u8t _spi_readOpcode(u16t reg);

	u16t _spi_readPhy(ENC28J60_PHY_REG reg);
	void _spi_writePhy(ENC28J60_PHY_REG reg, u16t data);

	void _spi_bitFieldSet(ENC28J60_REGS reg, u8t data);
	void _spi_bitFieldClear(ENC28J60_REGS reg, u8t data);

	void _spi_reset();

	void _spi_readBuffer(u8t* buff, u16t size);
	void _spi_writeBuffer(u8t* buff, u16t size);

	//---- Complex Methods ----//
	void _spi_setRxBufferSize(u16t size);
	u16t _spi_getRxBufferSize();

	void _spi_setTxBufferSize(u16t size);
	u16t _spi_getTxBufferSize();

	void _spi_setMAC();
	void _spi_getMAC(u8t *arr);

	//void _spi_setRxFilter();

	//bool _spi_setBuffers();

	//---- Others ----//
	void _callback(u8t pin, void *context);

	void callback(u8t pin);

	//---- Remove me ----//
	//Serial *serial;

};
*/
#endif






