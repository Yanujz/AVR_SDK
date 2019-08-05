#include "spimaster.h"


MasterSPI::MasterSPI()
{

}

void MasterSPI::init(u16t cfg){
	*SPIx_CFG_REG = bitValue(SPI_CFG_BIT_SPE) | bitValue(SPI_CFG_BIT_MSTR) | LO8(cfg);
	*SPIx_STAT_REG = HI8(cfg);
}

void MasterSPI::end()
{
	*SPIx_CFG_REG &= ~bitValue(SPI_CFG_BIT_SPE);
}

u8t MasterSPI::transfer(u8t data)
{
	*SPIx_DATA_REG = data;												//Load data into the buffer
	loop_until_bit_is_set(*SPIx_STAT_REG, SPI_STAT_BIT_SPIF);
	return *SPIx_DATA_REG;
}

void MasterSPI::transfer(u8t *src, int size)
{
	u8t dummy;
	while (size--) {
		dummy	= transfer(*src++);
		asm volatile("nop");
	}
}

void MasterSPI::transfer(u8t *dst, u8t *src, int size)
{
	if(nullptr == dst || nullptr == src ){
		return;
	}
	while (size--) {
		*dst++  = transfer(*src++);
		asm volatile("nop");
	}
}

void MasterSPI::enableSlave(PIN slave, bool enable)
{
	if(enable){
		digitalClr(slave);
		return;
	}
	digitalSet(slave);
}

