#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <stack>
#include <vector>

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    vector<int> nrs_ans(n, -1);
    for (int i = n - 1; i >= 0; i--)
    {
        if (s.empty())
        {
            nrs_ans[i] = -1;
        }
        else
        {
            while (!s.empty() && s.top() >= arr[i])
            {
                s.pop();
            };
            if (s.empty())
            {
                nrs_ans[i] = -1;
            }
            else
            {
                nrs_ans[i] = s.top();
            }
        }
        s.push(arr[i]);
    }
    return nrs_ans;
}
int main()
{
    return 0;
}
