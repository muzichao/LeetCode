#include <iostream>
#include <set>
#include <math.h>

using namespace std;

/**
 * 计算输入整数中所有数字的平方和
 * @param  iN int 输入
 * @return    int 输出
 */
int CalculateSumOfEveryNumberSquare(int iN)
{
    int iMiddle = 0;
    while (iN)
    {
        iMiddle += pow(iN % 10, 2);
        iN /= 10;
    }

    return iMiddle;
}

/**
 * 判断一个数是否是 happy 数
 * @param  n int 输入
 * @return   bool 输出
 */
bool isHappy(int n)
{
    if (n <= 0)
        return false;

    set<int> iSet; // 定义一个容器，用于保存出现过的数，避免死循环
    iSet.insert(n); // 先将 n 插入容器

    while (1 != n)
    {
        n = CalculateSumOfEveryNumberSquare(n); // 计算各位数字的平方和

        // 查找新数是否在容器中，如果在，则说明开始循环
        if (iSet.find(n) != iSet.end())
            break;

        // 将新数插入到容器中
        iSet.insert(n);
    }

    // 此时 n 可能为1，也可能不为1
    if (1 == n)
        return true;

    return false;
}

int main()
{
    int iData = 19;
    cout << isHappy(iData) << endl;

    return 0;
}
