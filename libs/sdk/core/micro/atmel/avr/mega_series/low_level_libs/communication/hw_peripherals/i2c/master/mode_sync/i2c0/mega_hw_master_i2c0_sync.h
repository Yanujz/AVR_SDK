#pragma once
#include <core.h>
#if defined (__MEGA_SERIES_I2C0_SUPPORT__)
#include <mega_hw_master_i2c_sync.h>
class MasterI2C0 : public MasterI2C {
public:
  MasterI2C0();
  void begin(F_SCL freq = F_SCL::SCL_500KHZ) override;
};
extern MasterI2C0 masterI2C0;
#endif
