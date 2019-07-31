#ifndef ASYNCMASTERSPI_H
#define ASYNCMASTERSPI_H
#include <spimaster.h>
#include <fifo.hpp>
#include <systemevent.h>


class AsyncMasterSPI : public virtual MasterSPI
{
public:
    AsyncMasterSPI();
				virtual void begin(SPI_MODE mode = MODE_0,
																							SPI_CLKSEL clock = FOSC_BY_128,
																							SPI_DORD dataOrder = MSB_FIRST) = 0;
    virtual void registerCallback(spi_cb_t* cb = nullptr) = 0;
    virtual void registerCallback(SystemEventHandler* cb = nullptr) = 0;

    void startAsyncTransfer();

    void push_rx_fifo(u8t value);
    u8t pop_rx_fifo();
    bool is_rx_fifo_empty();

    void push_tx_fifo(u8t *value, int size, bool startOnFinish = false);
    u8t pop_tx_fifo();
    bool is_tx_fifo_empty();


protected:
				void init();

    Fifo<u8t, 32> rx_fifo;
    Fifo<u8t, 32> tx_fifo;
};

#endif // ASYNCMASTERSPI_H
