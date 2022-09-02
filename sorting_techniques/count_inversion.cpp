#include <bits/stdc++.h>
#include <iostream>
using namespace std;
long long int merge_array(long long arr[], long long temp[], int low, int high, int mid)
{
}
long long int merge_sort(long long arr[], long long temp[], int low, int high)
{
    int mid, inv_count = 0;
    mid = (low + high) / 2;
    inv_count += merge_sort(arr, temp, low, mid);
    inv_count += merge_sort(arr, temp, mid + 1, high);

    inv_count += merge_array(arr, temp, low, high, mid);
    return inv_count;
}
long long int inversionCount(long long arr[], long long N)
{
}
int main()
{
    return 0;
}