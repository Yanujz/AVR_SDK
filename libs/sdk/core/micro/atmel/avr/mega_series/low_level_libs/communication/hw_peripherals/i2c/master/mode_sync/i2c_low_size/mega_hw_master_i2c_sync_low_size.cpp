#include <mega_hw_master_i2c_sync_low_size.h>
#if defined (__MEGA_SERIES__)

void i2c_master_init(I2C iface, F_SCL freq)
{
  ((TWI_TypeDef*)iface)->TWBR = toU8(freq);
}

void i2c_master_end(I2C iface)
{
  ((TWI_TypeDef*)iface)->TWBR = 0;
}

bool i2c_master_start(I2C iface, u8 address)
{
  // reset TWI control register
  ((TWI_TypeDef*)iface)->TWCR= 0;

  // transmit START condition
  ((TWI_TypeDef*)iface)->TWCR = START_CONDITION;

  // wait for end of transmission
  while( !(((TWI_TypeDef*)iface)->TWCR & bitValue(TWINTx)) );

  // check if the start condition was successfully transmitted
  if((((TWI_TypeDef*)iface)->TWSR & I2C_STAT_MASK) != TW_START){
	return false;
  }

  // load slave address into data register
  ((TWI_TypeDef*)iface)->TWDR = address;

  // start transmission of address
  ((TWI_TypeDef*)iface)->TWCR = START_TRASMISSION;
  // wait for end of transmission
  while( !(((TWI_TypeDef*)iface)->TWCR & bitValue(TWINTx)) );

  // check if the device has acknowledged the READ / WRITE mode
  u8 stat = ((TWI_TypeDef*)iface)->TWSR & I2C_STAT_MASK;
  if ( (stat != TW_MT_SLA_ACK) && (stat != TW_MR_SLA_ACK) ){
	return false;
  }

  return true;
}

void i2c_master_stop(I2C iface)
{
  ((TWI_TypeDef*)iface)->TWCR = STOP_CONDITION;
}

bool i2c_master_send(I2C iface, u8 data)
{
  // load data into data register
  ((TWI_TypeDef*)iface)->TWDR = data;

  // start transmission of data
  ((TWI_TypeDef*)iface)->TWCR = START_TRASMISSION;

  // wait for end of transmission
  while( !(((TWI_TypeDef*)iface)->TWCR & bitValue(TWINTx)) );

  if( (((TWI_TypeDef*)iface)->TWSR & I2C_STAT_MASK) != TW_MT_DATA_ACK ){
	return false;
  }
  return true;
}

bool i2c_master_send(I2C iface, u8 *buff, int size)
{
  bool res = false;
  while (size--) {
	res = i2c_master_send(iface, *buff++);
  }
  return res;
}

bool i2c_master_send(I2C iface, u8 address, u8 *buff, int size)
{
  if (false == i2c_master_start(iface, address | I2C_WRITE))
  {
	return false;
  }
  while (size--) {
	if(false == i2c_master_send(iface, *buff++)){
	  return  false;
	}
  }
  i2c_master_stop(iface);

  return 0;
}

u8 i2c_master_receive(I2C iface, u8 address)
{
  if (false == i2c_master_start(iface, address | I2C_READ)){
	return 0;
  }
  u8 data = i2c_master_read_sendNack(iface);

  i2c_master_stop(iface);

  return data;
}

bool i2c_master_receive(I2C iface, u8 address, u8 *buff, int size)
{
  if (false == i2c_master_start(iface, address | I2C_READ)){
	return false;
  }

  for (int i = 0; i < (size-1); i++)
  {
	buff[i] = i2c_master_read_sendAck(iface);
  }
  buff[(size-1)] = i2c_master_read_sendNack(iface);

  i2c_master_stop(iface);

  return true;
}

bool i2c_master_writeReg(I2C iface, u8 devaddr, u8 regaddr, u8 *buff, int size)
{
  if (false == i2c_master_start(iface, devaddr | I2C_WRITE)){
	return false;
  }

  i2c_master_send(iface, regaddr);
  while (size--) {
	if(false == i2c_master_send(iface, *buff++)){
	  return  false;
	}
  }

  i2c_master_stop(iface);

  return true;
}

bool i2c_master_readReg(I2C iface, u8 devAddr, u8 regAddr, u8 *buff, int size)
{
  if (false == i2c_master_start(iface, devAddr)){
	return false;
  }

  i2c_master_send(iface, regAddr);

  if (false == i2c_master_start(iface, devAddr | I2C_READ)){
	return false;
  }

  for (int i = 0; i < (size-1); i++)
  {
	buff[i] = i2c_master_read_sendAck(iface);
  }
  buff[(size-1)] = i2c_master_read_sendNack(iface);

  i2c_master_stop(iface);

  return true;
}

u8 i2c_master_read_sendAck(I2C iface)
{
  // start TWI module and acknowledge data after reception
  ((TWI_TypeDef*)iface)->TWCR = START_AND_ACK;

  // wait for end of transmission
  while( !(((TWI_TypeDef*)iface)->TWCR & bitValue(TWINTx)) );

  // return received data from TWDR
  return ((TWI_TypeDef*)iface)->TWDR;
}

u8 i2c_master_read_sendNack(I2C iface)
{
  // start receiving without acknowledging reception
  ((TWI_TypeDef*)iface)->TWCR = START_TRASMISSION;

  // wait for end of transmission
  while( !(((TWI_TypeDef*)iface)->TWCR & bitValue(TWINTx)) );

  // return received data from TWDR
  return ((TWI_TypeDef*)iface)->TWDR;
}
#endif
