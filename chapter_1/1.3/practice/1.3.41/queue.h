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

        T _item;
        Node * _next;
    };

public:
    Queue()       //构造函数
    : _front(nullptr)
    , _rear(nullptr)
    , _sz(0)
    {}

    Queue(const Queue & rhs)            //拷贝构造函数
    : _front(nullptr)
    , _rear(nullptr)
    , _sz(0)
    {
        Node * ptr = rhs._front;
        while (ptr)
        {
            Node * old_rear = _rear;
            _rear = new Node;
            _rear->_item = ptr->_item;
            if (!old_rear)
                _front = _rear;
            else
                old_rear->_next = _rear;
            _sz++;
            ptr = ptr->_next;
        }
    }
    //只要显示提供了拷贝构造函数或者复制运算符函数，那么析构函数也要显示提供
    ~Queue()
    {
        Node * ptr = _front;
        while (ptr)
        {
            Node * after = ptr->_next;
            delete ptr;
            ptr = after;
        }
        // cout << "~Queue()" << endl;
    }

    bool isEmpty(void) const   {    return _sz == 0;    }
    int size(void) const    {   return _sz; }

    void enqueue(T item)
    {
        Node * old_rear = _rear;
        _rear = new Node;
        _rear->_item = item;
        if (!old_rear)
            _front = _rear;
        else
            old_rear->_next = _rear;
        _sz++;
    }

    T dequeue(void)
    {
        if (isEmpty())
            return T(0);
        Node * old_front = _front;
        T item = old_front->_item;
        _front = _front->_next;
        if (!_front)
            _rear = nullptr;
        delete old_front;
        _sz--;
        return item;
    }

    Queue & operator=(const Queue & rhs)
    {
        if (&rhs == this)
            return *this;
        Node * ptr = rhs._front;
        while (ptr)
        {
            Node * old_rear = _rear;
            _rear = new Node;
            _rear->_item = ptr->_item;
            if (!_front)
                _front = _rear;
            else
                old_rear->_next = _rear;
            _sz++;
            ptr = ptr->_next;
        }
        return *this;
    }

    void print(void)
    {
        Node * ptr = _front;
        while (ptr)
        {
            cout << ptr->_item << " ";
            ptr = ptr->_next;
        } 
        cout << endl;
    }

private:
    Node * _front;
    Node * _rear;
    int _sz;
};









#endif