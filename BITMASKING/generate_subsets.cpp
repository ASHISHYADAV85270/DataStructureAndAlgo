#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void generate(vector<int> v)
{
    int n = v.size();
    for (int i = 0; i < (1 << n); i++)
    {
        vector<int> p;
        for (int bit_no = 0; bit_no < n; bit_no++)
        {
            if (i & (1 << bit_no))
            {
                p.push_back(v[bit_no]);
            }
        }
        for (auto &val : p)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}
int main()
{
    vector<int> l = {3, 4, 5};
    generate(l);
    return 0;
}