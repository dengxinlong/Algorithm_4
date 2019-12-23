#ifndef __DOUBLE_LINK_LIST_H__
#define __DOUBLE_LINK_LIST_H__

#include <iostream>

using std::cout;
using std::endl;

template<class T>
class Deque
{
private:
    struct DoubleNode
    {
        DoubleNode()
        : _prior(nullptr)
        , _next(nullptr)
        {}

        DoubleNode * _prior;
        DoubleNode * _next;
        T _item;
    };

public:
    Deque()
    : _phead(nullptr)
    , _ptail(nullptr)
    , _sz(0)
    {}

    int size(void) const   {    return _sz; }

    bool isEmpty(void) const {    return _sz == 0;  }

    //向左端添加一个元素
    void push_left(T item)
    {
        DoubleNode * old_phead = _phead;
        _phead = new DoubleNode;
        _phead->_item = item;
        if (!_ptail)
            _ptail = _phead;
        else
        {
            _phead->_next = old_phead;
            old_phead->_prior = _phead;
        }
        _sz++;
    }

    //向右端添加一个元素
    void push_right(T item)
    {
        DoubleNode * old_ptail = _ptail;
        _ptail = new DoubleNode;
        _ptail->_item = item;
        if (!_phead)
            _phead = _ptail;
        else
        {
            old_ptail->_next = _ptail;
            _ptail->_prior = old_ptail;
        }
        _sz++;
    }

    //从左端删除一个元素
    T pop_left(void)
    {
        if (!_phead)
            return (T)0;
        DoubleNode * old_phead = _phead;
        _phead = _phead->_next;
        if (!_phead)
            _ptail = nullptr;
        else
            _phead->_prior = nullptr;
        T item = old_phead->_item;
        delete old_phead;
        _sz--;
        return item;
    }

    //从右端删除一个元素
    T pop_right(void)
    {
        if (!_phead)
            return (T)0;
        DoubleNode * old_ptail = _ptail;
        _ptail = old_ptail->_prior;
        if (!_ptail)
            _phead = nullptr;
        else
            _ptail->_next = nullptr;
        T item = old_ptail->_item;
        delete old_ptail;
        --_sz;
        return item;
    }

    void print(void)
    {
        DoubleNode * ptr = _phead;
        while (ptr)
        {
            cout << ptr->_item << " ";
            ptr = ptr->_next;
        }
        cout << endl;
    }


private:    
    DoubleNode * _phead;
    DoubleNode * _ptail;
    int _sz;
};










#endif