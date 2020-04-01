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
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

namespace yanujz {
template<typename T, int SIZE = 1>
class vector {
public:
    vector(){
    _size = 0;
    _value = (T*)malloc((_size * sizeof(T)));
    }
    vector(T *ptr, size_t size){
    _size = size;
    _value = (T*)malloc((_size * sizeof(T)));
    for(int i = 0; i < size; i++){
        _value[i] = ptr[i];
    }
    }
    ~vector(){
    if(_value != nullptr){
        free(_value);
    }
    }

    T getValue(T index){
    if(index > _size - 1){
        return 255;
    }
    return *(_value + index);
    }

    T first(){
    return *_value;
    }

    T last(){
    return *(_value + (_size-1));
    }

    T* begin() const{
    return _value;
    }
    T* end() const {
    return _value + (_size-1);
    }

    void pushLeft(T value){
    if( _value == nullptr ){
        return;
    }

    size_t _tempSize = _size * sizeof(T);
    T *temp = (T*) malloc( _tempSize );
    memcpy(temp, _value, _tempSize);

    ++_size;

    _value = reinterpret_cast<T*> (realloc( _value, _size * sizeof(T)-1 ));
    if(_value == nullptr){
        delete temp;
        return;
    }

    *_value  = value;

    memcpy(_value+1, temp, _tempSize);

    delete temp;
    }

    void pushLeft(T arr[],T size){
    if(_value == nullptr){
        return;
    }

    size_t _tempSize = _size*sizeof(T);
    T *temp = (T*)malloc(_tempSize);
    memcpy(temp, _value, _tempSize);


    _size += size;


    _value = reinterpret_cast<T*>(realloc(_value, _size * sizeof(T)));

    if(_value == nullptr){
        //printf("Can't realloc\r\n");
        delete temp;
        return;
    }

    memcpy(_value, arr, size*sizeof(T));
    memcpy(_value + size, temp, _tempSize);
    }

    void pushRight(T value){
    if(_value == nullptr){
        return;
    }
    ++_size;
    _value = reinterpret_cast<T*> (realloc( _value,  _size * sizeof(T) ));
    if(_value== nullptr){
        return;
    }
    _value[_size - 1] = value;
    }

    void insert(size_t index,T arr[],size_t size){
    if(_value == nullptr){
        return;
    }

    size_t _tempSize = _size*sizeof(T);
    T *temp = (T*)malloc(_tempSize);
    memcpy(temp, _value, _tempSize);

    _size += size;


    _value = reinterpret_cast<T*> (realloc( _value, _size * sizeof(T)));

    if(_value == nullptr){
        free(temp);
        return;
    }

    memcpy(_value + index, arr, size*sizeof(T));

    memcpy(_value + size + index, temp + index, _tempSize);

    free(temp);
    }

    void insert(T *dst,T *srcStart,T *srcEnd){
    //if(_value == nullptr){
    //    return;
    //}
    //
    //size_t _tempSize = _size*sizeof(T);
    //T *temp = (T*)malloc(_tempSize);
    //memcpy(temp, _value, _tempSize);
    //
    //_size += size;
    //
    //
    //_value = reinterpret_cast<T*> (realloc( _value, _size * sizeof(T)));
    //
    //if(_value == nullptr){
    //    delete temp;
    //    return;
    //}
    //
    //memcpy(_value + index, arr, size*sizeof(T));
    //
    //memcpy(_value + size + index, temp + index, _tempSize);
    //
    //delete  temp;
    }
    void popRight(size_t value = 1){
    if(value > _size){
        return;
    }
    _size -= value;
    _value = reinterpret_cast<T*>(realloc(_value, (_size * sizeof(T)) ) );
    }
    void popLeft(size_t value = 1){
    if(value > _size){
        return;
    }
    _size -= value;
    memmove(_value, _value + value, _size*sizeof(T));
    _value = reinterpret_cast<T*>(realloc(_value, (_size * sizeof(T)) ) );
    }
    size_t size() const {
    return _size;
    }
    bool empty(){
    return size() == 0;
    }
    void clear(){
    _value = reinterpret_cast<T*>(realloc(_value, (0 * sizeof(T)) ) );
    }
    T* data(){
    return _value;
    }

    T at(size_t index) const {
    //if(index > _size){
    //    return 0;
    //}
    return _value[index];
    }

    //TODO Implementare gli operator
    T& operator[](size_t index){
    return _value[index];
    }
    //T& operator=( const vecTtor& other );
    //T& operator=(const vector<T> &a){
    //    memcpy(begin(),a.begin(),sizeof(T)*a.size());
    //    _size = a.size();
    //}
    //template <class T>
    vector<T>& operator=(const vector<T> &v)   {
    _size = v.size();
    if(_value !=  nullptr){
        //delete[] _value;
    }
    //_value = (T*) malloc( v.size() );
    _value = new T[v.size()];
    for(size_t i = 0; i < _size; i++)
        _value[i] = v.at(i);
    return *this;
    }
    //T operator=(std::initializer_list<T> list){
    //    for (int i : list) pushRight(i);
    //    //memcpy(_value,a,sizeof(a));
    //}


    bool operator==(const vector<T>&rhs){

    if(_size != rhs.size()){
        return false;
    }

    for(size_t i = 0; i < _size; ++i){
        if(this->at(i) != rhs.at(i)) {
        return false;
        }
    }

    return true;
    }

    bool operator!=(vector<T>&rhs){
    return !(*this == rhs);
    }


private:
    T *_value;
    size_t _size = SIZE;
};

}


