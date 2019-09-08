#include <core.h>
#if defined (__MEGA_SERIES_I2C0_SUPPORT__)
#include <mega_hw_slave_i2c0_async.h>

ISR(TWI_vect)
{
  switch(TW_STATUS)
  {
	case TW_SR_DATA_ACK:
	  // received data from master, call the receive callback
	  I2C_recv(TWDR);
	  TWCR = (1<<TWIE) | (1<<TWINT) | (1<<TWEA) | (1<<TWEN);
	  break;
	case TW_ST_SLA_ACK:
	  // master is requesting data, call the request callback
	  I2C_req();
	  TWCR = (1<<TWIE) | (1<<TWINT) | (1<<TWEA) | (1<<TWEN);
	  break;
	case TW_ST_DATA_ACK:
	  // master is requesting data, call the request callback
	  I2C_req();
	  TWCR = (1<<TWIE) | (1<<TWINT) | (1<<TWEA) | (1<<TWEN);
	  break;
	case TW_BUS_ERROR:
	  // some sort of erroneous state, prepare TWI to be readdressed
	  TWCR = 0;
	  TWCR = (1<<TWIE) | (1<<TWINT) | (1<<TWEA) | (1<<TWEN);
	  break;
	default:
	  TWCR = (1<<TWIE) | (1<<TWINT) | (1<<TWEA) | (1<<TWEN);
	  break;
  }
}
#endif
