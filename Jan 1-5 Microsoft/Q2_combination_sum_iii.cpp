#include <bits/stdc++.h>
using namespace std;
#define v vector

class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> currComb;
    int sum = 0;

    void findCombinations(int n, int k, int start)
    {
        if (sum > n)
            return;

        if (k == 0)
        {
            if (sum == n)
                ans.push_back(currComb);

            return;
        }

        for (int i = start; i <= 9; i++)
        {

            sum += i;
            currComb.push_back(i);

            findCombinations(n, k - 1, i + 1);

            sum -= i;
            currComb.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {

        findCombinations(n, k, 1);
        return ans;
    }
};

int main()
{

    return 0;
}