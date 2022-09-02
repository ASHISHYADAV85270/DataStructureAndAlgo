// https://www.hackerrank.com/challenges/cpp-maps/problem
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
        int num;
        cin >> num;
        if (num == 1)
        {
            string x;
            int y;
            cin >> x;
            cin >> y;
            m[x] = m[x] + y;
        }
        else
        {
            string x;
            cin >> x;
            if (num == 2)
            {
                m[x] = 0;
            }
            else
            {
                cout << m[x] << "\n";
            }
        }
    };
    return 0;
}