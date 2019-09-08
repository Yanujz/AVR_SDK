#include "avr_sdk.h"

void setupMasterSPI(MasterSPI *&master){
	Pin miso(50,INPUT);
	Pin mosi(51,INPUT);
	Pin sck(52,INPUT);
	Pin ss_default(53,OUTPUT);
	// Setting slaves
	Pin slave0(22,OUTPUT);

	masterSPI_t data(miso.getPINxAddr(),&miso,&mosi,&sck,&ss_default);
	data.SS.pushRight(slave0);

	mSPIsetting_t settings(FOSC_BY_128, MSB_FIRST, LR_TF, LS_TP);

	master = new MasterSPI(data,settings);

}

int main(){

	Serial *serial0 = SerialManager::getInstance(SERIAL0);
	serial0->init(BAUD_1000000,_LOW_PRIORITY);
	//serial0->registerCallback((ser_cb_t*)asd);
	serial0->setRxISRCallBack(false);
	serial0->setEchoServer(false);
	MasterSPI *master;
	setupMasterSPI(master);

	//uint8_t src[]={0x40,0x00,0x00,0x00,0x95};
	uint8_t src[]={0x00,0x00,0x00,0x0};

	uint8_t dst[SIZE_OF_ARRAY(src)];
	volatile uint8_t tmp = 0;
	volatile uint8_t i = 0;

	master->enable();
	while (1) {

		master->enableSlave(0);

		master->sendReceive(dst,src,SIZE_OF_ARRAY(src));
		//master->send(62);
		//master->disableSlave(0);
		//master->receive(temp,SIZE_OF_ARRAY(temp));
		for(i = 0; i< SIZE_OF_ARRAY(dst);++i){
			serial0->printf("Reply from slave [%d]: %d\r\n",i,dst[i]);
		}
		_delay_ms(500);

		master->disableSlave(0);
	}


	return 0;
}
