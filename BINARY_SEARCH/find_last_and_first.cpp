#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    int findsmaller(vector<int> &v, int target)
    {
        int l = 0, h = v.size() - 1;
        int ans = -1;
        while (h >= l)
        {
            int mid = l + (h - l) / 2;
            if (v[mid] == target)
            {
                ans = mid;
                h = mid - 1;
            }
            else if (v[mid] > target)
            {
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        };
        return ans;
    }
    int findlarger(vector<int> &v, int target)
    {
        int l = 0, h = v.size() - 1;
        int ans = -1;
        while (h >= l)
        {
            int mid = l + (h - l) / 2;
            if (v[mid] == target)
            {
                ans = mid;
                l = mid + 1;
            }
            else if (v[mid] > target)
            {
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        };
        return ans;
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int l = findsmaller(nums, target);
        if (l == -1)
        {
            return {-1, -1};
        }

        int r = findlarger(nums, target);
        return {l, r};
    }
};

int main()
{
    return 0;
}