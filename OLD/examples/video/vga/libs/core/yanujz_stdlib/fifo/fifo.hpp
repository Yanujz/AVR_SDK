#ifndef FIFO_H
#define FIFO_H
#include <macros.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

template<class T, int LEN>
class Fifo
{
public:
	Fifo(bool overwrite = false){
		_read_offset = -1;
		_write_offset = -1;
		this->overwrite = overwrite;
	}
	~Fifo(){}

	void push(T value){

		bool goBack = false;
		_write_offset = (_write_offset + 1);

		if (_read_offset < 0) {
			goBack = _write_offset >= LEN;
			_write_offset %= LEN;
		} else {
			_write_offset %= LEN;
			goBack = _write_offset == _read_offset;
		}

		if (goBack) {
			if(--_write_offset < 0){
				_write_offset = LEN - 1;
			}
			if (false == overwrite) return;
		}

		arr[_write_offset] = value;
	}

	T pop(){
		_read_offset = (_read_offset + 1) % LEN;
		return arr[_read_offset];
	}

	bool isEmpty(){
		if(_read_offset == _write_offset){
			return true;
		}
		return false;
	}
	void setOverwrite(bool value){
		overwrite = value;
	}
	void reset(){
		_read_offset = -1;
		_write_offset = -1;
	}
	int getUnreadElement(){
		return toABS(_write_offset - _read_offset);
	}
private:
	bool overwrite;
	int _read_offset;
	int _write_offset;
	T arr[LEN];
};




#endif // FIFO_H
