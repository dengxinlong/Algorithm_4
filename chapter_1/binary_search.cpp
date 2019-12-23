#include "Random.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>

#define N 10

using namespace std;

template<class T>
int binary_search(const vector<T> & nums, T target)
{   
    int low = 0, high = nums.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
            high = mid - 1;
        else 
            low = mid + 1;
    }
    return -1;
}

template<class T>
void read_file(vector<T> & nums, string file)
{
    fstream input_file(file);
    T value;
    while (input_file >> value)
        nums.push_back(value);
}

int main(int argc, char * argv[])
{
    if (argc != 2)
        cout << "argument is error.\n";

    vector<int> nums;
    read_file(nums, argv[1]);

    sort(nums.begin(), nums.end());
    // for (auto elem : nums)
    //     cout << elem << " ";
    // cout << endl;
    int value;
    while (cin >> value)
    {
        if (binary_search(nums, value) < 0)
            cout << value << endl;
    }


    return 0;
}