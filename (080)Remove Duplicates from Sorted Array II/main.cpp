#include <iostream>

using namespace std;

/**
 * 删除有序数组中的重复元素（最多允许出现两次）
 * @param  A 数组头指针
 * @param  n 数组元素个数
 * @return   返回新数组元素个数
 */
int removeDuplicates(int A[], int n)
{
    // 输入空数组或但元素数组
    if (n < 2)
        return n;

    int iFlagDup = 0; // 标记是否出现过
    int iLength = 0; // 标记新的数组A的坐标

    for (int i = 1; i < n; i++)
    {
        if (A[i] == A[iLength])
        {
            if (0 == iFlagDup)
            {
                ++iLength;
                ++iFlagDup;
                A[iLength] = A[i];
            }
        }
        else
        {
            iFlagDup = 0;
            ++iLength;
            A[iLength] = A[i];
        }
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

    cout << removeDuplicates(A, n) << endl;

    return 0;
}
