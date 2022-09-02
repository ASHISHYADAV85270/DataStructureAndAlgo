#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    void dfs(int node, vector<int> &vis, vector<int> &dfs_ans, vector<int> adj[])
    {
        dfs_ans.push_back(node);
        vis[node] = 1;
        for (auto &val : adj[node])
        {
            if (!vis[val])
            {
                dfs(val, vis, dfs_ans, adj);
            }
        }
    }


    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> vis(V + 1, 0);
        vector<int> dfs_ans;
        for (int i = 1; i <= V; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, dfs_ans, adj);
            }
        }
        return dfs_ans;
    }
};
int main()
{
    return 0;
}