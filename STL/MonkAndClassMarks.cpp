
/*
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    map<int, multiset<string>> m;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        string name;
        cin >> name >> x;
        m[x].insert(name);
    }
    for (auto outer = --m.end();; outer--)
    {
        int x = (*outer).first;
        auto &v = (*outer).second;
        for (auto it = v.begin(); it != v.end(); it++)
        {
            cout << (*it) << " " << x << "\n";
        }
        if (outer == m.begin())
        {
            break;
        }
    }

    return 0;
}  
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
bool cmp(pair<int, string> a,pair<int, string> b)
{
    if(a.first != b.first)
    {
        return a.first >b.first;
    }
    else
    {
        return a.second < b.second;
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
    sort(v.begin(),v.end(),cmp);
    for(auto &val :v)
    {
        cout<< val.second <<" "<<val.first<<"\n";
    }

    return 0;
}