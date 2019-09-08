#include "timer.h"



//---------Scheduler Class---------//
/*
yanujz::vector<func*> Scheduler::scheduler;
void Scheduler::init()
{
    //WARNING Untested code

    TCCR2A = 0;// set entire TCCR2A register to 0
    TCCR2B = 0;// same for TCCR2B
    TCNT2 = 0;//initialize counter value to 0
    // set compare match register for 2khz increments
    OCR2A = 255;//244Hz
    OCR2B = 100;//488Hz

    TCCR2B |= (1 << CS22) |(1 << CS21) | (1 << CS20);

    sei();
    TIMSK2 |=  (1 << TOIE2);

}

void Scheduler::addTask(func *task)
{
    Scheduler::scheduler.pushRight(task);
}
void Scheduler::removeTask(){
    Scheduler::scheduler.popLeft();
}

void Scheduler::stop()
{
    TCCR2B &= ~((1<<CS02) | (1<<CS01) | (1<<CS00));

}

void Scheduler::start()
{
    TCCR2B |= (1 << CS22) |(1 << CS21) | (1 << CS20);
}
func *Scheduler::getTask(size_t index)
{
    return (func*)Scheduler::scheduler[index];
}

ISR(TIMER2_OVF_vect){
    //static uint16_t p = 0;
    //if(++p != 63){return;}
    //p = 0;
    Scheduler::stop();
    func *f = Scheduler::getTask(0);
    //Serial0::printf("Task to do : %p\r\n",f);
    Scheduler::removeTask();
    Scheduler::addTask(f);
    if(f != nullptr){
        f();
    }
    Scheduler::start();
};*/
//---------End Scheduler Class---------//


//---------Timer Class---------//

Time Timer::_time;
bool Timer::_isInit = false;
volatile u8t __microSecond = 0;

//Timer *Timer::getInstance()
//{
//    static Timer *timer = nullptr;
//    if(timer == nullptr){
//        timer = new Timer();
//    }
//    return timer;
//}

void Timer::init()
{

    TCCR0A  = 0;
    TCCR0B  = 0;
    TCNT0   = 0;
    OCR0A   = 255;
    TCCR0A |= (0 << COM0A1) | (0 << COM0A0)|( 1 << WGM01);
    TCCR0B |= (0 << FOC0A) | (0 << CS02) | (0 << CS01) | (0 << CS00);
    TIMSK0  = (0 << TOIE0) | (1 << OCIE0A);
    sei();
    _isInit = true;

}

void Timer::start()
{
    if(_isInit == false){
        init();
    }
    _time.microSeconds	= 0;
    TCCR0B |= (0 << CS02) |(0 << CS01) | (1 << CS00);
    //TCNT0   = 255;

}

void Timer::stop()
{
    TCCR0B &= ~((1<<CS02) | (1<<CS01) | (1<<CS00));

}

u32t Timer::now()
{
    //return ((_time.microSeconds)+((1.0/F_CPU*1e6)*TCNT0));
    //_time.uSecComma = (0.0625*(float)TCNT0);
    return __microSecond;
}

//u8t ovfl_count __attribute__ ((section (".bss")));
volatile u8t ovfl_count = 0;
volatile u32t __system_time;


//uint16_t micros()
//{
//    ATOMIC_BLOCK(ATOMIC_FORCEON){
//        //Serial *serial0 = SerialManager::getInstance(SERIAL0);
//        //serial0->printf("Dentro micros\r\n");
//        return (ovfl_count*16)+((TCNT0 >> 4)+((TCNT0 >>3) & 1)>>1);
//        //return ovfl_count*16;
//        //return (TCNT0 >> 4)+((TCNT0 >>3) & 1);
//    }
//
//}

//ISR(TIMER0_COMPA_vect){
//     ovfl_count++;
//}

//---------End Timer Class---------//
