#ifndef ASYNCMASTERSPI0_H
#define ASYNCMASTERSPI0_H
#include <asyncmasterspi.h>
#include <spimaster0.h>

class AsyncMasterSPI0 :  public MasterSPI0, public AsyncMasterSPI
{
public:
				AsyncMasterSPI0();
				virtual void begin(SPI_MODE mode = MODE_0,
																							SPI_CLKSEL clock = FOSC_BY_128,
																							SPI_DORD dataOrder = MSB_FIRST) override;
				virtual void registerCallback(spi_cb_t* cb = nullptr) override;
				virtual void registerCallback(SystemEventHandler* context = nullptr) override;
};
extern AsyncMasterSPI0 asyncMasterSPI0;
#endif // ASYNCMASTERSPI0_H
