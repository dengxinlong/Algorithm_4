#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <iostream>

using namespace std;

//顺序可扩展
//顺序可扩展队列必然会浪费存储空间，因为每次出队列后之前的空间就无法使用了，所以这里采用改进的方式，采用循环队列
// template<class T>
// class Queue
// {
// public:
//     Queue(int cap)
//     : _cap(cap)
//     , _queue(new T[cap])
//     , _front(0)
//     , _back(0)
//     { }

//     void enqueue(T item)
//     {
//         if (_back - _front == _cap)     //此时队列的大小等于初始大小，应该扩展整个队列的大小
//             resize(2 * _cap);
//         _queue[_back++] = item;
//     }

//     T dequeue(void)
//     {
//         //当队列中的元素过少时，采取缩小队列capacity措施
//         if (_bakc - _front > 0 && _back - _front == _cap / 4)
//             resize(_cap / 2);
//         return _queue[_front++];
//     }

//     int size(void) const {  return _back - _front; }

//     int isEmpty(void) const { return _front == _back;   }

// private:
//     void resize(int cap)
//     {
//         T * temp = new T[cap];
//         for (int i = _front; i != _back; i++)
//             temp[i] = _queue[i];
//         delete [] _queue;
//         _queue = temp;
//         _cap = cap;
//     }

// private:
//     T * _queue;   
//     int _cap;             //队列的capacity
//     int _front;
//     int _back;
// };


//循环可扩展队列
template<class T>
class Queue
{
public:
    Queue(int cap)
    : _queue(new T[cap])
    , _front(0)
    , _back(0)
    , _cap(cap)
    { }

    void enqueue(T item)
    {
        //如果此时队列中的元素已经到达了上限，则扩容
        if (full())
            resize(_cap * 2);
        _queue[_back] = item;
        _back = (_back + 1) % _cap;
    }

    T dequeue(void)
    {
        // if (!isEmpty() && size() = _cap / 4)
        //     resize(_cap / 2);
        T item = _queue[_front];
        _front = (_front + 1) % _cap;
        return item;
    }

    int size(void) const {   return (_back - _front + _cap) % _cap;  }

    bool isEmpty(void) const { return _back == _front;  }

    int capacity(void) const { return _cap; }

private:    
    bool full(void) const { return (_back + 1 ) % _cap == _front;   }

    void resize(int cap)
    {
        T * temp = new T[cap];
        //这里进行复制的时候需要判断_front和_back的关系
        if (_back > _front)
        {
            for (int i = _front; i < _back; ++i)
                temp[i] = _queue[i];
        }
        else
        {
            for (int i = 0; i < _back; ++i)
                temp[i] = _queue[i];
            for (int i = _cap - 1; i >= _front; i--)
                temp[i + _cap] = _queue[i];
            _front += _cap;
        }
        delete [] _queue;
        _queue = temp;
        _cap = cap;
    }

private:
    T * _queue;
    int _front;
    int _back;
    int _cap;
};









#endif