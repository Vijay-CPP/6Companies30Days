#include <bits/stdc++.h>
using namespace std;
#define v vector

class Solution
{
public:
    bool isOperator(string op)
    {
        return op == "+" || op == "-" || op == "*" || op == "/";
    }

    int evalRPN(vector<string> &tokens)
    {

        stack<long long int> st;
        st.push(stoi(tokens[0]));

        for (int i = 1; i < tokens.size(); i++)
        {
            if (isOperator(tokens[i]))
            {
                long long int a = st.top();
                long long int b = 0;
                st.pop();

                if (!st.empty())
                {
                    b = st.top();
                    st.pop();
                }

                long long int ans = 0;

                if (tokens[i] == "+")
                    ans = b + a;
                else if (tokens[i] == "-")
                    ans = b - a;
                else if (tokens[i] == "*")
                    ans = b * a;
                else if (tokens[i] == "/")
                    ans = b / a;

                st.push(ans);
            }
            else
                st.push(stoi(tokens[i]));
        }

        return st.top();
    }
};

int main()
{
    
    return 0;
}