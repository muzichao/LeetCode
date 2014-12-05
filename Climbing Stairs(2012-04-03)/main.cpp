#include <iostream>
#include <time.h>

using namespace std;

int climbStairs(int n)
{
    if (n <= 2)
        return n;

    return climbStairs(n - 1) + climbStairs(n - 2);
}

int climbStairsOpt(int n)
{
    return n <= 2 ? n : climbStairs(n - 1) + climbStairs(n - 2);
}

int climbStairsOpt2(int n)
{
    if (n <= 2)
        return n;

    int iN1 = 1;
    int iN2 = 2;
    int iResutt = 0;
    int iCout = 2;

    while (iCout < n)
    {
        iResutt = iN1 + iN2;
        iN1 = iN2;
        iN2 = iResutt;
        iCout++;
    }

    return iResutt;
}

int main()
{
    int N = 40;

    clock_t startTime, endTime;
    startTime = clock();
    cout << climbStairs(N) << endl;
    endTime = clock();
    cout << "Run time: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "S" << endl;


    startTime = clock();
    cout << climbStairsOpt(N) << endl;
    endTime = clock();
    cout << "Run time: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "S" << endl;


    startTime = clock();
    cout << climbStairsOpt2(N) << endl;
    endTime = clock();
    cout << "Run time: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "S" << endl;


    return 0;
}
