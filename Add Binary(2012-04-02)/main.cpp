#include <iostream>
#include <vector>

using namespace std;

string addBinary(string a, string b)
{
    int iASize = a.size() - 1;
    int iBSize = b.size() - 1;
    int iFlag = 0;

    string sResult;

    // 0 和 1 加 = 1 + iFlag
    // iFlag = 1，则结果为0，iFlag=1
    // iFlag = 0，则结果为1，iFlag=0
    //
    // 0 和 0 加 = iFlag，iFlag=0
    // 1 和 1 加 = iFlag，iFlag=1
    while (iASize >= 0 && iBSize >= 0)
    {
        if (a[iASize] != b[iBSize])
            sResult = 0 == iFlag ? '1' + sResult : '0' + sResult;
        else
        {
            sResult = 0 == iFlag ? '0' + sResult : '1' + sResult;
            iFlag = '0' == a[iASize] ? 0 : 1;
        }

        iASize--;
        iBSize--;
    }

    while (iASize >= 0)
    {
        if ('0' == a[iASize])
        {
            sResult = 0 == iFlag ? '0' + sResult : '1' + sResult;
            iFlag = 0;
        }
        else
            sResult = 0 == iFlag ? '1' + sResult : '0' + sResult;

        iASize--;
    }

    while (iBSize >= 0)
    {
        if ('0' == b[iBSize])
        {
            sResult = 0 == iFlag ? '0' + sResult : '1' + sResult;
            iFlag = 0;
        }
        else
            sResult = 0 == iFlag ? '1' + sResult : '0' + sResult;

        iBSize--;
    }

    if (1 == iFlag)
        sResult = '1' + sResult;

    return sResult;
}

int main()
{
    string a = "11101";
    string b = "1011";

    cout << addBinary(a, b) << endl;

    return 0;
}
