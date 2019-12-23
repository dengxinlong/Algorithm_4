#include "link_list.h"

#include <iostream>
#include <string>

using namespace std;

//找到链表中结点值最大的结点值
// template<class T>
// T max_node(const LinkList<T> & link_list)
// {

// }

class Test
{
public: 
    static void test(void)
    {
        LinkList<int> link_list;
        int item;
        while (cin >> item)
        {
            link_list.push_back(item);
        }
        link_list.for_each();

        cout << link_list.max_node() << endl;
        
    }
};

int main(void)
{
    Test::test();


    return 0;
}