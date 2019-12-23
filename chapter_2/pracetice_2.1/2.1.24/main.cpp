#include "insert_sort.h"

#include <time.h>
#include <stdlib.h>

#include <iostream>
#include <vector>

#define SIZE (10 * 1)

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