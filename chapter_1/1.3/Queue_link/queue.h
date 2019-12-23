#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <iostream>

using namespace std;

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
    : _first(nullptr)
    , _last(nullptr)
    , _N(0)
    {}

    bool isEmpty(void)  {   return _N == 0; }
    int size(void) { return _N;    }
    void enqueue(T item)
    {
        Node * old_last = _last;
        _last = new Node;
        _last->_item = item;
        if (isEmpty())  _first = _last;         //如果在此时插入队列，队列为空，需要将_first 置为和 _last相同
        else            old_last->_next = _last;
        _N++;
    }

    T dequeue(void)
    {
        Node * old_first = _first;
        _first = _first->_next;
        T item = old_first->_item;
        if (!_first)                        //如果删除队列中元素时，此时刚好队列中只有一个元素，需要将last的值也置为空，此时_first的值为nullptr
            _last = _first;
        _N--;
        delete old_first;
        return item;
    }

private:
    Node * _first, * _last;
    int _N;
};









#endif 