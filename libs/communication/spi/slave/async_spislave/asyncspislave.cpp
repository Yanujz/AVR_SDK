#include "asyncspislave.h"


AsyncSlaveSPI::AsyncSlaveSPI() : SlaveSPI(){

}

void AsyncSlaveSPI::init()
{
	*SPCRx |= bitValue(SPIE);
	sei();
}
