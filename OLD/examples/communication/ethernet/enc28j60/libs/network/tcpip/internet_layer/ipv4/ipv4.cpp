#include "ipv4.h"


IPv4::IPv4(){
	//serial = SerialManager::getInstance(SERIAL0);
}

IPv4::~IPv4()
{

}
/*
void IPv4::encapsulate(std::vector<u8t> &payload)
{

				//dbg("size header : %u\r\n", sizeof(ipv4_header_t));
				//dbg("size bef : %u\r\n", sizeof(packet));
				//dbg("Payload data %s\r\n", payload.begin());
				//packet.payload.insert(packet.payload.begin(), payload.begin(), payload.end());
				//dbg("size after: %u\r\n", sizeof(packet));
				//std::vector<u8t> a;
				//a.reserve(sizeof(packet));
				//memcpy(&a, &packet, sizeof(packet));
				//dbg("size : %u", packet.payload.size());
				//ethernet.encapsulate(a);

}

std::vector<u8t> IPv4::decapsulate(std::vector<u8t> &data)
{

}
*/
void IPv4::setSrcAddress(ipv4addr_t &ip)
{
    packet.sourceAddress = ip.ip;
				//dbg("ip %lu\r\n",packet.sourceAddress);
}

void IPv4::setDstAddress(ipv4addr_t & ip)
{
    packet.destinationAddress = ip.ip;
}

HEAD_IPV4_PROTOCOL IPv4::getProtocol() const
{
    return (HEAD_IPV4_PROTOCOL)packet.protocol;
}

void IPv4::setProtocol(const HEAD_IPV4_PROTOCOL &value)
{
    packet.protocol = (u8t)value;
}
/*
ipv4addr_t IPv4::aton(char *ip)
{
    char *octects[4];
    ipv4addr_t tmp;

    //dbg(SERIAL0,"n split %u\r\n", split(ip, octects, "."));
    if(split(ip, octects, (char*)".") != 4){
         return tmp;
     }
    for(u8t i = 0;  i < 4 ; ++i){
        tmp.fields[i] = atoi(octects[i]);
    }
    return tmp;
}

ipv4addr_t IPv4::aton(const std::string &ip)
{
    std::vector<std::string> octects = split(ip,'.');
    ipv4addr_t tmp;
    if(octects.size() != 4 ){
        return tmp;
    }
    for(u8t i = 0; i < octects.size(); ++i ){
        tmp.fields[i] = atoi(octects[i].c_str());
    }
    return tmp;
}
*/
char *IPv4::ntoa(const u32t ip)
{

}

