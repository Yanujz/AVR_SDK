#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H
#include <ipv4.h>
#include <net_utils.h>

enum class INTERFACE {
    ENC28J60
};

enum class PROTOCOL_TYPE {
    TCP, UDP
};
class NetworkManager
{
public:
    NetworkManager();
    void loadInterface(INTERFACE interface);
    bool setupNetwork(INTERFACE interface, const char* ip, const char* mac);
    //bool send(std::vector<u8t> data, PROTOCOL_TYPE proto, const char* ip, u16t port);
    bool send(const char* data, PROTOCOL_TYPE proto, const char* ip, u16t port);
private:
    IPv4 _ipv4;
};

#endif // NETWORKMANAGER_H
