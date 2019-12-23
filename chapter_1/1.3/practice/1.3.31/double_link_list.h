#ifndef __DOUBLE_LINK_LIST_H__
#define __DOUBLE_LINK_LIST_H__

#include <iostream>

using std::cout;
using std::endl;

template<class T>
class DoubleLinkList
{
private:
    struct DoubleNode
    {
        DoubleNode()
        : _prior(nullptr)
        , _next(nullptr)
        {}

        DoubleNode * _prior;
        DoubleNode * _next;
        T _item;
    };

public:
    DoubleLinkList()
    : _phead(nullptr)
    , _ptail(nullptr)
    , _sz(0)
    {}

    int size(void) const   {    return _sz; }

    //头插法建立链表的顺序和输入输入数据的顺序相反
    void insert_head(T item)
    {
        DoubleNode * old_phead = _phead;
        _phead = new DoubleNode;
        _phead->_item = item;
        if (!_ptail)
            _ptail = _phead;
        else
        {
            _phead->_next = old_phead;
            old_phead->_prior = _phead;
        }
        _sz++;
    }

    
    void insert_tail(T item)
    {
        DoubleNode * old_ptail = _ptail;
        _ptail = new DoubleNode;
        _ptail->_item = item;
        if (!_phead)
            _phead = _ptail;
        else
        {
            old_ptail->_next = _ptail;
            _ptail->_prior = old_ptail;
        }
        _sz++;
    }

    //删除表头结点
    T delete_head(void)
    {
        if (!_phead)
            return (T)0;
        DoubleNode * old_phead = _phead;
        _phead = _phead->_next;
        if (!_phead)
            _ptail = nullptr;
        else
            _phead->_prior = nullptr;
        T item = old_phead->_item;
        delete old_phead;
        _sz--;
        return item;
    }

    //删除表尾结点
    T delete_tail(void)
    {
        if (!_phead)
            return (T)0;
        DoubleNode * old_ptail = _ptail;
        _ptail = old_ptail->_prior;
        if (!_ptail)
            _phead = nullptr;
        else
            _ptail->_next = nullptr;
        T item = old_ptail->_item;
        delete old_ptail;
        --_sz;
        return item;
    }

    //在pos之前插入结点
    void insert_before(T item, int pos)
    {
        if (pos > size() || pos <= 0)
            return;
        DoubleNode * new_node = new DoubleNode;
        new_node->_item = item;
        DoubleNode * ptr = _phead;
        for (int i = 0; i < pos - 1 && ptr; ++i, ptr = ptr->_next);
        new_node->_next = ptr;
        new_node->_prior = ptr->_prior;
        if (ptr == _phead)
            _phead = new_node;
        else
            ptr->_prior->_next = new_node;
        ptr->_prior = new_node;
        _sz++;
    }

    void insert_after(T item, int pos)
    {
        if (pos > size() || pos <= 0)
            return;
        DoubleNode * new_node = new DoubleNode;
        new_node->_item = item;
        DoubleNode * ptr = _phead;
        for (int i = 0; i < pos - 1 && ptr; ++i, ptr = ptr->_next);
        new_node->_next = ptr->_next;
        new_node->_prior = ptr;
        if (ptr == _ptail)
            _ptail = new_node;
        else
            ptr->_next->_prior = new_node;
        ptr->_next = new_node;
        _sz++;
    }

    void print(void)
    {
        DoubleNode * ptr = _phead;
        while (ptr)
        {
            cout << ptr->_item << " ";
            ptr = ptr->_next;
        }
        cout << endl;
    }


private:    
    DoubleNode * _phead;
    DoubleNode * _ptail;
    int _sz;
};










#endif