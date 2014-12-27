#include <iostream>
#include <vector>

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

void rotateAntiClockWise(vector<vector<int> > &matrix)
{
    int n = matrix.size();
    int iHalf = (n + 1) >> 1;

    for (int i = 0; i < iHalf; ++i)
    {
        int j = i;
        while (j < n - i - 1)
        {
            int temp = matrix[i][j]; // 等号后上三角
            matrix[i][j] = matrix[j][n-i-1]; // 等号后右三角
            matrix[j][n-i-1] = matrix[n-i-1][n-j-1]; // 等号后下三角
            matrix[n-i-1][n-j-1] = matrix[n-j-1][i]; // 等号后左三角
            matrix[n-j-1][i] = temp;
            ++j;
        }
    }
}

void rotateClockWise(vector<vector<int> > &matrix)
{
    int n = matrix.size();
    int iHalf = (n + 1) >> 1;

    for (int i = 0; i < iHalf; ++i)
    {
        int j = i;
        while (j < n - i - 1)
        {
            int temp = matrix[i][j]; // 等号后上三角
            matrix[i][j] = matrix[n-j-1][i]; // 等号后左三角
            matrix[n-j-1][i] = matrix[n-i-1][n-j-1]; // 等号后下三角
            matrix[n-i-1][n-j-1] = matrix[j][n-i-1]; // 等号后右三角
            matrix[j][n-i-1] = temp;
            ++j;
        }
    }
}

int main()
{
    vector<vector<int> > matrix;
    creteMatrix(matrix, 4, 4);
    showMatrix(matrix);

    rotateAntiClockWise(matrix);

    showMatrix(matrix);

    rotateClockWise(matrix);

    showMatrix(matrix);

    return 0;
}
