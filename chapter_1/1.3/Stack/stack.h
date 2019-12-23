#include <iostream>
#include <vector>

using namespace std;

template<class T>
class Stack
{
public:
    Stack()
    {}

    void push(T item)
    {
        _stack.push_back(item);
    }

    T pop()
    {
        T ans = _stack.back();
        _stack.pop_back();
        return ans;
    }

    bool isEmpty(void)
    {
        return _stack.size() == 0;
    }

    int size(void)
    {
        return _stack.size();
    }
private:
    vector<T> _stack;
};