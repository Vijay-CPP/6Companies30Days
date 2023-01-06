#include <bits/stdc++.h>
using namespace std;
#define v vector

class Solution
{
public:
    int trailingZeroes(int n)
    {

        int zeros = 0;
        int factor = 5;

        while (n / factor > 0)
        {
            zeros += n / factor;
            factor *= 5;
        }

        return zeros;
    }
};

int main()
{

    return 0;
}