#ifndef __EXAMPLE_H__
#define __EXAMPLE_H__

template<class T>
class Example
{
public:
    static void sort(T & a)
    {

    }

private:
    static bool less(T v, T w)
    {
        return v < w;
    }

    static void exchange(T & a, int i, int j)
    {
        T temp = a[i];
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
}










#endif