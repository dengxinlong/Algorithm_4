#ifndef __GENERALIZED_QUEUE_H__
#define __GENERALIZED_QUEUE_H__

template<class T>
class GeneralizedQueue
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
    GeneralizedQueue()
    : _front(nullptr)
    , _rear(nullptr)
    , _sz(0)
    {}

    int size(void) const {  return _sz; }
    bool isEmpty(void) const {  return !_front; }

    void insert(T item)
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

    //删除最早插入的第k个元素
    T delete_k(int k)
    {
        Node * ptr = _front, * before_node = nullptr;

        for (int i = 0; i < k - 1 && ptr; ++i, ptr = ptr->_next)
            before_node = ptr;
        T item = ptr->_item;
        if (ptr == _front)          //如果删除的结点是第一个结点
            _front = ptr->_next;
        else
            before_node->_next = ptr->_next;
            
        if (!ptr->_next)            //如果删除的结点是最后一个结点
            _rear = before_node;
        delete ptr;
        _sz--;
        return item;
    }

    for ()

private:
    Node * _front;
    Node * _rear;
    int _sz;
};










#endif 