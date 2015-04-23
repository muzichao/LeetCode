#include <iostream>

using namespace std;

int rangeBitwiseAnd(int m, int n)
{
    int iResult = n;
    while (0 != iResult && m < n)
    {
        iResult &= m;
        m++;
    }

    return iResult;
}

int rangeBitwiseAndOpt(int m, int n)
{
    if (m == n)
        return m;

    int iBit = 0x40000000;
    while (iBit > n)
        iBit >>= 1;

    return iBit > m ? 0 : iBit + rangeBitwiseAndOpt(m & (iBit-1), n & (iBit-1));
}

int main()
{
    int iLeft = 100;
    int iRight = 120;

    cout << rangeBitwiseAnd(iLeft, iRight) << endl;
    cout << rangeBitwiseAndOpt(iLeft, iRight) << endl;

    return 0;
}
