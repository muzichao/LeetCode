#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int> &prices)
{
    if (prices.size() <= 1)
        return 0;

    int iMaxProfit = 0;
    vector<int>::iterator iterBuy = prices.begin();
    vector<int>::iterator iterSell;

    for (; iterBuy != prices.end() - 1; iterBuy++)
    {
        for (iterSell = iterBuy + 1; iterSell != prices.end(); iterSell++)
        {
            int iPrice = iMaxProfit + *iterBuy;
            if (*iterSell > iPrice)
                iMaxProfit = *iterSell - *iterBuy;
        }
    }
    return iMaxProfit;
}

int maxProfitOpt(vector<int> &prices)
{
    if (prices.size() <= 1)
        return 0;

    int iMaxProfit = 0; // 收益
    vector<int>::iterator iterMin = prices.begin();
    vector<int>::iterator iterSell = prices.begin() + 1;

    int iCurMin = *iterMin; // 当前最小

    for (; iterSell != prices.end(); iterSell++)
    {
        iMaxProfit = max(iMaxProfit, *iterSell - iCurMin);
        iCurMin = min(iCurMin, *iterSell);
    }

    return iMaxProfit;
}

int main()
{
    int iData[11] = {21, 13, 16, 28, 16, 45, 23, 1, 24, 40, 23};

    vector<int> iVectorData(iData, iData + 11);

    cout << maxProfit(iVectorData) << endl;

    cout << maxProfitOpt(iVectorData) << endl;

    return 0;
}


