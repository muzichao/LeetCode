#include <iostream>
#include <vector>

using namespace std;

void rotate(int nums[], int n, int k)
{
    k = k % n;
    int iLeftNum = n - k;
    vector<int> iNums;

    for (int i = 0; i < iLeftNum; i++)
    {
        iNums.push_back(nums[i]);
    }

    int i = 0;
    for (; i < k; i++)
    {
        nums[i] = nums[i + iLeftNum];
    }
    for (int j = 0; j < iLeftNum; j++)
    {
        nums[i] = iNums[j];
        i++;
    }
}

int main()
{
    const int iN(7);
    int nums[iN] = {1, 2, 3, 4, 5, 6, 7};

    rotate(nums, 7, 3);

    for (int i = 0; i < iN; i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}
