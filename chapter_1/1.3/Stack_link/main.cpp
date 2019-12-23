#include "stack.h"

#include <iostream>
#include <string>

using namespace std;

class Test
{
public: 
    static void test(void)
    {
        Stack<string> stack;
        string str;
        while (cin >> str)
        {
            if (str != "-")
                stack.push(str);
            else if (!stack.isEmpty())
                cout << stack.pop() << " ";
        }
        cout << "( " << stack.size() << "left on stack)" << endl;

        Stack<string> stack_cp = stack;
        while (!stack_cp.isEmpty())
        {
            cout << stack_cp.pop() << endl;
        }
    }
};

int main(void)
{
    Test::test();



    return 0;
}