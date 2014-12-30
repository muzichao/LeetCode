#include <iostream>
using namespace std;

/**
 * n!末尾0的个数
 * @param  n int
 * @return   int
 */
int trailingZeroes(int n)
{
    int iCout = 0;
    while (n > 0)
    {
        n = n / 5;
        iCout += n;
    }

    return iCout;
}

int main()
{
    int n = 130;

    cout << trailingZeroes(n) << endl;

    return 0;
}
