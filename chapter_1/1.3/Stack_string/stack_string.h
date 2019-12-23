#ifndef __STACK_STRING_H__
#define __STACK_STRING_H__

#include <stdlib.h>

#include <iostream>
#include <string>

using namespace std;

template<class T>
class FixedCapacityStackOfString
{
public:
    FixedCapacityStackOfString(int cap)
    : _N(0)
    , _cap(cap)
    {
        _a = new T[cap];
    }

    void push(T item) 
    {   
        if (_N == _cap)
            resize(_N * 2);
        _a[_N++] = item; 
    }

    T pop(void)    
    {   
        --_N;
        if (_N > 0 && _N == _cap / 4)
            resize(_cap / 2);
        return _a[_N];
    }

    bool isEmpty(void)  {   return _N == 0; }

    int size(void)  {   return _N;  }

private:
    void resize(int max)
    {
        _cap = max;                 //此时stack中的容量也需要实时更新，不然无法知道此时数组的容量是多少
        T * temp = new T[max];
        for (int i = 0; i < _N; ++i)
        {
            temp[i] = _a[i];
        }

        delete [] _a;
        _a = temp;
    }

private:
    T  * _a;
    int _cap;           //_cap用于描述数组_a的容量，也就是栈的容量
    int _N;
};






#endif