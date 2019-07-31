#ifndef SPISLAVE_H
#define SPISLAVE_H
#include "spi.h"
/*
///@file
typedef void spi_cb_t(uint8_t data);

struct slaveSPI_t
{
				//slaveSPI_t (volatile uint8_t *pinx = nullptr, Pin *miso = nullptr, Pin *mosi = nullptr, Pin *sck = nullptr,Pin *ss = nullptr){
				//    if(pinx != nullptr){
				//        PINx    = pinx;
				//        DDRx    = pinx + 1;
				//        PORTx   = pinx + 2;
				//    }
				//    MISO    = miso	== nullptr ? 0xFF : miso->getRegisterBit();
				//    MOSI    = mosi	== nullptr ? 0xFF : mosi->getRegisterBit();
				//    SCK     = sck	== nullptr ? 0xFF : sck->getRegisterBit();
				//    SS      = ss	== nullptr ? 0xFF : ss->getRegisterBit();
				//}
    volatile uint8_t *PINx;
    volatile uint8_t *DDRx;
    volatile uint8_t *PORTx;
    uint8_t MISO;
    uint8_t MOSI;
    uint8_t SCK;
    uint8_t SS;
};



class SlaveSPI
{
public:
    //-----------------METHODS-----------------//
				//static SlaveSPI* getInstance(slaveSPI_t data = nullptr);

    void setISR(bool value = false);

    void send(uint8_t data);
    void send(uint8_t *buff,size_t size);

    uint8_t receive();
    void receive(uint8_t *buff,size_t size);

    bool busIsWritable();

    void registerCallback(spi_cb_t *cb);
    void callback(uint8_t data);

    void insertData(uint8_t data);
    uint8_t readData();
    bool bufferIsReadable();
private:
    //-----------------METHODS-----------------//
    SlaveSPI();
    SlaveSPI(slaveSPI_t data, SPI_DORD dataOrder = MSB_FIRST, SPI_CLKSEL clockSel = FOSC_BY_2
            ,SPI_CPOL clockPolarity = LR_TF, SPI_CPHA clockPhase = LS_TP);
    //-----------------VARIABLES---------------//
    uint8_t SPI_BUFF[MAX_SPI_BUFFER];
    slaveSPI_t self;
    spi_cb_t *_callback;

    uint8_t *_read;
    uint8_t *_write;
    bool bufferReadable;
};
*/

class SlaveSPI
{
public:
	virtual void begin(SPI_MODE mode = MODE_0,
																				SPI_CLKSEL clock = FOSC_BY_128,
																				SPI_DORD dataOrder = MSB_FIRST) = 0;
	void end();
	u8t receive();
protected:
	SlaveSPI() {}
	void init(u16t cfg, PIN miso, PIN mosi, PIN sck, PIN ss);
	virtual bool isAvailable() = 0;

	volatile u8t* SPCRx;
};

#endif // SPISLAVE_H
