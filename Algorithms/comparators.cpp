#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// cmp always take return in not form...mtlb true aayaa too false  aaygaa and viveversa

bool cmp(int a, int b)
{
    if (a > b)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//// hack jessa order chaiye boo hi bhej dooo
bool vector_cmp(pair<int, int> a, pair<int, int> b)
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
    // int arr[] = {6, 2, 9, 18, 8, 4, 5, 11};
    // sort(arr, arr + 8, cmp);

    // for (int i = 0; i < 8; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    vector<pair<int, int>> v = {{9, 2}, {3, 9}, {6, 1}, {6, 9}, {7, 4}, {1, 1}};
    sort(v.begin(), v.end(), vector_cmp);
    for (auto &val : v)
    {
        cout << val.first << " " << val.second << "\n";
    }

    bool a;
    return 0;
}