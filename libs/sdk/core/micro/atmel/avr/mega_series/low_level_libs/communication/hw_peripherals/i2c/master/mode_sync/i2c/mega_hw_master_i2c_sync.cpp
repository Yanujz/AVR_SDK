#include <core.h>
#if defined (__MEGA_SERIES__)
#include <mega_hw_master_i2c_sync.h>

MasterI2C::MasterI2C()
{

}

void MasterI2C::end()
{
  i2c_master_end(iface);
}

bool MasterI2C::start(u8t address)
{
  return i2c_master_start(iface, address);
}

void MasterI2C::stop()
{
  i2c_master_stop (iface);
}

bool MasterI2C::send(u8t data)
{
  return i2c_master_send(iface, data);
}

bool MasterI2C::send(u8t *buff, int size)
{
  return i2c_master_send(iface, buff, size);
}

bool MasterI2C::send(u8t address, u8t *buff, int size)
{
  return i2c_master_send(iface, address, buff, size);
}

u8t MasterI2C::receive(u8t address)
{
  return i2c_master_receive(iface, address);
}

bool MasterI2C::receive(u8t address, u8t *buff, int size)
{
  return i2c_master_receive(iface, address, buff, size);
}

bool MasterI2C::writeReg(u8t devaddr, u8t regaddr, u8t *buff, int size)
{
  return  i2c_master_writeReg(iface, devaddr, regaddr, buff, size);
}

bool MasterI2C::readReg(u8t devAddr, u8t regAddr, u8t *buff, int size)
{
  return  i2c_master_readReg (iface, devAddr, regAddr, buff, size);
}

u8t MasterI2C::read_sendAck()
{
  return  i2c_master_read_sendAck (iface);
}

u8t MasterI2C::read_sendNack()
{
  return  i2c_master_read_sendNack (iface);
}

void MasterI2C::init(F_SCL freq)
{
  i2c_master_init (iface, freq);
}


#endif
