#include "insert_sort.h"
#include "select_sort.h"
#include "shell_sort.h"

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
        if (alg == "Shell") ShellSort<vector<int>, int>::sort(a);
        if (alg == "Shell_t") ShellSort_t<vector<int>, int>::sort(a);
        
        return clock() - start;
    }

    static double timeRandomInput(string alg, int N, int times)
    {
        double total = 0.0;
        
        srand(clock());
        for (int i = 0; i < times; i++)
        {   
            T a;
            for (int j = 0; j < N; ++j)
                a.push_back((rand() % 10));
            N *= 2;
            cout << "N: " << N << endl;
            total += time(alg, a);
        }
        return total;
    }
};

int main(int argc, char * argv[])
{
    if (argc != 6)
    {
        cout << "Argument is fail.\n";
        return -1;
    }
    int N = stoi(argv[4]), T = stoi(argv[5]);

    double t1 = SortCompare<vector<int>>::timeRandomInput(argv[1], N, T);
    double t2 = SortCompare<vector<int>>::timeRandomInput(argv[2], N, T);
    double t3 = SortCompare<vector<int>>::timeRandomInput(argv[3], N, T);
    double t4 = SortCompare<vector<int>>::timeRandomInput(argv[4], N, T);
    cout << "For " << N <<  " random Double.\n" << argv[1] << " is " << t1 << endl
         << argv[2] << " is " << t2 << endl
         << argv[3] << " is " << t3 << endl;
}