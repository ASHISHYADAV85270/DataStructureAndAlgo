#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> vis(V + 1, 0);
        vector<int> bfs;
        for (int i = 1; i <= V; i++)
        {
            if (vis[i] == 0)
            {
                vis[i] = 1;
                queue<int> q;
                q.push(i);
                while (!q.empty())
                {
                    int node = q.front();
                    q.pop();
                    bfs.push_back(node);
                    for (auto &val : adj[node])
                    {
                        if (!vis[val])
                        {
                            vis[val] = 1;
                            q.push(val);
                        }
                    }
                }
            }
        }
        return bfs;
    }
};
int main()
{
    return 0;
}