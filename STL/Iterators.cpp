#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v = {4, 8, 1, 7, 9, 14, 18};
    vector<int>::iterator it;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
    for (it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << "\n";
    for (int value : v)
    {
        cout << value << " ";
    }
    cout << "\n";
    for (int &value : v)              //here change in value will change value in v
    {
        cout << value << " ";
    }
    cout << "\n";
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << "\n";
    for (auto &i : v)
    {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}