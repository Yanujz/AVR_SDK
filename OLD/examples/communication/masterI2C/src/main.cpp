#include "avr_sdk.h"

int main(){

	Serial *serial1 = SerialManager::getInstance(SERIAL1);
	serial1->init(BAUD_1000000,_LOW_PRIORITY);
	serial1->setRxISRCallBack(false);
	serial1->setEchoServer(false);

	I2CMaster master;
	master.enable(SCL_100KHZ);

	serial1->printf("Setup complete\r\n");

	serial1->clear();

	slave_t slave = master.scan();
	serial1->printf("Slave write address : 0x%x\r\n"
																	"Slave read address : 0x%x\r\n",
																	slave.writeAddr,slave.readAddr);
	while (1) {

		_delay_ms(10);
	}

	return 0;
}
