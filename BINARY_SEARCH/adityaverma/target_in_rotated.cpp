#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    int binary_search_for_smallest(vector<int> &nums)
    {
        int res = -1, n = nums.size();
        int s = 0, e = nums.size() - 1;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            int prev = (mid - 1 + n) % n, nxt = (mid + 1) % n;
            if (nums[mid] <= nums[prev] && nums[mid] <= nums[nxt])
            {
                return mid;
            }
            else if (nums[mid] <= nums[e])
            {
                e = mid - 1;
            }
            else if (nums[mid] >= nums[s])
            {
                s = mid + 1;
            }
        };
        return -1;
    }
    int binary_search(vector<int> &v, int start, int end, int target)
    {
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (v[mid] == target)
            {
                return mid;
            }
            else if (v[mid] < target)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        };
        return -1;
    }
    int search(vector<int> &nums, int target)
    {
        int smallestindex = binary_search_for_smallest(nums);
        if (target == nums[smallestindex])
        {
            return smallestindex;
        }
        else if (nums[smallestindex] <= target && target <= nums[nums.size() - 1])
        {
            return binary_search(nums, smallestindex + 1, nums.size() - 1, target);
        }
        else
        {
            return binary_search(nums, 0, smallestindex - 1, target);
        }
        return -1;
    }
};
int main()
{
    return 0;
}