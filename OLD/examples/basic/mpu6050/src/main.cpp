#include "avr_sdk.h"

int main(){

	Serial *serial1 = SerialManager::getInstance(SERIAL1);
	serial1->init(BAUD_1000000,_LOW_PRIORITY);
	serial1->setRxISRCallBack(false);
	serial1->setEchoServer(false);

	serial1->clear();
	Pin pin(13,OUTPUT);
	pin.setPWM(1000,50);

	Mpu6050 mpu6050;
	mpu6050.setAccelRange();
	mpu6050.setGyroRange();
	mpu6050.wakeUp();

	serial1->printf("Setup complete\r\n");
	while (1) {
		serial1->clear();

		serial1->printf("Accel x %f\r\n",mpu6050.getAccX());
		serial1->printf("Accel y %f\r\n",mpu6050.getAccY());
		serial1->printf("Accel z %f\r\n",mpu6050.getAccZ());

		serial1->printf("Gyro x %f\r\n",mpu6050.getGyroX());
		serial1->printf("Gyro y %f\r\n",mpu6050.getGyroY());
		serial1->printf("Gyro z %f\r\n",mpu6050.getGyroZ());
		serial1->printf("Temp : %f\r\n", mpu6050.getTemp(FAHRENHEIT_DEGREES));


		_delay_ms(100);
	}

	return 0;
}
