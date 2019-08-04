#ifndef TCP_H
#define TCP_H
#include <stdint.h>
#include <macros.h>
#include <utils.h>
#include <ipv4.h>
#include <socket.h>
/* TCP Header
+---+---+---+---+---+---+---+---+---+---+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 | 25 | 26 | 27 | 28 | 29 | 30 | 31 |
+---+---+---+---+---+---+---+---+---+---+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
|                              Source Port                            |                                Destination Port                               |
+---------------+-----------+-----------+-----------------------------+-------------------------------------------------------------------------------+
|                                                                Sequence Number                                                                      |
+---------------+-----------+-----------+-----------------------------+-------------------------------------------------------------------------------+
|                                                             Acknowledgment Number                                                                   |
+---------------+-----------+-----------+-----------------------------+-------------------------------------------------------------------------------+
|  Data Offset  | reserved  |    ECN    |         Control Bits        |                                    Window                                     |
+---------------+-----------+-----------+-----------------------------+-------------------------------------------------------------------------------+
|                           Checksum                                  |                                  Urgent Pointer                               |
+---------------------------------------------------------------------+-------------------------------------------------------------------------------+
|                                                               Option and Padding                                                                    |
+-----------------------------------------------------------------------------------------------------------------------------------------------------+
*/
struct tcp_header_t
{
    tcp_header_t(u16t srcPort = 0, u16t dstPort = 0, u32t seqNumber = 0, u32t ackNumber = 0, u8t dataOffset = 0,
                 u8t ECN = 0,	u8t controlBits = 0, u16t window = 0, u16t crc = 0, u16t urgentPointer = 0, u32t option_pad = 0){
        this->srcPort       = srcPort;
        this->dstPort       = dstPort;
        this->seqNumber     = seqNumber;
        this->ackNumber     = ackNumber;
        this->dataOffset    = dataOffset;
        this->ECN           = ECN;
        this->controlBits   = controlBits;
        this->window        = window;
        this->crc           = crc;
        this->urgentPointer = urgentPointer;
        this->option_pad    = option_pad;
        reserved = 0; // Do not change this
    }

    u16t srcPort;
    u16t dstPort;
    u32t seqNumber;
    u32t ackNumber;
    u8t dataOffset:4;
    u8t reserved:3;
    u8t ECN:3; // Explicit Congestion Notification. 3 bits.
    u8t controlBits:6;
    u16t window; // The number of data bytes beginning with the one indicated in the acknowledgment field which the sender of this segment is willing to accept.
    u16t crc;
    u16t urgentPointer; //If the URG bit is set, this field points to the sequence number of the last byte in a sequence of urgent data.
    u32t option_pad;
    //std::vector<u8t> payload;
};
enum class ECN
{
    NONCE_SUM 	= (1 << 0),
    CWR								= (1 << 1),
    ECN_ECHO   = (1 << 2)

};
enum class TCP_CONTROL_BITS
{
    URG = (1 << 0),
    ACK = (1 << 1),
    PSH = (1 << 2),
    RST = (1 << 3),
    SYN = (1 << 4),
    FIN = (1 << 5)
};

class Tcp
{
public:
    Tcp();
    ~Tcp();
    //void encapsulate(std::vector<u8t> & payload);
    //std::vector<u8t> decapsulate(std::vector<u8t> & data);


private:
    u16t genRandomPort();
    tcp_header_t self;
    IPv4 ipv4;
    Socket _socket;
};

#endif // TCP_H
