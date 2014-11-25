#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

/**
 * 生成vector<vector<int> >矩阵
 * @param matrix 输入遍历矩阵
 * @param n      矩阵行数
 * @param n      矩阵列数
 */
void creteMatrix(vector<vector<int> > &matrix, const int m, const int n)
{
    if (m < 0 || n < 0)
        return;

    int iCout = 0;
    for (int i = 0; i < m; i++)
    {
        vector<int> iVectorData;

        for (int j = 0; j < n; j++)
        {
            iVectorData.push_back(++iCout);
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

vector<int> SpiralMatrix(vector<vector<int> > &matrix)
{
    vector<int> iVectorData; // 开辟遍历数组

    if (matrix.empty())
        return iVectorData;

    int iRow = matrix.size(); // 行数
    int iCol = matrix[0].size(); // 列数


    int iHalf = (min(iRow, iCol) + 1) >> 1;

    // 每次按顺时针方向遍历一个正方形的边
    for (int i = 0; i < iHalf; ++i)
    {
        // 遍历上边界
        int k = i;
        while (k < iCol - i)
        {
            iVectorData.push_back(matrix[i][k]);
            k++;
        }

        // 遍历右边界
        k = i + 1;
        while (k < iRow - i)
        {
            iVectorData.push_back(matrix[k][iCol - i - 1]);
            k++;
        }

        // 遍历下边界
        k = iCol - i - 2;
        while ((k >= i) && (iRow - i - 1) > i)
        {
            iVectorData.push_back(matrix[iRow - i - 1][k]);
            k--;
        }

        // 遍历左边界
        k = iRow - i - 2;
        while ((k > i) && (i < iCol - i - 1))
        {
            iVectorData.push_back(matrix[k][i]);
            k--;
        }
    }

    return iVectorData;
}

int main()
{
    vector<vector<int> > matrix;
    creteMatrix(matrix, 7, 5);
    showMatrix(matrix);

    vector<int> iVectorData = SpiralMatrix(matrix);

    for (vector<int>::iterator it = iVectorData.begin(); it != iVectorData.end(); ++it)
        cout << *it << " ";

    cout << endl;

    return 0;
}
