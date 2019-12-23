#include "generalized_queue.h"

#include <iostream>
#include <string>

using namespace std;

class Test
{
public:
    static void test(void)
    {
        GeneralizedQueue<string> queue;
        string item;
        while (cin >> item)
        {
            queue.insert(item);
        }
        cout << queue.delete_k(3) << endl;

    }
};

int main(void)
{
    Test::test();

    return 0;
}