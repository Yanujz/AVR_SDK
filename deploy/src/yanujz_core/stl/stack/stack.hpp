/*
	

	Author : Yanujz

	Created in : 01/12/2020

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
#include <stdio.h>
#include "../list/list.h"
#include "../err/err.h"

namespace yanujz {

template <typename T, unsigned int MAX_SIZE>
class stack
{
public:
    stack() {}
    std_err push(T data)
    {
        if(MAX_SIZE == _size) return std_err::ERR_MAX_SIZE;

        std_err ret = _list.push_front(data);
        ++_size;
        return ret;
    }

    T pop()
    {
        T temp;
        if(0 == _size) return temp;

         temp = *_list.front();
        _list.pop_front();
        --_size;
        return temp;
    }

    unsigned int size()
    {
        return _size;
    }

private:
    unsigned int _size = 0;
    sl_list<T> _list;
};

}
