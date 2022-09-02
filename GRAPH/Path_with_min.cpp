#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int n = heights.size();
        int m = heights[0].size();
        vector<pair<int, int>> adj[n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                adj[i].push_back({j, heights[i][j]});
                adj[j].push_back({i, heights[i][j]});
            }
        }
        vector<int> dis
    }
};
int main()
{
    return 0;
}