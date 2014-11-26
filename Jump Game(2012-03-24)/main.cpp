#include <iostream>

using namespace std;

bool canJump(int A[], int n)
{
    int iNum = n - 2;
    int iCout = 0;

    while (iNum >= 0)
    {
        if (iCout >= A[iNum])
            iCout++;
        else
            iCout = 0;

        iNum--;
    }

    if (iCout == 0)
        return true;
    else
        return false;
}

bool canJumpSimple(int A[], int n)
{
    int iNum = n - 1;
    int iCout = 0;

    while (--iNum >= 0)
        iCout >= A[iNum] ? iCout++ : iCout = 0;

    return (iCout == 0 ? true : false);
}

int main()
{
    // int A[5] = {2, 3, 1, 1, 4};
    int A[5] = {3, 3, 1, 0, 4};

    cout << canJump(A, 5) << endl;

    cout << canJumpSimple(A, 5) << endl;

    return 0;
}
