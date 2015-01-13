#include <iostream>

using namespace std;

/**
 * 字符串的之字形转换
 * @param  s     输入字符串
 * @param  nRows 行数
 * @return       转换后的字符串
 */
string convert(string s, int nRows)
{
    if (nRows <= 1 || s.length() == 0)
        return s;

    int iLength = s.size();
    int iSpace = 2 * nRows - 2;

    string sResult = "";

    for (int i = 0; i < nRows; ++i)
    {
        for (int k = i; k < iLength; k += iSpace)
        {
            sResult += s[k];
            if ((i != 0) && (i != nRows - 1))
            {
                int iNewSpace = k + iSpace - 2 * i;
                if (iNewSpace < iLength)
                {
                    sResult += s[iNewSpace];
                }
            }
        }
    }

    return sResult;
}

int main()
{
    string str = "0123456789abcdef";
    // string str = "abcdefghijklmnopqrst";
    int iRows = 5;

    cout << convert(str, iRows) << endl;

    return 0;
}
