#pragma once
#include <core.h>

class StreamIn {
public:
    virtual u8t receive() = 0;
//protected:
	//StreamIn *streamIn_context;
};
