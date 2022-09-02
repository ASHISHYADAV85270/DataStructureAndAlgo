#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    unordered_map<char, int> m;
    int ct = 0;
    for (int i = 0; i <s.size(); i++)
    {
        int ch;
        if ((i + 1) % 2 != 0)
        {
            ch = s[i];
            m[ch]++;
        }
        else
        {
            ch = s[i] - 'A' + 'a';
            if (m[ch] != 0)
            {
                m[ch]--;
            }
            else
            {
                ct++;
            }
        }
    }
    cout << ct;
    return 0;
}