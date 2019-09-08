#pragma once
#include <core.h>

#if defined(__ATMEGA2560__) || defined(__ATMEG328P__) || defined(__ATMEGA328PB__)
#include <mega_hw_usart0_async.h>

#include <mega_hw_usart_sync_low_size.h>
#include <mega_hw_usart0_async_low_size.h>
#endif
#if defined(__ATMEGA2560__) || defined(__ATMEGA328PB__)
#include <mega_hw_usart1_async.h>

#include <mega_hw_usart1_async_low_size.h>
#endif

#if defined(__ATMEGA2560__)
#include <mega_hw_usart2_async.h>
#include <mega_hw_usart3_async.h>

#include <mega_hw_usart2_async_low_size.h>
#include <mega_hw_usart3_async_low_size.h>
#endif

