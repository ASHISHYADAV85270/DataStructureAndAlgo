#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    // TC-> O(n+e)   SC->O(N+E)+ o(n)// for visited array +   o(n)// for queue
    bool cyclecheck(int node, vector<int> &vis, vector<int> adj[])
    {
        queue<pair<int, int>> q;

        q.push({node, -1}); //   joo new node aaygii uskaa koi parent nhi hoga isliye
        vis[node] = 1;

        while (!q.empty())
        {
            int parent = q.front().second; // it will store the parent of the current node
            int child = q.front().first;   // it is itself the node we are traversing
            q.pop();
            for (auto &val : adj[child])
            {
                if (!vis[val])
                {
                    int parent_of_val = child;
                    q.push({val, parent_of_val}); // val is the child of curr node
                    vis[val] = 1;
                }
                else
                {
                    if (parent != val)
                    {
                        return true;
                    }
                }
            }
        };
        return false;
    }
    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> vis(V + 1, 0);
        for (int i = 1; i <= V; i++)
        {
            if (!vis[i])
            {
                if (cyclecheck(i, vis, adj))
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