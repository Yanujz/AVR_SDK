#include <iostream>
#include <stdio.h>
#include <math.h>

int main(){
	int adc = 512.0;
	float adcQuantum = 5.0/1024.0;

	while(adc){
	//float sensorValue =  65 * pow(1.0 / ((float)adc*(5.0/1024.0)), 1.10);
	float sensorValue = 65 * pow((204.8/(float)adc), 1.1);

	printf("Adc Value : %d  cm : %f\n", adc, sensorValue);
	adc--;
	}

	return 0;
}

/*

2266.1 * (1/x)^1.1

65 * pow((204.8/(float)adc), 1.1)

*/