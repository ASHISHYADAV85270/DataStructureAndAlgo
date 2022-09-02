#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void convert_toString(vector<int> &v, int num)
{
    while (num != 0)
    {
        int bit = num & 1;
        num = num >> 1;
        v.push_back(bit);
    };
    reverse(v.begin(), v.end());
}
int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        long long int a, b, n;
        cin >> a >> b >> n;
        vector<int> v_A, v_B;
        convert_toString(v_A, a);
        convert_toString(v_B, b);
        for (auto &val : v_A)
        {
            cout << val;
        }
        cout << endl;
        for (auto &val : v_B)
        {
            cout << val;
        }
    }
    return 0;
}
