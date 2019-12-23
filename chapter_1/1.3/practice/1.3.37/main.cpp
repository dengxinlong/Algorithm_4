#include "queue.h"

#include <iostream>
#include <string>

using namespace std;

class Test
{
public:
    static void test(int total, int flag)
    {
        Queue<int> queue(total + 1);            //循环队列
        for (int i = 0; i < total; i++)
            queue.enqueue(i);
        
        int k = 0;
        while (!queue.isEmpty())
        {
            int val = queue.dequeue();
            if (++k % flag == 0)
                cout << val << " ";
            else
                queue.enqueue(val);
        }
        cout << endl;
    }
};

int main(int argc, char * argv[])
{   
    if (argc != 3)
    {
        cout << "Argument is fail.\n";
        return -1;
    }
        
    Test::test(stoi(argv[1]), stoi(argv[2]));
    

    return 0;
}