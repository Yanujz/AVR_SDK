#include <core.h>
#if defined (__MEGA_SERIES_I2C0_SUPPORT__)
#include <mega_hw_master_i2c0_sync.h>
MasterI2C0 masterI2C0;

MasterI2C0::MasterI2C0()
{

}

void MasterI2C0::begin(F_SCL freq)
{
  iface = I2C0;
  MasterI2C::init(freq);
}
#endif
