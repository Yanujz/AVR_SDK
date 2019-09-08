#include <pins.h>

/* Blink Example
 *

*/



int main(){

	pinMode(PIN::IO13, OUTPUT);

	while (1) {
		digitalToggle(PIN::IO13);
		_delay_ms(500);
	}

	return 0;
}

