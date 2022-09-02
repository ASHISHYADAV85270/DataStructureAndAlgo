#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    int a[] = {3, 9, 1, 7, 18};
    sort(a, a + 3); //// jhaa sai krnaaa hai ,,,,,, khaa tk krna hai +1
    //is case mai index 0 sai index 2 tk hogi sorting

    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    vector<int> s = {3, 8, 4, 5, 2, 1};
    sort(s.begin(), s.end());
    for (auto &val : s)
    {
        cout << val << " ";
    }

    return 0;
}