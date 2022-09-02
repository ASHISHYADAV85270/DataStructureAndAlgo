#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// const int N = 1e7 + 10;
// long long int arr[N];
// int main()
// {
//     int n, query;
//     cin >> n >> query;
//     while(query--)
//     {   
//         int a, b, k;
//         cin >> a >> b >> k;
//         for (int i = a; i <= b; i++)
//         {
//             arr[i] += k;
//         }
//     }
//     long long mx = -1;
//     for (int i = 1; i <= n; i++)
//     {
//         if (mx < arr[i])
//         {
//             mx = arr[i];
//         }
//     }
//     cout << mx << endl;
//     return 0;
// }

const int N = 1e7 + 10;
long long int hsh[N];
int main()
{
    int n, query;
    cin >> n >> query;
    while(query--)
    {   
        int a, b, k;
        cin >> a >> b >> k;
        hsh[a]=hsh[a]+k;
        hsh[b+1]=hsh[b+1]-k;
    }
    for (int i = 1; i <=n; i++)
    {
        hsh[i]=hsh[i-1]+hsh[i];
    }
    long long mx = -1;
    for (int i = 1; i <= n; i++)
    {
        if (mx < hsh[i])
        {
            mx = hsh[i];
        }
    }
    cout << mx << endl;
    return 0;
}