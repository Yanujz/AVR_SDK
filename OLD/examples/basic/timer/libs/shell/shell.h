#ifndef SHELL_H
#define SHELL_H
#include <hardwareserial.h>

class Shell : public SystemEventHandler
{
public:
	Shell(AsyncSerial &serial, HW_UART baud);
private:
	virtual void callback(u8t byte) override;
	void clear();
	AsyncSerial* serial;
};

#endif // SHELL_H
