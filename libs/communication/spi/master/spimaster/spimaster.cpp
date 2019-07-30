#include "spimaster.h"

/*
MasterSPI::MasterSPI(masterSPI_t data, mSPIsetting_t settings)
{
				uint8_t i;
				self = data;

				SPCR = 0;

				// Set MOSI and SCK output SS output, all others input
				*self.DDRx |=  (1 << self.bitMOSI) | (1 << self.bitSCK);

				// Prevent to autoselect HW slave mode
				self._ss.setDirection(OUTPUT);
				self._ss.on();

				// Initializing slaves
				for(i = 0; i < self.SS.size(); ++i){
								self.SS[i].setDirection(OUTPUT);
								self.SS[i].on();                // Turning off all slave
				}


				setClockPhase(settings._clockPhase);
				setClockPolarity(settings._clockPolarity);
				setClock(settings._clock);
				setDataOrder(settings._dataOrder);



				SPCR |= (1 << MSTR);

				enable();

}*/
/*
MasterSPI::MasterSPI()
{

}

MasterSPI::MasterSPI(u8t miso, u8t mosi, u8t sck, u8t ss)
{
	_self = _masterSPI_t(miso, mosi, sck, ss);
	//self.SS[0].on();

	setClockPhase(_self._settings._clockPhase);
	setClockPolarity(_self._settings._clockPolarity);
	setClock(_self._settings._clock);
	setDataOrder(_self._settings._dataOrder);

	SPCR |= (1 << MSTR);
	enable();
}

void MasterSPI::enable()
{
	SPCR |= (1 << SPE);
}

void MasterSPI::disable()
{
	SPCR &= ~(1 << SPE);
}

void MasterSPI::setClock(SPI_CLKSEL clock)
{
	_self._settings._clock = clock;
	SPCR &= ~((1 << SPR1) | (1 << SPR0));
	SPSR &= ~(1 << SPI2X);

	SPSR |= ((_self._settings._clock & 4) >> 2) << SPI2X;
	SPCR |= (((_self._settings._clock & 2) >> 1) << SPR1) | ((_self._settings._clock & 1) << SPR0);

}

SPI_CLKSEL MasterSPI::getClock()
{
	return _self._settings._clock;
}

void MasterSPI::setDataOrder(SPI_DORD dataOrder)
{
	_self._settings._dataOrder = dataOrder;
	SPCR &= ~(1 << DORD);

	SPCR |= (_self._settings._dataOrder << DORD );
}

SPI_DORD MasterSPI::getDataOrder()
{
	return _self._settings._dataOrder;
}

void MasterSPI::setClockPolarity(SPI_CPOL clockPolarity)
{
	_self._settings._clockPolarity = clockPolarity;
	SPCR &= ~(1 << CPOL);

	SPCR |= (_self._settings._clockPolarity << CPOL);
}

SPI_CPOL MasterSPI::getClockPolarity()
{
	return _self._settings._clockPolarity;
}

void MasterSPI::setClockPhase(SPI_CPHA clockPhase)
{
	_self._settings._clockPhase = clockPhase;
	SPCR &= ~(1 << CPHA);


	SPCR |= (_self._settings._clockPhase << CPHA);

}

SPI_CPHA MasterSPI::getClockPhase()
{
	return _self._settings._clockPhase;
}

void MasterSPI::enableSlave(uint8_t slave)
{
	if(slaveIsValid(slave) == false){
		return;
	}
	//_self.SS[slave].off();
}

void MasterSPI::disableSlave(uint8_t slave)
{
	if(slaveIsValid(slave) == false){
		return;
	}
	//_self.SS[slave].on();
}


void MasterSPI::send(uint8_t data)
{
	// Start transmission
	SPDR = data;
	// Wait for transmission complete
	while(!(SPSR & (1<<SPIF)));
}

void MasterSPI::send(uint8_t *buff, size_t size)
{
	uint8_t i;
	for(i = 0;i < size;++i){
		send(buff[i]);
	}
}

uint8_t MasterSPI::receive()
{
	// Wait for reception complete
	//while(!(SPSR & (1<<SPIF)));
	//// Return Data Register
	//return SPDR;
	return sendReceive(0);
}

void MasterSPI::receive(uint8_t *buff, size_t size)
{
	uint8_t i;
	for(i = 0;i < size;++i){
		buff[i] = receive();
	}
}

uint8_t MasterSPI::sendReceive(uint8_t data)
{
	// Start transmission
	SPDR = data;
	// Wait for transmission complete
	while(!(SPSR & (1<<SPIF)));
	return SPDR;
}

void MasterSPI::sendReceive(uint8_t *dst, uint8_t *src, size_t size)
{
	u8t i;
	for(i = 0; i < size; ++i){
		dst[i] = sendReceive(src[i]);
	}

}

u8t MasterSPI::transfer(u8t data)
{
	SPDR = data;                       //Load data into the buffer
	while( !(SPSR & (1<<SPIF) ));       //Wait until transmission complete
	return SPDR;

}


bool MasterSPI::slaveIsValid(size_t slave)
{
	//if((slave+1) <= _self.SS.size()){
	//	return true;
	//}
	//return false;
}

bool MasterSPI::isInitilizedSPI()
{
	if (bitRead(SPCR, SPE)){
		return true;
	}
	return false;
}

u8t MasterSPI::getSlavePin(u8t index)
{
	//return _self.SS[index].getPinNumber();
}
*/



MasterSPI::MasterSPI()
{

}

void MasterSPI::init(u16t cfg, PIN miso, PIN mosi, PIN sck, PIN ss){
	pinMode(miso, INPUT);
	pinMode(mosi, OUTPUT);
	pinMode(sck, OUTPUT);
	pinMode(ss, OUTPUT);

	*SPCRx = bitValue(SPE) | bitValue(MSTR) | LO(cfg);
	_SPSRx(SPCRx) = HI(cfg);
}

void MasterSPI::end()
{
	*SPCRx &= ~bitValue(SPE);
}

u8t MasterSPI::transfer(u8t data)
{
	_SPDRx(SPCRx) = data;												//Load data into the buffer
	//while( !(SPSR & (1<<SPIF) ));					//Wait until transmission complete
	loop_until_bit_is_clear(_SPSRx(SPCRx), bitValue(SPIF));
	return _SPDRx(SPCRx);
}

void MasterSPI::transfer(u8t *dst, u8t *src, int size)
{
	while (size--) {
		*src++ = transfer(*dst++);
	}
}



void MasterSPI::enableSlave(PIN slave, bool enable)
{
	if(enable){
		digitalClr(slave);
	}
	digitalSet(slave);
}

