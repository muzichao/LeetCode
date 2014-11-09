/**
 * Given an array and a value, remove all instances of that value
 * in place and return the new length.
 *
 * The order of elements can be changed. It doesn't matter what
 * you leave beyond the new length.
 */

#include <iostream>

using namespace std;

template<size_t n>
int removeElement(int (&A)[n], int elem)
{
    int i = 0;
    int iLength = 0;

    while (i < n)
    {
        if (elem != A[i])
        {
            A[iLength] = A[i];
            ++iLength;
        }

        ++i;

    }
    return iLength;
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

    cout << removeElement(A, 5) << endl;

    return 0;
}
