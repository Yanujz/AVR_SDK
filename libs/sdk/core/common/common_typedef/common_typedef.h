#pragma once
#include <stdint.h>
#include <stdlib.h>

namespace core {
/**
	* @brief Shortname of uint8_t
	*/
using u8t = uint8_t;
using u8 = uint8_t;

/**
	* @brief Shortname of uint16_t
	*/
using u16t = uint16_t;
using u16 = uint16_t;

/**
	* @brief Shortname of uint32_t
	*/
using u32t = uint32_t;
using u32 = uint32_t;

/**
	* @brief Shortname of uint64_t
	*/
using u64t = uint64_t;
using u64 = uint64_t;

/**
	* @brief Shortname of unsigned int
	*/
using uint = unsigned int;



using spi_cb_t = void();

//typedef void ser_cb_t();
using ser_cb_t = void(u8t);
using i2c_cb_t = void(u8t);


namespace IO {

typedef enum {
  INPUT,
  OUTPUT,
  INPUT_PULLUP
} DDRx;

typedef enum {
  LOW, HIGH
} LOGIC_STATE;

using int_cb_t = void (u8t);

enum INT_EDGE: u8t{
  LOW_LEVEL,
  ANY_EDGE,
  FALLING,
  RISING
};

}

}
using namespace core;
