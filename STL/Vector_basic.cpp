#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// v.size()   O(1)
// v.push_back(x)  O(1)
// v.pop_back()  O(1)
// vector <int> v1=v;    O(n)
// vector <int> &v1=v;   O(1)

void printvec(vector<int> v1) //O(n)   because it is making copy of vector
{
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
}
void print_the_vec(vector<int> &v1) //O(1)   because it is taking actual vector
{
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
}

int main()
{
    vector<int> v;
    vector<int> a(10);    //10 places pai zero
    vector<int> b(10, 7); //10 places pai 7


//******vair with pair
    // vector<pair<int, int>> p = {{1, 3}, {2, 8}, {11, 6}};
    // vector<pair<int, int>> p;
    // int n=3;
    // for (int i = 0; i < n; i++)
    // {
    //     int x, y;
    //     cin >> x >> y;
    //     p.push_back({x, y});
    // }
    // for (int i = 0; i < n; i++)
    // {
    // cout<< p[i].first << "  " <<p[i].second<<endl;
    // }
    // a.pop_back(); // sbsai last bala gayaab
    // // iskaa bhi array ki trh same hai 10^5   inside and globally 10^7
    // v.push_back(6);
    // v.push_back(2);
    // v.push_back(9);
    // printvec(v);
    // cout << endl;
    // print_the_vec(v);
    return 0;
}