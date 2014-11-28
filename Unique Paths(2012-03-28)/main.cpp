#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

/**
 * 从左上角到右下角路径个数
 * 只能向下或向右
 * @param  m 矩阵行数
 * @param  n 矩阵列数
 * @return   路径数
 */
int uniquePaths(int m, int n)
{
    if (m == 1 || n == 1)
        return 1;
    else
        return uniquePaths(m, n - 1) + uniquePaths(m - 1, n);
}

/**
 * 从左上角到右下角路径个数
 * 只能向下或向右
 * @param  m 矩阵行数
 * @param  n 矩阵列数
 * @return   路径数
 */
int uniquePathsOpt(int m, int n)
{
    return  (m == 1 || n == 1) ? 1 : uniquePaths(m, n - 1) + uniquePaths(m - 1, n);
}

/**
 * 从左上角到右下角路径个数
 * 只能向下或向右
 * @param  m 矩阵行数
 * @param  n 矩阵列数
 * @return   路径数
 */
int uniquePathsOpt2(int m, int n)
{
    vector<int> iVectorData(n, 1);
    for (int i = 1; i < m; ++i)
        for (int i = 1; i < n; ++i)
            iVectorData[i] += iVectorData[i-1];

    return iVectorData[n-1];
}

int main()
{
    int m = 23, n = 12;

    clock_t startTime, endTime;
    startTime = clock();
    cout << uniquePaths(m, n) << endl;
    endTime = clock();
    cout<< "Run time: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "S" << endl;

    startTime = clock();
    cout << uniquePathsOpt(m, n) << endl;
    endTime = clock();
    cout<< "Run time: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "S" << endl;

    startTime = clock();
    cout << uniquePathsOpt2(m, n) << endl;
    endTime = clock();
    cout<< "Run time: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "S" << endl;


    return 0;
}
