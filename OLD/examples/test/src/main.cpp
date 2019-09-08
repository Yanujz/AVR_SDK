//#include <new>
#include <vector>
#include <string>
#include <portmanager.h>
#include <test.h>
#include <strutil.h>


int main(){
	Pin pin(13,OUTPUT);
std::string ciao("ciao");
std::vector<uint8_t> v;
Serial *serial0 = SerialManager::getInstance(SERIAL0);
serial0->init(BAUD_1000000);
serial0->setRxISRCallBack(false);
serial0->setEchoServer(false);
serial0->clear();
Test test;
std::string x("ciao");
to_upper(x);
while(1){
	test.hello();
_delay_ms(500);
}
//a.push_back(50);
}
