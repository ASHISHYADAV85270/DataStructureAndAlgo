#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    // it will give tle

    /* int largestRectangleArea(vector<int> &heights)
     {
         int max_Area = 0;
         for (int i = 0; i < heights.size(); i++)
         {
             int min_height = INT_MAX;
             for (int j = i; j < heights.size(); j++)
             {
                 min_height = min(min_height, heights[j]);
                 max_Area = max(max_Area, min_height * (j - i + 1));
             }
         }
         return max_Area;
     }
     */

    // method 2
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
                l_smallest[i] = st.top() + 1;
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
    int largestRectangleArea(vector<int> &heights)
    {
        vector<int> l_smallest = leftsmallest(heights);
        vector<int> r_smallest = rightsmallest(heights);
        int max_area = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            max_area = max(max_area, heights[i] * (r_smallest[i] - l_smallest[i] - 1));
        }
        return max_area;
    }
};
int main()
{
    return 0;
}