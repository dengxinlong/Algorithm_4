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
        cout << link_list.search("good") << endl;
        cout << "size: " << link_list.size() << endl;
        link_list.delete_last();
        link_list.for_each();
        cout << "size: " << link_list.size() << endl;
        cout << "last: " << link_list.last_node() << endl;
        link_list.for_each();
    }
};

int main(void)
{
    Test::test();


    return 0;
}