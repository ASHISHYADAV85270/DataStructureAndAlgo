#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
void bubble_sort_optimised(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int check = true;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                check = false;
                swap(arr[j], arr[j + 1]);
            }
        }
        if (check)
        {
            break;
        }
    }
}
void bubble_sort_Wtih_recursion(int arr[], int n, int i, int j, int flag)
{
    if (i == n - 1)
    {
        return;
    }

    if (j == n - 1 - i)
    {
        if (flag == 0)
        {
            return;
        }
        // jb i bdaa rhai hoo tooo flag ko again 0 krdo
        bubble_sort_Wtih_recursion(arr, n, i + 1, 0, 0);
        return;
    }

    if (arr[j] > arr[j + 1])
    {
        swap(arr[j], arr[j + 1]);
        flag = 1;
    }
    bubble_sort_Wtih_recursion(arr, n, i, j + 1, flag);
}
int main()
{
    int arr[] = {6, 98, 12, 2, 7, 276, 45, 2, 62};
    // bubble_sort_optimised(arr, 9);
    bubble_sort_Wtih_recursion(arr, 9, 0, 0, 0);
    for (auto &val : arr)
    {
        cout << val << " ";
    }
    return 0;
}