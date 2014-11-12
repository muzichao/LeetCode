#include <iostream>
#include <vector>
#include <set>

using namespace std;

// 使用最原始的双重 for 循环查找
vector<int> twoSum(vector<int> &numbers, int target)
{
    vector<int> index(2);
    for (int i = 0; i < numbers.size(); i++)
    {
        int iFindNumber = target - numbers[i];
        for (int j = i; j < numbers.size(); j++)
        {
            if (i != j &&  + numbers[j] == iFindNumber)
            {
                index[0] = i + 1;
                index[1] = j + 1;
                return index;
            }
        }
    }
    return index;
}

vector<int> twoSumOpt(vector<int> &numbers, int target)
{
    vector<int> index(2, 0);

    // 将 vector 数据放入 set 中，方便查找
    set<int> iSet(numbers.begin(), numbers.end());

    // 遍历每个 vecotr 中的值，利用 set 查找是否
    // 有满足条件的值与当前的遍历值之和满足条件
    for (int i = 0; i < numbers.size(); i++)
    {
        int iFindNumber = target - numbers[i];

        // 如果存在满足条件的值，则在vector中查找该值
        if (iSet.find(iFindNumber) != iSet.end())
        {
            for (int j = i; j < numbers.size(); j++)
            {
                // 要确保不是同一个位置的值的二倍等于 target
                if (iFindNumber == numbers[j] && i != j)
                {
                    index[0] = i + 1; // 先查找的值坐标肯定是小的值
                    index[1] = j + 1;
                    return index;
                }
            }
        }

    }
    return index;
}

int main()
{
    const int N(5); // 定义常数
    int iArray[N] = {3, 2, 5, 8, 4};
    vector<int> iVectorData(iArray, iArray + N);

    vector<int> iVectorIndex;

    iVectorIndex = twoSum(iVectorData, 6);

    cout << iVectorIndex[0] << " " << iVectorIndex[1] << endl;

    iVectorIndex = twoSumOpt(iVectorData, 6);

    cout << iVectorIndex[0] << " " << iVectorIndex[1] << endl;

    return 0;
}
