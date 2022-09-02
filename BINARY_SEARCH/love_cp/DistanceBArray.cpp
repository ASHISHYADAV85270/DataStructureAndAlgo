// https://leetcode.com/problems/find-the-distance-value-between-two-arrays/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
bool checkdistance(vector<int> &v, int num, int x)
{
    if (v.size() == 1)
    {
        return abs(v[0] - num) > x;
    }
    else
    {
        int lo = 0, hi = v.size() - 1, mid;
        while (hi - lo > 1)
        {
            
            mid = (lo + hi) >> 1;
            if (abs(v[mid] - num) > x)
            {
                lo = mid;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
}
int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
{
    sort(arr2.begin(), arr2.end());
    int ct = 0;
    for (int i = 0; i < arr1.size(); i++)
    {
        if (checkdistance(arr2, arr1[i], d))
        {
            ct++;
        }
    }
    return ct;
}
int main()
{
    // vector<int> a = {4,5,8};
    // vector<int> b = {10,9,1,8};
    // findTheDistanceValue(a,b,2);
    // vector<int> a = {1,4,2,3};
    // vector<int> b = {-4,-3,6,10,20,30};
    // findTheDistanceValue(a,b,3);

    // vector<int> a = {2,1,100,3};
    // vector<int> b = {-5,-2,10,-3,7};
    // findTheDistanceValue(a,b,6);

    return 0;
}