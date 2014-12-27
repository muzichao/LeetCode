#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 生成vector<vector<int> >矩阵
 * @param matrix 输入输出矩阵
 * @param m      矩阵行数
 * @param n      矩阵列数
 */
void creteMatrix(vector<vector<int> > &matrix, const int m, const int n)
{
    if (m < 0 || n < 0 )
        return;

    for (int i = 0; i < m; i++)
    {
        vector<int> iVectorData;

        for (int j = 0; j < n; j++)
        {
            iVectorData.push_back(i * 2 * n + j + 1);
        }

        matrix.push_back(iVectorData);
    }
}

/**
 * 显示矩阵
 * @param matrix 输入矩阵
 */
void showMatrix(vector<vector<int> > &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

/**
 * searchMatrix 矩阵中元素搜索
 * @param  matrix 输入矩阵
 * @param  target 搜索元素
 * @return        true 或者 false
 */
bool searchMatrix(vector<vector<int> > &matrix, int target)
{
    if (matrix.empty())
        return false;

    for (int i = 0; i < matrix.size(); i++)
    {
        int iVecCol = matrix[i].size();
        if (target <= matrix[i][iVecCol - 1] && target >= matrix[i][0])
        {
            // find函数在<algorithm>头文件中
            vector<int>::iterator it = find(matrix[i].begin(), matrix[i].end(), target);

            if (it != matrix[i].end())
                return true;
        }
    }
    return false;
}

/**
 * searchMatrix 矩阵中元素搜索
 * @param  matrix 输入矩阵
 * @param  target 搜索元素
 * @return        true 或者 false
 */
bool searchMatrixOpt(vector<vector<int> > &matrix, int target)
{
    if (matrix.empty())
        return false;

    int iFirst = 0;
    int iLast = matrix.size() - 1;
    int iVecCol = matrix[iFirst].size();

    while (iFirst < iLast)
    {
        int iMid = (iLast + iFirst) >> 1;
        if (target > matrix[iMid][iVecCol - 1])
            iFirst = iMid + 1;
        else
            iLast = iMid;
    }

    // find函数在<algorithm>头文件中
    vector<int>::iterator it = find(matrix[iFirst].begin(), matrix[iFirst].end(), target);

    if (it != matrix[iFirst].end())
        return true;

    return false;
}

int main()
{
    vector<vector<int> > matrix;
    creteMatrix(matrix, 9, 8);
    showMatrix(matrix);

    cout << searchMatrix(matrix, 41) << endl;

    cout << searchMatrixOpt(matrix, 41) << endl;
    return 0;
}
