#include <iostream>

using namespace std;

int singleNumber(int A[], int n)
{
    int iSingle = 0;

    for (int i = 0; i < n; i++)
        iSingle = iSingle ^ A[i];

    return iSingle;
}

int main()
{
    int a[] = {1, 2, 3, 4, 4, 5, 2, 3, 1};

    int iSingle = 0;

    iSingle = singleNumber(a, 9);

    cout << iSingle << endl;

    return 0;
}
