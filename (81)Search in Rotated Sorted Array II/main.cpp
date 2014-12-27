#include <iostream>

using namespace std;

bool search(int A[], int n, int target)
{
    // 如果等于起始位置元素或终止位置元素，直接返回
    if (target == A[0] || target == A[n - 1])
        return true;

    if (1 == n && A[0] != target)
        return false;

    int iLeft = 0; // 区间起始位置
    int iRight = n - 1; // 区间终止位置
    int iHalf = 0; // 区间结束位置

    if (A[0] >= A[n - 1])
    {
        // 二分查找转折点
        while (iRight != (iLeft + 1))
        {
            iHalf = (iRight + iLeft) >> 1;

            if (A[iHalf] > A[iLeft])
                iLeft = iHalf;
            else if (A[iHalf] < A[iRight])
                iRight = iHalf;
            else if (A[iHalf] == A[iLeft])
                iLeft++;
            else if (A[iHalf] == A[iRight])
                iRight--;
        }

        // 查找target所属的区间
        if (target == A[iLeft] || target == A[iRight])
            return true;
        else if (target < A[iLeft] && target > A[0]) // target属于转折点左侧区域
        {
            iRight = iLeft;
            iLeft = 0;
        }
        else if (target > A[iRight] && target < A[n - 1]) // target属于转折点右侧区域
        {
            iLeft = iRight;
            iRight = n - 1;
        }
        else // target 不在数组中
            return false;

    }

    // 在target属于的区间里使用二分法查找
    while (iRight != iLeft)
    {
        iHalf = (iRight + iLeft) >> 1;

        if (target > A[iHalf])
            iLeft = iHalf;
        else if (target < A[iHalf])
            iRight = iHalf;
        else
            return true;

        if (iRight - iLeft == 1 && target != A[iLeft])
            return false;
    }

    return false;
}

bool searchOpt(int A[], int n, int target)
{
    if (0 == n)
        return false;

    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int midle = (left + right) >> 1;
        if (A[midle] == target)
            return true;
        if (A[left] == A[midle] && A[midle] == A[right])
        {
            ++left;
            --right;
        }
        else if (A[left] <= A[midle])
        {
            if (A[left] <= target && target  < A[midle])
                right = midle - 1;
            else
                left = midle + 1;
        }
        else
        {
            if (A[midle] < target && target <= A[right])
                left = midle + 1;
            else
                right = midle - 1;
        }
    }
    return false;
}

int main()
{
    // int A[] = {6, 6, 7, 7, 8, 9, 10, 11, 1, 1, 1, 2, 3, 4, 5};
    // int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    // int A[] = {1, 3, 1, 1};
    int A[] = {3, 1, 2, 2, 2};

    // cout << search(A, 11, 1) << endl;

    // cout << searchOpt(A, 11, 1) << endl;

    cout << search(A, 5, 1) << endl;

    return 0;
}
