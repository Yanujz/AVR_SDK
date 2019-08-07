#ifndef SERIAL_H
#define SERIAL_H
#include <avr/interrupt.h>
#include <util/setbaud.h>
#include <stdio.h>
#include <systemevent.h>
#include <printf.h>
#include <core.h>
///@file

/**
  * !!!Warning!!!
  * Variable "volatile u8t* UCSRxA" is used into define written into "[mcu_family]_common.h" file.
  * It's just a trick in preprocessor to make code more readable.
  * So please don't change name of it or change it according new value!
  * Filename Ex: "mega_common.h"
*/


class Serial
{
public:
    virtual void begin(HW_UART baud) = 0;
    void end();
    void printf(const char *fmt, ...);
    void print(const char* str);
    void print(char c);
    void write(const char* buff, int size);
    void readUntil(char *buffer, char chr);
    void flush();
    bool isAvailable();
    char receive();

protected:
    Serial(){}
    void init(HW_UART baud);

    volatile u8t* UCSRxA;
};



#endif // SERIAL_H
