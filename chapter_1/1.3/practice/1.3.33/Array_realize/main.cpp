#include "deque.h"

#include <iostream>
#include <string>

using namespace std;

class Test
{
public:
    static void test(void)
    {
        Deque<int> deque(10);
        int item;
        while (cin >> item)
        {
            deque.push_left(item);
            deque.push_right(item);
            // deque.print();
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