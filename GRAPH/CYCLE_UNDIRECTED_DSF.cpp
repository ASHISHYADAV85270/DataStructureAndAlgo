#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    bool iscycle_dfs(int node, int parent, vector<int> &vis, vector<int> adj[])
    {
        vis[node] = 1;
        for (auto &val : adj[node])
        {
            if (!vis[val])
            {
                vis[val] = 1;
                if (iscycle_dfs(val, node, vis, adj))
                {
                    return true;
                }
            }
            else
            {
                if (parent != val)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> vis(V + 1, 0);
        for (int i = 1; i <= V; i++)
        {
            if (!vis[i])
            {
                if (iscycle_dfs(i, -1, vis, adj))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
int main()
{
    return 0;
}