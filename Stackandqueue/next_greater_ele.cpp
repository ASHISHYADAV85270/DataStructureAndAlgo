#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans_nge(n, -1);
        stack<int> s;
        for (int i = 2 * n - 1; i >= 0; i--)
        {
            while (!s.empty() && s.top() <= nums[i % n])
            {
                s.pop();
            };
            if (i < n)
            {
                if (s.empty())
                {
                    ans_nge[i] = -1;
                }
                else
                {
                    ans_nge[i] = s.top();
                }
            }
            s.push(nums[i % n]);
        }
        return ans_nge;
    }

    // for not circular
    vector<int> rightsmallest(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> r_smallest(arr.size(), 0);
        stack<int> st;
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            };
            if (st.empty())
            {
                r_smallest[i] = n - 1;
            }
            else
            {
                r_smallest[i] = st.top();
            }
            st.push(i);
        }

        return r_smallest;
    }
};
int main()
{
    return 0;
}