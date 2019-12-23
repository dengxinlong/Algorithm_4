#include "double_link_list.h"

#include <iostream>
#include <string>

using namespace std;

class Test
{
public:
    static void test(void)
    {
        DoubleLinkList<string> double_link_list;
        string str;
        while (cin >> str)
        {
            double_link_list.insert_tail(str);
        }
        double_link_list.print();
        double_link_list.delete_head();
        double_link_list.print();
        double_link_list.delete_tail();
        double_link_list.print();
        double_link_list.insert_before("ghost", 2);
        double_link_list.print();
    }
};

int main(void)
{
    Test::test();

    return 0;
}