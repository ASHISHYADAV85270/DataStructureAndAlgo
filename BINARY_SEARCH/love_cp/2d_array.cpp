#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    int algobinary(vector<int> &v, int n, int x)
    {
        int left = 0;
        int right = n - 1;
        int mid;
        while (right - left > 1)
        {
            mid = (right + left) / 2;
            if (x > v[mid])
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
            if (x == v[mid])
            {

                return true;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        for (auto &val : matrix)
        {
            if (val[0] <= target && val[val.size() - 1] >= target)
            {
                if (algobinary(val, val.size(), target))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    return 0;
}