#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// 1 2 3 4 5 6
void printnumberpattern(int n)
{
    if (n == 0)
    {
        return;
    }

    printnumberpattern(n - 1);

    cout << n << "\t";
}

// 5 4 3 2 1
void reversenumberpattern(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << n << "\t";

    reversenumberpattern(n - 1);
}
int factorial(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n * factorial(n - 1);
}
int sum(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n + sum(n - 1);
}
int sumofdigits(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n % 10 + sumofdigits(n / 10);
}
int pofdigits(int n)
{
    if (n % 10 == n)
    {
        return n;
    }
    return n % 10 * pofdigits(n / 10);
}

// void reverseanumber(int n, int sum)
// {
//     if (n == 0)
//     {
//         cout << sum;
//         return;
//     }
//     sum = sum * 10 + n % 10;
//     reverseanumber(n / 10, sum);
// }
int countnumverofzeroes(int n, int count)
{
    if (n == 0)
    {
        return count;
    }

    if (n % 10 == 0)
    {
        count++;
    }
    return countnumverofzeroes(n / 10, count);
}
int reverseanumber(int n, int sum)
{
    if (n == 0)
    {
        return sum;
    }
    sum = (sum * 10) + (n % 10);
    return reverseanumber(n / 10, sum);
}
void checkpalindrome(int n)
{
    if (n == reverseanumber(n, 0))
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }
}

// void check_array_is_inincreasing_order_Or_Not(int arr[], int i, int n)
// {
//     if (i == n - 1)
//     {
//         cout << "sorted";
//         return;
//     }
//     if (arr[i] > arr[i + 1])
//     {
//         cout << "not sorted";
//         return;
//     }

//     check_array_is_inincreasing_order_Or_Not(arr, i + 1, n);
// }
bool check_array_is_inincreasing_order_Or_Not(int arr[], int i, int n)
{
    if (i == n - 1)
    {

        return true;
    }
    return (arr[i] < arr[i + 1]) && check_array_is_inincreasing_order_Or_Not(arr, i + 1, n);
}
int main()
{
    // printnumberpattern(5);
    // cout << "\n";
    // reversenumberpattern(5);
    // cout << factorial(4);
    // cout << sum(7);
    // cout << sumofdigits(1234);
    // cout << pofdigits(1294);
    // cout << reverseanumber(3446, 0);
    // checkpalindrome(5445);
    // cout << countnumverofzeroes(1359000, 0);
    // cout << numberofsteps(8, 0);
    int arr[] = {4, 9, 13, 16, 56, 77, 98};
    cout << check_array_is_inincreasing_order_Or_Not(arr, 0, 7);
    return 0;
}