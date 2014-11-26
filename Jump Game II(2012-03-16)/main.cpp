#include <iostream>

using namespace std;

int canJump(int A[], int n)
{
    int iNum = n - 1;
    int iJump = -1;

    while (iNum >= 0)
    {
        int iSubNum = iNum - 1;
        int iMaxStep = -1;
        // 查找可以跳转到当前位置的最前位置
        while (iSubNum >= 0)
        {
            if (A[iSubNum] >= iNum - iSubNum)
                iMaxStep = iSubNum;

            iSubNum--;
        }

        iNum = iMaxStep; // 下一个查找位置就是可以跳转到当前位置的最前位置
        iJump++;
    }

    return iJump;
}


int main()
{
    // int A[5] = {2, 3, 1, 1, 4};
    int A[8] = {2, 3, 2, 4, 1, 1, 1, 5};

    cout << canJump(A, 8) << endl;

    return 0;
}
