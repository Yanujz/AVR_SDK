#ifndef TIMER_H
#define TIMER_H

#include "macros.h"
#include <avr/io.h>
//#include <vector.h>
//#include <avr/iom2560.h>
#include <avr/interrupt.h>
//#include <serial.h>
#include <util/atomic.h>
///@file
/*
typedef void func(void);
class Scheduler
{
public:

    static void init();
    static void addTask(func *task);
    static void removeTask();
    static void stop();
    static void start();
    static func *getTask(size_t index);
private:
    static yanujz::vector<func*> scheduler;
};


*/


struct Time{
    Time(){
        microSeconds    = 0;
       // milliSeconds    = 0;
       // seconds         = 0;
       // minutes         = 0;
       // hours           = 0;
       // days            = 0;
    }
    //Atm not used
    //float uSecComma;
    uint32_t microSeconds;
    /*uint16_t milliSeconds;
    uint16_t seconds     ;
    uint16_t minutes     ;
    uint16_t hours       ;
    uint16_t days        ;*/
};

class Timer{
public:
    //static Timer* getInstance();
    static void init();
    static void start();
    static void stop();
    static uint32_t now();
    static Time _time;

private:
    //Timer();
    static bool _isInit;
};



//uint16_t micros();
#endif // TIMER_H
