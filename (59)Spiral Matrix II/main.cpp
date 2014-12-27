#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;


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
 * 产生螺旋方阵
 * @param  n 方阵的行和列
 * @return   生成的方阵
 */
vector<vector<int> > SpiralMatrix(const int n)
{
    vector<vector<int> > matrix; // 开辟遍历数组

    vector<int> iVectorData(n, 0);
    for (int i = 0; i < n; ++i)
        matrix.push_back(iVectorData);

    int iRow = n; // 行数
    int iCol = n; // 列数
    int iHalf = (n + 1) >> 1;
    int iCout = 0;

    // 每次按顺时针方向遍历一个正方形的边
    for (int i = 0; i < iHalf; ++i)
    {
        // 遍历上边界
        int k = i;
        while (k < iCol - i)
        {
            matrix[i][k] = ++iCout;
            k++;
        }

        // 遍历右边界
        k = i + 1;
        while (k < iRow - i)
        {
            matrix[k][iCol - i - 1] = ++iCout;
            k++;
        }

        // 遍历下边界
        k = iCol - i - 2;
        while ((k >= i) && (iRow - i - 1) > i)
        {
            matrix[iRow - i - 1][k] = ++iCout;
            k--;
        }

        // 遍历左边界
        k = iRow - i - 2;
        while ((k > i) && (i < iCol - i - 1))
        {
            matrix[k][i] = ++iCout;
            k--;
        }
    }

    return matrix;
}

int main()
{
    vector<vector<int> > matrix;
    matrix = SpiralMatrix(4);
    showMatrix(matrix);

    return 0;
}
