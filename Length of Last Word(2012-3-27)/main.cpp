/**
 * Given a string s consists of upper/lower-case alphabets
 * and empty space characters ' ', return the length of
 * last word in the string.
 *
 * If the last word does not exist, return 0.
 *
 * Note: A word is defined as a character sequence consists of non-space characters only.
 *
 * For example,
 * Given s = "Hello World",
 * return 5.
 */

#include <iostream>
#include <string>

using namespace std;

int lengthOfLastWord(const char *s)
{
    int iLen = 0;
    int iLengthOfLastWord = 0;

    while (s[iLen] != '\0')
    {
        iLengthOfLastWord = 0;
        while (s[iLen] != ' ' && s[iLen] != '\0')
        {
            ++iLengthOfLastWord;
            ++iLen;
        }
        while (s[iLen] == ' ')
            ++iLen;
    }

    return iLengthOfLastWord;
}

int main()
{
    string str;
    getline(cin, str);

    const char *p = str.c_str();

    cout << LengthOfLastWord(p) << endl;

    return 0;
}
