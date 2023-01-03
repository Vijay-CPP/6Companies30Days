#include <bits/stdc++.h>
using namespace std;
#define v vector

// O(n) - Optimized
class Solution
{
public:
    string getHint(string secret, string guess)
    {

        int cows = 0, bulls = 0;
        vector<int> hash(10, 0);

        for (int i = 0; i < secret.length(); i++)
        {
            int s = secret[i] - '0';
            int g = guess[i] - '0';

            if (s == g)
                bulls++;
            else
            {
                if (hash[s] < 0)
                    cows++;
                if (hash[g] > 0)
                    cows++;

                hash[s]++;
                hash[g]--;
            }
        }

        string ans = to_string(bulls) + 'A' + to_string(cows) + 'B';
        return ans;
    }
};


// O(nlogn)
class Solution2 {
public:
    string getHint(string secret, string guess) {
        int cows = 0;
        int bulls = 0;

        for(int i=0; i<secret.length(); i++)
            if(secret[i] == guess[i])
            {
                bulls++;
                secret[i] = '#';
                guess[i] = '#';
            }

        unordered_map<char, int> m;
        for(auto it : secret)
            m[it]++;

        for(int i=0; i<guess.length(); i++)
        {
            if(secret[i] != '#')
            {
                if(m.find(guess[i]) != m.end())
                {    
                    cows++;
                    m[guess[i]]--;

                    if(m[guess[i]] == 0)
                        m.erase(guess[i]);
                }
            }
        }

        string ans = to_string(bulls) + 'A' + to_string(cows) + 'B';
        return ans;
    }
};

int main()
{

    return 0;
}