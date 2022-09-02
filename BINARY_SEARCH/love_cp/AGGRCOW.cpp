#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int l = 1e5;
int arr[l];
bool cowdistance(int gap, int stalls, int cow)
{
    int loc = -1, ct = 0;
    for (int i = 0; i < stalls; i++)
    {
        if ((arr[i] - loc) >= gap || loc == -1)
        {
            ct++;
            loc = arr[i];
            if (ct == cow)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int stalls, cow;
        cin >> stalls >> cow;
        // int arr[stalls];
        for (int i = 0; i < stalls; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + stalls);
        int lo = 0, hi = 1e9;
        while (hi - lo > 1)
        {
            int mid = (lo + hi) / 2;
            if (cowdistance(mid, stalls, cow))
            {
                lo = mid;
            }
            else
            {
                hi = mid - 1;
            }
        };
        if (cowdistance(hi, stalls, cow))
        {
            cout << hi << "\n";
        }
        else
        {
            cout << lo << "\n";
        }
    };
    return 0;
}
