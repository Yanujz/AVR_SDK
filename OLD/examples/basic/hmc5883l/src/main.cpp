#include "avr_sdk.h"

int main(){

	Serial *serial1 = SerialManager::getInstance(SERIAL1);
	serial1->init(BAUD_1000000,_LOW_PRIORITY);
	serial1->setRxISRCallBack(false);
	serial1->setEchoServer(false);

	I2CMaster master;
	master.enable(SCL_100KHZ);

	serial1->printf("Setup complete\r\n");

	Hmc5883 hmc5883;
	hmc5883.init();
	compass_t compass;

	while (1) {
		serial1->clear();
		compass = hmc5883.getData();

		serial1->printf("X : %d\r\n",compass.raw_x);
		serial1->printf("Y : %d\r\n",compass.raw_y);
		serial1->printf("Z : %d\r\n",compass.raw_z);
		serial1->printf("Deg : %f\r\n",compass.headingDegrees);

		_delay_ms(10);
	}

	return 0;
}
