#include <iostream>

using namespace std;

int search(int A[], int n, int target)
{
    int i = 0;
    for (; i < n; i++)
    {
        if (target == A[i])
            return i;
    }

    if (i == n)
        return -1;
}

int searchOpt(int A[], int n, int target)
{
    int i = 0;
    if (target >= A[0])
    {
        for (; i < n; i++)
        {
            if (target == A[i])
                return i;
            else if (A[i] > A[i + 1])
            {
                return -1;
            }
        }
    }
    else
    {
        for (i = n - 1; i > 0; --i)
        {
            if (target == A[i])
                return i;
            else if (A[i] < A[i - 1])
            {
                return -1;
            }
        }
    }

    return -1;
}

int searchOpt2(int A[], int n, int target)
{
    int iLeft = 0; // 区间起始位置
    int iRight = n - 1; // 区间终止位置
    int iHalf = 0; // 区间结束位置

    // 如果等于起始位置元素或终止位置元素，直接返回
    if (target == A[0])
    {
        return 0;
    }
    else if (target == A[n - 1])
    {
        return n - 1;
    }

    if (A[0] > A[n - 1])
    {
        // 二分查找转折点
        while (iRight != iLeft)
        {
            iHalf = (iRight + iLeft) >> 1;

            if (A[iHalf] > A[iLeft])
            {
                iLeft = iHalf;
            }
            else if (A[iHalf] < A[iLeft])
            {
                iRight = iHalf;
            }
            else
            {
                iRight = iHalf;
                iLeft = iHalf;
            }
        }

        // 查找target所属的区间
        if (target == A[iHalf])
        {
            return iHalf;
        }
        else if (target < A[iHalf] && target > A[0]) // target属于转折点左侧区域
        {
            iLeft = 0;
            iRight = iHalf;
        }
        else if (target == A[iHalf + 1])
        {
            return iHalf + 1;
        }
        else if (target > A[iHalf + 1] && target < A[n - 1]) // target属于转折点右侧区域
        {
            iLeft = iHalf + 1;
            iRight = n - 1;
        }
        else // target 不在数组中
        {
            return -1;
        }

    }

    // 在target属于的区间里使用二分法查找
    while (iRight != iLeft)
    {
        iHalf = (iRight + iLeft) >> 1;

        if (target > A[iHalf])
        {
            iLeft = iHalf;
        }
        else if (target < A[iHalf])
        {
            iRight = iHalf;
        }
        else
        {
            return iHalf;
        }
        if (iRight - iLeft == 1 && target != A[iLeft])
            return -1;
    }

    return -1;
}

int main()
{
    // int A[] = {6, 7, 8, 9, 10, 11, 1, 2, 3, 4, 5};
    // int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int A[] = {1, 3};

    // cout << search(A, 11, 1) << endl;

    // cout << searchOpt(A, 11, 1) << endl;

    cout << searchOpt2(A, 2, 2) << endl;
    return 0;
}
