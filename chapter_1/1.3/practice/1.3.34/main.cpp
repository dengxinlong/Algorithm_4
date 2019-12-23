#include "random_bag.h"

#include <iostream>

using namespace std;

class Test
{
public:
    static void test(void)
    {
        RandomBag<int> random_bag(10);
        int item;
        while (cin >> item)
        {
            random_bag.add(item);
        }
        // random_bag.print();
        random_bag.for_each();
    }
};

int main(void)
{
    Test::test();

    return 0;
}