//https://nifty-lamarr-60d995.netlify.app/
//https://www.hackerearth.com/practice/algorithms/sorting/selection-sort/visualize/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int arr[N];
void merge(int l, int r, int mid)
{
    int l_sz = mid - l + 1;
    int r_sz = r - mid;
    int l_array[l_sz + 1];
    int r_array[r_sz + 1];
    for (int i = 0; i < l_sz; i++)
    {
        l_array[i] = arr[i + l];
    }
    for (int i = 0; i < r_sz; i++)
    {
        r_array[i] = arr[i + mid + 1];
    }
    l_array[l_sz] = r_array[r_sz] = INT_MAX;
    int l_i = 0;
    int r_i = 0;
    for (int i = l; i <= r; i++)
    {
        if (l_array[l_i] <= r_array[r_i])
        {
            arr[i] = l_array[l_i];
            l_i++;
        }
        else
        {
            arr[i] = r_array[r_i];
            r_i++;
        }
    }
}

void mergesort(int l, int r)
{
    if (l == r)
    {
        return;
    }
    int mid = (l + r) / 2;
    mergesort(l, mid);
    mergesort(mid + 1, r);
    merge(l, r, mid);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    mergesort(0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}