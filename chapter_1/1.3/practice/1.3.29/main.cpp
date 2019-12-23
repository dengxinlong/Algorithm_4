#include "cycle_link_list.h"

#include <iostream>
#include <string>

using namespace std;

//找到链表中结点值最大的结点值
// template<class T>
// T max_node(const LinkList<T> & link_list)
// {

// }

class Test
{
public: 
    static void test(void)
    {
        Queue<string> queue;
        string item;
        while (cin >> item)
        {
            if (item != "-")
                queue.enqueue(item);
            else if (!queue.isEmpty())
                cout << queue.dequeue() << " ";
        }
        cout << endl << "Queue have " << queue.size() << " components.\n";
    }
};

int main(void)
{
    Test::test();


    return 0;
}