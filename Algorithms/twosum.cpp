#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> um;
        for (int i = 0; i < nums.size(); i++)
        {
            int x = nums[i], y = target - x;
            if (um.find(y) != um.end())
            {
                return {i, um[i]};
            }

            um[nums[i]] = i;
        }
        return {-1, -1};
    }
};