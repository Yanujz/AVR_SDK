#include <mega_hw_master_i2c_sync_low_size.h>
#if defined (__MEGA_SERIES__)

void i2c_master_init(I2C iface, F_SCL freq)
{
    *(volatile u8t*)(iface) = toU8(freq);
}

void i2c_master_end(I2C iface)
{
    *toIntPtr(iface) = 0;
}

bool i2c_master_start(I2C iface, u8t address)
{
    // reset TWI control register
    *I2Cx_CTRL_REG_OFFSET((volatile u8t*)(iface)) = 0;
    // transmit START condition
	*I2Cx_CTRL_REG_OFFSET((volatile u8t*)(iface)) = setBitValue(1, TWINTx) | setBitValue(1, TWSTAx) | setBitValue(1, TWENx);
    // wait for end of transmission
    while( !(*I2Cx_CTRL_REG_OFFSET((volatile u8t*)(iface)) & bitValue(TWINTx)) );

    // check if the start condition was successfully transmitted
    if((*I2Cx_STAT_REG_OFFSET((volatile u8t*)(iface)) & I2C_STAT_MASK) != TW_START){
	return false;
    }

    // load slave address into data register
    *I2Cx_DATA_REG_OFFSET((volatile u8t*)(iface)) = address;
    // start transmission of address
    *I2Cx_CTRL_REG_OFFSET((volatile u8t*)(iface)) = setBitValue(1, TWINTx) | setBitValue(1, TWENx);
    // wait for end of transmission
    while( !(*I2Cx_CTRL_REG_OFFSET((volatile u8t*)(iface)) & bitValue(TWINTx)) );

    // check if the device has acknowledged the READ / WRITE mode
    u8t stat = *I2Cx_STAT_REG_OFFSET((volatile u8t*)(iface)) & I2C_STAT_MASK;
    if ( (stat != TW_MT_SLA_ACK) && (stat != TW_MR_SLA_ACK) ){
	return false;
    }

    return true;
}

void i2c_master_stop(I2C iface)
{
    *I2Cx_CTRL_REG_OFFSET((volatile u8t*)(iface)) = setBitValue(1, TWINTx) | setBitValue(1, TWENx) | setBitValue(1, TWSTOx);
}

bool i2c_master_send(I2C iface, u8t data)
{
    // load data into data register
    *I2Cx_DATA_REG_OFFSET((volatile u8t*)(iface)) = data;
    // start transmission of data
    *I2Cx_CTRL_REG_OFFSET((volatile u8t*)(iface)) = setBitValue(1, TWINTx) | setBitValue(1, TWENx);
    // wait for end of transmission
    while( !(*I2Cx_CTRL_REG_OFFSET((volatile u8t*)(iface)) & bitValue(TWINTx)) );

    if( (*I2Cx_STAT_REG_OFFSET((volatile u8t*)(iface)) & I2C_STAT_MASK) != TW_MT_DATA_ACK ){
	return false;
    }
    return true;
}

bool i2c_master_send(I2C iface, u8t *buff, int size)
{
    bool res = false;
    while (size--) {
	res = i2c_master_send(iface, *buff++);
    }
    return res;
}

bool i2c_master_send(I2C iface, u8t address, u8t *buff, int size)
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

u8t i2c_master_receive(I2C iface, u8t address)
{
    if (false == i2c_master_start(iface, address | I2C_READ)){
	return 0;
    }
    u8t data = i2c_master_read_sendNack(iface);

    i2c_master_stop(iface);

    return data;
}

bool i2c_master_receive(I2C iface, u8t address, u8t *buff, int size)
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

bool i2c_master_writeReg(I2C iface, u8t devaddr, u8t regaddr, u8t *buff, int size)
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

bool i2c_master_readReg(I2C iface, u8t devAddr, u8t regAddr, u8t *buff, int size)
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

u8t i2c_master_read_sendAck(I2C iface)
{
    // start TWI module and acknowledge data after reception
    *I2Cx_CTRL_REG_OFFSET((volatile u8t*)(iface)) = setBitValue(1, TWINTx) | setBitValue(1, TWENx) | setBitValue(1, TWEAx);
    // wait for end of transmission
    while( !(*I2Cx_CTRL_REG_OFFSET((volatile u8t*)(iface)) & bitValue(TWINTx)) );
    // return received data from TWDR
    return *I2Cx_DATA_REG_OFFSET((volatile u8t*)(iface));
}

u8t i2c_master_read_sendNack(I2C iface)
{

    // start receiving without acknowledging reception
    *I2Cx_CTRL_REG_OFFSET((volatile u8t*)(iface)) = setBitValue(1, TWINTx) | setBitValue(1, TWENx);
    // wait for end of transmission
    while( !(*I2Cx_CTRL_REG_OFFSET((volatile u8t*)(iface)) & bitValue(TWINTx)) );
    // return received data from TWDR
    return *I2Cx_DATA_REG_OFFSET((volatile u8t*)(iface));
}
#endif
