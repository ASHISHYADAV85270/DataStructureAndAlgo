// https://www.spoj.com/problems/EKO/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int N = 1e6;
int arr[N], M;
bool calculatedwood(int H, int n)
{
    long long  sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > H)
        {
            sum += arr[i] - H;
        }
    }
    return sum >= M;
}
int main()
{
    int n;
    cin >> n >> M;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int lo = 0, hi = 1e9;
    while (hi - lo > 1)
    {
        int mid = (lo + hi) / 2;
        if (calculatedwood(mid, n))
        {
            lo = mid;
        }
        else
        {
            hi = mid - 1;
        }
    }
    if (calculatedwood(hi, n))
    {
        cout << hi;
    }
    else
    {
        cout << lo;
    }
    return 0;
}