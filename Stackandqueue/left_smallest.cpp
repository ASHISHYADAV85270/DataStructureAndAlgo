#include <bits/stdc++.h>
#include <iostream>
using namespace std;
vector<int> leftsmallest(vector<int> &arr)
{
    vector<int> l_smallest(arr.size(), 0);
    stack<int> st;
    for (int i = 0; i < arr.size(); i++)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        };
        if (st.empty())
        {
            l_smallest[i] = 0;
        }
        else
        {
            l_smallest[i] = st.top();
        }
        st.push(i);
    }

    return l_smallest;
}
int main()
{
    vector<int> arr = {1, 5, 4, 7, 3, 8, 2};
    vector<int> l_smallest = leftsmallest(arr);

    return 0;
}