#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void check(int arr[], int n, long long int sum)
{
    for (int i = 0; i <= (1 << n) - 1; i++)
    {
        long long int antisum = 0;
        for (int bit_check = 0; bit_check < n; bit_check++)
        {
            if (i & (1 << bit_check))
            {
                antisum += arr[bit_check];
            }
        }
        if (antisum == sum - antisum || ((antisum % 360 == 0) && (antisum != 0)))
        {
            cout << "YES";
            return;
        }
    }
    cout << "NO";
    return;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    long long int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum = sum + arr[i];
    }
    check(arr, n, sum);

    return 0;
}