#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    pair<int, string> p;
    pair<int, string> q;
    // cin >> q.first >> q.second;
    p = make_pair(2, "ashish");
    p = {2, "ashihs"};
    cout << p.first << "   " << p.second<<"\n";

    pair<int, string> &p2 = p; // reference variable


    //for accesing two array at a time 

    //for keeping realtion between two array
    int a[]={2,7,5};
    int b[]={4,49,25};
    pair <int,int> k[3];
    k[0]={2,4};
    k[1]={7,49};
    k[2]={5,25};

for (int i = 0; i < 3; i++)
{
    cout<<k[i].first<<"  "<<k[i].second<<"\n";
}
    

    return 0;
}