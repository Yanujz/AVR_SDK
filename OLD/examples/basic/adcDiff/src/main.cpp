#include "avr_sdk.h"

bool debug = false;



u16t getAvg(std::vector<u16t> & vect);
void calibrate();

Pin asd(A0, INPUT);
std::vector<u16t> arr;
float offset = 0;

int main(){

	Serial *serial  = SerialManager::getInstance(SERIAL0);
	serial->init(BAUD_1000000);
	serial->setRxISRCallBack(false);
	serial->setEchoServer(false);

	Pin asd0(A1, INPUT);

	for(u8t i = 0; i <20;++i ){
		arr.push_back(0);
	}

	float var;
	float newtown;
	float grams ;

	calibrate();
	while(1){
		//float val = (((asd.analogRead()*4.882813) - 2592.773700)*1);
		//serial->printf("%f\r\n", val);
		arr.erase(arr.begin());
		arr.push_back(asd.analogRead());
		var = (getAvg(arr)*4.882813 - offset)/160;
		serial->printf("var %f\r\n", var);
		newtown = var/0.015;
		//newtown = (var/1000)*5000/0.015;

		grams = newtown * 101.97162129779;
		serial->printf("%.03f mV %.03f N %.03f grams\r\n", var, newtown, grams );
		//int32_t var =  adc_compare(ADC_COMPARE::A1_A0_GAIN200);
		//serial->printf("ADC value : %f mV\r\n", var * 5000.0/(512.0 * 200));
		_delay_ms(100);

	}


}



u16t getAvg(std::vector<u16t> & vect){
	u16t var = 0;
	for(u8t i = 0; i < vect.size();++i ){
		var+= vect[i];
	}
	return var/vect.size();
}


void calibrate(){
	Serial *serial  = SerialManager::getInstance(SERIAL0);
	serial->printf("Calibrating please leave any weight\r\n");
	_delay_ms(1000);
	for(u8t i = 0; i < 255; ++i){
		arr.erase(arr.begin());
		arr.push_back(asd.analogRead());
	}
	offset = getAvg(arr)*4.882813;

	serial->printf("Calibration done\r\n");
	_delay_ms(1000);

}
