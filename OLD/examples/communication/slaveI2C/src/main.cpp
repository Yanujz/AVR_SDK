#include "avr_sdk.h"



int main(){

	Pin builtin_led(13,OUTPUT);
	builtin_led.setPWM(1000,0);
	uint8_t  i = 0;

	while (1) {
		for(i = 0; i < 100;++i){
			builtin_led.setDuty(i);
			_delay_ms(10);
		}
		for(i = 100; i > 1;--i){
			builtin_led.setDuty(i);
			_delay_ms(10);
		}
	}

	return 0;
}
