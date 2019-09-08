#include "avr_sdk.h"


enum keys {
	K_A0 = 27,	K_Bb0 = 29,	K_B0	= 31,
	K_C1	= 33,	K_Db1 = 35,	K_D1	= 37,	K_Eb1 = 39,	K_E1	= 41,K_F1	= 44,	K_Gb1 = 46,	K_G1	= 49,	K_Ab1 = 52,	K_A1	= 55,	K_Bb1 = 58,	K_B1	= 62,
	K_C2	= 65,	K_Db2 = 69,	K_D2	= 73,	K_Eb2 = 78,	K_E2	= 82,	K_F2	= 87,	K_Gb2 = 92,	K_G2	= 98,	K_Ab2 = 104,	K_A2	= 110,	K_Bb2 = 116,	K_B2	= 123,
	K_C3	= 131,	K_Db3 = 139,	K_D3	= 147,	K_Eb3 = 155,	K_E3	= 165,	K_F3	= 175,	K_Gb3 = 185,	K_G3	= 196,	K_Ab3 = 207,	K_A3	= 220,	K_Bb3 = 233,	K_B3	= 247,
	K_C4	= 262,	K_Db4 = 277,	K_D4	= 294,	K_Eb4 = 311,	K_E4	= 330,	K_F4	= 349,	K_Gb4 = 370,	K_G4	= 392,	K_Ab4 = 415,	K_A4	= 440,	K_Bb4 = 466,	K_B4	= 494,
	K_C5	= 523,	K_Db5 = 554,	K_D5	= 587,	K_Eb5 = 622,	K_E5	= 659,	K_F5	= 698,	K_Gb5 = 740,	K_G5	= 784,	K_Ab5 = 831,	K_A5	= 880,	K_Bb5 = 932,	K_B5	= 988,
	K_C6	= 1046,	K_Db6 = 1109,	K_D6	= 1175,	K_Eb6 = 1244,	K_E6	= 1318,	K_F6	= 1397,	K_Gb6 = 1480,	K_G6	= 1568,	K_Ab6 = 1661,	K_A6	= 1760,	K_Bb6 = 1864,	K_B6	= 1975,
	K_C7	= 2093,	K_Db7 = 2217,	K_D7	= 2349,	K_Eb7 = 2489,	K_E7	= 2637,	K_F7	= 2794,	K_Gb7 = 2960,	K_G7	= 3136,	K_Ab7 = 3322,	K_A7	= 3520,	K_Bb7 = 3729,	K_B7	= 3951,
	K_C8	= 4186,	K_Db8 = 4435,	K_D8	= 4699,	K_Eb8 = 4978,	K_E8	= 5274,	K_F8	= 5588,	K_Gb8 = 5920,	K_G8	= 6272,	K_Ab8 = 6645,	K_A8	= 7040,	K_Bb8 = 7459,	K_B8	= 7902
};
/*
enum notes
{

	// commands

	// set tempo

	//multipliers
	x2, x3, x4

	A1, x3, A3 = A1, A1, A1, A3

	// silence

	// 88 keys

	// special (drums)
}
*/
Pin pwm(13,OUTPUT);

uint8_t volume = 90;

