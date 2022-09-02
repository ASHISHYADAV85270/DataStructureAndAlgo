#include <bits/stdc++.h>
#include <iostream>
using namespace std;
unordered_map<char, int> symbols = {
    {'[', -1},
    {']', 1},
    {'{', -2},
    {'}', 2},
    {'(', -3},
    {')', 3},
};
string isBalanced(string s)
{
    stack<char> st;
    for (char val : s)
    {
        if (symbols[val] < 0)
        {
            st.push(val);
        }
        else
        {
            if (st.empty())
            {
                return "NO";
            }
            char top = st.top();
            st.pop();
            if (symbols[val] + symbols[top] != 0)
            {
                return "NO";
            }
        }
    }
    if (st.empty())
    {
        return "YES";
    }
    else
    {
        return "NO";
    }
}
