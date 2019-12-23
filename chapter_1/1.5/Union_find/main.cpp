#include "union_find.h"

#include <iostream>
#include <string>

using namespace std;

class Test
{
public: 
    static void test(void)
    {
        int N;
        cout << "please Enter a number: ";
        cin >> N;
        Union_find union_find(N);
        int p, q;
        while (cin >> p)
        {
            cin >> q;
            if (union_find.connected(p, q)) continue;
            union_find.set_union(p, q);
            cout << p << " " << q << endl;
        }

        cout << union_find.count() << "components.\n";
    }
};

int main(void)
{
    Test::test();


    return 0;
}