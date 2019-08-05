#include <project.h>
#include <hardwareserial.h>


int main(){

	serial0.begin(HW_UART::BAUD1000000);
	while (1) {
		serial0.print("Hello World!\r\n");
		_delay_ms(500);
	}

	return 0;
}
