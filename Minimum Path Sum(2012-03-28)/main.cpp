#include <iostream>
#include <vector>
#include <stdlib.h>

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
        srand(i * i);

        for (int j = 0; j < n; j++)
        {
            iVectorData.push_back(rand() % n);
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
 * 最短路径和
 * @param  grid 矩阵
 * @return      最短路径
 */
int minPathSum(vector<vector<int> > &grid)
{
    if (grid.empty())
        return 0;

    int iRow = grid.size();
    int iCol = grid[0].size();

    vector<int> iVecData(iCol, 0);

    iVecData[0] = grid[0][0];
    for (int j = 1; j < iCol; j++)
        iVecData[j] = grid[0][j] + iVecData[j - 1];

    for (int i = 1; i < iRow; i++)
    {
        iVecData[0] += grid[i][0];
        for (int j = 1; j < iCol; j++)
            iVecData[j] = grid[i][j] + min(iVecData[j - 1], iVecData[j]);
    }

    return iVecData[iCol - 1];
}

int main()
{
    vector<vector<int> > matrix;
    creteMatrix(matrix, 5, 5);
    showMatrix(matrix);

    cout << minPathSum(matrix) << endl;

    return 0;
}
