#ifndef __MOVE_TO_FRONT_H__
#define __MOVE_TO_FRONT_H__

#include <iostream>

using namespace std;

template<class T>
class MoveToFront
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
    MoveToFront()
    : _front(nullptr)
    , _rear(nullptr)
    , _sz(0)
    {}

    void insert(T item)
    {
        Node * ptr = find(item);
        if (!ptr)
        {
            if (_front && _front->_item == item)          //在第一个结点处找到
                return;
            Node * old_front = _front;
            _front = new Node;
            _front->_item = item;
            if (!old_front)
                _rear = _front;
            _front->_next = old_front;
        }
        else
        {
            Node * pcur = ptr->_next;
            ptr->_next = ptr->_next->_next;
            pcur->_next = _front;
            _front = pcur;
            if (pcur == _rear)    //需要调整的是最后一个结点，此时需要将rear的值指向尾结点的前驱
                _rear =  ptr;
        }
    }

    void print(void)
    {
        for (Node * ptr = _front; ptr; ptr = ptr->_next)
            cout << ptr->_item << " ";
        cout << endl;
    }

private:
    //如果在链表中已经存在该值，则返回该结点的前驱
    //这里需要注意的就是如果查找的结点就是第一个结点，此时返回的也是为nullptr
    Node * find(T item)
    {
        Node * ptr = _front;
        Node * before = nullptr;
        while (ptr && ptr->_item != item)
        {
            before = ptr;
            ptr = ptr->_next;
        }
            
        if (!ptr)
            return nullptr;
        else
            return before;
    }

private:
    Node * _front;
    Node * _rear;
    int _sz;
};







#endif