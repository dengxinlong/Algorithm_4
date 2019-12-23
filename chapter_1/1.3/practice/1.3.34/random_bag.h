#ifndef __RANDOM_BAG_H__
#define __RANDOM_BAG_H__

#include <stdlib.h>
#include <time.h>

#include <iostream>

using namespace std;

template<class T>
class RandomBag
{
public:
    RandomBag(int cap)
    : _sz(0)
    , _nums(new T[cap])
    , _cap(cap)
    , _helper(new T[cap])
    {}

    bool isEmpty(void) const {  return _sz == 0; }
    int size(void) const { return _sz;  }

    void add(T item)
    {
        if (size() == _cap)
            resize(_cap * 2);
        //_helper[_sz] = 1;
        _nums[_sz++] = item;
    }

    void print(void) const
    {
        for (int i = 0; i < _sz; ++i)
            cout << _nums[i] << " ";
        cout << endl;
    }

    void for_each(void)
    {
        srand(time(NULL));
        for ( int i = 0; i < _sz; )
        {
            int index =  (rand() % _sz);
            if (_helper[index] != -1)
            {
                cout << _nums[index] << " ";
                _helper[index] = -1;
                ++i;
            }
        }
        cout << endl;
        //对helper数组进行清空
        for (int i = 0; i < _sz; i++)
            _helper[i] = 0;
    }
    

private:
    void resize(int cap)
    {
        _cap = cap;
        T * temp = new T[cap];
        delete [] _helper;
        _helper = new T[cap];
        for (int i = 0; i < _sz; ++i)
            temp[i] = _nums[i];
        delete [] _nums;
        _nums = temp;
    }

    // int random(void)
    // {
    //     srand(time(NULL));
    //     return (rand() % _sz);
    // }
private:
    int _sz;
    T * _nums;
    int _cap;
    T * _helper;
};









#endif