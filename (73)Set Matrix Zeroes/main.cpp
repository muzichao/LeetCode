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
        srand(i);

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
 * 如果矩阵的某个元素为零，则令该元素所在行和列为零
 * @param matrix 输入矩阵
 */
void setZeroes(vector<vector<int> > &matrix)
{
    vector<int> iVecRow(matrix.size(), 0);
    vector<int> iVecCol(matrix[0].size(), 0);

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (0 == matrix[i][j])
            {
                iVecRow[i] = 1;
                iVecCol[j] = 1;
            }
        }
    }

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (1 == iVecRow[i] || 1 == iVecCol[j])
            {
                matrix[i][j] = 0;
            }
        }
    }
}



int main()
{
    vector<vector<int> > matrix;
    creteMatrix(matrix, 5, 6);
    showMatrix(matrix);

    setZeroes(matrix);
    showMatrix(matrix);

    return 0;
}
