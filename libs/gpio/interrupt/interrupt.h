#ifndef INTERRUPT_H
#define INTERRUPT_H
#include <portmanager.h>
#include <timer.h>
#define ELEMENT_IN_ARRAY(x)  (*(&x + 1) - x)
#define is_bit_on(var, i) ((var)&(1<<(i)))
typedef void int_cb_t(uint8_t pin);

enum INT_EDGE:uint8_t{
    LOW_LEVEL,
    RISING,
    FALLING,
    POSITIVE_EDGE,
    NEGATIVE_EDGE,
    ANYEDGE
};

enum PCINTx_vect:uint8_t{
    _PCINT0_vect,
    _PCINT1_vect,
    _PCINT2_vect,
};

enum INTx_vect:uint8_t{
    _INT0_vect,
    _INT1_vect,
    _INT2_vect,
    _INT3_vect,
    _INT4_vect,
    _INT5_vect,
};
enum ISCx_INT:uint8_t{
    INT0_LOW_LEVEL	= 0x00, INT1_LOW_LEVEL	= (0x00<<2), INT2_LOW_LEVEL	= (0x00<<4), INT3_LOW_LEVEL		= (0x00<<6),
    INT0_ANY_EDGE		= 0x01, INT1_ANY_EDGE		= (0x01<<2), INT2_ANY_EDGE		 = (0x01<<4), INT3_ANY_EDGE			=	(0x01<<6),
    INT0_FALLING_EDGE = 0x02, INT1_FALLING_EDGE	= (0x02<<2), INT2_FALLING_EDGE = (0x02<<4), INT3_FALLING_EDGE	= (0x02<<6),
    INT0_RISING_EDGE	= 0x03, INT1_RISING_EDGE	= (0x03<<2), INT2_RISING_EDGE	 = (0x03<<4), INT3_RISING_EDGE	= (0x03<<6),

    INT4_LOW_LEVEL		= 0x00, INT5_LOW_LEVEL		= (0x00<<2), INT6_LOW_LEVEL		 = (0x00<<4), INT7_LOW_LEVEL		= (0x00<<6),
    INT4_ANY_EDGE			=	0x01, INT5_ANY_EDGE			=	(0x01<<2), INT6_ANY_EDGE		 = (0x01<<4), INT7_ANY_EDGE		  = (0x01<<6),
    INT4_FALLING_EDGE = 0x02, INT5_FALLING_EDGE	= (0x02<<2), INT6_FALLING_EDGE = (0x02<<4), INT7_FALLING_EDGE = (0x02<<6),
    INT4_RISING_EDGE	= 0x03, INT5_RISING_EDGE	= (0x03<<2), INT6_RISING_EDGE	 = (0x03<<4), INT7_RISING_EDGE	= (0x03<<6),
};

enum INT_PIN_RES:uint8_t{
    NOT_FOUND,
    _PCINT,
    _INT
};


