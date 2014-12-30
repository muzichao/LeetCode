#include <iostream>
using namespace std;

/**
 * Excel 表格行数转换
 * @param  s string
 * @return   int
 */
int titleToNumber(string s)
{
    int iTimes = 1;
    int iNum = 0;
    for (int i = s.size() - 1; i >= 0; --i)
    {
        iNum += (int(s[i]) - 64) * iTimes;
        iTimes *= 26;
    }

    return iNum;
}

int main()
{
    string s = "AAA";

    cout << titleToNumber(s) << endl;

    return 0;
}
