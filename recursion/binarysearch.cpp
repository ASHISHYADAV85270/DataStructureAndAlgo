#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int binarysearch(int arr[], int target, int s, int e)
{
    if (s > e)
    {
        return -1;
    }
    int mid = s + ((e - s) / 2);
    if (arr[mid] == target)
    {
        return mid;
    }
    if (target < arr[mid])
    {
        return binarysearch(arr, target, s, mid - 1);
    }
    else
    {
        return binarysearch(arr, target, mid + 1, e);
    }
}
int main()
{
    int arr[] = {3, 8, 14, 18, 144};
    cout << binarysearch(arr, 8, 0, 5);
    return 0;
}