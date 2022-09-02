// https://www.hackerearth.com/problem/algorithm/monks-birthday-party/?fbclid=IwAR3COuGp9LqoHKWOnfS-duVdKrF0Vx5shbCbGeiWqSgkdoA2z9926vNy5Ew


#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {   set <string> s;
        int n;
        cin>>n;
        for (int i = 0; i < n; i++)
        {
            string name;
            cin>>name;
            s.insert(name);
        }
        for(auto &it: s)
        {
            cout<<it<<endl;
        }
    }
     return 0;
}