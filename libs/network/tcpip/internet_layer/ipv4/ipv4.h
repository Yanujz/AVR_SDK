#ifndef IPV4_H
#define IPV4_H
#include <stdint.h>
#include <macros.h>
#include <utils.h>
#include <ethernet.h>
#include <serial.h>
//#include <string>
#include <strutil.h>
#include <inet_global.h>
//#include <net_utils.h>
//extern bool debug;
//#include <vector>

/* IPv4 Header
+---+---+---+---+---+---+---+---+---+---+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 | 25 | 26 | 27 | 28 | 29 | 30 | 31 |
+---+---+---+---+---+---+---+---+---+---+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
|     Version   | Header Length |      Differentiated Services        |                               Total Length                                    |
+---------------+---------------+-------------------------------------+--------------+----------------------------------------------------------------+
|                          Identification                             |    Flags     |                       Fragment Offset                          |
+-------------------------------+-------------------------------------+--------------+----------------------------------------------------------------+
|         Time to Live          |               Protocol              |                             Header Checksum                                   |
+-------------------------------+-------------------------------------+-------------------------------------------------------------------------------+
|                                                                Source Address                                                                       |
+-----------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                              Destination Address                                                                    |
+-----------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                               Option and Padding                                                                    |
+-----------------------------------------------------------------------------------------------------------------------------------------------------+
*/

/*
struct ipv4_header_t
{
    ipv4_header_t() {}
    u8t version:4;
    u8t headerLength:4;
    u8t diffServices;
    u32t total_length;
    u16t identificaton;
    u8t flags:3;
    u16t fragmentOffset:13;
    u8t TTL;
    u8t protocol;
    u32t headerCRC;
    u32t sourceAddress;
    u32t destinationAddress;
    u8t option;
    u8t padding[3];
    std::vector<u8t> payload;

};
typedef union{
    u8t fields[4];
    u32t ip;
}ipv4addr_t;
*/
//extern  ipv4addr_t ipv4addr_u_t;

enum class HEAD_IPV4_VERSION {
    IPV4 = 4,
    ST,
    IPV6,
    TP_IX,
    PIP,
    TUBA
};

enum class HEAD_IPV4_DIFFSEVICES{
    CS0                      = 0b000000,
    CS1                      = 0b001000,
    CS2                      = 0b010000,
    CS3                      = 0b011000,
    CS4                      = 0b100000,
    CS5                      = 0b101000,
    CS6                      = 0b110000,
    CS7                      = 0b111000,
    ASSURED_FORWARDING11     = 0b001010,
    ASSURED_FORWARDING12     = 0b001100,
    ASSURED_FORWARDING13     = 0b001110,
    ASSURED_FORWARDING21     = 0b010010,
    ASSURED_FORWARDING22     = 0b010100,
    ASSURED_FORWARDING23     = 0b010110,
    ASSURED_FORWARDING31     = 0b011010,
    ASSURED_FORWARDING32     = 0b011100,
    ASSURED_FORWARDING33     = 0b011110,
    ASSURED_FORWARDING41     = 0b100010,
    ASSURED_FORWARDING42     = 0b100100,
    ASSURED_FORWARDING43     = 0b100110,
    VOICE_ADMIT              = 0b101100,
    EXPEDITED_FORWARDING_PHB = 0b101110

};

enum class HEAD_IPV4_PROTOCOL {
    HOPOPT              = 0, // IPv6 Hop-by-Hop Option
    ICMP                = 1, // Internet Control Message Protocol
    IGMP                = 2, // Internet Group Management Protocol  IGAP, IGMP for user Authentication Protocol RGMP, Router-port Group Management Protocol
    GGP                 = 3, //Gateway to Gateway Protocol
    IP                  = 4, //in IP encapsulation
    ST                  = 5, // Internet Stream Protocol
    TCP                 = 6, // Transmission Control Protocol
    UCL_CBT             = 7,
    EGP                 = 8, //Exterior Gateway Protocol
    IGRP                = 9, // Interior Gateway Routing Protocol
    BBN_RCC_MONITORING  = 10,
    NVP                 = 11, // Network Voice Protocol
    PUP                 = 12,
    ARGUS               = 13,
    EMCON               = 14, // Emission Control Protocol
    XNET                = 15, // Cross Net Debugger
    Chaos               = 16,
    UDP                 = 17 // User Datagram Protocol

};


class IPv4
{
public:
    //---- Methods -----//
    IPv4();
    ~IPv4();
/*
    void encapsulate(std::vector<u8t> & payload);
    std::vector<u8t> decapsulate(std::vector<u8t> & data);
*/
    u32t getSrcAddress();
    void setSrcAddress(ipv4addr_t & ip);

    u32t getDstAddress();
    void setDstAddress(ipv4addr_t & ip);

    HEAD_IPV4_PROTOCOL getProtocol() const;
    void setProtocol(const HEAD_IPV4_PROTOCOL &value);

    //ipv4addr_t aton(const std::string &ip);
    //ipv4addr_t aton(char *ip);
    char *ntoa(const u32t ip);

    //---- Variables ----//

private:
    //---- Methods -----//
    u16t calcHeaderCrc();

