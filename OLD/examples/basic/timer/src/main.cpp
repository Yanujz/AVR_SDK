#include "avr_sdk.h"
#include <time.h>
//#include "isr.s"
extern u16t ovfl_count;
extern u16t micros();
//extern static inline u32t micros();
int main(){
	//Pin builtin_led(13,OUTPUT);
	time_t t;


	/* Intializes random number generator */
	srand((unsigned) time(&t));
	DDRB = 0x80;

	TCCR0A  = 0;
	TCCR0B  = 0;
	TCNT0   = 0;
	OCR0A   = 255;
	TCCR0A |= (0 << COM0A1) | (0 << COM0A0)|( 1 << WGM01);
	TIMSK0  = (0 << TOIE0) | (1 << OCIE0A);

	Serial *serial1 = SerialManager::getInstance(SERIAL1);
	serial1->init(BAUD_1000000,_LOW_PRIORITY);
	serial1->setRxISRCallBack(false);
	serial1->setEchoServer(false);
	serial1->clear();
	//serial1->printf("Setup ok %u\r\n",rand() % 10);
	u16t _now = 0;
	u16t _prev = 0;
	u16t _deltaT = 0;
	sei();

	_delay_ms(500);
	TCCR0B |= (0 << FOC0A) | (0 << CS02) | (0 << CS01) | (1 << CS00);



	_prev = micros();
	_now = micros();
	_deltaT = ABS(_now-_prev);

	_delay_ms(250);

	serial1->printf("_Now :%u\r\n", _now);
	serial1->printf("_Prev :%u\r\n", _prev);
	serial1->printf("_Delta T :%u\r\n\r\n",_deltaT);
	while (1) {
		_delay_ms(500);
		//UDR1 = _deltaT;
		//serial1->printf("_Now :%lu\r\n", micros());
	}

	return 0;
}
