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
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "../../defines/defines.h"
#include "../list/list.h"
#include "../../utils/crc/crc_utils.h"

namespace yanujz {
template <typename T, typename D>
class hashable
{
public:
    hashable();
    virtual T getKey() = 0;
    virtual D getValue() = 0;
};



template <typename KEY, typename VALUE, int SIZE>
class hashmap {
public:
    hashmap(){}
    bool exists(KEY  key, int size){
         int ret = hash(key, size);
         if(buf[ret][0]){
             return true;
         }
         return false;
    }

    void put(KEY key, int size, VALUE val){
        int ret = hash(key, size);
        printf("put key: %s hash: 0x%02X\n", key, ret);

        buf[ret].push_back(val);
    }

    VALUE* get(KEY key, int size){
        int ret = hash(key, size);
        //printf("get Hash: 0x%02X %d\n", ret, SIZE);
        if(ret > SIZE - 1) {
            return nullptr;
        }

        int _list_size = buf[ret].size();
        if( _list_size > 1){
            // Iterate into list
            for (int i = 0; i < _list_size; ++i) {
                int retval = memcmp(key, buf[ret][i].getKey(), size);
                if( 0 == retval){
                    return buf[ret][i];
                }
            }
            return nullptr;
        }
        return buf[ret][0];
    }

private:
    int hash(const void* data, int size){
        return CRC8((uint8_t*)data, size) & MASK_FROM_VAL(SIZE);
    }

    dl_list<VALUE> buf[SIZE];
};
}
