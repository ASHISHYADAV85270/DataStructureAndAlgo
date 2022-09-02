#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void lower(vector<int> &v, int x)
{
    sort(v.begin(), v.end());
    int left = 0;
    int right = v.size() - 1;
    int mid;
    while (right - left > 1)
    {
        mid = (right + left) / 2;
        if (x > v[mid])
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
        if (x == v[mid])
        {
            cout << "lower bond of  " << x << "is equal to " << v[mid] << "\n";
            return;
        }
    }
    if (v[left] < x)
    {
        if (right > x)
        {

            cout << "lower bond of  " << x << "is equal to " << v[right] << "\n";
        }
        else
        {
            cout << "does not exist ";
        }
    }
    else
    {
        cout << "lower bond of  " << x << "is equal to " << v[left] << "\n";
    }
}
void uppeer(vector<int> &v, int x)
{
    sort(v.begin(), v.end());
    int left = 0;
    int right = v.size() - 1;
    int mid;
    while (right - left > 1)
    {
        mid = (right + left) / 2;
        if (x > v[mid])
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
        if (x == v[mid])
        {
            if (mid+1!=v.size())
            {
                cout << "upper bond of  " << x << "is equal to " << v[mid+1] << "\n";
            }
            else
            {
                cout<<"does not exist ";
            }
            return;
        }
    }
    if (v[left] < x)
    {
        if (right > x)
        {

            cout << "upper bond of  " << x << "is equal to " << v[right] << "\n";
        }
        else
        {
            cout << "does not exist ";
        }
    }
    else
    {
        cout << "upper bond of  " << x << "is equal to " << v[left] << "\n";
    }
}
int main()
{
    vector<int> t = {9, 3, 353, 33, 87, 99, 107,108};
    lower(t, 16);
    lower(t, 98);
    lower(t, 107);
    lower(t, 354);
    cout<<endl;
    uppeer(t, 16);
    uppeer(t, 98);
    uppeer(t, 107);
    uppeer(t, 354);

    return 0;
}