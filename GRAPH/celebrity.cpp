#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution
{
public:
    int celebrity(vector<vector<int>> &M, int n)
    {
        stack<int> st;
        // pushing all the elements
        for (int i = 0; i < n; i++)
        {
            st.push(i);
        }

        while (st.size() > 1)
        {
            int a = st.top();
            st.pop();

            int b = st.top();
            st.pop();

            // if a knows b or not
            if (M[a][b] == 1)
            {
                st.push(b); // mtlb a b koo janta hai too shayad b celebrity ho skta hai
            }
            else
            {
                st.push(a);
            }
        };

        int ans = st.top(); // most possible answer but we will verify it

        int r_ct = 0;
        for (int i = 0; i < M.size(); i++)
        {
            if (M[ans][i] == 0)
            {
                r_ct++;
            }
        }
        if (r_ct != n)
        {
            return -1;
        }

        int c_ct = 0;
        for (int i = 0; i < M.size(); i++)
        {
            if (M[i][ans] == 1)
            {
                c_ct++;
            }
        }
        if (c_ct != n - 1) // beacuse middle wala zero hota hai ans-->ans bala
        {
            return -1;
        }
        return ans;
    }
};
int main()
{
    return 0;
}