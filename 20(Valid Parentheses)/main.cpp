/**
 * Given a string containing just the characters
 * '(', ')', '{', '}', '[' and ']', determine if
 * the input string is valid.
 *
 * The brackets must close in the correct order,
 * "()" and "()[]{}" are all valid but "(]" and
 * "([)]" are not.
 */

#include <iostream>
#include <stack>

using namespace std;

bool isValid(string s)
{
    stack<char> stk; // 声明栈
    const char *cStr = s.c_str(); // string字符串转为char数组

    int iNum = 0;

    while (iNum <= s.size())
    {
        if (cStr[iNum] == '(' || cStr[iNum] == '[' || cStr[iNum] == '{') // 左括号，入栈
        {
            stk.push(cStr[iNum]);
        }
        else if (cStr[iNum] == ')' || cStr[iNum] == ']' || cStr[iNum] == '}') // 右括号，出栈
        {
            if (stk.empty()) // 如果此时栈为空，错误
            {
                return false;
            }
            else if ((cStr[iNum] == ')' && stk.top() == '(') ||
                     (cStr[iNum] == ']' && stk.top() == '[') ||
                     (cStr[iNum] == '}' && stk.top() == '{')) // 不配对，错误
            {
                stk.pop();
            }
            else
            {
                return false;
            }
        }
        iNum++;
    }

    return stk.empty();
}

int main()
{
    string str = "()";

    cout << isValid(str) << endl;
    return 0;
}
