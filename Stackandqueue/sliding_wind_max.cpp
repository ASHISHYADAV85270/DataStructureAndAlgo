#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int i = 0, j = 0, n = nums.size();
        vector<int> max_ans;
        list<int> l;
        while (j < n)
        {
            while (!l.empty() && l.back() <= nums[j])
            {
                l.pop_back();
            };
            l.push_back(nums[j]);

            //  sliding and calculations
            if (j - i + 1 < k)
            {
                j++;
            }
            else if (j - i + 1 == k)
            {
                max_ans.push_back(l.front());
                if (nums[i] == l.front())
                {
                    l.pop_front();
                }
                i++;
                j++;
            }
        }
        return max_ans;
    }
};
int main()
{
    return 0;
}