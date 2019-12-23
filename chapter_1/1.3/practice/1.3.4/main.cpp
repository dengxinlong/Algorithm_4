#include "stack.h"

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Test
{
public:
    static bool test(string str)
    {
        if (!str.size())
            return true;
        unordered_map<char, char> hash_map{{')', '('},
                                    {'}', '{'},
                                    {']', '['}};
        Stack<char> stack;
        for (auto elem : str)
        {
            auto iter = hash_map.find(elem);
            if (iter != hash_map.end())
            {
                if (stack.isEmpty() || iter->second != stack.top())
                    return false;
                else
                    stack.pop();
            }
            else
                stack.push(elem);
        } 

        return stack.isEmpty();
    }
};

int main(void)
{
    string str(")(");
    cout << Test::test(str) << endl;


    return 0;
}