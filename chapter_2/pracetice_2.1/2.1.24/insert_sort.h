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
        // for (int i = 1; i < a.size(); ++i)
        // {
        //     for (int j = i; j > 0 && less(a[j], a[j - 1]); --j)
        //         exchange(a, j, j - 1); 
        // }
        //这里使用哨兵来排序, 规避边界测试方法
        //先找到最小元素
        if (a.size() <= 0)
            return;
        int min = 0; 
        for (int i = 0; i < a.size(); ++i)
            if (a[i] < a[min])
                min = i;
        exchange(a, min, 0);            //将数组中最小元素值放置到数组的最左边
        for (int i = 1; i < a.size(); ++i)
        {
            for (int j = i; less(a[j],  a[j - 1]); --j)
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