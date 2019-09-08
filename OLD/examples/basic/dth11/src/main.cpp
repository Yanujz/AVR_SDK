#include "avr_sdk.h"
//static Pin pin(22,INPUT);

//const size_t size = 1024;
//static volatile uint8_t *state;
//static volatile uint32_t time[1024];

/*
void pulseIn(){
	uint32_t  previous;
	uint16_t i = 0;
	while (pin.digitalRead() == false);

	if(pin.digitalRead()){
		previous = Timer::now();
		while (pin.digitalRead()){
			var[i] = Timer::now() - previous;
			++i;
		};
	}

}


float getAVG(){
	uint32_t avg;
	for(size_t i = 0; i<SIZE_OF_ARRAY(var);++i){
		avg += var[i];
	}
	float asd = (float)avg/(float)SIZE_OF_ARRAY(var);
	asd += 0.0625*float(TCNT0);

	return asd;
}
*/
/*
uint8_t samples[8*1024];
int i; // n sample = 8kb * 8
int byte_i = i/8; // quale byte degli 8kb
int bit_i = i%8; // [ 0 - 7 ] quale bit, del byte byte_i-esimo

int byte_i = i>>3;
int bit_i  = i&7;

for(i=0; i<8*1024*8; i++)
{
	int byte_i = i>>3;
	int bit_i  = i&7;

	int v = digitalRead();
	samples[byte_i] |= (v<<bit_i);

int bit_i = i
void sample(){
	//Serial *serial1 = SerialManager::getInstance(SERIAL1);
	//serial1->printf("Sampling...\r\n");
	PORTB ^= 0X80;
	for(int i = 0; i < 4096; ++i){
		state[i] = pin.digitalRead();
		//time[i]		= Timer::now();
	}
	PORTB ^= 0X80;
	//serial1->printf("Done\r\n");
}

}*/
asm volatile("LDI r19,0x1\n\t"
													"LDI r18,0x0\n\t"
"LDS r17,0x22\n\t");

int main(){

	Pin asd(13,OUTPUT);
	DDRA = 0x1;
	asm volatile("LoopBegin:\n\t"
														//"EOR r17,r19\n\t"
														"sts 0x22,0\n\t"
														"sts 0x22,1\n\t"
														"sts 0x22,0\n\t"
														"sts 0x22,1\n\t"
														"sts 0x22,0\n\t"
														"sts 0x22,1\n\t"
														"sts 0x22,0\n\t"
														"sts 0x22,1\n\t"
														"sts 0x22,0\n\t"
														"sts 0x22,1\n\t"
														"sts 0x22,0\n\t"
														"sts 0x22,1\n\t"
														"sts 0x22,0\n\t"
														"sts 0x22,1\n\t"
														"sts 0x22,0\n\t"
														"sts 0x22,1\n\t"
														"sts 0x22,0\n\t"
														"sts 0x22,1\n\t"
														"sts 0x22,0\n\t"
														"sts 0x22,1\n\t"
														"sts 0x22,0\n\t"
														"sts 0x22,1\n\t"
														"sts 0x22,0\n\t"
														"sts 0x22,1\n\t"
														"sts 0x22,0\n\t"
														"sts 0x22,1\n\t"
														"sts 0x22,0\n\t"
														"sts 0x22,1\n\t"
														"sts 0x22,0\n\t"
														"sts 0x22,1\n\t"
														"sts 0x22,0\n\t"
														"sts 0x22,1\n\t"
														"sts 0x22,0\n\t"
														"sts 0x22,1\n\t"
													"rjmp LoopBegin\n\t");
	//Timer::start();
	//Serial *serial1 = SerialManager::getInstance(SERIAL0);
	//serial1->init(BAUD_1000000);



	//Dht11 dht11(22);

	//Pin pin(38,INPUT);
	//serial1->clear();
	//serial1->printf("Setup complete\r\n");
	//uint32_t prev, now;
	//uint16_t i = 0;
	//sample();
	while (1) {
		//	PORTA ^= 0x1;
		//prev = Timer::now();
		//_delay_ms(100);
		//now = Timer::now();
		//serial1->printf("Delta T %lu\r\n",now-prev);
		//_delay_ms(5000);
		//dht11.getData();
		//serial1->printf("%u\r\n",dht11.getTemperature());
		//serial1->printf("%u\r\n",dht11.getHumidity());
		//if (dht11.checkCrc() == false){
		//				serial1->printf("Checksum errato %d\r\n");
		//}
		//else {
		//				serial1->printf("CRC OK\r\n");
		//}


	}

	return 0;
}


/*
00100111 00000000 00010110 00000000 00111101
		39																22																	61



*/




























