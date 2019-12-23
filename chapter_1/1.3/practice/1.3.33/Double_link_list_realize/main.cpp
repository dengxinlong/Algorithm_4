#include "deque.h"

#include <iostream>
#include <string>

using namespace std;

class Test
{
public:
    static void test(void)
    {
        Deque<string> deque;
        string str;
        while (cin >> str)
        {
            deque.push_left(str);
            deque.push_right(str);
        }
        deque.print();
        while (!deque.isEmpty())
        {
            cout << deque.pop_left() << " ";
        }
        cout << endl;
        cout << "deque.size: " << deque.size() << endl;
    }
};

int main(void)
{
    Test::test();

    return 0;
}