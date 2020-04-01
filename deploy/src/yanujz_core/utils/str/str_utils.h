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
#include <stdio.h>
#include <stdint.h>
#include "../../defines/defines.h"
#include "../../ytype.h"

#include <string.h>

#include <ctype.h>

#if defined(__STL_SUPPORT__)
#include <string>
#include <vector>
#endif

///@file
namespace yanujz {
#if defined(__STL_SUPPORT__)
// convert case
std::string to_lower(std::string str);
std::string to_upper(std::string str);

char* to_lower(char* str);
char* to_upper(char* str);

// remove space & tabs from string
void filterWhite(std::string &str);

// check if string is numeric
bool isNumeric(const std::string &str);

inline std::string &ltrim(std::string &str);
inline std::string &rtrim(std::string &str);
std::string trim(std::string & str);

// split string by delimeters
std::vector<std::string> split(const std::string& str,char delim = ' ');
// count occurrence of char in string
size_t countOccurrences(const std::string& text, char c);

bool isset(const std::string &str);
bool isPrintableChar(char &c);
bool isBlankChar(char &c);

void removeChar(char *str, char chr);

#endif

size_t split(const char *src, char **&dst, const char *delim);

u8t hexByteStrToByte(const char* byteStr);


inline char *strToUpper(char *str)
{
    char* init = str;
    while (*str) {
        if(IS_IN_RANGE(*str, 'a', 'z'))
        {
            *str -= 0x20;
        }
        str++;
    }
    return init;
}

inline char *strToLower(char *str)
{
    char* init = str;
    while (*str) {
        if(IS_IN_RANGE(*str, 'A', 'Z'))
        {
            *str += 0x20;
        }
        str++;
    }
    return init;
}

}

