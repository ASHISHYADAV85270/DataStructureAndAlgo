#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    bool check_bipartite(int node, vector<int> &vis, vector<int> adj[])
    {
        if (vis[node] == -1)
        {
            vis[node] = 1;
        }

        for (auto &it : adj[node])
        {
            if (vis[it] == -1)
            {

                vis[it] = 1 - vis[node];

                if (check_bipartite(it, vis, adj) == false)
                {
                    return false;
                }
            }
            else if (vis[it] == vis[node])
            {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(int V, vector<int> adj[])
    {
        vector<int> vis(V, -1);
        for (int i = 0; i < V; i++)
        {
            if (check_bipartite(i, vis, adj) == false)
            {
                return false;
            }
        }
        return true;
    }
};
int main()
{
    return 0;
}