#include "counter.h"

void Counter::increment(void)
{
    _count++;
}

int Counter::tally(void)
{
    return _count;
}

string Counter::to_string(void)
{
    string temp = std::to_string(_count);
    temp.push_back(' ');
    temp += _name;
    return temp;
}