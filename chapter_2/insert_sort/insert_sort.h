#ifndef __INSERT_SORT_H__
#define __INSERT_SORT_H__

#include <iostream>

using namespace std;

template<class T, class t>
class InsertSort
{
public:
    static void sort(T & a)
    {
        for (int i = 1; i < a.size(); ++i)
        {
            for (int j = i; j > 0 && less(a[j], a[j - 1]); --j)
                exchange(a, j, j - 1); 
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