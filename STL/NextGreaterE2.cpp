// circular bala
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
vector<int> nextGreaterElements(vector<int> &nums)
{
    stack<int> s;
    vector<int> nge(nums.size());
    int n = nums.size();
    for (int i = (2 * n) - 1; i >= 0; i--)
    {
        while (!s.empty() && nums[i % n] >= s.top())
        {
            s.pop();
        }
        if (i < n)
        {

            if (!s.empty())
            {
                nge[i] = s.top();
            }
            else
            {
                nge[i] = -1;
            }
        }
        s.push(nums[i % n]);
    }
    return nge;
}
int main()
{

    return 0;
}