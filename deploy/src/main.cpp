#include <pins.h>
#include <hardwareserial.h>
int main(){

    pinMode(PIN::IO4,  OUTPUT);
    pinMode(PIN::IO11, OUTPUT);
    pinMode(PIN::IO12, OUTPUT);
    pinMode(PIN::IO13, OUTPUT);
    u8t duty = 0;
    while(1){
	setMultiPWM16(TIMER16::TIMER1, 1000, duty, duty, duty);
	if(duty++ > 100) duty = 0;
	_delay_ms(10);

    }

}
