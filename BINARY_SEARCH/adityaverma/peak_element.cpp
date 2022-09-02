#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution
{
public:
    int binary_search(vector<int> &arr, int start, int end)
    {
        int n = arr.size();
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if ((mid == 0 || arr[mid] > arr[mid - 1]) && (mid == n - 1 && arr[mid] > arr[mid + 1]))
            {
                return mid;
            }
            else if (arr[mid] < arr[mid + 1])
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
    int findPeakElement(vector<int> &nums)
    {

        return binary_search(nums, 0, nums.size() - 1);
    }
};
int main()
{
    return 0;
}