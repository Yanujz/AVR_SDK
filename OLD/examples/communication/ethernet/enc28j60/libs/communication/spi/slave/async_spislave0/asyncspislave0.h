#pragma once
#include <asyncspislave.h>
#include <spislave0.h>
#if defined(__SPI0_SUPPORT__)
class AsyncSlaveSPI0 : public AsyncSlaveSPI, public SlaveSPI0
{
public:
	AsyncSlaveSPI0();
	virtual void begin() override;
	virtual void registerCallback(spi_cb_t* cb = nullptr) override;
	virtual void registerCallback(SystemEventHandler* context = nullptr) override;

};
extern AsyncSlaveSPI0 asyncSlaveSPI0;
#endif // __SPI0_SUPPORT__
