#include <iostream>
#include <vector>

using namespace std;
/**
 * findPeakElement 查找峰值元素
 * @param  num 数组 vector<int>
 * @return     返回峰值坐标索引 int
 */
int findPeakElement(const vector<int> &num)
{
    int iLast = num.size() - 1;

    if (iLast < 1)
        return 0;

    if (num[0] > num[1])
        return 0;

    for (int i = 1; i < iLast; i++)
    {
        if (num[i] > num[i - 1] && num[i] > num[i + 1])
            return i;
    }

    return num[iLast] > num[iLast - 1] ? iLast : 0;
}

int main()
{
    int iData[] = {1, 3, 4, 5, 2};
    vector<int> iVectorData(iData, iData + 5);

    int iPosition = 0;
    iPosition = findPeakElement(iVectorData);

    cout << iPosition << endl;

    return 0;
}
