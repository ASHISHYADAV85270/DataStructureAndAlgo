#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int search_nearly_Sorted(vector<int> &v, int s, int e, int target)
{
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (target == v[mid])
        {
            return mid;
        }
        else if (mid - 1 >= s && target == v[mid - 1])
        {
            return mid - 1;
        }
        else if (mid + 1 <= e && target == v[mid + 1])
        {
            return mid + 1;
        }
        if (target > v[mid])
        {
            s = mid + 2;
        }
        else
        {
            e = mid - 2;
        }
    };
    return -1;
}
int main()
{
    return 0;
}