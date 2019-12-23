#include "move_to_front.h"

#include <iostream>
#include <string>

using namespace std;

class Test
{
public:
    static void test(void)
    {
        MoveToFront<string> nums;
        string item;
        while (cin >> item)
        {
            nums.insert(item);
        }

        nums.print();
    }
};

int main(void)
{
    Test::test();

    return 0;
}