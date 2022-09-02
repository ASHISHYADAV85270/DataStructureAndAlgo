#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int counter = 0;
void selection_sort_recursion(int arr[], int n, int i, int j, int min_ele)
{
    if (i == n - 1)
    {
        return;
    }
    if (j == n)
    {
        swap(arr[i], arr[min_ele]);
        selection_sort_recursion(arr, n, i + 1, i + 1, i + 1);
        return;
    }
    if (arr[j] < arr[min_ele])
    {
        min_ele = j;
    }
    counter++;

    selection_sort_recursion(arr, n, i, j + 1, min_ele);
}
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr[min], arr[i]);
    }
}
int main()
{
    int arr[] = {6, 98, 12, 2, 7, 276, 45, 2, 62};
    // selectionSort(arr, 9);
    selection_sort_recursion(arr, 9, 0, 0, 0);
    for (auto &val : arr)
    {
        cout << val << " ";
    }
    cout << "\n"
         << counter;
    return 0;
}