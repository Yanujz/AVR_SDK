#pragma once
#include <core.h>
#if defined(__ATMEGA2560__) || defined(__ATMEG328P__) || defined(__ATMEGA328PB__)
#include <mega_hw_master_spi0_sync.h>
#include <mega_hw_master_spi0_async.h>
#include <mega_hw_master_spi_sync_low_size.h>
#include <mega_hw_master_spi0_async_low_size.h>

#include <mega_hw_slave_spi0_sync.h>
#include <mega_hw_slave_spi0_async.h>
#include <mega_hw_slave_spi_sync_low_size.h>
#include <mega_hw_slave_spi0_async_low_size.h>
#endif

#if defined(__ATMEGA328PB__)
#include <mega_hw_master_spi1_sync.h>
#include <mega_hw_master_spi1_async.h>
#include <mega_hw_master_spi_sync_low_size.h>
#include <mega_hw_master_spi1_async_low_size.h>

#include <mega_hw_slave_spi1_sync.h>
#include <mega_hw_slave_spi1_async.h>
#include <mega_hw_slave_spi_sync_low_size.h>
#include <mega_hw_slave_spi1_async_low_size.h>
#endif
