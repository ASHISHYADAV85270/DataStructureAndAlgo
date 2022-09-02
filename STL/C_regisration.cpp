#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    int q;
    cin >> q;
    unordered_map<string, int> m;
    while (q--)
    {
        string s;
        cin >> s;
        int y = m[s];
        if (y == 0)
        {
            m[s]++;
            cout << "OK\n";
        }
        else
        {
            y = m[s];
            m[s]++;
            cout << s << y << "\n";
        }
    }

    return 0;
}