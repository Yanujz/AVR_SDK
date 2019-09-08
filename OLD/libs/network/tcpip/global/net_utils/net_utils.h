#ifndef NET_UTILS_H
#define NET_UTILS_H
#include <stdlib.h>
#include <inet_global.h>

//extern struct macaddr_t _macaddr_t;

///@file

//---- IPV4 ----//

///\brief Ex: 0.0.0.0
#define IPV4_STR_MIN_LEN 7

///\brief Ex: 255.255.255.255
#define IPV4_STR_MAX_LEN 15

///\brief Ex: 0.0.0.0/0
#define IPV4_NETMASK_STR_MIN_LEN 9

///\brief Ex: 255.255.255.255/32
#define IPV4_NETMASK_STR_MAX_LEN 18

///\brief Ex: 0.0.0.0/1
#define NETMASK_MIN_LEN 1

///\brief Ex: 0.0.0.0/32
#define NETMASK_MAX_LEN 32

#define IPV4_N_OCTECTS 4

/**
 * @brief Recovers broadcast address given an ip and netmask
 * @param[in] ip
 * @param[in] netmask
 * @return Broadcast address
 */
ipv4addr_t __inet_ipv4_getBroadcastAddr(ipv4addr_t ip, ipv4addr_t netmask);

/**
 * @brief Recovers broadcast address given an ip and netmask in format XXX.XXX.XXX.XXX/XX
 * @param[in] ip
 * @return Broadcast address
 */
ipv4addr_t __inet_ipv4_getBroadcastAddr(const char* ip);

/**
 * @brief Recovers network address given an ip and netmask
 * @param[in] ip
 * @param[in] netmask
 * @return Network address
 */
ipv4addr_t __inet_ipv4_getNetworkAddr(ipv4addr_t ip, ipv4addr_t netmask);

/**
 * @brief Recovers network address given an ip and netmask in format XXX.XXX.XXX.XXX/XX
 * @param[in] ip and netmask in format XXX.XXX.XXX.XXX/XX
 * @return Network address
 */
ipv4addr_t __inet_ipv4_getNetworkAddr(const char* ip);

/**
 * @brief Recovers subnet address given an ip and netmask in format XXX.XXX.XXX.XXX/XX
 * @param[in] ip and netmask in format XXX.XXX.XXX.XXX/XX
 * @return Subnet address
 */
inline u32t __inet_ipv4_getSubnet(const char* ip);

/**
 * @brief Converts netmask in notation 1-32 to uint32_t
 * @param[in] netmask
 * @return Converted value
 */
inline u32t __inet_ipv4_itosubnet(u8t netmask);

/**
 * @brief Recovers wildcard address given an ip and netmask
 * @param[in] ip and netmask in format XXX.XXX.XXX.XXX/XX
 * @return
 */
inline u32t __inet_ipv4_getWildcard(const char *ip);

/**
 * @brief Converts netmask in notation 1-32 to wildcard
 * @param[in] netmask
 * @return Wildcard
 */
inline u32t __inet_ipv4_itowildcard(u8t netmask);

/**
 * @brief Get number of client in a network
 * @param[in] up and netmask string in format XXX.XXX.XXX.XXX/XX
 * @return Number of clients
 */
size_t __inet_ipv4_getNumberClients(const char* ip);

/**
 * @brief Converts ip and netmask in format XXX.XXX.XXX.XXX/XX. Fills dst array
 * @param[out] dst The array where is stored the conversion [octect0, octect1, octect2, octect3, netmask]
 * @param[in] ip The IP string in format XXX.XXX.XXX.XXX/XX
 */
void __inet_ipv4_netmask_split(u8t *dst, const char* ip);

/**
 * @brief Recovers netmask from ip and netmask string in format XXX.XXX.XXX.XXX/XX
 * @param[in] ip
 * @return Netmask in range 1 - 32
 */
u8t __inet_ipv4_netmask_split(const char* ip);

/**
 * @brief Checks if given ip and netmask string is valid in format XXX.XXX.XXX.XXX/XX
 * @param[in] ip and netmask string is valid in format XXX.XXX.XXX.XXX/XX
 * @return True if valid, false if not
 */
bool __inet_ipv4_isValidIP(const char* ip);

/**
 * @brief Converts ASCII to Network an ip address
 * @param[in] ip without netmask in format XXX.XXX.XXX.XXX
 * @return
 */
//ipv4addr_t __inet_ipv4_aton(const std::string &ip);

/**
 * @brief Converts ASCII to Network an ip address
 * @param[in] ip without netmask in format XXX.XXX.XXX.XXX
 * @return
 */
ipv4addr_t __inet_ipv4_aton(const char *ip);

/**
 * @brief Converts Netwok to ASCII an ip address
 * @param[out] dst The resulting string
 * @param[in] ip without netmask in format XXX.XXX.XXX.XXX
 */
void __inet_ipv4_ntoa(char *dst, ipv4addr_t ip);

/**
 * @brief Converts Netwok to ASCII an ip address
 * @param[in] ip without netmask in format XXX.XXX.XXX.XXX
 * @return Ther resulting string
 */
//std::string  __inet_ipv4_ntoa(ipv4addr_t ip);
//---- End IPV4 ----//


//---- Ethernet ----//

//macaddr_t __inet_eth_aton(const std::string &mac);
//macaddr_t __inet_eth_aton(const char *mac);
//void __inet_eth_ntoa(char *dst, macaddr_t mac);
//std::string  __inet_eth_ntoa(macaddr_t mac);


//---- End Ethernet ----//


#endif // NET_UTILS_H
