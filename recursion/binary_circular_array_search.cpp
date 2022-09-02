#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void circularbinarysearch(int arr[], int n, int target)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            cout << "Target is at index= " << mid;
            return;
        }
        if (arr[mid] <= arr[high])
        {
            if ((target >= arr[mid]) && (target <= arr[high]))
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        if (arr[low] <= arr[mid])
        {
            if ((target >= arr[low]) && (target <= arr[mid]))
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
    }
    cout << "target not present in the array";
}
int circular_binarywithRecursion(int arr[], int n, int l, int h, int target)
{
    int mid = l + (h - l) / 2;
    if (h < l)
    {
        return -1;
    }
    if (arr[mid] == target)
    {
        return mid;
    }
    if (arr[mid] <= arr[h])
    {
        if ((target >= arr[mid]) && (target <= arr[h]))
        {
            return circular_binarywithRecursion(arr, n, mid + 1, h, target);
        }
        else
        {
            return circular_binarywithRecursion(arr, n, l, mid - 1, target);
        }
    }
    if (arr[l] <= arr[mid])
    {
        if ((target >= arr[l]) && (target <= arr[mid]))
        {
            return circular_binarywithRecursion(arr, n, l, mid - 1, target);
        }
        else
        {
            return circular_binarywithRecursion(arr, n, mid + 1, h, target);
        }
    }

    return -1;
}
int main()
{
    // int arr[] = {12, 14, 18, 21, 3, 6, 8, 9};
    // int arr[] = {5, 6, 7, 8, 9, 1, 2, 3};
    int arr[] = {4, 5, 1, 2, 3};
    circularbinarysearch(arr, 5, 2);
    cout << "\nby recursion\n";
    int low = 0, high = 4;
    cout << circular_binarywithRecursion(arr, 5, low, high, 2);
    return 0;
}