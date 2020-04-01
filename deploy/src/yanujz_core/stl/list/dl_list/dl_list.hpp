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
#include <stdint.h>
#include "../../err/err.h"


namespace yanujz {
template<class T>
class dl_list {
private:
    struct Node
    {
        Node *prev;
        T data;
        Node *next;
    };
public:
    dl_list()
    {
        _tail  = _head;
    }

    ~dl_list()
    {
        clear();
    }

    std_err push_front(T data)
    {
        Node* new_node = new Node;
        if(nullptr == new_node) return std_err::ERR_CANT_ALLOC;

        new_node->prev = nullptr;
        new_node->data = data;
        new_node->next = nullptr;

        if(_head == nullptr)
        {
            _head = new_node;
            _tail = new_node;
            ++_size;
            return std_err::ERR_OK;
        }

        _head->prev = new_node;
        new_node->next = _head;
        _head = new_node;

        ++_size;
        return std_err::ERR_OK;
    }

    std_err pop_front()
    {
        Node* temp = _head->next;
        free(_head);
        _head = temp;
        --_size;
        return  std_err::ERR_OK;
    }


    std_err push_back(T data)
    {

        Node* new_node = new Node;
        if(nullptr == new_node) return std_err::ERR_CANT_ALLOC;

        //Node *last = _head;
        Node *last = _tail;

        new_node->prev = last;
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

    std_err pop_back()
    {
        free(_tail);
        _tail = get_node(_size - 2);
        _tail->next = nullptr;
        --_size;
        return  std_err::ERR_OK;
    }



    T* front()
    {
        return (nullptr == _head) ? nullptr : &_head->data;
    }

    T* back()
    {
        return (nullptr == _tail) ? nullptr : &_tail->data;
    }


    T* get(unsigned int n)
    {
        Node* node = get_node(n);
        if(node) return &node->data;

        return nullptr;
    }

    T* operator[](unsigned int n){
        return get(n);
    }

    bool empty()
    {
        return (0 == _size);
    }

    unsigned int size()
    {
        return _size;
    }

    void clear()
    {
        while (nullptr != _head->next)
        {
            Node *temp = _head->next;
            free(_head);
            _head = temp;
        }
    }

    std_err erase(unsigned int n)
    {
        std_err ret = check_range(n);
        if(std_err::ERR_OK != ret) return ret;

        if(0 == n) return pop_front();
        if((_size - 1) == n) return pop_back();

        Node* current = get_node(n);

        current->prev->next = current->next;
        current->next->prev = current->prev;

        free(current);
        --_size;
        return std_err::ERR_OK;
    }

    std_err insert(unsigned int n, T data)
    {
        std_err ret = check_range(n);
        if(std_err::ERR_OK != ret) return ret;

        if(0 == n) return push_front(data);
        if((_size - 1) == n) return push_back(data);

        Node* new_node = new Node;
        if(nullptr == new_node) return std_err::ERR_CANT_ALLOC;


        new_node->data = data;

        Node* prev = get_node(n);
        new_node->next = prev->next;
        new_node->prev = prev;
        prev->next->prev = new_node;
        prev->next = new_node;

        ++_size;
        return std_err::ERR_OK;
    }

    std_err swap(unsigned int dst, unsigned int src)
    {
        std_err ret = check_range(dst);
        if(std_err::ERR_OK != ret) return ret;
        ret = check_range(src);
        if(std_err::ERR_OK != ret) return ret;

        Node* _dst = get_node(dst);
        Node* _src = get_node(src);

        Node* _dst_next = _dst->next;
        Node* _dst_prev = _dst->prev;

        if(_dst->prev)
        {
            _dst->prev->next = _src;
        }

        if(_dst->next)
        {
            _dst->next->prev = _src;
        }

        if(_src->prev)
        {
            _src->prev->next = _dst;
        }

        if(_src->next)
        {
            _src->next->prev = _dst;
        }

        _src->prev = _dst_prev;
        _src->next = _dst_next;


        // Check for update _head and _tail
        if(0 == dst)
        {
            _head = _src;
        }

        if(_size - 1 == dst)
        {
            _tail = _src;
        }

        if(0 == src)
        {
            _head = _dst;
        }

        if(_size - 1 == src)
        {
            _tail = _dst;
        }

        return  std_err::ERR_OK;
    }

private:


    Node* _head = nullptr;
    Node* _tail;
    unsigned int _size = 0;

    std_err check_range(unsigned int n)
    {
        if(n > _size - 1){
            return std_err::ERR_NOT_IN_RANGE;
        }
        return std_err::ERR_OK;
    }

    Node* get_node(unsigned int n)
    {
        Node* temp = nullptr;
        std_err ret = check_range(n);
        if(std_err::ERR_OK != ret) return temp;

        // Checking iteration from tail
        unsigned int it_from_tail = (_size - 1) - n;
        if(it_from_tail < n){
            temp = _tail;
            for (unsigned int i = 0; i < it_from_tail; i++) {
                temp = temp->prev;
            }
            return temp;
        }

        temp = _head;
        for (unsigned int i = 0; i < n; i++) {
            temp = temp->next;
        }
        return temp;
    }

};



} // namespace yanujz

