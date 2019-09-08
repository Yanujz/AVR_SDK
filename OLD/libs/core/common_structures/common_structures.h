#pragma once
#include <systemevent.h>
#include <common_typedef.h>
namespace AsyncSPI{

struct HW_SPI_INT : SystemEventHandler::SYS_EVENT
{
	HW_SPI_INT(){
		user_cb = nullptr;
		context = nullptr;
	}
	spi_cb_t* user_cb;
};

}
