#include "enc28j60.h"
/*
Enc28j60::Enc28j60(macaddr_t &mac)
{

	if (_spi->isInitilizedSPI() == false){
		setSPI(DEF_SPI_MISO, DEF_SPI_MOSI, DEF_SPI_SCK, DEF_SPI_SS);
	}
	_spi_reset();


	//---- Setting buffers ----//
	// TX Start Address
	_spi_writeControlReg(REG_ETXSTL, LO(ENC28J60_TX_BUFFER_START));
	_spi_writeControlReg(REG_ETXSTH, HI(ENC28J60_TX_BUFFER_START));

	_spi_writeControlReg(REG_ETXNDH, HI(ENC28J60_TX_BUFFER_END));
	_spi_writeControlReg(REG_ETXNDH, HI(ENC28J60_TX_BUFFER_END));

	// RX Start Address
	_spi_writeControlReg(REG_ERXSTL, LO(ENC28J60_RX_BUFFER_START));
	_spi_writeControlReg(REG_ERXSTH, HI(ENC28J60_RX_BUFFER_START));

	// RX Data Pointer
	_spi_writeControlReg(REG_ERXRDPTL, LO(ENC28J60_RX_BUFFER_START));
	_spi_writeControlReg(REG_ERXRDPTH, HI(ENC28J60_RX_BUFFER_START));

	// RX End Address
	_spi_writeControlReg(REG_ERXNDL, LO(ENC28J60_RX_BUFFER_END));
	_spi_writeControlReg(REG_ERXNDH, HI(ENC28J60_RX_BUFFER_END));


	//---- Setting Filters ----//
	_spi_writeControlReg(REG_ERXFCON, regBitToValue(ENC28J60_ERXFCON_REG_BIT::UCEN) | regBitToValue(ENC28J60_ERXFCON_REG_BIT::CRCEN) |
																						regBitToValue(ENC28J60_ERXFCON_REG_BIT::MCEN)  | regBitToValue(ENC28J60_ERXFCON_REG_BIT::BCEN));

	_spi_setMAC();

	//---- Setting Hash Table ----//
	_spi_writeControlReg(REG_EHT0, 0x00);
	_spi_writeControlReg(REG_EHT1, 0x00);
	_spi_writeControlReg(REG_EHT2, 0x00);
	_spi_writeControlReg(REG_EHT3, 0x00);
	_spi_writeControlReg(REG_EHT4, 0x00);
	_spi_writeControlReg(REG_EHT5, 0x00);
	_spi_writeControlReg(REG_EHT6, 0x00);
	_spi_writeControlReg(REG_EHT7, 0x00);


	//---- Setting Magic Packet ----//
	//_spi_writeControlReg(REG_EPMM0, 0x3f);
	//_spi_writeControlReg(REG_EPMM1, 0x30);
	//_spi_writeControlReg(REG_EPMCSL, 0xf9);
	//_spi_writeControlReg(REG_EPMCSH, 0xf7);



	_spi_writeControlReg(REG_ECOCON, regBitToValue(ENC28J60_ECOCON_REG_CFG::CLKOUT_DISABLED));


	//Enable the MAC to receive frames
	_spi_writeControlReg(REG_MACON1, regBitToValue(ENC28J60_MACON1_REG_BIT::MARXEN) | regBitToValue(ENC28J60_MACON1_REG_BIT::TXPAUS) | regBitToValue(ENC28J60_MACON1_REG_BIT::RXPAUS));


	//Enable automatic padding to at least 60 bytes, always append a valid CRC
	//and check frame length. MAC can operate in half-duplex or full-duplex mode
	if(_self.fullDuplex){
		_spi_writeControlReg(REG_MACON3, regBitToValue(ENC28J60_MACON3_REG_BIT::PADCFG0) | regBitToValue(ENC28J60_MACON3_REG_BIT::TXCRCEN) |
																							regBitToValue(ENC28J60_MACON3_REG_BIT::FRMLNEN) | regBitToValue(ENC28J60_MACON3_REG_BIT::FULDPX));
		_spi_writePhy(REG_PHCON1, regBitToValue(ENC28J60_PHCON1_REG_BIT::PDPXMD));
	}
	else {
		_spi_writeControlReg(REG_MACON3, regBitToValue(ENC28J60_MACON3_REG_BIT::PADCFG0) | regBitToValue(ENC28J60_MACON3_REG_BIT::TXCRCEN) |
																							regBitToValue(ENC28J60_MACON3_REG_BIT::FRMLNEN));
		_spi_writePhy(REG_PHCON1, 0);

		//Disable half-duplex loopback in PHY
		_spi_writePhy(REG_PHCON2, regBitToValue(ENC28J60_PHCON2_REG_BIT::HDLDIS));
	}

	_spi_bitFieldSet(REG_MACON4, regBitToValue(ENC28J60_MACON4_REG_BIT::DEFER));

	_spi_writeControlReg(REG_MAIPGL, 0x12);
	_spi_writeControlReg(REG_MAIPGH, 0x0C);

	_spi_writeControlReg(REG_MABBIPG, _self.fullDuplex ? 0x15: 0x12);

	_spi_writeControlReg(REG_MAMXFLL, LO(ENC28J60_MAX_FRAMELENGTH));
	_spi_writeControlReg(REG_MAMXFLH, HI(ENC28J60_MAX_FRAMELENGTH));


	_spi_writeControlReg(REG_MACLCON2, 63);

	//_spi_writePhy(REG_PHCON1, regBitToValue(ENC28J60_PHCON1_REG_BIT::PRST));


	//---- Clear interrupt flags ----//
	_spi_writeControlReg(REG_EIR, 0x00);
	//Configure interrupts as desired

	enableInterrupt(regBitToValue(ENC28J60_EIE_REG_BIT::PKTIE) | regBitToValue(ENC28J60_EIE_REG_BIT::RXERIE) |	regBitToValue(ENC28J60_EIE_REG_BIT::LINKIE)
																	| regBitToValue(ENC28J60_EIE_REG_BIT::TXIE) | regBitToValue(ENC28J60_EIE_REG_BIT::TXERIE));


	//Configure PHY interrupts as desired
	_spi_writePhy(REG_PHIE,regBitToValue(ENC28J60_PHIE_REG_BIT::PLNKIE) | regBitToValue(ENC28J60_PHIE_REG_BIT::PGEIE));

	_spi_writeControlReg(REG_ECON2, regBitToValue(ENC28J60_ECON2_REG_BIT::AUTOINC));

	_spi_bitFieldSet(REG_ECON1, regBitToValue(ENC28J60_ECON1_REG_BIT::RXEN));

}


void Enc28j60::setSPI(u8t miso, u8t mosi, u8t sck, u8t ss)
{
	_spi = new MasterSPI(miso, mosi, sck, ss);
	_spi->setClock(FOSC_BY_2);
}

void Enc28j60::sendPacket(u8t *buff, u16t size)
{
	_spi_writeControlReg(REG_EWRPTL, LO(_self.txBuffStart));
	_spi_writeControlReg(REG_EWRPTH, HI(_self.txBuffStart));

	_spi_writeControlReg(REG_ETXNDL, LO(_self.txBuffStart+size));
	_spi_writeControlReg(REG_ETXNDH, HI(_self.txBuffStart+size));

	_spi_writeBuffer(buff, size);

	_spi_bitFieldSet(REG_ECON1, regBitToValue(ENC28J60_ECON1_REG_BIT::TXRTS));
	_spi_bitFieldClear(REG_ECON1, regBitToValue(ENC28J60_ECON1_REG_BIT::TXRTS));
	_spi_bitFieldClear(REG_EIR, regBitToValue(ENC28J60_EIR_REG_BIT::TXIF) | regBitToValue(ENC28J60_EIR_REG_BIT::TXERIF));


	_spi_bitFieldSet(REG_ECON1, regBitToValue(ENC28J60_ECON1_REG_BIT::TXRTS));
}

u16t Enc28j60::receivePacket(u8t *buff, u16t size)
{
	uint16_t rxstat;
	uint16_t len;
	if(_spi_readControlReg(REG_EPKTCNT) == 0){
		return 0;
	}

	_spi_writeControlReg(REG_ERDPTL,LO(_self.nextPacketPtr));
	_spi_writeControlReg(REG_ERDPTH,HI(_self.nextPacketPtr));

	_self.nextPacketPtr  = _spi_readOpcode(SPI_OPCODE_RBM);
	_self.nextPacketPtr |= _spi_readOpcode(SPI_OPCODE_RBM)<<8;


	len  = _spi_readOpcode(SPI_OPCODE_RBM);
	len |= _spi_readOpcode(SPI_OPCODE_RBM)<<8;
	len-=4;
	//dbg("Packet size %u\r\n", len);
	rxstat  = _spi_readOpcode(SPI_OPCODE_RBM);
	rxstat |= _spi_readOpcode(SPI_OPCODE_RBM)<<8;

	if(len > size-1) {
		len = size-1;
	}
	if ((rxstat & 0x80) == 0){
		//len=0;
		return 0;
	}

	_spi_readBuffer(buff, size);

	if(_self.nextPacketPtr == ENC28J60_RX_BUFFER_START)
	{
		_spi_writeControlReg(REG_ERXRDPTL, LO(ENC28J60_RX_BUFFER_END));
		_spi_writeControlReg(REG_ERXRDPTH, HI(ENC28J60_RX_BUFFER_END));
	}
	else
	{
		_spi_writeControlReg(REG_ERXRDPTL, LO(_self.nextPacketPtr - 1));
		_spi_writeControlReg(REG_ERXRDPTH, HI(_self.nextPacketPtr - 1));
	}
	_spi_bitFieldSet(REG_ECON2, regBitToValue(ENC28J60_ECON2_REG_BIT::PKTDEC));

	return len;

}

bool Enc28j60::Enc28j60::isReceivingData()
{
	if(_spi_readPhy(REG_PHSTAT2) & regBitToValue(ENC28J60_PHSTAT2_REG_BIT::RXSTAT)){
		return true;
	}
	if(_spi_readControlReg(REG_ESTAT) & regBitToValue(ENC28J60_ESTAT_REG_BIT::RXBUSY)){
		return true;
	}
	return false;
}

bool Enc28j60::isLinkUp()
{
	if(_spi_readPhy(REG_PHSTAT2) & regBitToValue(ENC28J60_PHSTAT2_REG_BIT::LSTAT)){
		return true;
	}
	return false;
}

u8t Enc28j60::getUnreadPacket()
{
	return _spi_readControlReg(REG_EPKTCNT);
}

void Enc28j60::enableInterrupt(u8t value)
{

	_spi_writeControlReg(REG_EIE, regBitToValue(ENC28J60_EIE_REG_BIT::INTIE) | value);

	//int_cb_t *callback = (int_cb_t*)&([&](){	this->_callback(this);	});

	//Interrupt::attachInterrupt(13, FALLING, this);
}

void Enc28j60::disableInterrupt()
{
	_spi_writeControlReg(REG_EIE, 0x00);
}

void Enc28j60::registerCallback(enc_cb_t *cb)
{
	_cb = cb;
}





//---- Private Methods ----//

//---- Raw Methods ----//
u8t Enc28j60::_spi_readControlReg(ENC28J60_REGS reg)
{
	_spi_selectBank(ENC28J60_READ_BANK(reg));
	return _spi_readOpcode(reg & ~(toU16(0x7) << 5));
}

void Enc28j60::_spi_writeControlReg(ENC28J60_REGS reg, u8t data)
{
	_spi_selectBank(ENC28J60_READ_BANK(reg));
	_spi_writeOpCode(SPI_OPCODE_WCR | LO(reg), &data, 1);
}

void Enc28j60::_spi_selectBank(u8t bank)
{
	if(bank > 3 || _self.currentBank == bank){
		return;
	}
	_self.currentBank = bank;
	u8t var = _spi_readOpcode(REG_ECON1);
	var &= ~0x03;
	var |= bank;
	_spi_writeOpCode(SPI_OPCODE_WCR | REG_ECON1, &var, 1);
}

void Enc28j60::_spi_writeOpCode(u8t reg, u8t *buff, size_t size)
{
	//_delay_ms(1);
	_spi->enableSlave(0);
	u8t dummy = _spi->transfer(reg);
	if(buff != nullptr){
		for(size_t i = 0; i < size; ++i){
			dummy = _spi->transfer(buff[i]);
		}
	}
	_spi->disableSlave(0);
}

u8t Enc28j60::_spi_readOpcode(u16t reg)
{
	_spi->enableSlave(0);
	u8t data = _spi->transfer(LO(reg));

	data = _spi->transfer(0);
	if(ENC28J60_READ_KoR(reg)){
		//	if(reg & 0x80){
		data = _spi->transfer(0);
	}
	_spi->disableSlave(0);
	return data;
}

u16t Enc28j60::_spi_readPhy(ENC28J60_PHY_REG reg)
{
	_spi_writeControlReg(REG_MIREGADR, reg);
	_spi_bitFieldSet(REG_MICMD, regBitToValue(ENC28J60_MICMD_REG_BIT::MIIRD));
	_delay_us(15);
	while(_spi_readControlReg(REG_MISTAT) & regBitToValue(ENC28J60_MISTAT_REG_BIT::BUSY));
	_spi_bitFieldClear(REG_MICMD, regBitToValue(ENC28J60_MICMD_REG_BIT::MIIRD));

	return ((_spi_readControlReg(REG_MIRDH) << 8) | _spi_readControlReg(REG_MIRDL));
}

void Enc28j60::_spi_writePhy(ENC28J60_PHY_REG reg, u16t data)
{
	_spi_writeControlReg(REG_MIREGADR, reg);
	_spi_writeControlReg(REG_MIWRL, LO(data));
	_spi_writeControlReg(REG_MIWRH, HI(data));
	while(_spi_readControlReg(REG_MISTAT) & regBitToValue(ENC28J60_MISTAT_REG_BIT::BUSY));
}

void Enc28j60::_spi_bitFieldSet(ENC28J60_REGS reg, u8t data)
{
	_spi_selectBank(ENC28J60_READ_BANK(reg));
	_spi_writeOpCode(SPI_OPCODE_BFS | LO(reg), &data, 1);
}

void Enc28j60::_spi_bitFieldClear(ENC28J60_REGS reg, u8t data)
{
	_spi_selectBank(ENC28J60_READ_BANK(reg));
	_spi_writeOpCode(SPI_OPCODE_BFC | LO(reg), &data, 1);
}

void Enc28j60::_spi_reset()
{
	_spi_writeOpCode(SPI_OPCODE_SRC, nullptr, 0);
	// Wait for the ENC28J60 to finish startup
	while(!(_spi_readControlReg(REG_ESTAT)) & regBitToValue(ENC28J60_ESTAT_REG_BIT::CLKRDY));
}

void Enc28j60::_spi_readBuffer(u8t *buff, u16t size)
{
	_spi->enableSlave(0);
	u8t dummy = _spi->transfer(SPI_OPCODE_RBM);
	u16t i = 0;
	for(; i < size; ++i){
		buff[i] = _spi->transfer(0);
	}
	//buff[i] = '\0';
	_spi->disableSlave(0);
}

void Enc28j60::_spi_writeBuffer(u8t *buff, u16t size)
{
	_spi->enableSlave(0);
	u8t dummy = _spi->transfer(SPI_OPCODE_WBM);
	dummy = _spi->transfer(0);
	for(u16t i = 0; i < size; ++i){
		dummy = _spi->transfer(buff[i]);
	}
	_spi->disableSlave(0);
}

//---- End Raw Methods ----//


//---- Complex Methods ----//
void Enc28j60::_spi_setRxBufferSize(u16t size)
{
	if(size){
		_self.rxBuffEnd = size;
	}
	_spi_writeControlReg(REG_ERXSTH, HI(_self.rxBuffStart));
	_spi_writeControlReg(REG_ERXSTL, LO(_self.rxBuffEnd));

	_spi_writeControlReg(REG_ERXNDH, HI(_self.rxBuffEnd));
	_spi_writeControlReg(REG_ERXNDL, LO(_self.rxBuffEnd));
}

u16t Enc28j60::_spi_getRxBufferSize()
{
	return (_spi_readControlReg(REG_ERXNDH) << 8) | _spi_readControlReg(REG_ERXNDL);
}

void Enc28j60::_spi_setTxBufferSize(u16t size)
{
	_self.txBuffStart = _self.rxBuffEnd + 1;
	if(size){
		_self.txBuffEnd = _self.txBuffStart + size;
		if(_self.txBuffEnd > ENC28J60_TX_BUFFER_END){
			_self.txBuffEnd = ENC28J60_TX_BUFFER_END;
		}
	}
	else {
		_self.txBuffEnd = ENC28J60_TX_BUFFER_END;
	}

	_spi_writeControlReg(REG_ETXSTH, HI(_self.txBuffStart));
	_spi_writeControlReg(REG_ETXSTL, LO(_self.txBuffEnd));

	_spi_writeControlReg(REG_ETXNDH, HI(_self.txBuffEnd));
	_spi_writeControlReg(REG_ETXNDL, LO(_self.txBuffEnd));
}

u16t Enc28j60::_spi_getTxBufferSize()
{
	return (_spi_readControlReg(REG_ETXNDH) << 8) | _spi_readControlReg(REG_ETXNDL);
}

void Enc28j60::_spi_setMAC()
{
	_spi_writeControlReg(REG_MAADR6, _self.macAddress._mac[0]);
	_spi_writeControlReg(REG_MAADR5, _self.macAddress._mac[1]);
	_spi_writeControlReg(REG_MAADR4, _self.macAddress._mac[2]);
	_spi_writeControlReg(REG_MAADR3, _self.macAddress._mac[3]);
	_spi_writeControlReg(REG_MAADR2, _self.macAddress._mac[4]);
	_spi_writeControlReg(REG_MAADR1, _self.macAddress._mac[5]);
}

void Enc28j60::_spi_getMAC(u8t *arr)
{
	arr[0] = _spi_readControlReg(REG_MAADR6);
	arr[1] = _spi_readControlReg(REG_MAADR5);
	arr[2] = _spi_readControlReg(REG_MAADR4);
	arr[3] = _spi_readControlReg(REG_MAADR3);
	arr[4] = _spi_readControlReg(REG_MAADR2);
	arr[5] = _spi_readControlReg(REG_MAADR1);
}
/*
void Enc28j60::_spi_setRxFilter()
{


	//_spi_writeControlReg(REG_ERXFCON, 0);
	//_spi_bitFieldClear(REG_ERXFCON, regBitToValue(ENC28J60_ERXFCON_REG_BIT::ANDOR));
}
*/
/*
void Enc28j60::_spi_setBuffers()
{
	u8t res = 0;

	// TX Start Address
	_spi_writeControlReg(REG_ETXSTL, LO(ENC28J60_TX_BUFFER_START));
	_spi_writeControlReg(REG_ETXSTH, HI(ENC28J60_TX_BUFFER_START));

	_spi_writeControlReg(REG_ETXNDH, HI(ENC28J60_TX_BUFFER_END));
	_spi_writeControlReg(REG_ETXNDH, HI(ENC28J60_TX_BUFFER_END));

	// RX Start Address
	_spi_writeControlReg(REG_ERXSTL, LO(ENC28J60_RX_BUFFER_START));
	_spi_writeControlReg(REG_ERXSTH, HI(ENC28J60_RX_BUFFER_START));

	// RX Data Pointer
	_spi_writeControlReg(REG_ERXRDPTL, LO(ENC28J60_RX_BUFFER_START));
	_spi_writeControlReg(REG_ERXRDPTH, HI(ENC28J60_RX_BUFFER_START));

	// RX End Address
	_spi_writeControlReg(REG_ERXNDL, LO(ENC28J60_RX_BUFFER_END));
	_spi_writeControlReg(REG_ERXNDH, HI(ENC28J60_RX_BUFFER_END));

	if(_confirmRegisters){

		if(((_spi_readControlReg(REG_ETXSTH)   << 8) | _spi_readControlReg(REG_ETXSTL)) == ENC28J60_TX_BUFFER_START){
			res++;
		}

		if(((_spi_readControlReg(REG_ERXSTH)   << 8) | _spi_readControlReg(REG_ERXSTL)) == ENC28J60_RX_BUFFER_START){
			res++;
		}

		if(((_spi_readControlReg(REG_ERXRDPTH) << 8) | _spi_readControlReg(REG_ERXRDPTL)) == ENC28J60_RX_BUFFER_START){
			res++;
		}

		if(((_spi_readControlReg(REG_ERXNDH)   << 8) | _spi_readControlReg(REG_ERXNDL)) == ENC28J60_RX_BUFFER_END){
			res++;
		}
	}
	if(res == 4){
		return true;
	}

	return false;



}
*/
/*
void Enc28j60::_callback(u8t pin, void *context)
{
	if(context == nullptr) {
		return;
	}

	Enc28j60 * _context = ((Enc28j60*)context);
	_context->_spi_writeControlReg(REG_EIR, 0x00);
	if(_context->_cb!= nullptr){
		_context->_cb(LINKIF);
	}
}

void Enc28j60::callback(u8t pin)
{

}

*/
