#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string pattern, book;
        int check = 0;
        cin >> pattern >> book;
        int hsh[2][26];
        for (int i = 0; i < pattern.size(); i++)
        {
            hsh[0][pattern[i] - 'a']++;
        }
        for (int i = 0; i < book.size(); i++)
        {
            hsh[1][book[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            if ((hsh[0][i] - hsh[1][i]) > 0)
            {
                cout << "NO\n";
                check = 1;
                break;
            }
        }
        if (check == 0)
        {
            cout << "YES\n";
        }
    }
    return 0;
}