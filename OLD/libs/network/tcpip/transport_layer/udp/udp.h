#ifndef UDP_H
#define UDP_H
#include <stdint.h>
#include <macros.h>
#include <utils.h>

/* UDP Header
+---+----------------------------+
| 0 |       | 16 |          | 31 |
+---+-------+-+------------------+
| Source Port | Destination Port |
+-------------+------------------+
|   Length    |	    Checksum     |
+-------------+------------------+
*/

struct udp_header_t
{
    u16t srcPort;
    u16t dstPort;
    u16t length;
    u16t crc;
};

class Udp
{
public:
    Udp();
};

#endif // UDP_H
