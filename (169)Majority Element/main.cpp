#include <iostream>
#include <vector>
#include <hash_map>
#include <map>

using namespace std;

int majorityElementHashmap(vector<int> &num)
{
    int iResult = 0;
    hash_map<int, int> hNumberOfData;

    for (int i = 0; i < num.size(); i++)
    {
        hNumberOfData[num[i]]++;
    }
    for (int i = 0; i < num.size(); i++)
    {
        if (hNumberOfData[num[i]] >= (num.size() >> 1))
        {
            iResult = num[i];
            break;
        }
    }
    return iResult;
}

int majorityElement(vector<int> &num)
{
    int iResult = 0;
    map<int, int> hNumberOfData;

    for (int i = 0; i < num.size(); i++)
    {
        hNumberOfData[num[i]]++;
    }
    for (int i = 0; i < num.size(); i++)
    {
        if (hNumberOfData[num[i]] >(num.size() >> 1))
        {
            iResult = num[i];
            break;
        }
    }
    return iResult;
}

int main()
{
    const int N(14);
    vector<int> num = { 1, 2, 1, 3, 1, 4, 5, 5, 1, 6, 1, 1};

    cout << majorityElement(num) << endl;
}
