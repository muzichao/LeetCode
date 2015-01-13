/**
 * Reverse digits of an integer.
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 */


#include <iostream>

using namespace std;

int reverse(int x)
{
    int iData = 0;
    int iX = x;

    while (0 != iX)
    {
        iData = 10 * iData + (iX % 10);
        iX /= 10;
    }
    return iData;
}
int main()
{
    int x = -123;

    cout << reverse(x) << endl;

    return 0;
}
