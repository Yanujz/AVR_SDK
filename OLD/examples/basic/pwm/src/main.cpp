#include <pins.h>

int main(){
    pinMode(PIN::IO13, OUTPUT);
    setPWM(PIN::IO13, 1000, 50);

	while (1) {
	}

	return 0;
}
