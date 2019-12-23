#ifndef __COUNTER_H__
#define __COUNTER_H__

#include <string>

using namespace std;

class Counter
{
public:
    Counter(string name)
    : _name(name)
    , _count(0)
    {}

    void increment(void);
    int tally(void);
    
    string to_string(void);

private:
    const string _name;
    int _count;
};









#endif