#ifndef __QUEUE_LINK_H__
#define __QUEUE_LINK_H__

template<class T>
class Queue
{
private:
    class Node
    {
    public:
        Node()
        : _next(nullptr)
        { }

    public:
        T _item;
        Node * _next;
    };

public:
    Queue()
    : _first(nullptr)
    , _last(nullptr)
    , _sz(0)
    { }

    void enqueue(T item)
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

    T dequeue(void)
    {
        Node * old_first = _first;
        T item = _first->_item;
        _first = _first->_next;
        if (!_first)
            _last = _first;
        _sz--;
        delete old_first;
        return item;
    }

    int size(void) const { return _sz;  }

    bool isEmpty(void) const {  return _sz == 0;    }

private:
    Node * _first;
    Node * _last;
    int _sz;
};












#endif 