#include <pins.h>

/* Fade Example
 *
 * In this example we'll introduce PWM(Pulse Width Modulation).
 *
 * 5V   |‾‾‾‾|    |‾‾‾‾|    |‾‾‾‾|    |‾‾‾‾|
 *      |    |    |    |    |    |    |    |
 * 0V __|    |____|    |____|    |____|    |__
 *
 * Functions prototypes:
 *  void pinMode(PIN pin, DDRx dir);
 *  void setPWM(PIN pin, size_t freq, u8t duty);
*/

int main(){

    // Setting pin 13 as output
    pinMode(PIN::IO13, OUTPUT);
    u8t i = 0;

    while (1) {
        // Setting PWM in pin 13 with a frequency of 1000Hz and a variable duty in range 0 - 100
        setPWM(PIN::IO13, 1000, i++);
        if(i > 99) i = 0;
        _delay_ms(25);
    }
}
