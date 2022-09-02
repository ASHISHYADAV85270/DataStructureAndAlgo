#include <bits/stdc++.h>
#include <iostream>
using namespace std;

unordered_map<int, int> m;
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        stack<int> s;
        vector<int> nge(10002);

        for (int i = nums2.size()-1; i >= 0; i--)
        {
            while (!s.empty() && nums2[i] >= s.top())
            {
                s.pop();
            }
            if (!s.empty())
            {
                nge[nums2[i]] = s.top();
            }
            else
            {
                nge[nums2[i]] = -1;
            }
            s.push(nums2[i]);
        }
        vector<int> final;
        for (int i = 0; i < nums1.size(); i++)
        {
            final.push_back(nge[nums1[i]]);
        }
        return final;
    }
};
int main()
{

    return 0;
}