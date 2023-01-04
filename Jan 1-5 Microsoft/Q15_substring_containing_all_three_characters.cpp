#include <bits/stdc++.h>
using namespace std;
#define v vector

class Solution
{
public:
    int numberOfSubstrings(string s)
    {

        int count = 0;
        int a = -1, b = -1, c = -1;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'a')
                a = i;
            else if (s[i] == 'b')
                b = i;
            else
                c = i;

            if (a == -1 || b == -1 || c == -1)
                continue;

            count += min(a, min(b, c)) + 1;
        }

        return count;
    }
};

int main()
{

    return 0;
}