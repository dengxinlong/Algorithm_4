#include "link_list.h"

#include <iostream>
#include <string>

using namespace std;

class Test
{
public:
    static void test(void)
    {
        LinkList<string> link_list;
        string str;
        while (cin >> str)
        {
            link_list.push_back(str);
        }
        link_list.for_each();
        link_list.reverse();
        link_list.for_each();
    }
};

int main(void)
{
    Test::test();
    
    return 0;
}