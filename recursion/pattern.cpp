#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void pattern_one(int r, int c)
{
    if (r == 0)
    {
        return;
    }
    if (r > c)
    {
        pattern_one(r, c + 1);
        cout << "*"
             << " ";
    }
    else
    {
        pattern_one(r - 1, 0);
        cout << "\n";
    }
}
// void pattern_one(int n, int i)
// {
//     if (i == 0)
//     {
//         return;
//     }
//     for (int j = 0; j < i; j++)
//     {
//         cout << "*"
//              << " ";
//     }
//     cout << "\n";
//     pattern_one(n, i - 1);
// }
int main()
{
    pattern_one(5, 0);
    return 0;
}