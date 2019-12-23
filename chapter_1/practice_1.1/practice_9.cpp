#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string str;
    int val = 10;
    for (int n = val; n > 0; n /= 2)
        str = to_string(n % 2) + str;
    cout << str << endl;

    return 0;
}