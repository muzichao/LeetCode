#include <iostream>

using namespace std;

string intToRoman(int num)
{
    char ch[20] = {};
    int iCout = 0;

    while (num > 0)
    {

        if (num >= 1000)
        {
            ch[iCout++] = 'M';
            num -= 1000;
        }
        else if (num >= 900)
        {
            ch[iCout++] = 'C';
            ch[iCout++] = 'M';
            num -= 900;
        }
        else if (num >= 500)
        {
            ch[iCout++] = 'D';
            num -= 500;
        }
        else if (num >= 400)
        {
            ch[iCout++] = 'C';
            ch[iCout++] = 'D';
            num -= 400;
        }
        else if (num >= 100)
        {
            ch[iCout++] = 'C';
            num -= 100;
        }
        else if (num >= 90)
        {
            ch[iCout++] = 'X';
            ch[iCout++] = 'C';
            num -= 90;
        }
        else if (num >= 50)
        {
            ch[iCout++] = 'L';
            num -= 50;
        }
        else if (num >= 40)
        {
            ch[iCout++] = 'X';
            ch[iCout++] = 'L';
            num -= 40;
        }
        else if (num >= 10)
        {
            ch[iCout++] = 'X';
            num -= 10;
        }
        else if (num >= 9)
        {
            ch[iCout++] = 'I';
            ch[iCout++] = 'X';
            num -= 9;
        }
        else if (num >= 5)
        {
            ch[iCout++] = 'V';
            num -= 5;
        }
        else if (num >= 4)
        {
            ch[iCout++] = 'I';
            ch[iCout++] = 'V';
            num -= 4;
        }
        else
        {
            ch[iCout++] = 'I';
            num -= 1;
        }
    }

    return ch;
}

int main()
{
    int num = 1976;
    cout << intToRoman(num) << endl;

    return 0;
}
