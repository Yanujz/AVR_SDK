#include "spislave.h"
/*
SlaveSPI *SlaveSPI::getInstance(slaveSPI_t data)
{
	static SlaveSPI *instance = 0;
	if(instance == 0){
		instance = new SlaveSPI(data);
	}
	return instance;
}*/






SlaveSPI::SlaveSPI()
{

}




SlaveSPI::SlaveSPI(slaveSPI_t data, SPI_DORD dataOrder, SPI_CLKSEL clockSel, SPI_CPOL clockPolarity, SPI_CPHA clockPhase)
{
	self = data;
	SPCR = 0;
	DDRB = 0;
	SPSR = 0;
	// Set MISO output, all others input
	*self.DDRx	= ~((1 << self.MOSI) | (1 << self.SCK) | (1 << self.SS));
	*self.DDRx	|= (1 << self.MISO);
	//*self.PORTx |= (1 << self.MISO);



	//SPCR |= (clockPolarity << CPOL) | (clockPhase << CPHA);
	//SPSR |= ((clockSel & 4) >> 2) << SPI2X;
	////SPSR |= (1 << SPI2X);
	//SPCR |= (((clockSel & 2) >> 1) << SPR1) | ((clockSel & 1) << SPR0);
	//SPCR |= (dataOrder << DORD );
	SPCR &= ~(1 << MSTR);
	SPCR |= (1 << SPE);

	_callback = nullptr;

}



void SlaveSPI::setISR(bool value)
{
	if(value){
		SPCR |= (1 << SPIE);
		sei();
		return;
	}
	SPCR &= ~(1 << SPIE);
}

void SlaveSPI::send(uint8_t data)
{
	// Start transmission
	SPDR = data;
	// Wait for transmission complete
	while(!(SPSR & (1<<SPIF)));
}

void SlaveSPI::send(uint8_t *buff, size_t size)
{   //TO TEST
	for(uint8_t i = 0;i< size;++i){
		send(buff[i]);
	}
}

uint8_t SlaveSPI::receive()
{
	// Wait for reception complete
	while(!(SPSR & (1<<SPIF)));
	// Return Data Register
	return SPDR;
}

void SlaveSPI::receive(uint8_t *buff, size_t size)
{
	for(uint8_t i = 0;i< size;++i){
		buff[i] = receive();
	}
}

bool SlaveSPI::busIsWritable()
{
	return !(*self.PINx & (1<<self.SS)) >> self.SS;
}

void SlaveSPI::registerCallback(spi_cb_t *cb)
{
	setISR(true);
	_callback = *cb;
}

void SlaveSPI::callback(uint8_t data)
{
	if(_callback != nullptr){
		_callback(data);
	}
}

void SlaveSPI::insertData(uint8_t data)
{
	bool bufferIsWritable = true;
	if( ++_write > (uint8_t*)(&SPI_BUFF+1)-1){
		_write = SPI_BUFF;
	}
	if(_write == _read){

		bufferIsWritable = false;
		--_write;
		if(_write < SPI_BUFF){
			_write = (uint8_t*)(&SPI_BUFF+1)-1;
		}
	}
	if(bufferIsWritable){
		*_write = data;
	}

}

uint8_t SlaveSPI::readData()
{
	bufferReadable = false;

	if( ++_read > (uint8_t*)(&SPI_BUFF+1)-1){
		_read = SPI_BUFF;
	}
	if(_read != _write){
		bufferReadable = true;
	}
	uint8_t temp = *_read;
	return temp;
}

bool SlaveSPI::bufferIsReadable()
{
	if(_read == _write){
		return false;
	}

	return true;
}



//-------ISR------/
ISR(SPI_STC_vect){
//	///SlaveSPI *slave = SlaveSPI::getInstance();
	//volatile uint8_t a = SPDR;
	//SPDR = 6;
	////slave->insertData(a);
	////slave->callback(a);
	//Serial *serial0 = SerialManager::getInstance(SERIAL0);
	//serial0->printf("ISR called data : %d\r\n",a);
	//if(a == 0xAA){
	//    SPDR = 6;
	//}

	// Start transmission
	//SPDR = a;
	// Wait for transmission complete
}
