#include <iostream>
#include <string>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    const char *cStr = s.c_str();

    int iLength = s.size();
    int iResult = 0;

    // 从第i个字符开始查找
    for (int i = 0; i < iLength; ++i)
    {
        int iSubResult = 1;

        // 从第(i+1)个字符开始添加不同的字符
        for (int j = i + 1; j < iLength; ++j)
        {
            // 判断第j个字符是否与(i,j-1)之间的字符不同
            for (int k = i; k < j; ++k)
            {
                if (cStr[k] == cStr[j])
                {
                    k = j;
                    j = iLength;
                }
            }

            // 当前字符满足条件
            if (j < iLength)
            {
                iSubResult++;
            }
        }

        // 是否更新当前最长子字符串
        if (iSubResult > iResult)
        {
            iResult = iSubResult;
        }
    }

    return iResult;
}

int lengthOfLongestSubstringOpt(string s)
{
    const char *cStr = s.c_str();

    int iLength = s.size(); // 字符串长度
    if (0 == iLength)
    {
        return 0;
    }

    int iResult = 1; // 输出结果

    int iLeft = 0; // 满足条件的子字符串的起始位置
    int iRight = 0; // 满足条件的子字符串的终止位置

    // 从第i个字符开始查找
    for (int i = 1; i < iLength; ++i)
    {
        for (int j = iLeft; j <= iRight; ++j)
        {
            if (cStr[j] == cStr[i])
            {
                iLeft = j + 1;
                break;
            }
        }

        iRight++;

        // 是否更新当前最长子字符串
        int iSubResult = iRight - iLeft + 1;
        if (iSubResult > iResult)
        {
            iResult = iSubResult;
        }
    }

    return iResult;
}

int main()
{

    // string str = "abcabcdabcdebaf";
    string str = "abcabcdabcdebafcd";
    // string str = "abcabc";
    // string str = "a";

    cout << lengthOfLongestSubstring(str) << endl;
    cout << lengthOfLongestSubstringOpt(str) << endl;

    return 0;
}
