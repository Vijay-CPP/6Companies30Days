#include <bits/stdc++.h>
using namespace std;
#define v vector

class Solution
{
public:
    vector<int> findSubset(int ind, vector<int> &nums, vector<vector<int>> &dp)
    {
        int n = nums.size();
        if (ind == n)
            return {};

        if (dp[ind].size() != 0)
            return dp[ind];

        vector<int> ans;

        for (int i = ind + 1; i < n; i++)
        {
            if (nums[i] % nums[ind] != 0)
                continue;

            vector<int> res = findSubset(i, nums, dp);
            if (res.size() >= ans.size())
                ans = res;
        }

        ans.push_back(nums[ind]);
        return dp[ind] = ans;
    }

    vector<int> largestDivisibleSubset(vector<int> &nums)
    {

        sort(nums.begin(), nums.end());
        vector<int> ans;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            vector<vector<int>> dp(n);
            vector<int> res;
            res = findSubset(i, nums, dp);

            if (res.size() >= ans.size())
                ans = res;
        }

        return ans;
    }
};

int main()
{

    return 0;
}