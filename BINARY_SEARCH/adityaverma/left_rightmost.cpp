#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    int binary_search_leftmost(vector<int> &v, int start, int end, int target)
    {
        int res = -1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (v[mid] == target)
            {
                res = mid;
                end = mid - 1;
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
        return res;
    }
    int binary_search_rightmost(vector<int> &v, int start, int end, int target)
    {
        int res = -1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (v[mid] == target)
            {
                res = mid;
                start = mid + 1;
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
        return res;
    }
    vector<int> firstAndLast(vector<int> &arr, int n, int x)
    {
        int left = binary_search_leftmost(arr, 0, n - 1, x);
        if (left == -1)
        {
            return {-1};
        }
        int right = binary_search_rightmost(arr, 0, n - 1, x);
        return {left, right};
    }
};
int main()
{
    return 0;
}