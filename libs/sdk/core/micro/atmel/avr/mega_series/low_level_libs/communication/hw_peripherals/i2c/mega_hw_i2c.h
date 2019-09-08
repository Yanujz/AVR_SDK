#pragma once
#include <core.h>
#if defined(__ATMEGA2560__) || defined(__ATMEG328P__) || defined(__ATMEGA328PB__)
#include <mega_hw_master_i2c_sync_low_size.h>
#include <mega_hw_master_i2c_sync.h>
#include <mega_hw_master_i2c0_sync.h>

#include <mega_hw_slave_i2c_async_low_size.h>
#include <mega_hw_slave_i2c0_async.h>
#endif
