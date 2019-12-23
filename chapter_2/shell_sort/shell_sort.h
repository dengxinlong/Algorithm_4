#ifndef __SHELL_SORT_H__
#define __SHELL_SORT_H__

#include <iostream>

using namespace std;

template<class T, class t>
class ShellSort
{
public:
    static void sort(T & a)
    {
        //希尔排序
        int N = a.size();
        int h = 1;
        while (h < N / 3)
            h *= 3 + 1;
        while (h >= 1)
        {
            for (int i = h; i < N; i++)
                for (int j = i; j - h >= 0 && less(a[j], a[j - h]); j -= h)
                    exchange(a, j, j - h);
            h = h / 3;
        }
        show(a);
    }

private:
    static bool less(t v, t w)
    {
        return v < w;
    }

    static void exchange(T & a, int i, int j)
    {
        t temp = a[i];
        a[i] = a[j];
        a[j] = temp;

        //或者这样写，不使用第三个变量实现两个数的交换
        // a[i] = a[i] ^ a[j];
        // a[j] = a[i] ^ a[j];
        // a[i] = a[i] ^ a[j];
    }

    static void show(T & a)
    {
        for (int i = 0; i < a.size(); ++i)
            cout << a[i] << " ";
        cout << endl;
    }

public:
    static bool isSorted(T & a)
    {
        for (int i = 1; i < a.size(); ++i)
            if (less(a[i], a[i - 1]))
                return false;
        return true;
    }
};










#endif