#include <bits/stdc++.h>
#include <iostream>
using namespace std;
/*
//it will give tle
int minslidingWindow(vector<int> &nums, int k)
{
    int i = 0, j = 0, n = nums.size(), mx_for_this = INT_MIN;
    list<int> l;
    while (j < n)
    {
        while (!l.empty() && l.back() > nums[j])
        {
            l.pop_back();
        };
        l.push_back(nums[j]);

        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            mx_for_this = max(mx_for_this, l.front());
            if (nums[i] == l.front())
            {
                l.pop_front();
            }
            i++;
            j++;
        }
    };
    return mx_for_this;
}
vector<int> maxMinWindow(vector<int> a, int n)
{
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++)
    {
        ans[i] = minslidingWindow(a, i + 1);
    }
    return ans;
}
*/

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
            l_smallest[i] = st.top() + 1; // last valid upper element
        }
        st.push(i);
    }

    return l_smallest;
}
vector<int> rightsmallest(vector<int> &arr)
{
    int n = arr.size();
    vector<int> r_smallest(arr.size(), 0);
    stack<int> st;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        };
        if (st.empty())
        {
            r_smallest[i] = n - 1;
        }
        else
        {
            r_smallest[i] = st.top() - 1;
        }
        st.push(i);
    }
    return r_smallest;
}
vector<int> maxMinWindow(vector<int> a, int n)
{
    vector<int> ans_max(n, INT_MIN);
    vector<int> r_smallest = rightsmallest(a);
    vector<int> l_smallest = leftsmallest(a);
    for (int i = 0; i < n; i++)
    {
        int index_valid = r_smallest[i] - l_smallest[i] + 1;
        // cout << index_valid << " ";
        ans_max[index_valid - 1] = max(ans_max[index_valid - 1], a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (ans_max[i] == INT_MIN)
        {
            ans_max[i] = ans_max[n - 1];
        }
    }
    return ans_max;
}
int main()
{

    // vector<int> a = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> a = {10, 20, 30, 50, 10, 70, 30};

    maxMinWindow(a, a.size());
    return 0;
}