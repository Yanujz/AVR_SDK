#include "asyncspislave.h"


AsyncSlaveSPI::AsyncSlaveSPI() : SlaveSPI(){

}

void AsyncSlaveSPI::init()
{
	*SPIx_CFG_REG |= bitValue(SPI_CFG_BIT_SPIE);
	sei();
}
