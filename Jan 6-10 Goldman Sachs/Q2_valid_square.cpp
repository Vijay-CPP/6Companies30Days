#include <bits/stdc++.h>
using namespace std;
#define v vector

class Solution
{
public:
    long long int disFormula(vector<int> &p1, vector<int> &p2)
    {
        return pow(p2[1] - p1[1], 2) + pow(p2[0] - p1[0], 2);
    }

    bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
    {

        if (p1 == p2 || p2 == p3 || p3 == p4 || p4 == p1 || p1 == p3 || p2 == p4)
            return false;

        unordered_map<long long int, long long int> m;

        m[disFormula(p1, p2)]++;
        m[disFormula(p2, p3)]++;
        m[disFormula(p3, p4)]++;
        m[disFormula(p4, p1)]++;
        m[disFormula(p1, p3)]++;
        m[disFormula(p4, p2)]++;

        if (m.size() <= 2)
            return true;

        return false;
    }
};

int main()
{

    return 0;
}