void basslineC(){
	pwm.setDuty(volume);
	pwm.setFreq(K_C5);
	_delay_ms(100);
	pwm.setDuty(0);
	_delay_ms(200);

	pwm.setDuty(volume);
	pwm.setFreq(K_C5);
	_delay_ms(100);
	pwm.setDuty(0);
	_delay_ms(100);

	pwm.setDuty(volume);
	pwm.setFreq(K_C6);
	_delay_ms(100);
	pwm.setDuty(0);
	_delay_ms(200);

	pwm.setDuty(volume);
	pwm.setFreq(K_C6);
	_delay_ms(100);
	pwm.setDuty(0);
	_delay_ms(100);


	pwm.setDuty(volume);
	pwm.setFreq(K_Bb5);
	_delay_ms(100);
	pwm.setDuty(0);
	_delay_ms(200);

	pwm.setDuty(volume);
	pwm.setFreq(K_Bb5);
	_delay_ms(100);
	pwm.setDuty(0);
	_delay_ms(100);

	pwm.setDuty(volume);
	pwm.setFreq(K_G5);
	_delay_ms(100);
	pwm.setDuty(0);
	_delay_ms(200);

	pwm.setDuty(volume);
	pwm.setFreq(K_G5);
	_delay_ms(100);
	pwm.setDuty(0);
	_delay_ms(100);
}
void basslineF(){
	pwm.setDuty(volume);
	pwm.setFreq(K_F5);
	_delay_ms(100);
	pwm.setDuty(0);
	_delay_ms(200);

	pwm.setDuty(volume);
	pwm.setFreq(K_F5);
	_delay_ms(100);
	pwm.setDuty(0);
	_delay_ms(100);

	pwm.setDuty(volume);
	pwm.setFreq(K_F6);
	_delay_ms(100);
	pwm.setDuty(0);
	_delay_ms(200);

	pwm.setDuty(volume);
	pwm.setFreq(K_F6);
	_delay_ms(100);
	pwm.setDuty(0);
	_delay_ms(100);


	pwm.setDuty(volume);
	pwm.setFreq(K_Eb6);
	_delay_ms(100);
	pwm.setDuty(0);
	_delay_ms(200);

	pwm.setDuty(volume);
	pwm.setFreq(K_Eb6);
	_delay_ms(100);
	pwm.setDuty(0);
	_delay_ms(100);

	pwm.setDuty(volume);
	pwm.setFreq(K_C6);
	_delay_ms(100);
	pwm.setDuty(0);
	_delay_ms(200);

	pwm.setDuty(volume);
	pwm.setFreq(K_C6);
	_delay_ms(100);
	pwm.setDuty(0);
	_delay_ms(100);
}
void basslineG(){
	pwm.setDuty(volume);
	pwm.setFreq(K_G5);
	_delay_ms(100);
	pwm.setDuty(0);
	_delay_ms(200);

	pwm.setDuty(volume);
	pwm.setFreq(K_G5);
	_delay_ms(100);
	pwm.setDuty(0);
	_delay_ms(100);

	pwm.setDuty(volume);
	pwm.setFreq(K_G7);
	_delay_ms(100);
	pwm.setDuty(0);
	_delay_ms(200);

	pwm.setDuty(volume);
	pwm.setFreq(K_G7);
	_delay_ms(100);
	pwm.setDuty(0);
	_delay_ms(100);


	pwm.setDuty(volume);
	pwm.setFreq(K_F7);
	_delay_ms(100);
	pwm.setDuty(0);
	_delay_ms(200);

	pwm.setDuty(volume);
	pwm.setFreq(K_F7);
	_delay_ms(100);
	pwm.setDuty(0);
	_delay_ms(100);

	pwm.setDuty(volume);
	pwm.setFreq(K_D7);
	_delay_ms(100);
	pwm.setDuty(0);
	_delay_ms(200);

	pwm.setDuty(volume);
	pwm.setFreq(K_D7);
	_delay_ms(100);
	pwm.setDuty(0);
	_delay_ms(100);
}

void closing(){
	pwm.setDuty(volume);
	pwm.setFreq(K_C5);
	_delay_ms(200);
	pwm.setDuty(0);
	_delay_ms(100);

	pwm.setDuty(volume);
	pwm.setFreq(K_C5);
	_delay_ms(100);
	pwm.setDuty(0);
	_delay_ms(100);

	pwm.setDuty(volume);
	pwm.setFreq(K_E5);
	_delay_ms(200);
	pwm.setDuty(0);
	_delay_ms(100);

	pwm.setDuty(volume);
	pwm.setFreq(K_E5);
	_delay_ms(100);
	pwm.setDuty(0);
	_delay_ms(100);


	pwm.setDuty(volume);
	pwm.setFreq(K_F5);
	_delay_ms(200);
	pwm.setDuty(0);
	_delay_ms(100);

	pwm.setDuty(volume);
	pwm.setFreq(K_F5);
	_delay_ms(100);
	pwm.setDuty(0);
	_delay_ms(100);


	pwm.setDuty(volume);
	pwm.setFreq(K_Gb5);
	_delay_ms(200);
	pwm.setDuty(0);
	_delay_ms(100);

	pwm.setDuty(volume);
	pwm.setFreq(K_Gb5);
	_delay_ms(100);
	pwm.setDuty(0);
	_delay_ms(100);

	pwm.setDuty(volume);
	pwm.setFreq(K_G5);
	_delay_ms(200);
	pwm.setDuty(0);
	_delay_ms(100);


	pwm.setDuty(volume);
	pwm.setFreq(K_F5);
	_delay_ms(150);
	pwm.setDuty(0);
	_delay_ms(50);


	pwm.setDuty(volume);
	pwm.setFreq(K_Gb5);
	_delay_ms(150);
	pwm.setDuty(0);
	_delay_ms(150);

	pwm.setDuty(volume);
	pwm.setFreq(K_G5);
	_delay_ms(200);
	pwm.setDuty(0);
	_delay_ms(1000);


}




int main(){
	uint16_t doMajor[] = {K_C5,K_D5,K_E5,K_F5,K_G5,K_A5,K_B5,K_C6};
	uint16_t blueDo[] = {K_C5,K_Eb5,K_F5,K_Gb5,K_G5,K_Bb5,K_C6};
	Serial *serial =SerialManager::getInstance(SERIAL0);
	serial->init(BAUD_1000000);
	pwm.setPWM(1000,0);
	_delay_ms(1000);

	//for(uint8_t i = 0; i<SIZE_OF_ARRAY(doMajor);++i){
	//	pwm.setDuty(volume);
	//	pwm.setFreq(doMajor[i]);
	//	_delay_ms(100);
	//	pwm.setDuty(0);
	//_delay_ms(50);
	//
	//}

	uint8_t i = 0;

	while (1) {
		for(i = 0; i< 4;++i){
			basslineC();
		}
		for(i = 0; i< 2;++i){
			basslineF();
		}
		for(i = 0; i< 2;++i){
			basslineC();
		}
		basslineG();
		basslineF();
		closing();
	}

	return 0;
}
