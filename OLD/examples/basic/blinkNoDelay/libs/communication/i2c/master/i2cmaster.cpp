#include "i2cmaster.h"


I2CMaster::I2CMaster(){

}

void I2CMaster::enable(F_SCL f_scl)
{
    TWBR = f_scl;
}


void I2CMaster::disable()
{
    TWBR = 0;
}

uint8_t I2CMaster::start(uint8_t address)
{
    // reset TWI control register
    TWCR = 0;
    // transmit START condition
    TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
    // wait for end of transmission
    while( !(TWCR & (1<<TWINT)) );

    // check if the start condition was successfully transmitted
    if((TWSR & 0xF8) != TW_START){
        return 1;
    }

    // load slave address into data register
    TWDR = address;
    // start transmission of address
    TWCR = (1<<TWINT) | (1<<TWEN);
    // wait for end of transmission
    while( !(TWCR & (1<<TWINT)) );

    // check if the device has acknowledged the READ / WRITE mode
    uint8_t twst = TW_STATUS & 0xF8;
    if ( (twst != TW_MT_SLA_ACK) && (twst != TW_MR_SLA_ACK) ){
        return 1;
    }

    return 0;
}

void I2CMaster::stop(void)
{
    // transmit STOP condition
    TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
}

uint8_t I2CMaster::send(uint8_t data)
{
    // load data into data register
    TWDR = data;
    // start transmission of data
    TWCR = (1<<TWINT) | (1<<TWEN);
    // wait for end of transmission
    while( !(TWCR & (1<<TWINT)) );

    if( (TWSR & 0xF8) != TW_MT_DATA_ACK ){
        return 1;
    }
    return 0;
}

uint8_t I2CMaster::send(uint8_t *buff, uint16_t length)
{

    uint8_t success = 1;
    for (size_t i = 0; i < length; ++i) {
        success &= send(buff[i]);
    }

    return success;
}

uint8_t I2CMaster::send(uint8_t address, uint8_t* data, uint16_t length)
{
    if (start(address | I2C_WRITE))
    {
        return 1;
    }

    for (uint16_t i = 0; i < length; i++)
    {
        if (send(data[i])){
            return 1;
        }
    }

    stop();

    return 0;
}


uint8_t I2CMaster::receive(uint8_t address)
{
    if (start(address | I2C_READ)){
        return 0;
    }
    uint8_t data = read_sendNack();

    stop();

    return data;
}

uint8_t I2CMaster::receive(uint8_t address, uint8_t* data, uint16_t length)
{
    if (start(address | I2C_READ)){
        return 1;
    }

    for (uint16_t i = 0; i < (length-1); i++)
    {
        data[i] = read_sendAck();
    }
    data[(length-1)] = read_sendNack();

    stop();

    return 0;
}

uint8_t I2CMaster::writeReg(uint8_t devaddr, uint8_t regaddr, uint8_t *data, size_t length)
{
    if (start(devaddr | 0x00)) return 1;

    send(regaddr);

    for (uint16_t i = 0; i < length; i++)
    {
        if (send(data[i])){
            return 1;
        }
    }

    stop();

    return 0;
}

uint8_t I2CMaster::readReg(uint8_t devAddr, uint8_t regAddr, uint8_t* data, size_t length)
{
    if (start(devAddr)){
        return 1;
    }

    send(regAddr);

    if (start(devAddr | I2C_READ)){
        return 1;
    }

    for (uint16_t i = 0; i < (length-1); i++)
    {
        data[i] = read_sendAck();
    }
    data[(length-1)] = read_sendNack();

    stop();

    return 0;
}

slave_t I2CMaster::scan()
{
    slave_t slave;
    uint8_t buff[] = {0,0};
    for (size_t i = 0, x = 0; i <= 0xFF; ++i) {
        if(start(i) == 0){
            buff[x] = i;
            if(x++ == 1){break;}
        }
    }
    slave.writeAddr = buff[0];
    slave.readAddr = buff[1];
    return slave;
}

yanujz::vector<slave_t> I2CMaster::scanMultiple()
{
    slave_t slave;
    yanujz::vector<slave_t> vect;
    uint8_t buff[2] = {0,0};
    for (uint16_t i = 0, x = 0; i <= 0xFF; ++i) {
        if(start(i) == 0){
            buff[x] = i;
            if(x++ == 1){
                slave.writeAddr = buff[0];
                slave.readAddr  = buff[1];
                vect.pushRight(slave);
                x = 0;
            }
        }
    }
    return vect;
}





//-------- PRIVATE METHODS --------//
uint8_t I2CMaster::read_sendAck(void)
{

    // start TWI module and acknowledge data after reception
    TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
    // wait for end of transmission
    while( !(TWCR & (1<<TWINT)) );
    // return received data from TWDR
    return TWDR;
}

uint8_t I2CMaster::read_sendNack(void)
{

    // start receiving without acknowledging reception
    TWCR = (1<<TWINT) | (1<<TWEN);
    // wait for end of transmission
    while( !(TWCR & (1<<TWINT)) );
    // return received data from TWDR
    return TWDR;
}


















