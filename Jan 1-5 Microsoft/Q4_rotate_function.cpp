#include <bits/stdc++.h>
using namespace std;
#define v vector

class Solution
{
public:
    int maxRotateFunction(vector<int> &nums)
    {

        int totalSum = 0, currSum = 0, prevSum = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            totalSum += nums[i];
            currSum += nums[i] * i;
        }

        int lastIndex = n - 1;
        int maxSum = currSum;

        for (int i = 1; i < n; i++)
        {
            prevSum = currSum;
            currSum = prevSum + (totalSum)-nums[lastIndex] * n;
            lastIndex--;
            maxSum = max(maxSum, currSum);
        }

        return maxSum;
    }
};

int main()
{

    return 0;
}