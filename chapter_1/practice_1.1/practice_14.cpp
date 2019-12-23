#include <iostream>

using namespace std;


//法一：直接遍历
// class Solution
// {
// public:
//     int less_than_equal(int val)
//     {
//         if (val < 1)
//             return 0;
//         int i;
//         for ( i = 1; i <= val / 2; ++i)
//         {
//             if (power(2, i) > val)
//                 break;
//         }
        
//         return i - 1;
//     }

// private:
//     int power(int x, int y)
//     {
//         int ret = 1;
//         for (int i = 0; i < y; ++i)
//         {
//             ret *= x;
//         }

//         return ret;
//     }
// };

//法二：二分法计算
class Solution
{
public:
    int less_than_equal(int val)
    {
        if (val < 1)
            return 0;
        long low = 1, high = val / 2;
        while (low < high)
        {
            int mid = low + (high - low + 1) / 2;

            if (power(2, mid) > val)
                high = mid - 1;
            else
                low = mid;
        }

        return low;
    }

private:
    int power(int x, int y)
    {
        int ret = 1;
        for (int i = 0; i < y; ++i)
        {
            ret *= x;
        }

        return ret;
    }
};

int main(void)
{
    Solution so;

    int val = 10;
    cout << so.less_than_equal(val) << endl;

    return 0;
}