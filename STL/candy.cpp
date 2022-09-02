#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    int t, n, k;
    cin>>t;
    while (t--)
    {
        multiset<long long int> m;
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            long long int val;
            cin >> val;
            m.insert(val);
        }
        long long candy = 0;
        for (int i = 0; i < k; i++)
        {
            auto l_can = (--m.end());
            long long x = *l_can;
            candy = x + candy;
            m.erase(l_can);
            m.insert(x / 2);
        }
        cout << candy << "\n";
    }
    return 0;
}