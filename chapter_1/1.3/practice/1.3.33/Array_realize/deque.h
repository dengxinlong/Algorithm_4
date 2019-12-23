#ifndef __DEQUE_H__
#define __DEQUE_H__

#include <iostream>

using namespace std;

template<class T>
class Deque
{
public:
    Deque(int cap)
    : _cap(cap)
    , _deque(new T[cap])
    , _head(cap / 2)
    , _tail(cap / 2)
    , _sz(0)
    { }
    
    bool isEmpty(void) const { return _sz == 0; }
    int size(void) const { return _sz;  }
    void push_left(T item)
    {
        if (size() == 0)
            _tail++;
        if (_sz == _cap)
            resize(_cap * 2);
        _deque[_head--] = item;
        _sz++;
    }

    void push_right(T item)
    {
        if (size() == 0)
            _head--;
        if (_sz == _cap)
            resize(_cap * 2);
        _deque[_tail++] = item;
        _sz++;
    }

    T pop_left(void)
    {
        if (size() == 1)
            _tail--;
        _sz--;
        return _deque[--_head];
    }

    T pop_right(void)
    {
        if (size() == 1)
            _head--;
        _sz--;
        return _deque[--_tail];
    }

    void print(void)
    {
        for (int i = _head + 1; i < _tail; ++i)
            cout << _deque[i] << " ";
        cout << endl;
    }
private:
    void resize(int cap)
    {
        _cap = cap;
        T * temp = new T[cap];
        int i = (_tail - _head) / 2;
        for (int k = cap / 2; i > _head; --i, --k)
        {
            temp[k] = _deque[i];
        }
        for (int j = i + 1, k = cap / 2 + 1; j < _tail; ++j)
        {
            temp[k] = _deque[j];
        }
        delete [] _deque;
        _deque = temp;
    }
private:
    int _cap;
    T * _deque;
    int _head;
    int _tail;
    int _sz;
};







#endif