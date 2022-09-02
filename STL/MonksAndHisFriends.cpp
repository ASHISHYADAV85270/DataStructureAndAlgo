#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        unordered_map<long long, long long> data;
        int n, m;
        cin >> n >> m;
        for (long long i = 0; i < n; i++)
        {
            long long x;
            cin >> x;
            data[x]++;
        }
        while (m--)
        {
            long long x;
            cin >> x;
            auto it = data.find(x);
            if (it != data.end())
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
                data[x]++;
            }
        };
    };
    return 0;
}
