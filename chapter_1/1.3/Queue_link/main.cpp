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
        string str;
        while (cin >> str)
        {
            if (str != "-")
                queue.enqueue(str);
            else if (!queue.isEmpty())
                cout << queue.dequeue() << " ";
        }

        cout << "(" << queue.size() << " left on quque)" << endl;
    }
};

int main(void)
{

    Test::test();

    return 0;
}