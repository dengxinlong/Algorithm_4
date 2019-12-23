#ifndef __LINK_LIST_H__
#define __LINK_LIST_H__

#include <iostream>

using namespace std;

template<class T>
class LinkList
{
private:
    struct Node
    {
        Node()
        : _next(nullptr)
        {}

        Node * _next;
        T _item;
    };

public:
    LinkList()
    : _first(nullptr)
    , _last(nullptr)
    , _sz(0)
    {}

    void push_back(T item)
    {
        Node * old_last = _last;
        _last = new Node;
        _last->_item = item;
        if (!_first)
            _first = _last;
        else
            old_last->_next = _last;
        _sz++;
    }

    int size(void) const {  return _sz; }

    //逆置整个链表，相当于采用头插法建立链表，之前往链表中插入元素时采用的尾插法
    //时间复杂度为O(N)，空间复杂度为O(1)
    // void reverse(void)
    // {
    //     if (size() <= 1)
    //         return;
    //     Node * next_first = nullptr;
    //     Node * new_first = nullptr;
    //     _last = _first;
    //     while (_first) 
    //     {
    //         next_first = _first->_next;
    //         _first->_next = new_first;
    //         new_first = _first;
    //         _first = next_first;
    //     }
    //     _first = new_first;
    // }

    //递归实现
    void reverse(void)
    {
        _last = _first;
        _first = reverse(_first);
    }
    
    void for_each(void)
    {
        Node * ptr = _first;
        while (ptr)
        {
            cout << ptr->_item << " ";
            ptr = ptr->_next;
        }
        cout << endl;
    }
private:
    Node * reverse(Node * first)
    {
        if (!first)
            return nullptr;
        if (!first->_next)
            return first;
        Node * next_first = first->_next;
        Node * rest = reverse(next_first);
        next_first->_next = first;
        first->_next = nullptr;
        return rest;
    }

private:
    Node * _first;
    Node * _last;
    int _sz;
};











#endif