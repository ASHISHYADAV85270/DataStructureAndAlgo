#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    int binary_search(int v[], int start, int end, int n)
    {

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            int prev = (mid + n - 1) % n, next = (mid + 1) % n;
            if (v[mid] <= v[prev] && v[mid] <= v[next])
            {
                return mid;
            }
            else if (v[mid] <= v[end])
            {
                end = (mid - 1);
            }
            else if (v[start] <= v[mid])
            {
                start = (mid + 1);
            }
        };
        return 0;
    }

    int findKRotation(int arr[], int n)
    {
        return binary_search(arr, 0, n - 1, n);
    }
};
int main()
{
    return 0;
}