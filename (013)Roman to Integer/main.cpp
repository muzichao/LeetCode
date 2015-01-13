#include <iostream>

using namespace std;

int romanToInt(string s)
{
    const char *str = s.c_str();
    int iResult = 0;

    int iCout = 0;
    while (iCout < s.size())
    {
        switch (str[iCout++])
        {
        case 'M':
            iResult += 1000;
            break;
        case 'D':
            iResult += 500;
            break;
        case 'C':
            if ('M' == str[iCout])
            {
                iResult += 900;
                iCout++;
            }
            else if ('D' == str[iCout])
            {
                iResult += 400;
                iCout++;
            }
            else
            {
                iResult += 100;
            }
            break;
        case 'L':
            iResult += 50;
            break;
        case 'X':
            if ('C' == str[iCout])
            {
                iResult += 90;
                iCout++;
            }
            else if ('L' == str[iCout])
            {
                iResult += 40;
                iCout++;
            }
            else
            {
                iResult += 10;
            }
            break;
        case 'V':
            iResult += 5;
            break;
        default :
            if ('X' == str[iCout])
            {
                iResult += 9;
                iCout++;
            }
            else if ('V' == str[iCout])
            {
                iResult += 4;
                iCout++;
            }
            else
            {
                iResult++;
            }
            break;
        }
    }
    return iResult;
}

int main()
{
    string str = "MCDLXXVI";

    cout << romanToInt(str) << endl;

    return 0;
}
