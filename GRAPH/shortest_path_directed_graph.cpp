#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define INF INT_MAX
/*
6
7
0 1 2
0 4 1
1 2 3
2 3 6
4 2 2
4 5 4
5 3 1
*/
void topo_sort_dac(int node, vector<int> &vis, stack<int> &st, vector<pair<int, int>> adj[])
{
    vis[node] = 1;
    for (auto &it : adj[node])
    {
        if (vis[it.first] == 0)
        {
            topo_sort_dac(it.first, vis, st, adj);
        }
    }
    st.push(node);
}

void shortestpath(int scr, int n, vector<pair<int, int>> adj[])
{

    vector<int> vis(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            topo_sort_dac(i, vis, st, adj);
        }
    }
    vector<int> dis(n, 0);
    for (int i = 0; i < n; i++)
    {
        dis[i] = 1e9;
    }

    dis[scr] = 0;
    // cout << st.size();
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (dis[node] != INF)
        {
            for (auto it : adj[node])
            {
                if (dis[node] + it.second < dis[it.first])
                {
                    dis[it.first] = dis[node] + it.second;
                }
            }
        }
    }

    for (auto &val : dis)
    {
        cout << val << " ";
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }
    shortestpath(0, n, adj);
    return 0;
}