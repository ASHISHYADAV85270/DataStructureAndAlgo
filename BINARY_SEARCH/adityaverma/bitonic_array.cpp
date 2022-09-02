#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution
{
public:
    int findMaximum(int arr[], int n)
    {
        // code here
        int s = 0, e = n - 1;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if ((mid == 0 || arr[mid] > arr[mid - 1]) && (mid == n - 1 || arr[mid] > arr[mid + 1]))
            {
                return arr[mid];
            }
            else if (arr[mid] < arr[mid + 1])
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        return -1;
    }
    int binary_search_increasingorder(int v[], int start, int end, int target)
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
    int binary_search_deccreasingorder(int v[], int start, int end, int target)
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
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        };
        return -1;
    }
    int solve(int *A, int n1, int B)
    {
        int pos_of_max = findMaximum(A, n1);
        int left_side = binary_search_increasingorder(A, 0, pos_of_max, B);
        int right_side = binary_search_deccreasingorder(A, pos_of_max + 1, n1 - 1, B);
        return max(left_side, right_side);
    }
};
int main()
{
    return 0;
}