#include <iostream>
#include <vector>

using namespace std;

/**
 * 产生n位的格雷码
 * @param n 格雷码的位数
 */
vector<int> GrayCode(const int n)
{
    vector<int> iVectorData;
    if (n < 0)
        return iVectorData;

    iVectorData.push_back(0);

    int iNum = 1;

    while (iNum <= n)
    {
        int iRange = 1 << (iNum - 1);
        for (int i = 0; i < iRange; ++i)
            iVectorData.push_back(iVectorData[iRange - i - 1] + iRange);

        iNum++;
    }
}

int main()
{
    vector<int> iVectorData;

    iVectorData = GrayCode(3);

    for (vector<int>::iterator it = iVectorData.begin(); it != iVectorData.end(); ++it)
        cout << *it << endl;

    return 0;
}
