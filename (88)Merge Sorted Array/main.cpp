#include <iostream>
#include <vector>

using namespace std;

/**
 * 合并有序数组
 * @param A 数组A
 * @param m A的长度
 * @param B 数组B
 * @param n B的长度
 */
void merge(int A[], int m, int B[], int n)
{
    int iNum = m + n - 1;
    m--;
    n--;

    while (iNum > m)
    {
        if (m >= 0)
            A[iNum--] = A[m] > B[n] ? A[m--] : B[n--];
        else
            A[iNum--] = B[n--];
    }
}

/**
 * 合并有序数组
 * @param A 数组A
 * @param m A的长度
 * @param B 数组B
 * @param n B的长度
 */
void mergeOpt(int A[], int m, int B[], int n)
{
    int iNum = m + n - 1;
    m--;
    n--;

    while (iNum > m)
        A[iNum--] = m >= 0 ? (A[m] > B[n] ? A[m--] : B[n--]) : B[n--];
}


int main()
{
    int A[10] = {1, 4, 7, 8};
    int B[5] = {2, 3, 6, 9, 10};

    // merge(A, 4, B, 5);
    mergeOpt(A, 4, B, 5);

    for (int i = 0; i < 10; ++i)
    {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
