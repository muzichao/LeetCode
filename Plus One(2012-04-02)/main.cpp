#include <iostream>
#include <vector>

using namespace std;

/**
 * 以Vector形式存储的数字加1
 * @param  digits 输入的Vector数组
 * @return        相加后的结果
 */
vector<int> plusOne(vector<int> &digits)
{
    // 如果为9，99，999 ... 的形式，数字位数应多1
    vector<int> iVecDigits(digits.size() + 1, 0);

    int iFlag = 1; // 标记是否有进位

    vector<int>::reverse_iterator it = digits.rbegin(); // vector数组的尾元素
    vector<int>::reverse_iterator itNew = iVecDigits.rbegin(); // 新数组的尾元素

    while ( it != digits.rend())
    {
        // 某位数字为9，且有进位，则该位置为0，进位为1
        if (iFlag != 0 && 9 == *it)
        {
            *itNew = 0;
            iFlag = 1;
        }
        else
        {
            *itNew = *it + iFlag;
            iFlag = 0;
        }
        ++it;
        ++itNew;
    }

    // 如果最后进位依然为1，则最高位为1，否则删除最高位
    if (1 == iFlag)
        *itNew = 1;
    else
        iVecDigits.erase(iVecDigits.begin());

    return iVecDigits;
}

int main()
{
    const int N(5); // 定义常数
    int iArray[N] = {8, 9, 9, 9, 9};
    vector<int> iVectorData(iArray, iArray + N);

    vector<int> iVectorIndex;

    iVectorIndex = plusOne(iVectorData);

    vector<int>::iterator it = iVectorIndex.begin();
    while (it != iVectorIndex.end())
    {
        cout << *it << " ";
        it++;
    }

    return 0;
}