    //---- Variables ----//
    ipv4addr_t self;
    ipv4_header_t packet;
				//Ethernet ethernet;


				// REMOVE ME
				//Serial *serial;
};

#endif

/*

TMux, Transport Multiplexing Protocol =18,
DCN Measurement Subsystems =19,

HMP, Host Monitoring Protocol =20,
Packet Radio Measurement =21,
XEROX NS IDP =22,
Trunk-1 =23,
Trunk-2 =24,
Leaf-1 =25,
Leaf-2 =26,

RDP, Reliable Data Protocol =27,

IRTP, Internet Reliable Transaction Protocol =28,
ISO Transport Protocol Class 4 =29,

NETBLT, Network Block Transfer =30,
MFE Network Services Protocol =31,
MERIT Internodal Protocol =32,

DCCP, Datagram Congestion Control Protocol =33,
Third Party Connect Protocol =34,

IDPR, Inter-Domain Policy Routing Protocol =35,

XTP, Xpress Transfer Protocol =36,
Datagram Delivery Protocol =37,

IDPR, Control Message Transport Protocol =38,
TP++ Transport Protocol =39,
IL Transport Protocol =40,

IPv6 over IPv4 =41,

SDRP, Source Demand Routing Protocol =42,
IPv6 Routing header =43,
IPv6 Fragment header =44,
IDRP, Inter-Domain Routing Protocol =45,

RSVP, Reservation Protocol =46,

GRE, General Routing Encapsulation =47,

DSR, Dynamic Source Routing Protocol =48,
BNA =49,

ESP, Encapsulating Security Payload =50,

AH, Authentication Header =51,
I-NLSP, Integrated Net Layer Security TUBA =52,
SWIPE, IP with Encryption =53,

NARP, NBMA Address Resolution Protocol =54,

Minimal Encapsulation Protocol =55,
TLSP, Transport Layer Security Protocol using Kryptonet key management =56,
SKIP =57,

ICMPv6, Internet Control Message Protocol for IPv6
MLD, Multicast Listener Discovery =58,
IPv6 No Next Header =59,
IPv6 Destination Options =60,
Any host internal protocol =61,
CFTP =62,
Any local network =63,
SATNET and Backroom EXPAK =64,
Kryptolan =65,
MIT Remote Virtual Disk Protocol =66,
Internet Pluribus Packet Core =67,
Any distributed file system =68,
SATNET Monitoring =69,
VISA Protocol =70,
Internet Packet Core Utility =71,
Computer Protocol Network Executive =72,
Computer Protocol Heart Beat =73,
Wang Span Network =74,
Packet Video Protocol =75,
Backroom SATNET Monitoring =76,
SUN ND PROTOCOL-Temporary =77,
WIDEBAND Monitoring =78,
WIDEBAND EXPAK =79,

ISO-IP =80,

VMTP, Versatile Message Transaction Protocol =81,
SECURE-VMTP=82,
VINES =83,
TTP =84,
NSFNET-IGP =85,
Dissimilar Gateway Protocol =86,
TCF =87,
EIGRP =88,

OSPF, Open Shortest Path First Routing Protocol
MOSPF, Multicast Open Shortest Path First =89,
Sprite RPC Protocol =90,
Locus Address Resolution Protocol =91,

MTP, Multicast Transport Protocol =92,

AX 25 =93,
IP-within-IP Encapsulation Protocol =94,
Mobile Internetworking Control Protocol =95,
Semaphore Communications Sec  Pro =96,

EtherIP =97,
Encapsulation Header =98,
Any private encryption scheme =99,
GMTP =100,
IFMP, Ipsilon Flow Management Protocol =101,
PNNI over IP =102,

PIM, Protocol Independent Multicast =103,
ARIS =104,
SCPS =105,
QNX =106,
Active Networks =107,

IPPCP, IP Payload Compression Protocol =108,
SNP, Sitara Networks Protocol =109,
Compaq Peer Protocol =110,
IPX in IP =111,

VRRP, Virtual Router Redundancy Protocol =112,

PGM, Pragmatic General Multicast =113,
any 0-hop protocol =114,

L2TP, Level 2 Tunneling Protocol =115,
DDX, D-II Data Exchange =116,
IATP, Interactive Agent Transfer Protocol =117,
ST, Schedule Transfer =118,
SRP, SpectraLink Radio Protocol =119,
UTI =120,
SMP, Simple Message Protocol =121,
SM =122,

PTP, Performance Transparency Protocol =123,
ISIS over IPv4 =124,
FIRE =125,
CRTP, Combat Radio Transport Protocol =126,
CRUDP, Combat Radio User Datagram =127,
SSCOPMCE =128,
IPLT =129,
SPS, Secure Packet Shield =130,
PIPE, Private IP Encapsulation within IP =131,

SCTP, Stream Control Transmission Protocol =132,
Fibre Channel =133,

RSVP-E2E-IGNORE =134,

Mobility Header =135,

UDP-Lite, Lightweight User Datagram Protocol =136,

MPLS in IP =137,
MANET protocols =138,

HIP, Host Identity Protocol =139,

Shim6, Level 3 Multihoming Shim Protocol for IPv6 =140,
WESP, Wrapped Encapsulating Security Payload =141,

ROHC, RObust Header Compression =142,



*/
