#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void merge_array(int arr[], int mid, int s, int e)
{
    int size = e - s + 1;
    int ans[size];
    int itr1 = s, itr2 = mid + 1, k = 0;
    while (itr1 <= mid && itr2 <= e)
    {
        if (arr[itr1] < arr[itr2])
        {
            ans[k] = arr[itr1];
            itr1++;
            k++;
        }
        else
        {
            ans[k] = arr[itr2];
            itr2++;
            k++;
        }
    };
    while (itr1 <= mid)
    {
        ans[k] = arr[itr1];
        itr1++;
        k++;
    }
    while (itr2 <= e)
    {
        ans[k] = arr[itr2];
        itr2++;
        k++;
    }
    for (int i = s, j = 0; i <= e; i++)
    {
        arr[i] = ans[j];
        j++;
    }
}
void break_array(int arr[], int s, int e)
{
    int mid = (e + s) / 2;
    if (s >= e)
    {
        return;
    }
    break_array(arr, s, mid);
    break_array(arr, mid + 1, e);
    merge_array(arr, mid, s, e);
}
int main()
{
    int arr[] = {6, 98, 12, 2, 7, 276, 45, 2, 62};
    break_array(arr, 0, 8);
    for (auto &val : arr)
    {
        {
            cout << val << " ";
        }
    }
    return 0;
}