#include "networkmanager.h"

NetworkManager::NetworkManager()
{

}

bool NetworkManager::setupNetwork(INTERFACE interface, const char *ip, const char *mac)
{
    ipv4addr_t ipv4_addr = __inet_ipv4_aton(ip);
    _ipv4.setSrcAddress(ipv4_addr);
}
