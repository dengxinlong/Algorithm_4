#include "queue_link.h"

#include <iostream>
#include <string>

using namespace std;

class Test
{
public:
    static void test(int k)
    {
        Queue<string> queue;
        string str;
        while (cin >> str)
        {
            queue.enqueue(str);
        }
        int n = queue.size();
        for (int i = 0; i < n - k; ++i)             //时间复杂度为O(N)
            queue.dequeue();
        cout << "k: " << queue.dequeue() << endl;
    }
};


int main(int argc, char * argv[])
{
    if (argc != 2)
    {
        cout << "argument is fail.\n";
        return -1;
    }
        
    Test::test(stoi(argv[1]));

    return 0;
}