//https://nifty-lamarr-60d995.netlify.app/
//https://www.hackerearth.com/practice/algorithms/sorting/selection-sort/visualize/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    int arr[7]={4,1,9,12,62,3,8};
    int n=7;
    for (int i = 0; i < n; i++)
    {  int mini_index=i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[j]<arr[mini_index])
            {

                mini_index=j;
            }
        }
        swap(arr[i],arr[mini_index]);
    }

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
     return 0;
}

// O(n^2) complexibility