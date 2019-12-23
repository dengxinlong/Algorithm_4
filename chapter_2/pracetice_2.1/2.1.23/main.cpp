#include "insert_sort.h"

#include <time.h>
#include <stdlib.h>

#include <iostream>
#include <vector>

#define SIZE (10 * 10)

using namespace std;

int main(void)
{
    vector<int> nums;
    srand(clock());
    for (int i = 0; i < SIZE; ++i)
    {
        nums.push_back(rand() % 100 - 50);
    }
    // vector<int> nums{33, 11, 59, 10, 44, 66, -1, -34};
    InsertSort<vector<int>, int>::sort(nums);
    cout << InsertSort<vector<int>, int>::isSorted(nums) << endl;

    return 0;
}


//插入排序算法
template<class T>
void insert_sort(T & nums)
{
    for (int i = 1; i < nums.size(); ++i)
    {
        for (int j = i; j > 0 && nums[j] < nums[j - 1]; --j)
            //交换nums[j], nums[j - 1];
    }
}