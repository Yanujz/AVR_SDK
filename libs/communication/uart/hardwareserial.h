#ifndef HARDWARESERIAL_H
#define HARDWARESERIAL_H
#if defined(__AVR_ATmega328P__) ||  defined(__AVR_ATmega640__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
#include <asyncserial0.h>
#endif
#if defined(__AVR_ATmega640__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
#include <asyncserial1.h>
#include <asyncserial2.h>
#include <asyncserial3.h>
#else
#include <asyncserial0.h>
#include <asyncserial1.h>
#include <asyncserial2.h>
#include <asyncserial3.h>
#endif


#endif // HARDWARESERIAL_H
