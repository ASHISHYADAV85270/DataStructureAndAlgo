// https://www.spoj.com/problems/MAY99_E1/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
bool cmp(pair<int, char> a, pair<int, char> b)
{
    if (a.first != b.first)
    {
        return a.first > b.first;
    }
    else
    {
        return a.second < b.second;
    }
}
int main()
{
    string s;
    cin >> s;
    map<char, int> m;
    for (int i = 0; i < s.size(); i++)
    {
        m[s[i]]++;
    }
    vector<pair<int, char>> v;
    for (auto &val : m)
    {
        v.push_back({val.second, val.first});
    }
    sort(v.begin(), v.end(), cmp);
    cout << v[0].second;
    return 0;
}