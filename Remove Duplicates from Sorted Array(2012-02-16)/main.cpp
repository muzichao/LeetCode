/**
 * Given a sorted array, remove the duplicates in place such that
 * each element appear only once and return the new length.
 *
 * Do not allocate extra space for another array, you must
 * do this in place with constant memory.
 *
 * For example,
 * Given input array A = [1,1,2],
 *
 * Your function should return length = 2, and A is now [1,2].
 */


#include <iostream>

using namespace std;


template<size_t n>
int removeDuplicates(int (&A)[n])
{
    // 输入可能为空数组
    if (0 == n)
    {
        return 0;
    }

    int iLength = 0; // 标记新的数组A的坐标
    int i = 1; // 标记原始数组A的坐标

    while (i < n)
    {
        // 知道找到不等的数字
        while (A[iLength] == A[i] && i < n)
        {
            i++;
        }

        if (i == n) // 可能最后的几个元素相同
        {
            return iLength + 1;
        }
        ++iLength;
        A[iLength] = A[i];
        ++i;
    }
    return iLength + 1;
}

int main()
{
    const int n(6); // 定义常数
    int A[n] = {0};

    int i = 0;
    while (i < n)
    {
        cin >> A[i];
        ++i;
    }

    cout << removeDuplicates(A) << endl;

    return 0;
}
