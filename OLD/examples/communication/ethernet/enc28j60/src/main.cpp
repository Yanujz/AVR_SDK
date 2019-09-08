#include "avr_sdk.h"

#include <pins.h>

bool debug = true;
#define MISO 50
#define MOSI 51
#define SCK 52
#define SS 53
#pragma pack(1)
struct  eth_header_t
{
	u8t dst_addr[6];
	u8t src_addr[6];
	u8t etherType[2];
};
#pragma pop


void func(uint8_t pin){
	//Serial *serial0 = SerialManager::getInstance(SERIAL0);
//	serial0->printf("Interrupt dal pin %u\r\n", pin);
}

//extern void toggle(u8t pin);

int main(){
	//Serial *serial0 = SerialManager::getInstance(SERIAL0);
	//serial0->init(BAUD_1000000);
	//serial0->setRxISRCallBack(false);
	//serial0->setEchoServer(false);
	//serial0->clear();

	//Pin pin(13,OUTPUT);
	//pin.setPWM(1000, 50);


	macaddr_t asd(0xA0, 0xB1, 0xC2, 0xD3, 0xE4, 0xF5);
	Enc28j60 encj2860(asd);
	//encj2860.setSPI(MISO,MOSI,SCK,SS);
	//encj2860.init();

	//encj2860.setMAC(std::vector<uint8_t>{0xAA,0xBB,0xCC,0xDD,0xEE,0xFF});
	//std::vector<uint8_t> a{0xA0,0xB1,0xC2,0xD3,0xE4,0xF5};
	//u8t c[] = {0xF5,0xE4,0xD3,0xC2,0xB1,0xA0};

	//u8t mac[6];
	//encj2860._spi_getMAC(mac);
	//for(size_t i = 0; i < 6; ++i){
	//	serial0->printf("Data[%u] 0x%02X\r\n", i, mac[i]);
	//}
	//if(memcmp(c, mac, MACADDR_N_OCTECTS) == 0){
	//	serial0->printf("Mac set ok\r\n");
	//}


	u8t frameLittle[] = {
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xA0, 0xB1, 0xC2, 0xD3, 0xE4, 0xF5,
		0x08, 0x06, 0x00, 0x01, 0x08, 0x00,
		0x06, 0x04, 0x00, 0x01, 0xA0, 0xB1,
		0xC2,	0xD3, 0xE4, 0xF5, 0xC0, 0xA8,
		0x02,	0xC8, 0x00, 0x00, 0x00, 0x00,
		0x00,	0x00, 0xC0, 0xA8, 0x02, 0x01
	};
	u8t frameBig[] = {
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xF5, 0xE4, 0xD3, 0xC2, 0xB1, 0xA0,
		0x06, 0x08, 0x01, 0x00, 0x00, 0x08,
		0x04, 0x06, 0x01, 0x00, 0xF5, 0xE4,
		0xD3,	0xC2, 0xB1, 0xA0, 0xC8, 0x02,
		0xA8,	0xC0, 0x00, 0x00, 0x00, 0x00,
		0x00,	0x00, 0x01, 0x02, 0xA8, 0xC0
	};


	
	/*
	u8t _dst[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
	u8t _src[] = {0xA0, 0xB1, 0xC2, 0xD3, 0xE4, 0xF5};
	//u8t _src[] = {0xF5, 0xE4, 0xD3, 0xC2, 0xB1, 0xA0};

	macaddr_t dst((char*)_dst);
	macaddr_t src((char*)_src);

	eth_frame_t eth(dst, src);
	eth.etherType = 0x0608;

	arp_header_t arp;
	arp.hardwareType = 0x0100;
	arp.protocolType = 0x0008;
	arp.hw_addr_length = 6;
	arp.proto_addr_length = 4;
	arp.opcode = 0x0100;
	arp.src_hw_addr = 0xF5E4D3C2B1A0;

	//arp.src_proto_addr = 0xC0A802C8;
	arp.src_proto_addr = __inet_ipv4_aton("192.168.2.200").ip;//0xC802A8C0;
	arp.dst_hw_addr = 0;
	//arp.dst_proto_addr = 0xC0A80201;
	arp.dst_proto_addr = __inet_ipv4_aton("192.168.2.1").ip;//0x0102A8C0;
	//arp.dst_proto_addr = 0x0102A8C0;

	std::vector<u8t> ptr;
	ptr.insert(ptr.begin(), (u8t*)&eth, (u8t*)&eth+sizeof(eth));
	ptr.insert(ptr.end(), (u8t*)&arp, (u8t*)&arp+sizeof(arp));

*/


	//	for(size_t i = 0; i < SIZE_OF_ARRAY(frame); ++i){
	//		if(i % 15 == 0){
	//			serial0->printf("\r\n");
	//		}
	//		serial0->printf("[%02u] 0x%02X ", i, frame[i]);
	//	}
	//	serial0->printf("\r\n");
	//	__swapEndian(frame, 4, SIZE_OF_ARRAY(frame));
	//	for(size_t i = 0; i < SIZE_OF_ARRAY(frame); ++i){
	//		if(i % 15 == 0){
	//			serial0->printf("\r\n");
	//		}
	//		serial0->printf("[%02u] 0x%02X ", i, frame[i]);
	//	}
	//encj2860._spi_selectBank(3);
	//u8t buff[512];

	//for(size_t i = 0; i < SIZE_OF_ARRAY(frameLittle); ++i){
	//	if(i % 15 == 0){
	//		serial0->printf("\r\n");
	//	}
	//	serial0->printf("[%02u] 0x%02X ", i, buff[i]);
	//}

	//encj2860.sendPacket(frameLittle, SIZE_OF_ARRAY(frameLittle));

	//u16t size = 0;
	//serial0->printf("\r\n");
	//if(encj2860.isLinkUp()) {
	//serial0->printf("Link is up\r\n");
	//}
	//serial0->printf("\r\n");


	//encj2860.enableInterrupt(regBitToValue(ENC28J60_EIE_REG_BIT::LINKIE));
	//encj2860.registerCallback((enc_cb_t*)func);

	//Interrupt::attachInterrupt(13, FALLING, (int_cb_t*)&([&](){
	//																																																								Serial *serial0 = SerialManager::getInstance(SERIAL0);
	//																																																								serial0->printf("Interrupt dal pin\r\n");
	//																																																									}
	//																																																								) );
	//int_cb_t *ptr =  (int_cb_t*)func;
	//ptr(0);
	//eth_header_t _eth;
	//arp_header_t _arp;
	//pinMode(13, OUTPUT);

	while(1){
		//toggle(13);

		//PORTB ^= 0x80;
		//if(encj2860.isLinkUp()) {
		//	serial0->printf("link is up\r\n");
		//	serial0->printf("unread packet %u\r\n", encj2860.getUnreadPacket());
		//	if(encj2860.isReceivingData()) {
		//		serial0->printf("Receiving data\r\n");
		//	}
		//}
		//serial0->printf("Sending...\r\n");
		//encj2860.sendPacket(ptr.begin(), ptr.size());
		//encj2860.sendPacket(frameLittle, SIZE_OF_ARRAY(frameLittle));
		///	//if(encj2860.newPacket()){
		//size = encj2860.receivePacket(buff, SIZE_OF_ARRAY(buff));
		//if(size){
		//	serial0->printf("\r\nPacket size: %u\r\n",size);
		//	memcpy(&_eth, buff, sizeof(eth_header_t));
		//	serial0->printf("Ethernet:\r\n");
		//	serial0->printf("\tDestination : %02X:%02X:%02X:%02X:%02X:%02X\r\n", _eth.dst_addr[0], _eth.dst_addr[1], _eth.dst_addr[2], _eth.dst_addr[3], _eth.dst_addr[4], _eth.dst_addr[5]);
		//	serial0->printf("\tSource      : %02X:%02X:%02X:%02X:%02X:%02X\r\n", _eth.src_addr[0], _eth.src_addr[1], _eth.src_addr[2], _eth.src_addr[3], _eth.src_addr[4], _eth.src_addr[5]);
		//	__swapEndian(_eth.etherType,2,2);
		//	serial0->printf("\tEtherType   : 0x%04X\r\n", *(toU16Ptr(_eth.etherType)));
		//	if(*(toU16Ptr(_eth.etherType)) == toU16(EtherType::ARP)){
		//		serial0->printf("ARP:\r\n");
		//		memcpy(&_arp, buff+sizeof(eth_header_t), sizeof(arp_header_t));
		//		serial0->printf("\tHardware Type  : 0x%04X\r\n", *(toU16Ptr(_arp.hardwareType)));
		//		serial0->printf("\tProtocol Type  : 0x%04X\r\n", *(toU16Ptr(_arp.protocolType)));
		//		serial0->printf("\tHardware len   : 0x%02X\r\n", _arp.hw_addr_length);
		//		serial0->printf("\tProtocol len   : 0x%02x\r\n", _arp.proto_addr_length);
		//		serial0->printf("\tOpcode         : 0x%04x\r\n", *(toU16Ptr(_arp.opcode)));
		//		serial0->printf("\tSrc hw addr    : %02X:%02X:%02X:%02X:%02X:%02X\r\n", _arp.src_hw_addr[0], _arp.src_hw_addr[1], _arp.src_hw_addr[2], _arp.src_hw_addr[3], _arp.src_hw_addr[4], _arp.src_hw_addr[5]);
		//		serial0->printf("\tSrc proto addr : %d.%d.%d.%d\r\n", _arp.src_proto_addr[0], _arp.src_proto_addr[1], _arp.src_proto_addr[2], _arp.src_proto_addr[3] );
		//		serial0->printf("\tDst hw addr    : %02X:%02X:%02X:%02X:%02X:%02X\r\n", _arp.dst_hw_addr[0], _arp.dst_hw_addr[1], _arp.dst_hw_addr[2], _arp.dst_hw_addr[3], _arp.dst_hw_addr[4], _arp.dst_hw_addr[5]);
		//		serial0->printf("\tDst proto addr : %d.%d.%d.%d\r\n", _arp.dst_proto_addr[0], _arp.dst_proto_addr[1], _arp.dst_proto_addr[2], _arp.dst_proto_addr[3]);
		//
		//	}
		//
		//}
		//	_delay_ms(500);
	}
}