/* +--------------+---------------+---------------+
 * | PCINT0_vect	| PCINT1_vect	  | PC_INT2_vect	|
 * +--------------+---------------+---------------+
 * | PCINT0 - P53 | PCINT08 - P06 | PCINT16 - P62 |
 * | PCINT1 - P52 | PCINT09 - P15 | PCINT17 - P63 |
 * | PCINT2 - P51 | PCINT10 - P14 | PCINT18 - P64 |
 * | PCINT3 - P50 | PCINT11 - P-- | PCINT19 - P65 |
 * | PCINT4 - P10 | PCINT12 - P-- | PCINT20 - P66 |
 * | PCINT5 - P11 | PCINT13 - P-- | PCINT21 - P67 |
 * | PCINT6 - P12 | PCINT14 - P-- | PCINT22 - P68 |
 * | PCINT7 - P13 | PCINT15 - P-- | PCINT23 - P69 |
 * +--------------+---------------+---------------+
 * +-----------------+-----------------+------------------+------------------+-----------------+----------------+
 * |      INT0       |      INT1       |      INT2        |      INT3        |      INT4       |      INT5      |
 * +-----------------+-----------------+------------------+------------------+-----------------+----------------+
 * | INT0_vect - P21 | INT1_vect - P20 | INT2_vect - P19  | INT3_vect - P18  | INT4_vect - P2  | INT5_vect - P3 |
 * +-----------------+-----------------+------------------+------------------+-----------------+----------------+
 *
 *
*/
#pragma push(1)
struct INT_REG_CALLBACK{
    //INT_REG_CALLBACK(uint8_t,uint8_t,uint8_t,uint8_t,uint8_t,uint8_t,uint8_t,uint8_t,uint8_t,uint8_t
    //								 ,uint8_t,uint8_t,uint8_t,uint8_t,uint8_t,uint8_t,uint8_t,uint8_t,uint8_t,uint8_t,uint8_t){
    //	*pe0 = 0;*pe1 = 0;*ph3 = 0;*pj0 = 0;*pj1 = 0;*pb0 = 0;*pb1 = 0;*pb2 = 0;*pb3 = 0;*pb4 = 0;
    //	*pb5 = 0;*pb6 = 0;*pb7 = 0;*pk0 = 0;*pk1 = 0;*pk2 = 0;*pk3 = 0;*pk4 = 0;*pk5 = 0;*pk6 = 0;
    //	*pk7 = 0;
    //}
    volatile int_cb_t *pe0 = nullptr;
    volatile int_cb_t *pe1 = nullptr;
    volatile int_cb_t *ph3 = nullptr;
    volatile int_cb_t *pb4 = nullptr;
    volatile int_cb_t *pb5 = nullptr;
    volatile int_cb_t *pb6 = nullptr;
    volatile int_cb_t *pb7 = nullptr;
    volatile int_cb_t *pj1 = nullptr;
    volatile int_cb_t *pj0 = nullptr;
    volatile int_cb_t *pb3 = nullptr;
    volatile int_cb_t *pb2 = nullptr;
    volatile int_cb_t *pb1 = nullptr;
    volatile int_cb_t *pb0 = nullptr;
    volatile int_cb_t *pk0 = nullptr;
    volatile int_cb_t *pk1 = nullptr;
    volatile int_cb_t *pk2 = nullptr;
    volatile int_cb_t *pk3 = nullptr;
    volatile int_cb_t *pk4 = nullptr;
    volatile int_cb_t *pk5 = nullptr;
    volatile int_cb_t *pk6 = nullptr;
    volatile int_cb_t *pk7 = nullptr;

    INT_EDGE pe0_edge;
    INT_EDGE pe1_edge;
    INT_EDGE ph3_edge;
    INT_EDGE pj0_edge;
    INT_EDGE pj1_edge;
    INT_EDGE pb0_edge;
    INT_EDGE pb1_edge;
    INT_EDGE pb2_edge;
    INT_EDGE pb3_edge;
    INT_EDGE pb4_edge;
    INT_EDGE pb5_edge;
    INT_EDGE pb6_edge;
    INT_EDGE pb7_edge;
    INT_EDGE pk0_edge;
    INT_EDGE pk1_edge;
    INT_EDGE pk2_edge;
    INT_EDGE pk3_edge;
    INT_EDGE pk4_edge;
    INT_EDGE pk5_edge;
    INT_EDGE pk6_edge;
    INT_EDGE pk7_edge;

    volatile int_cb_t *pd0 = nullptr;
    volatile int_cb_t *pd1 = nullptr;
    volatile int_cb_t *pd2 = nullptr;
    volatile int_cb_t *pd3 = nullptr;
    volatile int_cb_t *pe4 = nullptr;
    volatile int_cb_t *pe5 = nullptr;
    INT_EDGE pd0_edge;
    INT_EDGE pd1_edge;
    INT_EDGE pd2_edge;
    INT_EDGE pd3_edge;
    INT_EDGE pe4_edge;
    INT_EDGE pe5_edge;
};


struct PCINT_PIN{
    uint8_t mappedPin;
    uint8_t PCINTx_vect;
    uint8_t PCINTx;
    volatile int_cb_t **interruptCallback;
    INT_EDGE *px_edge;
};
struct HW_INT_PIN{
    uint8_t mappedPin;
    uint8_t EICRx;
    volatile int_cb_t **interruptCallback;
    INT_EDGE *px_edge;
    ISCx_INT lowLevel;
    ISCx_INT anyEdge;
    ISCx_INT falling;
    ISCx_INT rising;
    uint8_t bitField;

};
#pragma pop

class Interrupt
{
public:
    static bool attachInterrupt(uint8_t pin, INT_EDGE edge, int_cb_t *func);
    static bool deatchInterrupt(uint8_t pin);
    static INT_REG_CALLBACK interruptCallback;
private:
    static void initInterrupt();
    static INT_PIN_RES searchPin(uint8_t pin, PCINT_PIN *_pin, HW_INT_PIN *_pinHW);
};


#endif // INTERRUPT_H