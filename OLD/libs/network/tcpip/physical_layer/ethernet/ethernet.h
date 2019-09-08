#ifndef ETHERNET_H
#define ETHERNET_H
#include <stdint.h>
#include <macros.h>
#include <utils.h>
#include <serial.h>
#include <inet_global.h>
/*
struct macaddr_t
{
    macaddr_t(u8t* mac = nullptr) {
        if(mac != nullptr){
            memcpy(&this->mac,mac,6);
        }
    }
    uint8_t mac[6];

};

struct eth_frame_t
{
    eth_frame_t(macaddr_t dstMAC = macaddr_t(), macaddr_t srcMAC = macaddr_t(), u16t etherType = 0, u32t crc = 0, u8t* interpacket_gap = nullptr) {
        this->dstMAC = dstMAC;
        this->srcMAC = srcMAC;
        this->etherType = etherType;
        //this->payload = payload;
        this->crc = crc;
        if(interpacket_gap != nullptr){
            memcpy(interpacket_gap, interpacket_gap, 12);
        }
    }

    u8t preamble[7] = {0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55};
    u8t SFD = 0xD5;
    macaddr_t dstMAC;
    macaddr_t srcMAC;
    u16t etherType;
    std::vector<u8t> payload;
    u32t crc;
    u8t interpacket_gap[12];

};

struct eth_vlan_frame_t // IEE802.3 and IEE802.1Q
{
    eth_vlan_frame_t(macaddr_t dstMAC = macaddr_t(), macaddr_t srcMAC = macaddr_t(), u32t vlanTag = 0, u16t etherType = 0, u32t crc = 0, u8t* interpacket_gap = nullptr) {
        this->dstMAC = dstMAC;
        this->srcMAC = srcMAC;
        this->vlanTag = vlanTag;
        this->etherType = etherType;
        //this->payload = payload;
        this->crc = crc;
        if(interpacket_gap != nullptr){
            memcpy(this->interpacket_gap, interpacket_gap, 12);
        }
    }
    u8t preamble[7] = {0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55};
    u8t SFD = 0xD5;
    macaddr_t dstMAC;
    macaddr_t srcMAC;
    u32t vlanTag;
    u16t etherType;
    std::vector<uint8_t> payload;
    u32t crc;
    u8t interpacket_gap[12];

};
*/


enum class EtherType : u16t {
				IPV4 = 0x0800,
				ARP  = 0x0806,
    WAKE_ON_LAN				      = 0x0842,
    IETF_TRILL				      = 0x22F3,
    STREAM_RESERVATION_PROTOCOL	              = 0x22EA,
    DEC_MOP_RC				      = 0x6002,
    DECNET_PHASE_IV_DNA_ROUTING	              = 0x6003,
    RARP				      = 0x8035,
    APPLETALK_ETHERTALK		              = 0x809B,
    AARP			       	      = 0x80F3,
    IEEE802_1QAND802_1AQ	              = 0x8100,
    SLPP			       	      = 0x8102,
    IPX				       	      = 0x8137,
    QNX_QNET			       	      = 0x8204,
    IPV6				      = 0x86DD,
    ETHERNET_FLOW_CONTROL		      = 0x8808,
    ETHERNET_SLOW_PROTOCOLS		      = 0x8809,
    COBRANET				      = 0x8819,
    MPLS_UNICAST			      = 0x8847,
    MPLS_MULTICAST			      = 0x8848,
    PPPOE_DISCOVERY_STAGE		      = 0x8863,
    PPPOE_SESSION_STAGE			      = 0x8864,
    INTEL_ADVANCED_NETWORKING_SERVICES	      = 0x886D,
    JUMBO_FRAMES			      = 0x8870,
    HOMEPLUG_1_0_MME			      = 0x887B,
    EAP_OVER_LAN_IEEE802_1X		      = 0x888E,
    PROFINET_PROTOCOL			      = 0x8892,
    HYPERSCSI				      = 0x889A,
    ATA_OVER_ETHERNET			      = 0x88A2,
    ETHERCAT_PROTOCOL			      = 0x88A4,
    PROVIDER_BRIDGING_SHORTEST_PATH_BRIDGING  = 0x88A8,
    ETHERNET_POWERLINK                        = 0x88AB,
    GOOSE				      = 0x88B8,
    GSE_MANAGEMENT_SERVICES		      = 0x88B9,
    SV                                        = 0x88BA,
    LLDP                                      = 0x88CC,
    SERCOS_III				      = 0x88CD,
    WSMP				      = 0x88DC,
    HOMEPLUG_AV_MME			      = 0x88E1,
    MEDIA_REDUNDANCY			      = 0x88E3,
    MAC_SECURITY			      = 0x88E5,
    PROVIDER_BACKBONE_BRIDGES		      = 0x88E7,
    PRECISION_TIME_PROTOCOL_OVER_ETHERNET     = 0x88F7,
    NC_SI				      = 0x88F8,
    PRP					      = 0x88FB,
    CONNECTIVITY_FAULT_MANAGEMENT	      = 0x8902,
    FIBRE_CHANNEL_OVER_ETHERNET		      = 0x8906,
    FCOE_INITIALIZATION_PROTOCOL	      = 0x8914,
    RDMA_OVER_CONVERGED_ETHERNET	      = 0x8915,
    TTETHERNET_PROTOCOL_CONTROL_FRAME	      = 0x891D,
    HIGH_AVAILABILITY_SEAMLESS_REDUNDANCY     = 0x892F,
    ETHERNET_CONFIGURATION_TESTING_PROTOCOL   = 0x9000,
    IEEE_802_1Q_DOUBLE_TAGGING		      = 0x9100,
    LOW_LATENCY_TRANSPORT		      = 0xCAFE
};
#define MIN_PAYLOAD_SIZE 46
#define MAX_PAYLOAD_SIZE 1500
/*
class Ethernet
{
public:
    Ethernet();
    bool encapsulate(std::vector<u8t> & payload);
    void decapsulate(std::vector<u8t> & data);
private:
    eth_frame_t frame;
    eth_vlan_frame_t vlan_frame;
};
*/
#endif // ETHERNET_H
