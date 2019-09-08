#include <pins.h>
#include <interrupt.h>
#include <system_clock.h>
#include <hardware_usart.h>
#include <hardware_spi.h>
#include <hardware_i2c.h>
#include <streams.h>
//#include <crc_utils.h>
//#include <console.h>

//#include <mega_hw_usart_sync_low_size.h>

/*

void rxReceive(u8t byte){
	usart_print(USART1, byte);
	if('\r' == byte){
	usart_print(USART1, '\n');
	}
	if(byte == 'A'){
	asyncUsart0.startAsyncSend();

	}
}


void txComplete(u8t  byte){
	usart_print(USART1, "Complete\r\n");
}
*/


int main()
{
  sys_clock_init();
  u8t arr[] = {0xFF, 0xEE, 0xDD, 0xCC};
  //i2c_master_init(I2C0);
  //masterI2C0.begin(F_SCL::SCL_500KHZ);
  pinMode (PIN::IO12, OUTPUT);
  pinMode (PIN::IO13, OUTPUT);

  //i2c_master_init(ASYNC_I2C0);
  //i2c_master_push_tx_fifo(ASYNC_HW_MASTER_I2C0_TX_FIFO, "hello");
  //i2c_master_asyncSend(ASYNC_I2C0, 0xAA);
		usart_init (USART3, HW_UART::BAUD115200);
  u8t i = 0;
  while (true) {
	//shiftOut(PIN::IO13, PIN::IO12, DATA_ORDER::MSB, CLOCK_EDGE::RISING, arr[i++ % sizeOfArray(arr)]);
	usart_print (USART3, "ciao\r\n");
		digitalToggle (PIN::IO13);
	//fastShiftOut (PIN::IO13, PIN::IO12, 0b10110011);
	//masterI2C0.start (0xAA);
	//masterI2C0.send(arr, sizeOfArray(arr));
	//masterI2C0.stop ();

	//i2c_master_start(I2C0, 0xAA);
	//i2c_master_send(I2C0, &arr[0], sizeOfArray(arr));
	//i2c_master_stop(I2C0);
	_delay_ms(128);
  }
}

