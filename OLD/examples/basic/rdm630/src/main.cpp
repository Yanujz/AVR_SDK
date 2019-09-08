#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include <avr_sdk.h>
#include <arp.h>

using namespace std;



bool debug = true;

int main(){

	Serial *serial0 = SerialManager::getInstance(SERIAL0);
	serial0->init(BAUD_1000000);
	serial0->setRxISRCallBack(false);
	serial0->setEchoServer(false);
	serial0->clear();


	Rdm6300 rdm6300;
	if(rdm6300.setBuzzerPin(13)){
		serial0->printf("Buzzer ok!\r\n");
	}
	if(rdm6300.attachTo(SERIAL3, BAUD_9600)){
		serial0->printf("Attach ok\r\n");
	}


	vector<uint8_t> cardNum;
	while(1){

		//serial0->printf("%s\r\n",a.c_str());
		//serial0->printf("%s\r\n",ltrim((char*)a.c_str()));
		//serial0->printf("Sending %s\r\n",ciao.c_str());
		//serial0->printf("%u\r\n",cardNum.size());
		if(rdm6300.isNewCard()){
			serial0->printf("New Card found!\r\n");
			//encj2860.send();
			cardNum = rdm6300.getData();
			serial0->printf("ID: ");
			for(uint8_t i = 0; i < cardNum.size();++i){
				serial0->printf("%c", cardNum[i], cardNum[i]);
			}
			serial0->printf("\r\n");
			_delay_ms(1000);
		}

		_delay_ms(10);
	}



}
