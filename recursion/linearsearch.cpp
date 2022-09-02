#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// void linearsearch(int arr[], int i, int n, int target)
// {
//     if (arr[i] == target)
//     {
//         cout << "target founded at index = " << i << "\n";
//         return;
//     }
//     if (i == n - 1)
//     {
//         cout << "not founded";
//         return;
//     }

//     linearsearch(arr, i + 1, n, target);
// }
bool linearsearch(int arr[], int i, int n, int target)
{

    if (i == n)
    {
        return false;
    }

    return (arr[i] == target) || linearsearch(arr, i + 1, n, target);
}

vector<int> GetAllTheIndex(int arr[], int i, int n, int target, vector<int> ans)
{
    if (arr[i] == target)
    {
        ans.push_back(i);
    }
    if (i == n)
    {
        return ans;
    }
    return GetAllTheIndex(arr, i + 1, n, target, ans);
}
int main()
{
    int arr[] = {3, 8, 214, 108, 18, 8, 65, 8, 0};
    // cout << linearsearch(arr, 0, 5, 18);
    vector<int> final;
    final = GetAllTheIndex(arr, 0, 9, 8, final);
    for (auto &val : final)
    {
        cout << val << " ";
    }
    return 0;
}