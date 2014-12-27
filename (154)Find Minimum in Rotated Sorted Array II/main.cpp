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
    int iMid = 0;

    while (iLeft <= iRight)
    {
        if (iLeft == iRight || iLeft == iRight - 1)
            return min(num[iLeft], num[iRight]);

        iMid = (iLeft + iRight + 1) >> 1;

        if (num[iMid] == num[iLeft])
            iLeft++;

        if (num[iMid] == num[iRight])
            iRight--;

        if (num[iLeft] < num[iRight])
            return num[iLeft];

        if (num[iMid] > num[iLeft])
            iLeft = iMid;

        if (num[iMid] < num[iLeft])
            iRight = iMid;
    }
}

int main()
{
    // int A[15] = {6, 6, 7, 7, 8, 9, 10, 11, 1, 1, 1, 2, 3, 4, 5};
    // int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    // int A[] = {1, 3, 1, 1};
    // int A[] = {3, 1, 2, 2, 2};
    // int A[2] = {1, 3};
    int A[2] = {2, 1};
    // int A[3] = {1, 3, 3};
    // int A[3] = {3, 3, 1};
    // int A[4] = {3, 1, 3, 3};

    vector<int> iVectorData(A, A + 2);

    cout << findMin(iVectorData) << endl;

    cout << findMinOpt(iVectorData) << endl;

    return 0;
}
