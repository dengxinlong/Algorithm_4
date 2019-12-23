#include "insert_sort.h"
#include "select_sort.h"

#include <stdlib.h>
#include <time.h>

#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<class T>
class SortCompare
{
public:
    static double time(string alg, T & a)
    {
        clock_t start = clock();
        if (alg == "Insertion") InsertSort<vector<int>, int>::sort(a);
        if (alg == "Selection") SelectSort<vector<int>, int>::sort(a);
        
        return clock() - start;
    }

    static double timeRandomInput(string alg, int N, int times)
    {
        double total = 0.0;
        
        srand(clock());
        for (int i = 0; i < times; i++)
        {   
            T a;
            cout << "i：" << i << endl;
            
            for (int j = 0; j < N; ++j)
                a.push_back((rand() % 10));
            total += time(alg, a);
        }
        return total;
    }
};

int main(int argc, char * argv[])
{
    if (argc != 5)
    {
        cout << "Argument is fail.\n";
        return -1;
    }
    int N = stoi(argv[3]), T = stoi(argv[4]);

    double t1 = SortCompare<vector<int>>::timeRandomInput(argv[1], N, T);
    double t2 = SortCompare<vector<int>>::timeRandomInput(argv[2], N, T);
    cout << "For " << N <<  " random Double.\n" << argv[1] << " is "
         << t1 / t2 << " times faster than " << argv[2] << endl;
}