#pragma once
#include <core.h>
#if defined(__MEGA_SERIES__)
#include <util/twi.h>
#include <avr/interrupt.h>


/*

static void (*I2C_recv)(uint8_t);
static void (*I2C_req)();

void I2C_setCallbacks(void (*recv)(uint8_t), void (*req)())
{
  I2C_recv = recv;
  I2C_req = req;
}

void I2C_init(uint8_t address)
{
  cli();
  // load address into TWI address register
  TWAR = address << 1;
  // set the TWCR to enable address matching and enable TWI, clear TWINT, enable TWI interrupt
  TWCR = (1<<TWIE) | (1<<TWEA) | (1<<TWINT) | (1<<TWEN);
  sei();
}

void I2C_stop(void)
{
  // clear acknowledge and enable bits
  cli();
  TWCR = 0;
  TWAR = 0;
  sei();
}
*/
#endif
