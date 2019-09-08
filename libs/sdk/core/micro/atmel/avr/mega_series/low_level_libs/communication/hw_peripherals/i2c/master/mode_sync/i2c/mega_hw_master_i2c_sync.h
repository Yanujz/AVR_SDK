#pragma once
#include <core.h>
#if defined (__MEGA_SERIES__)
#include <mega_hw_master_i2c_sync_low_size.h>
class MasterI2C
{
public:
  MasterI2C();
  virtual void begin(F_SCL freq) = 0;
  void end();

  bool start(u8t address);
  void stop();

  bool send(u8t data);
  bool send(u8t *buff, int size);
  bool send(u8t address, u8t *buff, int size);

  u8t receive(u8t address);
  bool receive(u8t address, u8t* buff, int size);

  bool writeReg(u8t devaddr, u8t regaddr, u8t *buff, int size);
  bool readReg(u8t devAddr, u8t regAddr, u8t* buff, int size);

  u8t read_sendAck();
  u8t read_sendNack();
protected:
  void init(F_SCL freq = F_SCL::SCL_500KHZ);
  I2C iface;
};

#endif
