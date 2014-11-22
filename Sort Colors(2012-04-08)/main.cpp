#include <iostream>
#include <stdlib.h>

using namespace std;

void sortColors(int A[], int n)
{
    int iRed = 0;
    int iWhite = 0;

    for (int i = 0; i < n; i++)
    {
        if (0 == A[i])
            ++iRed;
        else if (1 == A[i])
            ++iWhite;
    }

    for (int i = 0; i < iRed; i++)
        A[i] = 0;

    for (int i = iRed; i < iRed + iWhite; i++)
        A[i] = 1;

    for (int i = iRed + iWhite; i < n; i++)
        A[i] = 2;
}

int main()
{
    const int N(6); // 定义常数
    int A[N] = {1, 0, 2, 1, 2, 1};

    sortColors(A, N);

    for (int i = 0; i < N; ++i)
        cout << A[i] << " ";

    return 0;
}
