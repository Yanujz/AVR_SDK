#include "avr_sdk.h"

void setupSlaveSPI(SlaveSPI *&slave){
	Pin miso(50,OUTPUT);
	Pin mosi(51,INPUT);
	Pin sck(52,INPUT);
	Pin SS(53,INPUT);

	slaveSPI_t dataSlave = slaveSPI_t(miso.getPINxAddr(),&miso,&mosi,&sck,&SS);
	slave = SlaveSPI::getInstance(dataSlave);
}


void rxCallback(){
	Serial *serial0 = SerialManager::getInstance(SERIAL0);
	serial0->printf("Hi from callback\r\n");
}

int main(){

	Serial *serial0 = SerialManager::getInstance(SERIAL0);
	serial0->init(BAUD_1000000,_LOW_PRIORITY);
	//serial0->registerCallback((ser_cb_t*)asd);
	serial0->setRxISRCallBack(false);
	serial0->setEchoServer(false);


	SlaveSPI *slave;
	setupSlaveSPI(slave);
	slave->registerCallback((spi_cb_t*)rxCallback);


	uint8_t src[]={0x00,0x00,0x00,0x0};

	uint8_t dst[SIZE_OF_ARRAY(src)];
	volatile uint8_t tmp = 0;
	volatile uint8_t i = 0;


	while (1) {
		asm volatile("nop");
	}

	return 0;
}
