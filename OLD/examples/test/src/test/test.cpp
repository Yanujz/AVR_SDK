#include "test.h"


Test::Test(){
serial0 = SerialManager::getInstance(SERIAL0);
}

void Test::hello(){
	serial0->printf("ciao dalla classe test\r\n");
}