#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>
#include <string>

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
    Stack()
    : _first(nullptr)
    , _N(0)
    {}

    bool isEmpty(void) const {  return _N == 0; }
    int size(void) const { return _N; }
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

    T top(void) const {   return _first->_item;  }

private:
    Node * _first;
    int _N;
};







#endif