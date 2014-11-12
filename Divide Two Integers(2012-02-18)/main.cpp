/**
 * Divide two integers without using multiplication,
 * division and mod operator.
 */

#include <iostream>
#include <time.h>

using namespace std;

/**
 * 不用除法，乘法，取余，求两个int数的商
 * 1. 利用累加法
 * @param  dividend [除数]
 * @param  divisor  [被除数]
 * @return          [商]
 */
int divide(int dividend, int divisor)
{
    long long int iAbsiDvidend = dividend;
    long long int iAbsDivisor = divisor;

    // 判断是否同号
    int flag = 0;
    if ((iAbsiDvidend > 0 && iAbsDivisor > 0) || (iAbsiDvidend < 0 && iAbsDivisor < 0))
        flag = 0;
    else
        flag = 1;

    iAbsiDvidend = iAbsiDvidend < 0 ? -iAbsiDvidend : iAbsiDvidend;
    iAbsDivisor = iAbsDivisor < 0 ? -iAbsDivisor : iAbsDivisor;

    long long int iTimes = 0;
    long long int iSum = 0;

    while (iSum <= iAbsiDvidend)
    {
        iSum += iAbsDivisor;
        ++iTimes;
    }

    return flag > 0 ? -(iTimes - 1) : iTimes - 1;
}

/**
 * 不用除法，乘法，取余，求两个int数的商
 * 1. 用左移操作乘2，找到商的区间[2^(n-1), 2^n]
 * 2. 用二分法查找
 * @param  dividend [除数]
 * @param  divisor  [被除数]
 * @return          [商]
 */
int divideOpt(int dividend, int divisor)
{
    long long int iAbsiDvidend = dividend;
    long long int iAbsDivisor = divisor;

    // 判断是否同号
    int flag = -1; // 0 : 同号; 1 : 异号
    if ((iAbsiDvidend > 0 && iAbsDivisor > 0) || (iAbsiDvidend < 0 && iAbsDivisor < 0))
        flag = 1;

    iAbsiDvidend = iAbsiDvidend < 0 ? -iAbsiDvidend : iAbsiDvidend;
    iAbsDivisor = iAbsDivisor < 0 ? -iAbsDivisor : iAbsDivisor;

    // 标记区间左值
    long long int iSumSmall = 0;
    long long int iTimesSmall = 0;

    // 标记区间右值
    long long int iTimesBig = 1;
    long long int iSumBig = iAbsDivisor;

    // 以2倍递增，直到
    // iTimesBig * iAbsDivisor > iAbsiDvidend
    while (iSumBig <= iAbsiDvidend)
    {
        iTimesBig = iTimesBig << 1;
        iSumBig = iSumBig << 1;
    }

    // iTimesSmall * iAbsDivisor < iAbsiDvidend
    iTimesSmall = iTimesBig >> 1;
    iSumSmall = iSumBig >> 1;


    // 折半查找
    while (iTimesSmall != iTimesBig && iTimesSmall != iTimesBig - 1)
    {
        // 计算中值
        long long int iSumMid = (iSumBig + iSumSmall) >> 1;
        long long int iTimesMid = (iTimesSmall + iTimesBig) >> 1;

        // cout << iSumSmall << " " << iSumBig << " " << iSumMid << endl;

        // 根据中值计算新的区间
        if (iSumMid < iAbsiDvidend)
        {
            iTimesSmall = iTimesMid;
            iSumSmall = iSumMid;
        }
        else if (iSumMid > iAbsiDvidend)
        {
            iTimesBig = iTimesMid;
            iSumBig = iSumMid;
        }
        else
        {
            return flag > 0 ? iTimesMid : -iTimesMid;
        }
    }

    return flag > 0 ? iTimesSmall : -iTimesSmall;
}

int main()
{
    int a = 0x70000000;
    int b = 1;

    clock_t startTime, endTime;
    // startTime = clock();
    // cout << divide(a, b) << endl;
    // endTime = clock();
    // cout << "Run time: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "S" << endl;

    startTime = clock();
    for (int i = 0; i < 10000; ++i)
    {
        int aa = divideOpt(a, b);
    }
    cout << divideOpt(a, b) << endl;
    endTime = clock();
    cout << "Run time: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "S" << endl;

    startTime = clock();
    for (int i = 0; i < 10000; ++i)
    {
        int bb = divideOpt2(a, b);
    }
    cout << divideOpt2(a, b) << endl;
    endTime = clock();
    cout << "Run time: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "S" << endl;
    return 0;
}
