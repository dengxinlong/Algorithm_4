#ifndef __LINK_LIST_H__
#define __LINK_LIST_H__

#include <iostream>

using namespace std;

template<class T>
class LinkList
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
    LinkList()
    : _first(nullptr)
    , _last(nullptr)
    , _sz(0)
    {}

    int size(void) const { return _sz; }

    bool search(T item)
    {
        Node * ptr = _first;
        while (ptr)
        {
            if (ptr->_item == item)
                return true;
            ptr = ptr->_next;
        }
        return false;
    }

    void push_back(T item)
    {
        Node * old_last = _last;
        _last = new Node;
        _last->_item = item;
        if (!_first)
            _first = _last;
        else
            old_last->_next = _last;
        _sz++;
    }

    bool remove(T item)
    {
        Node * ptr = _first;
        Node * pfront = _first;
        int flag = 0;
        while (ptr)
        {
            if (ptr->_item == item)
            {
                //判断删除的结点是否是第一个结点
                if (ptr == _first)
                    _first = _first->_next;
                if (ptr == _last)           //删除的结点是否是最后一个结点
                    _last = pfront;
                pfront->_next = ptr->_next;
                delete ptr;
                _sz--;
                flag = 1;               //可能链表中有多个结点需要删除
            }
            pfront = ptr;
            ptr = ptr->_next;
        }

        return flag == 1;
    }

    void for_each(void)
    {
        Node * ptr = _first;
        while (ptr)
        {
            cout << ptr->_item << " ";
            ptr = ptr->_next;
        }
        cout << endl;
    }

    void delete_last(void)
    {
        Node * ptr = _first, * pfront = _first;
        while (ptr)         //找到倒数第二个结点
        {
            if (pfront->_next == _last)
                break;
            pfront = ptr;
            ptr = ptr->_next;
        }
        if (pfront == _last)           //此时链表中有一个或者没有结点
        {
            if (!pfront)
                return;
            delete pfront;
            _first = _last = nullptr;
            _sz--;
            return;
        }
        pfront->_next = nullptr;
        _sz--;
        delete _last;
        _last = pfront;
    }

    //删除第k个结点
    bool delete_k_node(int k)
    {
        if (k > size() || k < 1)
            return false;
        if (k == 1)
        {
            Node * old_first = _first;
            _first = _first->_next;
            delete old_first;
            _sz--;
            return true;
        }
        Node * ptr = _first, * pfront = _first;
        for (int i = 0; i < k - 2; i++)
            ptr = ptr->_next;
        Node * del_node = ptr->_next;
        if (size() == 1)
        {
            delete _last;
            _last = _first = nullptr;
        }
        else
        {
            ptr->_next = del_node->_next;
            if (del_node == _last)
                _last = ptr;
            return true;
        }
    }

    T last_node(void)
    {
        if (_last)
            return _last->_item;
        return "null";
    }

private:
    Node * _first;
    Node * _last;
    int _sz;
};










#endif