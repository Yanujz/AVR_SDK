#ifndef ARP_H
#define ARP_H
#include <stdint.h>
#include <macros.h>
#include <utils.h>
/* ARP Header
+---+---+---+---+---+---+---+---+---+---+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 | 25 | 26 | 27 | 28 | 29 | 30 | 31 |
+---+---+---+---+---+---+---+---+---+---+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
|                          Hardware type                              |                                  Protocol type                                |
+-------------------------------+-------------------------------------+-------------------------------------------------------------------------------+
| Hardware address length       |       Protocol address length       |                                     Opcode                                    |
+-------------------------------+-------------------------------------+-------------------------------------------------------------------------------+
|                                                          Source hardware address                                                                    |
+-----------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                          Source protocol address                                                                    |
+-----------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                        Destination hardware address                                                                 |
+-----------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                        Destination protocol address                                                                 |
+-----------------------------------------------------------------------------------------------------------------------------------------------------+
*/
struct arp_header_t{
				u8t hardwareType[2];
				u8t protocolType[2];
    u8t hw_addr_length;
    u8t proto_addr_length;
				u8t opcode[2];
				u8t src_hw_addr[6];
				u8t src_proto_addr[4];
				u8t dst_hw_addr[6];
				u8t dst_proto_addr[4];
};

enum class HARDWARE_TYPE {
    ETHERNET              = 0x01,
    EXPERIMENTAL_ETHERNET = 0x02,
    AMATEUR_RADIO_AX_25	  = 0x03,
    PROTEON_PRONET_TOKEN_RING	=	0x04,
    CHAOS																					=	0x05,
    IEEE802																			=	0x06,
    ARCNET_RFC_1201											=	0x07,
    HYPERCHANNEL														=	0x08,
    LANSTAR																			=	0x09,
    AUTONET_SHORT_ADDRESS					=	0x0A,
    LOCALTALK																	=	0x0B,
    LOCALNET																		=	0x0C,	//(IBM PCNET OR SYTEK LOCALNET)
    ULTRA_LINK																=	0x0D,
    SMDS																						=	0x0E,
    FRAME_RELAY															=	0x0F,
    ATM0 																					=	0x10,
    HDLC																						=	0x11,
    FIBRE_CHANNEL													=	0x12,
    ATM1																						=	0x13,
    SERIAL_LINE															=	0x14,
    ATM2																						=	0x15,
    MIL_STD_188_220											=	0x16,
    METRICOM																		=	0x17,
    IEEE_1394_1995												=	0x18,
    MAPOS																					=	0x19,
    TWINAXIAL																	=	0x1A,
    EUI_64																				=	0x1B,
    HIPARP																				=	0x1C,
    IP_ARP_OVER_ISO7816_3					=	0x1D,
    ARPSEC																				=	0x1E,
    IPSEC_TUNNEL														=	0x1F,
    INFINIBAND																=	0x20,
    CAI																							=	0x21, //TIA-102 PROJECT 25 COMMON AIR INTERFACE
    WIEGAND_INTERFACE									=	0x22,
    PURE_IP																			=	0x23,
    HW_EXP1																			=	0x24,
    HW_EXP2																			=	0x100
};


enum class OPCODE{
    REQUEST																 = 0x01,
    REPLY																		 = 0x02,
    REQUEST_REVERSE								 = 0x03,
    REPLY_REVERSE										 = 0x04,
    DRARP_REQUEST										 = 0x05,
    DRARP_REPLY												 = 0x06,
    DRARP_ERROR												 = 0x07,
    INARP_REQUEST										 = 0x08,
    INARP_REPLY												 = 0x09,
    ARP_NAK																 = 0x0A,
    MARS_REQUEST											 = 0x0B,
    MARS_MULTI													 = 0x0C,
    MARS_MSERV													 = 0x0D,
    MARS_JOIN														 = 0x0E,
    MARS_LEAVE													 = 0x0F,
    MARS_NAK															 = 0x10,
    MARS_UNSERV												 = 0x11,
    MARS_SJOIN													 = 0x12,
    MARS_SLEAVE												 = 0x13,
    MARS_GROUPLIST_REQUEST  = 0x14,
    MARS_GROUPLIST_REPLY			 = 0x15,
    MARS_REDIRECT_MAP						 = 0x16,
    MAPOS_UNARP												 = 0x17,
    OP_EXP1																 = 0x18,
    OP_EXP2																 = 0x19,
};


class Arp
{
public:
    Arp();
    ~Arp();
};

#endif // ARP_H
/*





























*/
