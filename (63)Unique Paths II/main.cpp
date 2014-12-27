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
            iVectorData.push_back(int(rand() > 25000));
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

int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<int> iVectorData(n, 0);

    iVectorData[0] = obstacleGrid[0][0] == 0 ? 1 : 0;
    for (int i = 0; i < m; ++i)
    {
        iVectorData[0] = obstacleGrid[i][0] == 0 ? iVectorData[0] : 0;
        for (int j = 1; j < n; ++j)
            iVectorData[j] = obstacleGrid[i][j] == 0 ? iVectorData[j] + iVectorData[j - 1] : 0;
    }

    return iVectorData[n - 1];
}

int main()
{
    vector<vector<int> > matrix;
    creteMatrix(matrix, 5, 5);
    showMatrix(matrix);

    cout << uniquePathsWithObstacles(matrix) << endl;

    return 0;
}
