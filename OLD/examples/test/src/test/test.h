#ifndef TEST_H
#define TEST_H
#include <serial.h>
class Test
{
public:
	Test();
	void hello();
private:
	Serial *serial0;
};

#endif
