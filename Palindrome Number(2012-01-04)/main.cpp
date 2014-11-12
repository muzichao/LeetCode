/**
 * Determine whether an integer is a palindrome.
 * Do this without extra space.
 * "回文数"是一种数字。如：98789, 这个数字正读是98789,
 * 倒读也是98789,正读倒读一样，所以这个数字就是回文数。
 */
#include <iostream>

using namespace std;

bool isPalindrome(int x)
{
    if (x < 0)
        return false;

    int iData = 0;
    int iX = x;

    while (0 != iX)
    {
        iData = 10 * iData + (iX % 10);
        iX /= 10;
    }


    return x == iData;
}


int main()
{
    int x = 121;

    cout << "Palindrome Number : " << isPalindrome(x) << endl;

    return 0;
}
