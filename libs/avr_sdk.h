#ifndef AVR_SDK_H
#define AVR_SDK_H
///@file



#include <portmanager.h>
#include <interrupt.h>
#include <vector.h>
//#include <cppfix.h>
#include <macros.h>
#include <timer.h>
#include <spi.h>
#include <serial.h>
#include <dht11.h>
#include <adccomparator.h>
#include <utils/utils.h>
#include <spislave.h>
#include <spimaster.h>
#include <i2cmaster.h>
#include <i2cslave.h>


#include <rdm630.h>
#include <strutil.h>
#include <mpu6050.h>
#include <hmc5883.h>

#include <networkmanager.h>
//---- TCP/IP ----//

//---- APP_LAYER ----//

//---- TRANSPORT_LAYER	----//
#include <tcp.h>

//---- INTERNET_LAYER	----//
#include <ipv4.h>
#include <net_utils.h>
#include <arp.h>
#include <arptable.h>
//---- PHYSICAL_LAYER	----//
#include <ethernet.h>
#include <enc28j60.h>

//----- STL -----//
#include <vector>
#include <string>


#endif // AVR_SDK_H
