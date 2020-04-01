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
#include <stdlib.h>
#include <stdint.h>
#include "../../err/err.h"



namespace yanujz {

template<class T>
class sl_list
{
private:
    struct Node
    {
        T data;
        Node *next;
    };

public:

    sl_list()
    {
        _tail  = _head;
    }
    ~sl_list()
    {
        clear();
    }

    std_err push_front(T data)
    {
        Node* new_node = new Node();
        if(nullptr == new_node) return std_err::ERR_CANT_ALLOC;

        new_node->data = data;
        new_node->next = nullptr;

        if(_head == nullptr)
        {
            _head = new_node;
            _tail = new_node;
            ++_size;
            return std_err::ERR_OK;
        }

        new_node->next = _head;
        _head = new_node;


        ++_size;
        return std_err::ERR_OK;
    }

    std_err pop_front(){
        Node* temp  = _head->next;
        free(_head);
        _head = temp;
        --_size;
        return std_err::ERR_OK;
    }

    std_err push_back(T data){

        Node* new_node = new Node();
        if(nullptr == new_node) return std_err::ERR_CANT_ALLOC;

        //Node *last = _head;
        Node *last = _tail;

        new_node->data = data;
        new_node->next = nullptr;


        if (_head == NULL)
        {
            _head = new_node;
            _tail = new_node;
            ++_size;
            return std_err::ERR_OK;
        }

        last->next = new_node;
        _tail = new_node;
        ++_size;
        return std_err::ERR_OK;
    }
    std_err pop_back(){
        free(_tail);
        _tail = get(_size - 2);
        _tail->next = nullptr;
        --_size;
        return  std_err::ERR_OK;
    }

    T* front(){
        return (nullptr == _head) ? nullptr : &_head->data;
    }
    T* back(){
        return (nullptr == _tail) ? nullptr : &_tail->data;
    }

    T* get(int n){
        if(n > _size - 1) return nullptr;
        Node* temp = _head;
        for (int i = 0; i < n; ++i) {
            temp = _head->next;
        }
        return &temp->data;
    }

    T* operator[](int n){
        return get(n);
    }

    bool empty(){
        return (0 == _size);
    }

    int size(){
        return _size;
    }

    void clear(){
        while (nullptr != _head->next)
        {
            Node *temp = _head->next;
            free(_head);
            _head = temp;
        }
    }


    std_err erase(int n){
        std_err ret = check_range(n);
        if(std_err::ERR_OK != ret) return ret;

        if(0 == n) return pop_front();
        if((_size - 1) == n) return pop_back();

        Node* prev = get(n - 1);
        Node* current = get(n);

        prev->next = current->next;
        free(current);
        --_size;

        return std_err::ERR_OK;
    }

    std_err insert(int n, T data){
        std_err ret = check_range(n);
        if(std_err::ERR_OK != ret) return ret;

        if(0 == n) return push_front(data);
        if((_size - 1) == n) return push_back(data);

        Node* new_node = new Node;
        if(nullptr == new_node){
            return std_err::ERR_CANT_ALLOC;
        }

        new_node->data = data;
        T prev = get(n);
        Node* temp = prev.next;

        prev.next = new_node;

        new_node->next = temp;
        ++_size;
        return std_err::ERR_OK;
    }








private:
    Node* _head = nullptr;
    Node* _tail;
    unsigned int _size = 0;

    std_err check_range(unsigned int n){
        if(n > _size - 1){
            return std_err::ERR_NOT_IN_RANGE;
        }
        return std_err::ERR_OK;
    }
};



} // namespace yanujz
