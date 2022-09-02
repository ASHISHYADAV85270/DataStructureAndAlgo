#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int sort_and_loc_of_piv(int arr[], int start, int end)
{
    int pivot_idx = start;
    while (start < end)
    {
        while (arr[start] <= arr[pivot_idx])
        {
            start++;
        };
        while (arr[end] > arr[pivot_idx])
        {
            end--;
        };
        if (start < end)
        {
            swap(arr[start], arr[end]);
        }
    }
    swap(arr[pivot_idx], arr[end]);
    pivot_idx = end;
    return pivot_idx;
}
void partition_of_arr(int arr[], int start, int end)
{
    if (start < end)
    {
        int piv_idx = sort_and_loc_of_piv(arr, start, end);
        partition_of_arr(arr, start, piv_idx - 1);
        partition_of_arr(arr, piv_idx + 1, end);
    }
    return;
}
int main()
{
    int arr[] = {6, 98, 12, 2, 7, 276, 45, 2, 62};
    partition_of_arr(arr, 0, 8);
    for (auto &val : arr)
    {
        cout << val << " ";
    }
    return 0;
}