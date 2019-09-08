#ifndef INET_GLOBAL_H
#define INET_GLOBAL_H
//#include <macros.h>
//#include <utils.h>
#include <strutil.h>
#define MACADDR_N_OCTECTS 6
//---- IPV4 ----//
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
//	std::vector<u8t> payload;

};
typedef union{
	u8t fields[4];
	u32t ip;
}ipv4addr_t;

//---- End IPV4 ----//

//---- Ethernet ----//
struct macaddr_t
{
	// macaddr_t(){}
	//macaddr_t(char* mac = nullptr) {
	//	if(mac != nullptr){
	//		memcpy(&_mac,mac,6);
	//	}
	//}
	macaddr_t(u8t oct0 = 0, u8t oct1 = 0, u8t oct2 = 0, u8t oct3 = 0,u8t oct4 = 0, u8t oct5 = 0 ) {
		_mac[0] = oct0;
		_mac[1] = oct1;
		_mac[2] = oct2;
		_mac[3] = oct3;
		_mac[4] = oct4;
		_mac[5] = oct5;
	}
	uint8_t _mac[6];

};

struct eth_frame_t
{
	eth_frame_t(macaddr_t dstMAC = macaddr_t(), macaddr_t srcMAC = macaddr_t(), u16t etherType = 0,
													u32t crc = 0, u8t* interpacket_gap = nullptr) {
		//this->dstMAC = dstMAC;
		//this->srcMAC = srcMAC;
		memcpy(this->dstMAC._mac, dstMAC._mac, MACADDR_N_OCTECTS);
		memcpy(this->srcMAC._mac, srcMAC._mac, MACADDR_N_OCTECTS);
		this->etherType = etherType;
		//this->payload = payload;
		//this->crc = crc;
		//if(interpacket_gap != nullptr){
		//    memcpy(interpacket_gap, interpacket_gap, 12);
		//}
	}

	//u8t preamble[7] = {0x55 , 0x55, 0x55, 0x55, 0x55, 0x55, 0x55};
	//u8t SFD = 0xD5;
	macaddr_t dstMAC;
	macaddr_t srcMAC;
	u16t etherType;
	//std::vector<u8t> payload;
	//u32t crc;
	//u8t interpacket_gap[12];

};

struct eth_vlan_frame_t // IEE802.3 and IEE802.1Q
{
	eth_vlan_frame_t(macaddr_t dstMAC = macaddr_t(), macaddr_t srcMAC = macaddr_t(), u32t vlanTag = 0,
																		u16t etherType = 0, u32t crc = 0, u8t* interpacket_gap = nullptr) {
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
//	std::vector<uint8_t> payload;
	u32t crc;
	u8t interpacket_gap[12];

};

//---- End Ethernet ----//

#endif // INET_GLOBAL_H
