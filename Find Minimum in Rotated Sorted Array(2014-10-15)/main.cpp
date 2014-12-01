#include <iostream>
#include <vector>

using namespace std;

/**
 * 查找旋转数组的最小值
 * @param  num 数组
 * @return     最小值
 */
int findMin(vector<int> &num)
{
    if (num.empty())
        return 0;

    int iMin = num[0];

    for (int i = 1; i < num.size(); i++)
    {
        if (iMin > num[i])
            iMin = num[i];
    }
    return iMin;
}

/**
 * 查找旋转数组的最小值
 * @param  num 数组
 * @return     最小值
 */
int findMinOpt(vector<int> &num)
{
    if (num.empty())
        return 0;

    int iLeft = 0;
    int iRight = num.size() - 1;

    if (num[iLeft] <= num[iRight])
        return num[iLeft];

    while (iLeft < iRight)
    {
        int iMid = (iLeft + iRight + 1) >> 1;

        num[iMid] > num[iLeft] ? iLeft = iMid : iRight = iMid;

        if (iLeft == iRight || iLeft == iRight - 1)
            return min(num[iLeft], num[iRight]);
    }
}

int main()
{
    int A[11] = {6, 7, 8, 9, 10, 11, 1, 2, 3, 4, 5};
    // int A[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    // int A[2] = {2, 1};
    vector<int> iVectorData(A, A + 11);

    cout << findMin(iVectorData) << endl;

    cout << findMinOpt(iVectorData) << endl;

    return 0;
}
