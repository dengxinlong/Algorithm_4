#ifndef __DOUBLE_LINK_LIST_H__
#define __DOUBLE_LINK_LIST_H__

#include <iostream>

using std::cout;
using std::endl;

template<class T>
class Steque
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
    Steque()
    : _phead(nullptr)
    , _ptail(nullptr)
    , _sz(0)
    {}

    int size(void) const   {    return _sz; }

    bool isEmpty(void) const    {    return _phead == nullptr; }

    //头插法建立链表的顺序和输入输入数据的顺序相反
    void push(T item)
    {
        Node * old_phead = _phead;
        _phead = new Node;
        _phead->_item = item;
        if (!old_phead)
            _ptail = _phead;
        _phead->_next = old_phead;
        _sz++;
    }

    T pop(void)
    {
        Node * old_phead = _phead;
        _phead = _phead->_next;
        T item = old_phead->_item;
        if (!_phead)
            _ptail = nullptr;
        delete old_phead;
        _sz--;
        return item;
    }

    void enqueue(T item)
    {
        Node * old_ptail = _ptail;
        _ptail = new Node;
        _ptail->_item = item;
        if (!old_ptail)
            _phead = _ptail;
        else
            old_ptail->_next = _ptail;
        _sz++;
    }

    void print(void)
    {
        Node * ptr = _phead;
        while (ptr)
        {
            cout << ptr->_item << " ";
            ptr = ptr->_next;
        }
        cout << endl;
    }


private:    
    Node * _phead;
    Node * _ptail;
    int _sz;
};










#endif