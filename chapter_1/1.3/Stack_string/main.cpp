#include "stack_string.h"

#include <iostream>

using namespace std;

class Test
{
public:
    static void test(void)
    {
        FixedCapacityStackOfString<string> stack_string(10);
        string str;
        while (cin >> str)
        {
            if (str != "-")
                stack_string.push(str);
            else if (!stack_string.isEmpty())
                cout << stack_string.pop() << " ";
        }

        cout << "(" << stack_string.size() << " left on stack)" << endl;
    }
};

int main(void)
{
    Test::test();



    return 0;
}