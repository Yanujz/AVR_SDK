#pragma once
#include <core.h>
#if defined (__MEGA_SERIES__)
#include <util/twi.h>

#define I2C_READ 0x01
#define I2C_WRITE 0x00

using namespace core::mega::i2c;
using namespace core::mega::common_typef;

void i2c_master_init(I2C iface,F_SCL freq = F_SCL::SCL_500KHZ);
void i2c_master_end(I2C iface);

bool i2c_master_start(I2C iface, u8 address);
void i2c_master_stop(I2C iface);

bool i2c_master_send(I2C iface, u8 data);
bool i2c_master_send(I2C iface, u8 *buff, int size);
bool i2c_master_send(I2C iface, u8 address, u8 *buff, int size);

u8 i2c_master_receive(I2C iface, u8 address);
bool i2c_master_receive(I2C iface, u8 address, u8* buff, int size);

bool i2c_master_writeReg(I2C iface, u8 devaddr, u8 regaddr, u8 *buff, int size);
bool i2c_master_readReg(I2C iface, u8 devAddr, u8 regAddr, u8* buff, int size);

u8 i2c_master_read_sendAck(I2C iface);
u8 i2c_master_read_sendNack(I2C iface);
#endif
