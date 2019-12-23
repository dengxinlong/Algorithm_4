#include "queue.h"

#include <iostream>
#include <string>

using namespace std;

class Test
{
public:
    static void test(void)
    {
        Queue<string> queue(10);
        string str;
        while (cin >> str)
        {
            if (str != "-")
                queue.enqueue(str);
            else if (!queue.isEmpty())
                cout << queue.dequeue() << " ";
        }

        cout << endl << "queue hava " << queue.size() << " compnents" << endl;
        cout << "queue's capacity is " << queue.capacity() << endl;
    }
};

int main(void)
{
    Test::test();


    return 0;
}