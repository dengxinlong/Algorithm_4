#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>

using namespace std;

template<class T>
class Stack
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
    Stack()         //构造函数
    : _first(nullptr)
    , _N(0)
    {}

    Stack(const Stack & rhs)  //拷贝构造函数
    : _first(nullptr)
    , _N(0)
    {
        Node * ptr = rhs._first;
        Node * last = nullptr;
        while (ptr)
        {
            //尾插法将栈中的数据复制到本对象中
            
            Node * new_node = new Node;
            new_node->_item = ptr->_item;
            if (!_first)
                last = _first = new_node;  
            else
            {
                last->_next = new_node;
                last = last->_next;
            }
            ptr = ptr->_next;
        }
    }

    bool isEmpty(void)  {   return _first == nullptr;   }
    int size(void)  {   return _N;  }
    void push(T item)
    {
        Node * old_first = _first;
        _first = new Node;
        _first->_item = item;
        _first->_next = old_first;
        _N++;
    }

    T pop(void)
    {
        Node * old_first = _first;
        _first = _first->_next;
        T item = old_first->_item;
        _N--;
        delete old_first;
        return item;
    }

    T top(void) const  {    return _first->_item;   }

    Stack & operator=(const Stack & rhs)        //重载赋值运算符函数
    {
        
    }

private:
    Node * _first;              //栈顶元素
    int _N;             //栈中元素的个数
};










#endif