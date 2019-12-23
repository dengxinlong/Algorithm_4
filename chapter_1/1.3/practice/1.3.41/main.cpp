#include "queue.h"

#include <iostream>
#include <string>

using namespace std;

class Test
{
public:
    static void test(void)
    {
        Queue<string> queue;
        string item;
        while (cin >> item)
        {
            if (item != "-")
                queue.enqueue(item);
            else if (!queue.isEmpty())
                cout << queue.dequeue() << " ";
        }
        cout << endl;
        queue.print();
        Queue<string> queue_1 = queue;
        queue_1.print();
        queue_1.enqueue("hello");
        queue.print();
        queue_1.print();

    }
};

int main(void)
{
    Test::test();

    return 0;
}