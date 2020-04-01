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


namespace yanujz {

class string
{
public:
    string();
    string(const char* str);
	~string();

	const char* c_str() const;
	unsigned int size() const;

	const char &front() const;
	char &back() const;

    void concat(string &str);
    void concat(const char* str);

	int find_firsOf(const char* str);

	bool empty();

	void clear();

	void erase(unsigned int n);

    //operators
	bool operator=(string const &rhs);
	bool operator=(const char* rhs);

    string operator+(string &rhs);
    string operator+(const char* rhs);

    bool operator==(string &rhs);
	bool operator==(const char* str);

    void operator+=(string str);
    void operator+=(const char* str);

	char &operator[](int index) const;

private:
	char* _buf = nullptr;
    int _str_size;
    int _malloc_size;

    bool equal_assign(const char* rhs);
    bool equal(const char* str);
    string plus(const char* str);

};


} //namespace yanujz

