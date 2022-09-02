#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        queue<pair<pair<int, int>, int>> q; // pair-->  <pair<row,col> ,time >
        int n = grid.size(), m = grid[0].size(), vis[n][m], t_mx = 0;
        // we will marks visited as 2
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
                else
                {
                    vis[i][j] = 0;
                }
            }
        }
        int r_check[4] = {-1, 0, 1, 0};
        int c_check[4] = {0, -1, 0, 1};
        while (!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            t_mx = max(t_mx, t);
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int r_curr = r + r_check[i];
                int c_curr = c + c_check[i];
                if (r_curr >= 0 && r_curr < n && c_curr >= 0 && c_curr < m && vis[r_curr][c_curr] != 1 && grid[r_curr][c_curr] == 1)
                {
                    q.push({{r_curr, c_curr}, t + 1});
                    vis[r_curr][c_curr] = 1;
                }
            }
        };
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (vis[i][j] == 0 && grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        return t_mx;
    }
};

int main()
{
    return 0;
}