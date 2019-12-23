#include <stdlib.h>
#include <time.h>

#include <iostream>
#include <vector>

using namespace std;

class Random
{
public:
    //用于产生0 -- 1之间的随机数
    static double random(void)
    {
        srand(::clock());
        return (double)(rand() % 10) / 10;
    }

    //产生 0 -- N - 1之间的随机数
    static int uniform(int N)
    {
        return (int)(random() * N);
    }

    static double uniform(double N)
    {
        return random() * N;
    }


    //产生lo -- hi - 1 之间的随机数
    static int uniform(int lo, int hi)
    {
        return lo + uniform(hi - lo);
    }

    static double uniform(double lo, int hi)
    {
        return lo + uniform(hi - lo);
    }

    //返回i的概率为a[i]
    static int discrete(vector<double> a)
    {
        double r = random();
        double sum = 0.0;
        for (int i = 0; i < a.size(); ++i)
        {
            sum += a[i];
            if (sum >= r)
                return i;
        }
        return -1;
    }

    //将数组a中的元素随机排序
    static void shuffle(vector<double> & a)
    {
        for (int i = 0; i < a.size(); ++i)
        {
            int r = uniform(i, a.size() - i);
            double temp = a[i];
            a[i] = a[r];
            a[r] = temp;
        }
    }
};