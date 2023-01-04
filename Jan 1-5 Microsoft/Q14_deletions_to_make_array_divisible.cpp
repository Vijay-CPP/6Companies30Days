#include <bits/stdc++.h>
using namespace std;
#define v vector

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        
        map<int, int> m;

        for(auto it : nums)
            m[it]++;


        int prevEle = 0;
        for(auto i : m)
        {
            int count = 0;

            for(auto j : numsDivide)
            {
                if(j % i.first != 0)
                    break;
                else
                    count++;
            }

            if(count == numsDivide.size())
                return prevEle;

            prevEle += i.second;
        }

        return -1;
    }
};

int main()
{
    

    return 0;
}