#include "avr_sdk.h"

int main(){
	Timer::start();
	Pin builtin_led(13,OUTPUT);
	Serial *serial1 = SerialManager::getInstance(SERIAL1);
	serial1->init(BAUD_1000000,_LOW_PRIORITY);
	serial1->setRxISRCallBack(false);
	serial1->setEchoServer(false);

	double now;
	double previous = Timer::now();
	uint16_t ms_now;
	uint16_t ms_prev = now /1000.0;
	u8 pippo;
	while (1) {
		now = Timer::now();
		if(ABS(ms_now - ms_prev) > 100){
			builtin_led.toggle();
			ms_prev = ms_now;
		}
	}

	return 0;
}
