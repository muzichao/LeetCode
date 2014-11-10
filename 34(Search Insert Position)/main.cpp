/**
 * Given a sorted array and a target value, return the
 * index if the target is found. If not, return the index
 * where it would be if it were inserted in order.
 *
 * You may assume no duplicates in the array.
 *
 * Here are few examples.
 * [1,3,5,6], 5 → 2
 * [1,3,5,6], 2 → 1
 * [1,3,5,6], 7 → 4
 * [1,3,5,6], 0 → 0
 */

#include <iostream>

using namespace std;

template<size_t n>
int searchInsert(int (&A)[n], int target)
{
    int iPosition = 0;

    while (iPosition < n)
    {
        if (A[iPosition] >= target)
            return iPosition;
        else if (A[iPosition] < target)
            ++iPosition;
    }
    return iPosition;
}

int main(int argc, char const *argv[])
{
    const int n(6); // 定义常数
    int A[n] = {0};

    int i = 0;
    while (i < n)
    {
        cin >> A[i];
        ++i;
    }

    cout << searchInsert(A, 5) << endl;
    return 0;
}
