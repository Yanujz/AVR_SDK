#include <pins.h>
#include <hardwareserial.h>




int main(){
    pinMode(PIN::IO2,  OUTPUT);
    pinMode(PIN::IO3,  OUTPUT);
    pinMode(PIN::IO4,  OUTPUT);
    pinMode(PIN::IO5,  OUTPUT);
    pinMode(PIN::IO6,  OUTPUT);
    pinMode(PIN::IO7,  OUTPUT);
    pinMode(PIN::IO8,  OUTPUT);
    pinMode(PIN::IO9,  OUTPUT);
    pinMode(PIN::IO10, OUTPUT);
    pinMode(PIN::IO11, OUTPUT);
    pinMode(PIN::IO12, OUTPUT);
    pinMode(PIN::IO13, OUTPUT);
    pinMode(PIN::IO44, OUTPUT);
    pinMode(PIN::IO45, OUTPUT);
    pinMode(PIN::IO46, OUTPUT);

    u8t duty = 50;


    setPWM(PWM_IO2,  1000, duty);
    setPWM(PWM_IO3,  1000, duty);
    setPWM(PWM_IO4,  1000, duty);
    setPWM(PWM_IO5,  1000, duty);
    setPWM(PWM_IO6,  1000, duty);
    setPWM(PWM_IO7,  1000, duty);
    setPWM(PWM_IO8,  1000, duty);
    setPWM(PWM_IO9,  1000, duty);
    setPWM(PWM_IO10, 1000, duty);
    setPWM(PWM_IO11, 1000, duty);
    setPWM(PWM_IO12, 1000, duty);
    setPWM(PWM_IO13, 1000, duty);
    setPWM(PWM_IO44, 1000, duty);
    setPWM(PWM_IO45, 1000, duty);
    setPWM(PWM_IO46, 1000, duty);
    while(1){

	//digitalToggle(PIN::IO13);
	//_delay_ms(500);
	//setPWM(PWM::IO13, 1000, duty);
	//setMultiPWM16(TIMER16::TIMER1, 1000, duty, duty, duty);
	//if(duty++ > 100) duty = 0;
	//_delay_ms(10);

    }

}
