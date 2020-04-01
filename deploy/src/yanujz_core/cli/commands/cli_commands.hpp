/*
	

	Author : Yanujz

	Created in : 01/11/2020

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
#include <stdint.h>
#include <stdio.h>
#include "../../utils/utils.h"
#include "../../defines/defines.h"
#include <assert.h>

typedef int (*cmd_func)(int argc, char** argv);
#define MAX_CMD_LEN 16
struct cmd_t {
    const char name[MAX_CMD_LEN];
    cmd_func func;
};


namespace cmd_table {

enum err
{
    ERR_OK,
    ERR_COLLISION,
    ERR_OUT_OF_TABLE,
    ERR_NOT_EMPTY
};
enum add_policy
{
    SKIP,
    IGNORE,
    OVERWRITE
};
}

/* @param SIZE test
*/
template <int SIZE>
class CmdTable
{
        static_assert(
    IS_POWER_OF_TWO(SIZE)
    , "You must use a power of two");

public:

    CmdTable(cmd_table::add_policy policy = cmd_table::add_policy::SKIP)
    {
        _policy = policy;
    }

    cmd_table::err add(cmd_t cmd){
        coordinates coord = get_tuple(cmd.name);
        if(coord.y > (SIZE - 1) || coord.x > (SIZE - 1)){
            return cmd_table::err::ERR_OUT_OF_TABLE;
        }

        bool isEmpty = (nullptr == jump_table[coord.y][coord.x]);

        if((cmd_table::add_policy::SKIP == _policy) && (false == isEmpty)) return cmd_table::err::ERR_NOT_EMPTY;

        jump_table[coord.y][coord.x] = cmd.func;
        return cmd_table::err::ERR_OK;
    }

    cmd_func get(const char* cmd)
    {
        coordinates coord = get_tuple(cmd);
        return (cmd_func)jump_table[coord.y][coord.x];
    }
    void set_add_policy(cmd_table::add_policy policy = cmd_table::add_policy::SKIP)
    {
        _policy = policy;
    }
private:
    cmd_func jump_table[SIZE][SIZE] = {{nullptr}};
    cmd_table::add_policy _policy = cmd_table::add_policy::SKIP;

    struct coordinates {
        int y;
        int x;
    };

    coordinates get_tuple(const char* str)
    {
        coordinates temp;
        int size    = strlen(str);
        temp.y      = CRC8((uint8_t*)str,
                           size / 2) & (SIZE - 1);

        temp.x      = CRC8((uint8_t*)str + (size / 2),
                            size - (size / 2)) & (SIZE - 1);

        return temp;
    }
};
