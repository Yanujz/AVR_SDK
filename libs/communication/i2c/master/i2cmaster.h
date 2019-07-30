#ifndef I2CMASTER_H
#define I2CMASTER_H
#include <util/twi.h>
//#include <avr/iom2560.h>
#include <avr/io.h>
#include <vector.hpp>
#include <stdint.h>
///@file


//#define F_SCL 100000UL // SCL frequency
#define Prescaler 1
#define TWBR_val(x) ((((F_CPU / x) / Prescaler) - 16 ) / 2)

#define I2C_READ 0x01
#define I2C_WRITE 0x00


enum F_SCL:uint8_t{
	SCL_100KHZ = TWBR_val(100000),
	SCL_200KHZ = TWBR_val(200000),
	SCL_300KHZ = TWBR_val(300000),
	SCL_400KHZ = TWBR_val(400000),
	SCL_500KHZ = TWBR_val(500000)
};


struct slave_t
{
	slave_t(uint8_t wAddr = 0, uint8_t rAddr = 0){
		writeAddr = wAddr;
		readAddr = rAddr;
	}

	uint8_t writeAddr;
	uint8_t readAddr;
};

class I2CMaster
{
public:
	I2CMaster();

	void enable(F_SCL f_scl = SCL_100KHZ);
	void disable();

	uint8_t start(uint8_t address);
	void stop(void);

	uint8_t send(uint8_t data);
	uint8_t send(uint8_t *buff, uint16_t length);
	uint8_t send(uint8_t address, uint8_t *buff, uint16_t length);

	uint8_t receive(uint8_t address);
	uint8_t receive(uint8_t address, uint8_t* data, uint16_t length);

	uint8_t writeReg(uint8_t devaddr, uint8_t regaddr, uint8_t *data, size_t length);
	uint8_t readReg(uint8_t devAddr, uint8_t regAddr, uint8_t* data, size_t length);

	slave_t scan();
	yanujz::vector<slave_t> scanMultiple();

	uint8_t read_sendAck(void);
	uint8_t read_sendNack(void);
private:



};

#endif
