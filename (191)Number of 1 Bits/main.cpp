#include <iostream>

using namespace std;

int hammingWeight(unsigned int uiN)
{
    int iCount = 0;

    while(0 != uiN)
    {
        iCount += uiN & 1;
        uiN = uiN >> 1;
    }

    return iCount;
}

int main()
{
    unsigned int uiN = 0x10F;

    cout << hammingWeight(uiN) << endl;

    return 0;
}
