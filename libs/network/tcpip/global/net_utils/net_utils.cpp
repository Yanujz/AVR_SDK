#include "net_utils.h"

//---- IPV4 ----//

ipv4addr_t __inet_ipv4_getBroadcastAddr(const char *ip)
{
    ipv4addr_t temp;
    if(isInRange(strlen(ip), IPV4_STR_MIN_LEN, IPV4_NETMASK_STR_MAX_LEN) == false){
        return temp;
    }
    u8t _ip[5];
    __inet_ipv4_netmask_split(_ip, ip);

    temp.ip |= ~__inet_ipv4_itosubnet(_ip[4]);

    return temp;
}

ipv4addr_t __inet_ipv4_getBroadcastAddr(ipv4addr_t ip, ipv4addr_t netmask)
{
    ipv4addr_t temp;
    temp.ip = ip.ip | ~netmask.ip;
    return temp;
}


ipv4addr_t __inet_ipv4_getNetworkAddr(const char *ip)
{
    ipv4addr_t temp;
    if(isInRange(strlen(ip), IPV4_STR_MIN_LEN, IPV4_NETMASK_STR_MAX_LEN) == false){
        return temp;
    }
    u8t _ip[5];
    __inet_ipv4_netmask_split(_ip, ip);

    temp.ip &= __inet_ipv4_itosubnet(_ip[4]);

    return temp;
}



ipv4addr_t __inet_ipv4_getNetworkAddr(ipv4addr_t ip, ipv4addr_t netmask)
{
    ipv4addr_t temp;
    temp.ip = ip.ip & netmask.ip;
    return temp;
}

size_t __inet_ipv4_getNumberClients(const char *ip)
{

}

u32t __inet_ipv4_itosubnet(u8t netmask)
{
    if(isInRange(netmask,1,32) == false){
        return 0;
    }
    u32t _netmask32;
    u8t i = 31;
    do{
        bitSet(_netmask32,i--);
        netmask;
    }while(netmask--);

    return _netmask32;
}


u32t __inet_ipv4_getWildcard(const char* ip)
{
    return ~__inet_ipv4_getSubnet(ip);
}

u32t __inet_ipv4_itowildcard(u8t netmask)
{
    return ~__inet_ipv4_itosubnet(netmask);
}

u32t __inet_ipv4_getSubnet(const char *ip)
{
    return __inet_ipv4_itosubnet(__inet_ipv4_netmask_split(ip));
}

void __inet_ipv4_netmask_split(u8t *dst, const char *ip)
{
    if(isInRange(strlen(ip), IPV4_NETMASK_STR_MIN_LEN, IPV4_NETMASK_STR_MAX_LEN) == false){
        dst = nullptr;
        return;
    }
    char *_ip[5]; // 4 Octects 1 netmask
    if(split(ip,_ip,"./") != 5) { // 0.0.0.0/0
        return;
    }
    for(u8t i = 0; i < 4; ++i){
        dst[i] = atoi((const char*)_ip[i]);
    }

    dst[4] = __inet_ipv4_itosubnet(atoi((const char*)_ip[4]));
}


u8t __inet_ipv4_netmask_split(const char *ip)
{
    char *_ip[2];
    if(split(ip,_ip,"/") != 2) { // 0.0.0.0/0
        return 0;
    }
    u8t netmask = atoi(_ip[1]);
    if(isInRange(netmask,IPV4_NETMASK_STR_MIN_LEN,IPV4_NETMASK_STR_MAX_LEN)){
        return  netmask;

    }
    return 0;
}


bool __inet_ipv4_isValidIP(const char *ip)
{
    if(isInRange(strlen(ip), IPV4_NETMASK_STR_MIN_LEN, IPV4_NETMASK_STR_MAX_LEN) == false){
        return false;
    }
    u8t _ip[5];
    __inet_ipv4_netmask_split(_ip, ip);
    for(u8t i = 0; i < IPV4_N_OCTECTS; ++i){
        if(isInRange(atoi((const char*)_ip[i]),0,255) == false){
            return false;
        }
    }
    if(isInRange(atoi((const char*)_ip[4]), 1, 32) == false ){
        return false;
    }
    return true;
}

ipv4addr_t __inet_ipv4_aton(const string &ip)
{
    ipv4addr_t tmp;
    if(__inet_ipv4_isValidIP(ip.c_str()) == false){
        return tmp;
    }
    std::vector<std::string> octects = split(ip,'.');
    if(octects.size() != 4 ){
        return tmp;
    }
    for(u8t i = 0; i < octects.size(); ++i ){
        tmp.fields[i] = atoi(octects[i].c_str());
    }
    return tmp;
}

ipv4addr_t __inet_ipv4_aton(char *ip)
{
    ipv4addr_t tmp;
    if(__inet_ipv4_isValidIP(ip) == false){
        return tmp;
    }
    char *octects[4];

    if(split(ip, octects, (char*)".") != 4){
        return tmp;
    }
    for(u8t i = 0;  i < 4 ; ++i){
        tmp.fields[i] = atoi(octects[i]);
    }
    return tmp;

}

void __inet_ipv4_ntoa(char *dst, ipv4addr_t ip)
{
    sprintf(dst,"%u.%u.%u.%u",ip.fields[0], ip.fields[1], ip.fields[2], ip.fields[3]);
}

string __inet_ipv4_ntoa(ipv4addr_t ip)
{
    std::string _ip;
    _ip.reserve(sizeof(ip.ip));
    sprintf(_ip.begin(),"%u.%u.%u.%u",ip.fields[0], ip.fields[1], ip.fields[2], ip.fields[3]);
    return _ip;
}



//---- End IPV4 ----//
