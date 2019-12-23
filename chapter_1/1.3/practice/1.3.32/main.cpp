#include "double_link_list.h"

#include <iostream>
#include <string>

using namespace std;

class Test
{
public:
    static void test(void)
    {
        Steque<string> steque;
        string str;
        while (cin >> str)
        {
            if (str != "-")
                steque.push(str);
            else if (!steque.isEmpty())
                cout << steque.pop() << " ";
        }
        cout << "steque has " << steque.size() << " compnents.\n";
        steque.print();
        steque.enqueue("ghost");
        steque.print();
    }
};

int main(void)
{
    Test::test();

    return 0;
}