#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <iostream>

using namespace std;

template<class T>
class Queue
{
public:
    Queue(int cap)
    : _nums(new T[cap])
    , _sz(0)
    , _cap(cap)
    , _front(0)
    , _last(0)
    {}

    int size(void)  {   return _sz; }
    bool isEmpty(void) const { return _sz == 0; }

    bool full(void) const { return (_last + 1) % _cap == _front; }

    void enqueue(T item)    
    {
        _nums[_last] = item;
        _last = (_last + 1) % _cap;
        _sz++;
    }

    T dequeue(void)
    {
        T item = _nums[_front];
        _front = (_front + 1) % _cap;
        _sz--;
        return item;
    }

    void print(void)
    {
        for (int i = _front; i != _last; i = (i + 1) % _cap)
            cout << _nums[i] << " ";
        cout << endl;
    }

private:
    T * _nums;
    int _sz;
    int _cap;
    int _front;
    int _last;
};










#endif