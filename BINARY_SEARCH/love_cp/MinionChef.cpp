// https://www.codechef.com/problems/MINEAT
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int n, h;
const int l = 1e5 + 1;
int arr[l];
//4 3 2 7
//0 -1 -2 -3
// 0 0 0 0 3
bool calbanan(int x)
{
    int ct = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > x)
        {
            if (arr[i] % x == 0)
            {
                ct = ct + int(arr[i] / x);
            }
            else
            {
                ct = ct + int(arr[i] / x) + 1;
            }
        }
        else
        {
            ct++;
        }
    }
    return ct <= h;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> h;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int lo = 1, hi = 1e9, mid;
        while (hi - lo > 1)
        {
            mid = (lo + hi) / 2;

            if (!calbanan(mid))
            {
                lo = mid;
            }
            else
            {
                hi = mid;
            }
        };
        cout << hi << endl;
    }
    return 0;
}