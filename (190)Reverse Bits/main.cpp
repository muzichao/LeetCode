#include <iostream>

using namespace std;

unsigned int reverseBits(unsigned int n)
{
    unsigned int uiResult = 0;
    for (int i = 0; i < 32; i++)
    {
        uiResult = uiResult << 1;
        uiResult += n & 1;
        n = n >> 1;
    }
    return uiResult;
}

int main()
{
    unsigned int uiN = 43261596;

    cout << reverseBits(uiN) << endl;

    return 0;
}
