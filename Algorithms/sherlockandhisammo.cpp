
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
bool cmp(pair<int, string> a, pair<int, string> b)
{
    if (a.first != b.first)
    {
        return a.first > b.first;
    }
    else
    {
        return a.second > b.second;
    }
}
int main()
{
    vector<pair<int, string>> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        string s;
        cin >> s >> x;
        v.push_back({x, s});
    }
    sort(v.begin(), v.end(), cmp);
    for (auto &val : v)
    {
        cout << val.second << " " << val.first << "\n";
    }

    return 0;
}