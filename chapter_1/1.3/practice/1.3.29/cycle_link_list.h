#ifndef __LINK_LIST_H__
#define __LINK_LIST_H__

#include <iostream>

using namespace std;

//利用环形链表实现一个队列，其实就是把first指针替换成last->_next值
template<class T>
class Queue
{
private:
    class Node
    {
    public:
        Node()
        : _next(nullptr)
        {}
    public:
        T _item;
        Node * _next;
    };

public:
    Queue()
    : _last(nullptr)
    , _sz(0)
    {}

    int size(void) const { return _sz; }

    bool isEmpty(void) const { return _last == nullptr; }

    void enqueue(T item)
    {
        Node * new_node = new Node;
        new_node->_item = item;
        if (!_last)
        {
            _last = new_node;
            _last->_next = _last;
        }
        else
        {
            new_node->_next = _last->_next;
            _last->_next = new_node;
            _last = new_node;
        }
        _sz++;
    }

    T dequeue(void)
    {
        Node * old_first = _last->_next;
        _last->_next = old_first->_next;
        T item = old_first->_item;
        if (old_first == _last)             //此时队列中只有一个结点
            _last = nullptr;
        delete old_first;
        _sz--;
        return item;
    }

    // void push_back(T item)
    // {
    //     Node * old_last = _last;
    //     _last = new Node;
    //     _last->_item = item;
    //     if (!_first)
    //         _first = _last;
    //     else
    //         old_last->_next = _last;
    //     _sz++;
    // }

    // bool remove(T item)
    // {
    //     Node * ptr = _first;
    //     Node * pfront = _first;
    //     int flag = 0;
    //     while (ptr)
    //     {
    //         if (ptr->_item == item)
    //         {
    //             //判断删除的结点是否是第一个结点
    //             if (ptr == _first)
    //                 _first = _first->_next;
    //             if (ptr == _last)           //删除的结点是否是最后一个结点
    //                 _last = pfront;
    //             pfront->_next = ptr->_next;
    //             delete ptr;
    //             _sz--;
    //             flag = 1;               //可能链表中有多个结点需要删除
    //         }
    //         pfront = ptr;
    //         ptr = ptr->_next;
    //     }

    //     return flag == 1;
    // }

    void for_each(void)
    {
        if (!_last)
            return;
        Node * ptr = _last->_next;
        while (ptr != _last)
        {
            cout << ptr->_item << " ";
            ptr = ptr->_next;
        }
        cout << ptr->_item << " ";
        cout << endl;
    }

private:
    Node * _last;
    int _sz;
};










#endif