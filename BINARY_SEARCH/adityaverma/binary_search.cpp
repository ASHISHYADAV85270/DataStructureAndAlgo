#include <bits/stdc++.h>
#include <iostream>
using namespace std;
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
int main()
{
    return 0;
}