#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

int maxArea(vector<int> &height)
{
    int iMaxArea = 0;
    for (int i = 0; i < height.size() - 1; i++)
    {
        for (int j = i + 1; j < height.size(); j++)
        {
            int iLowSize = min(height[i], height[j]);
            int iArea = (j - i) * iLowSize;

            if (iArea > iMaxArea)
                iMaxArea = iArea;
        }
    }
    return iMaxArea;
}

int maxAreaOpt(vector<int> &height)
{
    if (height.size() < 2)
        return 0;

    int iLeft = 0;
    int iRight = height.size() - 1;

    int iMaxArea = 0;

    while (iLeft < iRight)
    {
        int iLowSize = min(height[iLeft], height[iRight]);
        int iArea = (iRight - iLeft) * iLowSize;

        iMaxArea = max(iMaxArea, iArea);

        if (height[iLeft] <= height[iRight])
            iLeft++;
        else
            iRight--;
    }

    return iMaxArea;
}

int maxAreaOpt2(vector<int> &height)
{
    int iLeft = 0;
    int iRight = height.size() - 1;
    int iMaxArea = 0;

    while (iLeft < iRight)
    {
        iMaxArea = max(iMaxArea, (iRight - iLeft) * min(height[iLeft], height[iRight]));
        height[iLeft] <= height[iRight] ? iLeft++ : iRight--;
    }

    return iMaxArea;
}

int maxAreaOpt3(vector<int> &height)
{
    if (height.size() < 2)
        return 0;

    int iLeft = 0;
    int iRight = height.size() - 1;

    int iMaxArea = 0;

    while (iLeft < iRight)
    {
        int iLowSize = min(height[iLeft], height[iRight]);
        int iArea = (iRight - iLeft) * iLowSize;

        iMaxArea = max(iMaxArea, iArea);

        if (height[iLeft] <= height[iRight])
        {
            int iLeftNew = iLeft + 1;
            while (height[iLeftNew] <= height[iLeft] && iLeftNew < iRight)
                iLeftNew++;

            iLeft = iLeftNew;
        }
        else
        {
            int iRightNew = iRight - 1;
            while (height[iRightNew] <= height[iRight] && iRightNew > iLeft)
                iRightNew--;

            iRight = iRightNew;
        }
    }

    return iMaxArea;
}

// 产生随机数组
template<size_t SIZE>
void gen_rand_n(int (&A)[SIZE])
{
    srand(1);
    for (int i = 0; i < SIZE; ++i)
    {
        A[i] = rand() % SIZE;
    }
}

const int N(10000000); // 定义常数
// int A[N] = {2, 5, 3, 11, 6, 9, 1, 14, 7, 8};
// int A[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
// int A[N] = {5, 2, 12, 1, 5, 3, 4, 11, 9, 4};

int A[N] = {0};

int main()
{
    gen_rand_n(A);

    vector<int> iVectorData(A, A + N);

    clock_t startTime, endTime;

    startTime = clock();
    // cout << maxArea(iVectorData) << endl;
    endTime = clock();
    cout << "Run time: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "S" << endl;

    startTime = clock();
    cout << maxAreaOpt(iVectorData) << endl;
    endTime = clock();
    cout << "Run time: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "S" << endl;

    startTime = clock();
    cout << maxAreaOpt2(iVectorData) << endl;
    endTime = clock();
    cout << "Run time: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "S" << endl;

    startTime = clock();
    cout << maxAreaOpt3(iVectorData) << endl;
    endTime = clock();
    cout << "Run time: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "S" << endl;
    return 0;
}
