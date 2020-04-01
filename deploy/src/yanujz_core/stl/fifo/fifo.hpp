/*
	

	Author : Yanujz

	Created in : 01/09/2020

    Copyright (C) 2020  Yanujz

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

	You may contact the author by:
		e-mail: yanujz@live.it
*/
#pragma once
#include "../../defines/defines.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

namespace yanujz {

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
        return (_read_offset == _write_offset);
    }
    void setOverwrite(bool value){
        overwrite = value;
    }
    void reset(){
        _read_offset = -1;
        _write_offset = -1;
    }
    int getUnreadElement(){
        return ABS(_write_offset - _read_offset);
    }
    private:
    bool overwrite;
    int _read_offset;
    int _write_offset;
    T arr[LEN];
    };
}

